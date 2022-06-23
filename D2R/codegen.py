import os
import json
import shutil
from collections import OrderedDict


path = os.path.abspath(os.path.dirname(__file__))

base = idaapi.get_imagebase()
end_ea = idc.get_segm_end(0)

shutil.rmtree(os.path.join(path, 'gen'), ignore_errors=True)
os.makedirs(os.path.join(path, 'gen'), exist_ok=True)

def offset(item):
    address = ida_search.find_binary(0, end_ea, str(item['pattern']), 16, idc.SEARCH_DOWN)
    if address == idaapi.BADADDR:
        return
    if item['type'] == 'operand':
        address = idc.get_operand_value(address, item['operand'])
    #idk have to do this for function table..
    elif item['type'] == 'other':
        address = base + idc.get_operand_value(address, item['operand'])
    #sig points to an absolute addr usually start of func or something unnecassary code but making it explict what is happening
    elif item['type'] == 'absolute':
        None
    offset = address - base
    return offset

def write(outfile, data):
    data = sorted(data, key=lambda x: x['name'])
    outfile.write("[\n")
    if len(data) > 1:
        for d in data[:-1]:
            outfile.write("{},\n".format(json.dumps(d)))
    if len(data) > 0:
        outfile.write("{}\n".format(json.dumps(data[-1])))
    outfile.write("]\n")
    return

with open(os.path.join(path, 'gen', 'D2Structs.h'), "w") as outfile:
    outfile.write("#pragma once\n")
    outfile.write("#include <cstdint>\n\n")
    outfile.write("""
//IDA types
typedef unsigned __int64 _QWORD;
typedef unsigned __int32 _DWORD;
typedef union __declspec(intrin_type) __declspec(align(16)) __m128i {
	__int8              m128i_i8[16];
	__int16             m128i_i16[8];
	__int32             m128i_i32[4];
	__int64             m128i_i64[2];
	unsigned __int8     m128i_u8[16];
	unsigned __int16    m128i_u16[8];
	unsigned __int32    m128i_u32[4];
	unsigned __int64    m128i_u64[2];
} __m128i;

//D2R types
""")
    with open(os.path.join(path, 'IDA.h'), "r") as infile:
        outfile.write(infile.read())


for filename in ['D2UIMessages.h', 'D2UIMessages.cpp', 'D2Enums.h']:
    with open(os.path.join(path, 'gen', filename), "w") as outfile:
        with open(os.path.join(path, 'data', filename), "r") as infile:
            outfile.write(infile.read())

with open(os.path.join(path, 'data', 'functions.json')) as f:
    functions = json.load(f)
with open(os.path.join(path, 'data', 'variables.json')) as f:
    variables = json.load(f)
if os.path.exists(os.path.join(path, 'data', '_functions.json')) and os.path.isfile(os.path.join(path, 'data', '_functions.json')):
    with open(os.path.join(path, 'data', '_functions.json')) as f:
        functions = functions + json.load(f)
if os.path.exists(os.path.join(path, 'data', '_variables.json')) and os.path.isfile(os.path.join(path, 'data', '_variables.json')):
    with open(os.path.join(path, 'data', '_variables.json')) as f:
        variables = variables + json.load(f)

with open(os.path.join(path, 'data', 'd2gs_types.json')) as f:
    d2gs_types = json.load(f)
if os.path.exists(os.path.join(path, 'data', '_d2gs_types.json')) and os.path.isfile(os.path.join(path, 'data', '_d2gs_types.json')):
    with open(os.path.join(path, 'data', '_d2gs_types.json')) as f:
        d2gs_types = d2gs_s2c + json.load(f)
with open(os.path.join(path, 'data', 'd2gs_c2s.json')) as f:
    d2gs_c2s = json.load(f)
if os.path.exists(os.path.join(path, 'data', '_d2gs_c2s.json')) and os.path.isfile(os.path.join(path, 'data', '_d2gs_c2s.json')):
    with open(os.path.join(path, 'data', '_d2gs_c2s.json')) as f:
        d2gs_c2s = d2gs_c2s + json.load(f)
with open(os.path.join(path, 'data', 'd2gs_s2c.json')) as f:
    d2gs_s2c = json.load(f)
if os.path.exists(os.path.join(path, 'data', '_d2gs_s2c.json')) and os.path.isfile(os.path.join(path, 'data', '_d2gs_s2c.json')):
    with open(os.path.join(path, 'data', '_d2gs_s2c.json')) as f:
        d2gs_s2c = d2gs_s2c + json.load(f)


