#pragma once



#pragma pack(1)

enum D2DrlgFlags
{
	DRLGFLAG_ONCLIENT = 0x01,
};

enum D2Directions
{
	DIRECTION_INVALID = -1,
	DIRECTION_SOUTHWEST = 0,
	DIRECTION_NORTHWEST = 1,
	DIRECTION_SOUTHEAST = 2,
	DIRECTION_NORTHEAST = 3,
	DIRECTION_COUNT = 4,
};

enum D2AltDirections
{
	ALTDIR_WEST,
	ALTDIR_NORTH,
	ALTDIR_EAST,
	ALTDIR_SOUTH,
	ALTDIR_NORTHWEST,
	ALTDIR_NORTHEAST,
	ALTDIR_SOUTHEAST,
	ALTDIR_SOUTHWEST,
};

enum D2C_DrlgTypes
{
	DRLGTYPE_MAZE = 0x01,
	DRLGTYPE_PRESET = 0x02,
	DRLGTYPE_OUTDOOR = 0x03,
	NUM_DRLGTYPES
};

enum D2RoomExFlags
{
	ROOMEXFLAG_INACTIVE = 0x00000002,
	ROOMEXFLAG_HAS_WARP_0 = 0x00000010,
	ROOMEXFLAG_HAS_WARP_1 = 0x00000020,
	ROOMEXFLAG_HAS_WARP_2 = 0x00000040,
	ROOMEXFLAG_HAS_WARP_3 = 0x00000080,
	ROOMEXFLAG_HAS_WARP_4 = 0x00000100,
	ROOMEXFLAG_HAS_WARP_5 = 0x00000200,
	ROOMEXFLAG_HAS_WARP_6 = 0x00000400,
	ROOMEXFLAG_HAS_WARP_7 = 0x00000800,
	ROOMEXFLAG_SUBSHRINE_ROW1 = 0x00001000,
	ROOMEXFLAG_SUBSHRINE_ROW2 = 0x00002000,
	ROOMEXFLAG_SUBSHRINE_ROW3 = 0x00004000,
	ROOMEXFLAG_SUBSHRINE_ROW4 = 0x00008000,
	ROOMEXFLAG_HAS_WAYPOINT = 0x00010000,			//outdoors with subtheme and subwaypoint
	ROOMEXFLAG_HAS_WAYPOINT_SMALL = 0x00020000,		//waypoint small
	ROOMEXFLAG_AUTOMAP_REVEAL = 0x00040000,
	ROOMEXFLAG_NO_LOS_DRAW = 0x00080000,
	ROOMEXFLAG_HAS_ROOM = 0x00100000,				//an active pRoom structure is attached to this RoomEx
	ROOMEXFLAG_ROOM_FREED_SRV = 0x00200000,			//set after freeing the pRoom
	ROOMEXFLAG_HASPORTAL = 0x00400000,				//prevents room deletion
	ROOMEXFLAG_POPULATION_ZERO = 0x00800000,		//set for towns, also set if a ds1 has populate=0 // nospawn region
	ROOMEXFLAG_TILELIB_LOADED = 0x01000000,
	ROOMEXFLAG_PRESET_UNITS_ADDED = 0x02000000,		//refers to DRLGMap or DRLGFile; adds the hardcoded preset units
	ROOMEXFLAG_PRESET_UNITS_SPAWNED = 0x04000000,	//set after RoomEx preset units have been spawned / prevents respawning them on room reactivation
	ROOMEXFLAG_ANIMATED_FLOOR = 0x08000000,			//animated floors (river of flame, hell act5)

	ROOMEXFLAG_HAS_WARP = (ROOMEXFLAG_HAS_WARP_0 | ROOMEXFLAG_HAS_WARP_1 | ROOMEXFLAG_HAS_WARP_2 | ROOMEXFLAG_HAS_WARP_3 | ROOMEXFLAG_HAS_WARP_4 | ROOMEXFLAG_HAS_WARP_5 | ROOMEXFLAG_HAS_WARP_6 | ROOMEXFLAG_HAS_WARP_7),
};