functions = sorted(functions, key=lambda x: x['name'])
variables = sorted(variables, key=lambda x: x['name'])
d2gs_c2s = sorted(d2gs_c2s, key=lambda x: int(x['id'], 16))
d2gs_s2c = sorted(d2gs_s2c, key=lambda x: int(x['id'], 16))

#sort files
for filename in ['_functions.json', 'functions.json', '_variables.json', 'variables.json']:
    if os.path.exists(os.path.join(path, 'data', filename)) and os.path.isfile(os.path.join(path, 'data', filename)):
        with open(os.path.join(path, 'data', filename)) as f:
            data = json.load(f, object_pairs_hook=OrderedDict)
        with open(os.path.join(path, 'data', filename), 'w') as outfile:
            write(outfile, data)


with open(os.path.join(path, 'gen', 'D2Ptrs.h'), "w") as outfile:
    outfile.write("#pragma once\n")
    outfile.write("#include <Windows.h>\n")
    outfile.write("#include <cstdint>\n")
    outfile.write("#include \"D2Structs.h\"\n\n")
    outfile.write("extern uint64_t BaseAddress;\n\n")
    outfile.write("//Variables: \n")
    for item in variables:
        if not item['used']:
            continue
        if 'summary' in item:
            outfile.write("/*\n{}\n*/\n".format(item['summary']))
        outfile.write("extern {}* {};\n".format(item['ctype'],item['name']))
    outfile.write("\n")
    outfile.write("//Functions: \n")
    for item in functions:
        if not item['used']:
            continue
        outfile.write("typedef {} {} {}_t{};\n".format(item['ret'],item['conv'],item['name'],item['args']))
        if 'summary' in item:
            outfile.write("/// <summary>\n")
            for l in item['summary'].splitlines(True):
                outfile.write("/// {}".format(l))
            outfile.write("\n/// </summary>\n")
        outfile.write("extern {}_t* {};\n\n".format(item['name'],item['name']))

with open(os.path.join(path, 'gen', 'D2Ptrs.cpp'), "w") as outfile:
    outfile.write("#include <Windows.h>\n")
    outfile.write("#include \"D2Ptrs.h\"\n\n")
    outfile.write("uint64_t BaseAddress = (uint64_t)GetModuleHandle(NULL);\n\n")
    outfile.write("//Variables: \n")
    for item in variables:
        item['offset'] = hex(offset(item)).rstrip("L")
        if not item['used']:
            continue
        print(f"Generating variable {item}")
        outfile.write("{}* {} = ({}*)(BaseAddress + static_cast<uint64_t>({}));\n".format(item['ctype'],item['name'],item['ctype'],item['offset']))
    outfile.write("\n")
    outfile.write("//quick copy pasta method testing:\n")
    outfile.write("// reinterpret_cast<void(__fastcall*)(void*)>(BaseAddress + 0x0)(nullptr);\n")
    outfile.write("//Functions: \n")
    for item in functions:
        item['offset'] = hex(offset(item)).rstrip("L")
        if not item['used']:
            continue
        print(f"Generating function {item}")
        outfile.write("{}_t* {} = ({}_t*)(BaseAddress + static_cast<uint64_t>({}));\n".format(item['name'],item['name'],item['name'],item['offset']))

with open(os.path.join(path, 'gen', 'D2GS.cpp'), "w") as outfile:
    outfile.write("#include \"D2GS.h\"\n")
    outfile.write("#include <iostream>\n\n")

    outfile.write("void D2GS_C2S_Print(uint8_t* pPacket, uint64_t nLen)\n{\n\tswitch(pPacket[0])\n\t{\n")
    for item in d2gs_c2s:
        if 'ignore' in item and item['ignore']:
            outfile.write("\tcase {}: {{ break; }} //D2GS_C2S_{}\n".format(item['id'], item['name']))
        else:
            outfile.write("\tcase {}: {{ D2GS_C2S_{}* pCasted = reinterpret_cast<D2GS_C2S_{}*>(pPacket); printf(\"{}: ".format(item['id'], item['name'], item['name'], item['name']))
            for field in item['fields']:
                outfile.write("{}: %d ".format(field['name']))
            outfile.write("\\n\"".format(item['name']))
            for field in item['fields']:
                outfile.write(", pCasted->{}".format(field['name']))
            outfile.write("); break; }\n")
    outfile.write("\tdefault: { printf(\"Unknown Packet: \"); for (int i = 0; i < nLen; i++) { printf(\"%02X \", pPacket[i]); } printf(\"\\n\"); break; }\n\t}\n}\n\n")