enum D2DrlgLevelFlags
{
	DRLGLEVELFLAG_AUTOMAP_REVEAL = 0x10,
};


struct D2DrlgCoordStrc
{
	int32_t nPosX;								//0x00
	int32_t nPosY;								//0x04
	int32_t nWidth;								//0x08
	int32_t nHeight;							//0x0C
};

struct D2DrlgCoordsStrc
{
	int32_t dwSubtilesLeft;						//0x00
	int32_t dwSubtilesTop;						//0x04
	int32_t dwSubtilesWidth;					//0x08
	int32_t dwSubtilesHeight;					//0x0C
	int32_t dwTilesLeft;						//0x10
	int32_t dwTilesTop;							//0x14
	int32_t dwTilesWidth;						//0x18
	int32_t dwTilesHeight;						//0x1C
};

struct D2RoomExStrc
{
	D2DrlgLevelStrc* pLevel;					//0x00
	union
	{
		struct
		{
			int32_t nTileXPos;					//0x04
			int32_t nTileYPos;					//0x08
			int32_t nTileWidth;					//0x0C
			int32_t nTileHeight;				//0x10
		};
		D2DrlgCoordStrc pDrlgCoord;				//0x04
	};
	uint32_t dwFlags;							//0x14
	uint32_t dwOtherFlags;						//0x18
	int32_t nType;								//0x1C
	union
	{
		D2DrlgPresetRoomStrc* pMaze;		//0x20
		D2DrlgOutdoorRoomStrc* pOutdoor;	//0x20
	};
	uint32_t dwDT1Mask;						//0x24 - tile caching mask, used to init below @ D2Common.0x4A380
	D2TileLibraryHashStrc* pTiles[32];		//0x28
	D2DrlgTileGridStrc* pTileGrid;			//0xA8
											//uint32_t fRoomStatus;						//0xAC - actually a byte, the padding up to +B8 is related
	uint8_t fRoomStatus;						//0xAC
	uint8_t unk0xAD;							//0xAD
	uint16_t unk0xAE[5];						//0xAE
	D2RoomExStrc* pStatusNext;				//0xB8
	D2RoomExStrc* pStatusPrev;				//0xBC
	D2RoomExStrc** ppRoomsNear;				//0xC0 // names pptVisibleRooms in the original game
	int32_t nRoomsNear;							//0xC4
	D2RoomTileStrc* pRoomTiles;				//0xC8
	D2PresetUnitStrc* pPresetUnits;			//0xCC
	D2DrlgOrthStrc* pDrlgOrth;				//0xD0
	D2SeedStrc pSeed;						//0xD4
	uint32_t dwInitSeed;						//0xDC
	D2DrlgCoordListStrc* pCoordList;		//0xE0 // named ptLogicalRoomInfo in the original game
	D2RoomStrc* pRoom;						//0xE4
	D2RoomExStrc* pRoomExNext;				//0xE8
};

typedef int32_t(__stdcall* ROOMCALLBACKFN)(D2RoomStrc*, void*);

struct D2RoomStrc
{
	union
	{
		struct
		{
			int32_t nSubtileX;					//0x00
			int32_t nSubtileY;					//0x04
			int32_t nSubtileWidth;				//0x08
			int32_t nSubtileHeight;				//0x0C
			int32_t nTileXPos;					//0x10
			int32_t nTileYPos;					//0x14
			int32_t nTileWidth;					//0x18
			int32_t nTileHeight;				//0x1C
		};
		D2DrlgCoordsStrc pCoords;			//0x00
	};
	D2DrlgRoomTilesStrc* pRoomTiles;		//0x20
	D2RoomStrc** ppRoomList;				//0x24
	int32_t nNumRooms;							//0x28
	D2UnitStrc* pUnitFirst;					//0x2C
	D2UnitStrc* pUnitUpdate;				//0x30
	D2RoomCollisionGridStrc* pCollisionGrid;//0x34
	D2RoomExStrc* pRoomEx;					//0x38
	D2SeedStrc pSeed;						//0x3C
	D2DrlgDeleteStrc* pDrlgDelete;			//0x44
	uint32_t dwFlags;							//0x48
	D2ClientStrc** ppClients;				//0x4C
	int32_t nNumClients;						//0x50
	int32_t nMaxClients;						//0x54
	int32_t nTileCount;							//0x58
	int32_t nAllies;							//0x5C // nPlayerUnits in the game
	int32_t unk0x60;							//0x60
	uint8_t nCurrentDeathIndex;				//0x64
	uint8_t pad0x65[3];						//0x65
	int32_t nLastDeadGUIDs[4];					//0x68
	D2DrlgActStrc* pAct;					//0x78
	D2RoomStrc* pRoomNext;					//0x7C
};

struct D2RoomTileStrc
{
	D2RoomExStrc* pRoomEx;					//0x00
	D2LvlWarpTxt* pLvlWarpTxtRecord;		//0x04
	BOOL bEnabled;							//0x08
	D2DrlgTileDataStrc* unk0x0C;			//0x0C
	D2DrlgTileDataStrc* unk0x10;			//0x10
	D2RoomTileStrc* pNext;					//0x14
};

typedef void(__stdcall* AUTOMAPFN)(D2RoomStrc*);
typedef void(__stdcall* TOWNAUTOMAPFN)(int32_t, int32_t, int32_t, int32_t);

//struct D2RoomCoordStrc
//{
//	int32_t nSubtileX;							//0x00
//	int32_t nSubtileY;							//0x04
//	int32_t nSubtileWidth;						//0x08
//	int32_t nSubtileHeight;						//0x0C
//	int32_t nTileXPos;							//0x10
//	int32_t nTileYPos;							//0x14
//	int32_t nTileWidth;							//0x18
//	int32_t nTileHeight;						//0x1C
//};

struct D2RoomCoordListStrc
{
	D2DrlgCoordStrc pBox[2];				//0x00
	BOOL bNode;								//0x20
	BOOL bRoomActive;						//0x24
	int32_t nIndex;								//0x28
	D2RoomCoordListStrc* pNext;				//0x2C
};

struct D2DrlgStrc
{
	D2DrlgLevelStrc* pLevel;				//0x00
	void* pMempool;							//0x04
	void* unk0x08;							//0x08
	D2DrlgActStrc* pAct;					//0x0C
	uint8_t nAct;								//0x10
	uint8_t pad0x11[3];						//0x11
	D2SeedStrc pSeed;						//0x14
	uint32_t dwStartSeed;						//0x1C
	uint32_t dwGameLowSeed;					//0x20
	uint32_t dwFlags;							//0x24
	D2RoomExStrc pRooms[4];		//0x28
	D2RoomExStrc* pRoomEx;			//0x3D8
	uint8_t unk0x3DC;							//0x3DC
	uint8_t unk0x3DD[3];						//0x3DD
	int32_t unk0x3E0[2];						//0x3E0
	D2GameStrc* pGame;						//0x3E8
	uint8_t nDifficulty;						//0x3EC
	uint8_t pad0x3ED[3];						//0x3ED
	AUTOMAPFN pfAutomap;					//0x3F0
	TOWNAUTOMAPFN pfTownAutomap;			//0x3F4
	int32_t nStaffTombLevel;					//0x3F8
	int32_t nBossTombLevel;						//0x3FC
	D2TileLibraryHashStrc* pTiles[32];		//0x400
	int32_t bJungleInterlink;					//0x480
	D2DrlgWarpStrc* pWarp;					//0x484
};

struct D2DrlgTileDataStrc
{
	int32_t nWidth;								//0x00
	int32_t nHeight;							//0x04
	int32_t nPosX;								//0x08
	int32_t nPosY;								//0x0C
	int32_t unk0x10;							//0x10
	uint32_t dwFlags;					//0x14
	D2TileLibraryEntryStrc* pTile;			//0x18
	int32_t unk0x1C;							//0x1C
	D2DrlgTileDataStrc* unk0x20;			//0x20
	int32_t unk0x24;							//0x24
	uint8_t nRed;								//0x28
	uint8_t nGreen;							//0x29
	uint8_t nBlue;								//0x2A
	uint8_t nIntensity;						//0x2B
	int32_t unk0x2C;							//0x2C
};