with open(os.path.join(path, 'gen', 'D2GS.h'), "w") as outfile:
    outfile.write("#pragma once\n")
    outfile.write("#include <Windows.h>\n")
    outfile.write("#include <cstdint>\n")
    outfile.write("\n")
    outfile.write("#pragma pack(push, 1)\n\n")
    outfile.write("//Shared Types: \n")
    for item in d2gs_types:
        if 'ignore' in item and item['ignore']:
            continue
        else:
            outfile.write("struct D2GS_{} {{\n".format(item['name']))
            for field in item['fields']:
                if any(x['name'] == field['type'] for x in d2gs_types):
                    outfile.write("\tD2GS_{} {}".format(field['type'], field['name']))
                else:
                    outfile.write("\t{} {}".format(field['type'], field['name']))
                if 'array' in field and 'len' in field and field['array']:
                    outfile.write("[{}]".format(field['len']))
                if 'value' in field:
                    outfile.write(" = {}".format(field['value']))
                outfile.write(";")
                if 'summary' in field:
                    outfile.write(" //{}".format(field['summary'].replace('\n', ' ')))
                outfile.write("\n")
            outfile.write("};\n")
            if 'size' in item:
                outfile.write("static_assert(sizeof(D2GS_{}) == {});\n".format(item['name'], item['size']))
            outfile.write("\n")


    outfile.write("//Client to Server: \n")

    outfile.write("void D2GS_C2S_Print(uint8_t* pPacket, uint64_t nLen);\n")

    for item in d2gs_c2s:
        if 'ignore' in item and item['ignore']:
            continue
        else:
            outfile.write("/// <summary>\n")
            outfile.write("/// D2GS Client to Server Packet {}\n".format(item['id']))
            if 'summary' in item:
                for l in item['summary'].splitlines(True):
                    outfile.write("/// {}".format(l))
            outfile.write("/// </summary>\n")
            outfile.write("struct D2GS_C2S_{} {{\n\tuint8_t ID = {};\n".format(item['name'], item['id']))
            for field in item['fields']:
                if any(x['name'] == field['type'] for x in d2gs_types):
                    outfile.write("\tD2GS_{} {}".format(field['type'], field['name']))
                else:
                    outfile.write("\t{} {}".format(field['type'], field['name']))
                if 'array' in field and 'len' in field and field['array']:
                    outfile.write("[{}]".format(field['len']))
                if 'value' in field:
                    outfile.write(" = {}".format(field['value']))
                outfile.write(";")
                if 'summary' in field:
                    outfile.write(" //{}".format(field['summary'].replace('\n', ' ')))
                outfile.write("\n")
            outfile.write("};\n")
            if 'size' in item:
                outfile.write("static_assert(sizeof(D2GS_C2S_{}) == {});\n".format(item['name'], item['size']))
            outfile.write("\n")

    outfile.write("//Server to Client: \n")
    for item in d2gs_s2c:
        if 'ignore' in item and item['ignore']:
            continue
        else:
            outfile.write("/// <summary>\n")
            outfile.write("/// D2GS Server to Client Packet {}\n".format(item['id']))
            if 'summary' in item:
                for l in item['summary'].splitlines(True):
                    outfile.write("/// {}".format(l))
            outfile.write("/// </summary>\n")
            outfile.write("struct D2GS_S2C_{} {{\n\tuint8_t ID = {};\n".format(item['name'], item['id']))
            for field in item['fields']:
                if any(x['name'] == field['type'] for x in d2gs_types):
                    outfile.write("\tD2GS_{} {}".format(field['type'], field['name']))
                else:
                    outfile.write("\t{} {}".format(field['type'], field['name']))
                if 'array' in field and 'len' in field and field['array']:
                    outfile.write("[{}]".format(field['len']))
                if 'value' in field:
                    outfile.write(" = {}".format(field['value']))
                outfile.write(";")
                if 'summary' in field:
                    outfile.write(" //{}".format(field['summary'].replace('\n', ' ')))
                outfile.write("\n")
            outfile.write("};\n")
            if 'size' in item:
                outfile.write("static_assert(sizeof(D2GS_S2C_{}) == {});\n".format(item['name'], item['size']))
            outfile.write("\n")

    outfile.write("\n#pragma pack(pop)")


with open(os.path.join(path, 'gen', 'offsets_variables.json'), "w") as outfile:
    json.dump(variables, outfile)

with open(os.path.join(path, 'gen', 'offsets_functions.json'), "w") as outfile:
    json.dump(functions, outfile)


print('Done')