typedef void(__fastcall* ACTCALLBACKFN)(D2RoomStrc*);

struct D2DrlgActStrc
{
	uint8_t nAct;								//0x00
	uint8_t pad0x01[3];						//0x01
	D2RoomStrc* pRoom;						//0x04
	D2DrlgStrc* pDrlg;						//0x08
	uint32_t dwInitSeed;						//0x0C
	int32_t nTownId;							//0x10
	D2DrlgEnvironmentStrc* pEnvironment;	//0x14
	ACTCALLBACKFN pfnActCallBack;			//0x18
	BOOL bClient;							//0x1C
	BOOL unk0x20;							//0x20
	BOOL bUpdateEx;							//0x24
	BOOL bUpdate;							//0x28
	D2DrlgTileDataStrc pTileData;			//0x2C
	void* pMemPool;							//0x5C
};

struct D2DrlgAnimTileGridStrc
{
	D2DrlgTileDataStrc** ppMapTileData;		//0x00
	int32_t nFrames;							//0x04
	int32_t nCurrentFrame;						//0x08
	int32_t nAnimationSpeed;					//0x0C
	D2DrlgAnimTileGridStrc* pNext;			//0x10
};

struct D2DrlgBuildStrc
{
	int32_t nPreset;							//0x00
	int32_t nDivisor;							//0x04
	int32_t nRand;								//0x08
	D2DrlgBuildStrc* pNext;					//0x0C
};

struct D2DrlgDeleteStrc
{
	int32_t nUnitType;							//0x00
	int32_t nUnitGUID;							//0x04
	D2DrlgDeleteStrc* pNext;				//0x08
};

struct D2DrlgFileStrc
{
	int32_t unk0x00;							//0x00
	void* pDS1File;								//0x04
	int32_t unk0x08;							//0x08
	int32_t nWidth;								//0x0C
	int32_t nHeight;							//0x10
	int32_t nWalls;								//0x14
	int32_t nFloors;							//0x18
	void* pOrientationLayer[4];					//0x1C
	void* pWallLayer[4];						//0x2C
	void* pFloorLayer[2];						//0x3C
	void* pShadowLayer;							//0x44
	void* pSubstGroupTags;						//0x48
	int32_t nSubstGroups;						//0x4C named nClusters in original game
	struct D2DrlgSubstGroupStrc* pSubstGroups;	//0x50
	D2PresetUnitStrc* pPresetUnit;				//0x54
	D2DrlgFileStrc* pNext;						//0x58
};

struct D2DrlgTileInfoStrc
{
	int32_t nPosX;								//0x00
	int32_t nPosY;								//0x04
	int32_t nTileIndex;							//0x08
};

struct D2DrlgLevelStrc
{
	D2DrlgStrc* pDrlg;						//0x00
	int32_t nLevelId;							//0x04
	int32_t nLevelType;							//0x08
	int32_t nDrlgType;							//0x0C
	uint32_t dwFlags;							//0x10
	D2SeedStrc pSeed;						//0x14
	uint32_t dwInitSeed;						//0x1C
	union
	{
		struct
		{
			int32_t nPosX;						//0x20
			int32_t nPosY;						//0x24
			int32_t nWidth;						//0x28
			int32_t nHeight;					//0x2C
		};
		D2DrlgCoordStrc pLevelCoords;		//0x20
	};
	D2RoomExStrc* pFirstRoomEx;				//0x30
	int32_t nRooms;								//0x34
	union
	{
		D2DrlgPresetInfoStrc* pPreset;		//0x38
		D2DrlgOutdoorInfoStrc* pOutdoors;	//0x38
		D2LvlMazeTxt* pMaze;				//0x38

		//void* pLevelData;						//0x38
	};
	D2DrlgMapStrc* pCurrentMap;				//0x3C
	int32_t nCoordLists;						//0x40
	D2DrlgTileInfoStrc pTileInfo[32];		//0x44
	int32_t nTileInfo;							//0x1C4
	int32_t nRoom_Center_Warp_X[9];				//0x1C8
	int32_t nRoom_Center_Warp_Y[9];				//0x1EC
	int32_t nRoomCoords;						//0x210
	int32_t* pJungleDefs;						//0x214
	int32_t nJungleDefs;						//0x218
	D2DrlgBuildStrc* pBuild;				//0x21C
	BOOL bActive;							//0x220
	uint32_t dwInactiveFrames;					//0x224
	int32_t* pPresetMaps;						//0x228
	D2DrlgLevelStrc* pNextLevel;			//0x22C
};

struct D2DrlgLevelLinkDataStrc
{
	D2SeedStrc pSeed;						//0x00
	D2DrlgCoordStrc pLevelCoord[15];		//0x08
	D2DrlgLinkStrc* pLink;					//0xF8
	union
	{
		int32_t nRand[4][15];					//0xFC
		int32_t nRand2[60];						//0xFC
	};
	int32_t nIteration;							//0x1EC
	int32_t nCurrentLevel;						//0x1F0
};

struct D2DrlgLinkStrc
{
	void* pfLinker;							//0x00
	int32_t nLevel;								//0x04
	int32_t nLevelLink;							//0x08
	int32_t nLevelLinkEx;						//0x0C
};

struct D2DrlgLinkerParamsStrc
{
	int32_t nLinkerLevels[3];					//0x00
	int32_t nChance[2];							//0x0C
	int32_t dwFlags;							//0x14
};


struct D2DrlgOrthStrc
{
	union
	{
		D2RoomExStrc* pRoomEx;				//0x00
		D2DrlgLevelStrc* pLevel;			//0x00
	};
	uint8_t nDirection;						//0x04
	uint8_t unk0x05[3];						//0x05
	BOOL bPreset;							//0x08
	BOOL bInit;								//0x0C
	D2DrlgCoordStrc* pBox;					//0x10
	D2DrlgOrthStrc* pNext;					//0x14
};


struct D2DrlgVertexStrc
{
	int32_t nPosX;								//0x00
	int32_t nPosY;								//0x04
	uint8_t nDirection;						//0x08
	uint8_t pad0x09[3];						//0x09
	int32_t dwFlags;							//0x0C
	D2DrlgVertexStrc* pNext;				//0x10
};


struct D2DrlgPresetInfoStrc
{
	D2DrlgMapStrc* pDrlgMap;				//0x00
	int32_t nDirection;							//0x04
};

struct D2DrlgRGBStrc
{
	uint32_t unk0x00[6];						//0x00
	uint8_t nRed;								//0x18
	uint8_t nGreen;							//0x19
	uint8_t nBlue;								//0x1A
};

struct D2DrlgRoomTilesStrc
{
	D2DrlgTileDataStrc* pWallTiles;			//0x00
	int32_t nWalls;								//0x04
	D2DrlgTileDataStrc* pFloorTiles;		//0x08
	int32_t nFloors;							//0x0C
	D2DrlgTileDataStrc* pRoofTiles;			//0x10
	int32_t nRoofs;								//0x14
};

struct D2DrlgTileGridStrc
{
	D2DrlgTileLinkStrc* pMapLinks;			//0x00
	D2DrlgAnimTileGridStrc* pAnimTiles;		//0x04
	int32_t nWalls;								//0x08
	int32_t nFloors;							//0x0C
	int32_t nShadows;							//0x10
	D2DrlgRoomTilesStrc pTiles;				//0x14
};

struct D2DrlgTileLinkStrc
{
	BOOL bFloor;							//0x00
	D2DrlgTileDataStrc* pMapTile;			//0x04
	D2DrlgTileLinkStrc* pNext;				//0x08
};

struct D2DrlgUnitsStrc
{
	uint32_t unk0x00[9];						//0x00
	BOOL bDelete;							//0x24
	BOOL bUpdate;							//0x28
	uint32_t unk0x2C[12];						//0x2C
	void* pMemPool;							//0x5C
};

struct D2DrlgWarpStrc
{
	int32_t nLevel;								//0x00
	int32_t nVis[8];							//0x04
	int32_t nWarp[8];							//0x24
	D2DrlgWarpStrc* pNext;					//0x44
};

#pragma pack()