#pragma once

enum D2C_Skills
{
	SKILL_ATTACK = 0,
	SKILL_KICK,
	SKILL_THROW,
	SKILL_UNSUMMON,
	SKILL_LEFTHANDTHROW,
	SKILL_LEFTHANDSWING,
	SKILL_MAGICARROW,
	SKILL_FIREARROW,
	SKILL_INNERSIGHT,
	SKILL_CRITICALSTRIKE,
	SKILL_JAB,
	SKILL_COLDARROW,
	SKILL_MULTIPLESHOT,
	SKILL_DODGE,
	SKILL_POWERSTRIKE,
	SKILL_POISONJAVELIN,
	SKILL_EXPLODINGARROW,
	SKILL_SLOWMISSILES,
	SKILL_AVOID,
	SKILL_IMPALE,
	SKILL_LIGHTNINGBOLT,
	SKILL_ICEARROW,
	SKILL_GUIDEDARROW,
	SKILL_PENETRATE,
	SKILL_CHARGEDSTRIKE,
	SKILL_PLAGUEJAVELIN,
	SKILL_STRAFE,
	SKILL_IMMOLATIONARROW,
	SKILL_DOPPLEZON,
	SKILL_EVADE,
	SKILL_FEND,
	SKILL_FREEZINGARROW,
	SKILL_VALKYRIE,
	SKILL_PIERCE,
	SKILL_LIGHTNINGSTRIKE,
	SKILL_LIGHTNINGFURY,
	SKILL_FIREBOLT,
	SKILL_WARMTH,
	SKILL_CHARGEDBOLT,
	SKILL_ICEBOLT,
	SKILL_FROZENARMOR,
	SKILL_INFERNO,
	SKILL_STATICFIELD,
	SKILL_TELEKINESIS,
	SKILL_FROSTNOVA,
	SKILL_ICEBLAST,
	SKILL_BLAZE,
	SKILL_FIREBALL,
	SKILL_NOVA,
	SKILL_LIGHTNING,
	SKILL_SHIVERARMOR,
	SKILL_FIREWALL,
	SKILL_ENCHANT,
	SKILL_CHAINLIGHTNING,
	SKILL_TELEPORT,
	SKILL_GLACIALSPIKE,
	SKILL_METEOR,
	SKILL_THUNDERSTORM,
	SKILL_ENERGYSHIELD,
	SKILL_BLIZZARD,
	SKILL_CHILLINGARMOR,
	SKILL_FIREMASTERY,
	SKILL_HYDRA,
	SKILL_LIGHTNINGMASTERY,
	SKILL_FROZENORB,
	SKILL_COLDMASTERY,
	SKILL_AMPLIFYDAMAGE,
	SKILL_TEETH,
	SKILL_BONEARMOR,
	SKILL_SKELETONMASTERY,
	SKILL_RAISESKELETON,
	SKILL_DIMVISION,
	SKILL_WEAKEN,
	SKILL_POISONDAGGER,
	SKILL_CORPSEEXPLOSION,
	SKILL_CLAYGOLEM,
	SKILL_IRONMAIDEN,
	SKILL_TERROR,
	SKILL_BONEWALL,
	SKILL_GOLEMMASTERY,
	SKILL_RAISESKELETALMAGE,
	SKILL_CONFUSE,
	SKILL_LIFETAP,
	SKILL_POISONEXPLOSION,
	SKILL_BONESPEAR,
	SKILL_BLOODGOLEM,
	SKILL_ATTRACT,
	SKILL_DECREPIFY,
	SKILL_BONEPRISON,
	SKILL_SUMMONRESIST,
	SKILL_IRONGOLEM,
	SKILL_LOWERRESIST,
	SKILL_POISONNOVA,
	SKILL_BONESPIRIT,
	SKILL_FIREGOLEM,
	SKILL_REVIVE,
	SKILL_SACRIFICE,
	SKILL_SMITE,
	SKILL_MIGHT,
	SKILL_PRAYER,
	SKILL_RESISTFIRE,
	SKILL_HOLYBOLT,
	SKILL_HOLYFIRE,
	SKILL_THORNS,
	SKILL_DEFIANCE,
	SKILL_RESISTCOLD,
	SKILL_ZEAL,
	SKILL_CHARGE,
	SKILL_BLESSEDAIM,
	SKILL_CLEANSING,
	SKILL_RESISTLIGHTNING,
	SKILL_VENGEANCE,
	SKILL_BLESSEDHAMMER,
	SKILL_CONCENTRATION,
	SKILL_HOLYFREEZE,
	SKILL_VIGOR,
	SKILL_CONVERSION,
	SKILL_HOLYSHIELD,
	SKILL_HOLYSHOCK,
	SKILL_SANCTUARY,
	SKILL_MEDITATION,
	SKILL_FISTOFTHEHEAVENS,
	SKILL_FANATICISM,
	SKILL_CONVICTION,
	SKILL_REDEMPTION,
	SKILL_SALVATION,
	SKILL_BASH,
	SKILL_SWORDMASTERY,
	SKILL_AXEMASTERY,
	SKILL_MACEMASTERY,
	SKILL_HOWL,
	SKILL_FINDPOTION,
	SKILL_LEAP,
	SKILL_DOUBLESWING,
	SKILL_POLEARMMASTERY,
	SKILL_THROWINGMASTERY,
	SKILL_SPEARMASTERY,
	SKILL_TAUNT,
	SKILL_SHOUT,
	SKILL_STUN,
	SKILL_DOUBLETHROW,
	SKILL_INCREASEDSTAMINA,
	SKILL_FINDITEM,
	SKILL_LEAPATTACK,
	SKILL_CONCENTRATE,
	SKILL_IRONSKIN,
	SKILL_BATTLECRY,
	SKILL_FRENZY,
	SKILL_INCREASEDSPEED,
	SKILL_BATTLEORDERS,
	SKILL_GRIMWARD,
	SKILL_WHIRLWIND,
	SKILL_BERSERK,
	SKILL_NATURALRESISTANCE,
	SKILL_WARCRY,
	SKILL_BATTLECOMMAND,
	SKILL_FIREHIT,
	SKILL_UNHOLYBOLT,
	SKILL_SKELETONRAISE,
	SKILL_MAGGOTEGG,
	SKILL_SHAMANFIRE,
	SKILL_MAGOTTUP,
	SKILL_MAGOTTDOWN,
	SKILL_MAGOTTLAY,
	SKILL_ANDRIALSPRAY,
	SKILL_JUMP,
	SKILL_SWARMMOVE,
	SKILL_NEST,
	SKILL_QUICKSTRIKE,
	SKILL_VAMPIREFIREBALL,
	SKILL_VAMPIREFIREWALL,
	SKILL_VAMPIREMETEOR,
	SKILL_GARGOYLETRAP,
	SKILL_SPIDERLAY,
	SKILL_VAMPIREHEAL,
	SKILL_VAMPIRERAISE,
	SKILL_SUBMERGE,
	SKILL_FETISHAURA,
	SKILL_FETISHINFERNO,
	SKILL_ZAKARUMHEAL,
	SKILL_EMERGE,
	SKILL_RESURRECT,
	SKILL_BESTOW,
	SKILL_MISSILESKILL1,
	SKILL_MONTELEPORT,
	SKILL_PRIMELIGHTNING,
	SKILL_PRIMEBOLT,
	SKILL_PRIMEBLAZE,
	SKILL_PRIMEFIREWALL,
	SKILL_PRIMESPIKE,
	SKILL_PRIMEICENOVA,
	SKILL_PRIMEPOISONBALL,
	SKILL_PRIMEPOISONNOVA,
	SKILL_DIABLIGHT,
	SKILL_DIABCOLD,
	SKILL_DIABFIRE,
	SKILL_FINGERMAGESPIDER,
	SKILL_DIABWALL,
	SKILL_DIABRUN,
	SKILL_DIABPRISON,
	SKILL_POISONBALLTRAP,
	SKILL_ANDYPOISONBOLT,
	SKILL_HIREABLEMISSILE,
	SKILL_DESERTTURRET,
	SKILL_ARCANETOWER,
	SKILL_MONBLIZZARD,
	SKILL_MOSQUITO,
	SKILL_CURSEDBALLTRAPRIGHT,
	SKILL_CURSEDBALLTRAPLEFT,
	SKILL_MONFROZENARMOR,
	SKILL_MONBONEARMOR,
	SKILL_MONBONESPIRIT,
	SKILL_MONCURSECAST,
	SKILL_HELLMETEOR,
	SKILL_REGURGITATOREAT,
	SKILL_MONFRENZY,
	SKILL_QUEENDEATH,
	SKILL_SCROLLOFIDENTIFY,
	SKILL_BOOKOFIDENTIFY,
	SKILL_SCROLLOFTOWNPORTAL,
	SKILL_BOOKOFTOWNPORTAL,
	SKILL_RAVEN,
	SKILL_PLAGUEPOPPY,
	SKILL_WEARWOLF,
	SKILL_SHAPESHIFTING,
	SKILL_FIRESTORM,
	SKILL_OAKSAGE,
	SKILL_SUMMONSPIRITWOLF,
	SKILL_WEARBEAR,
	SKILL_MOLTENBOULDER,
	SKILL_ARCTICBLAST,
	SKILL_CYCLEOFLIFE,
	SKILL_FERALRAGE,
	SKILL_MAUL,
	SKILL_ERUPTION,
	SKILL_CYCLONEARMOR,
	SKILL_HEARTOFWOLVERINE,
	SKILL_SUMMONFENRIS,
	SKILL_RABIES,
	SKILL_FIRECLAWS,
	SKILL_TWISTER,
	SKILL_VINES,
	SKILL_HUNGER,
	SKILL_SHOCKWAVE,
	SKILL_VOLCANO,
	SKILL_TORNADO,
	SKILL_SPIRITOFBARBS,
	SKILL_SUMMONGRIZZLY,
	SKILL_FURY,
	SKILL_ARMAGEDDON,
	SKILL_HURRICANE,
	SKILL_FIRETRAUMA,
	SKILL_CLAWMASTERY,
	SKILL_PSYCHICHAMMER,
	SKILL_TIGERSTRIKE,
	SKILL_DRAGONTALON,
	SKILL_SHOCKFIELD,
	SKILL_BLADESENTINEL,
	SKILL_QUICKNESS,
	SKILL_FISTSOFFIRE,
	SKILL_DRAGONCLAW,
	SKILL_CHARGEDBOLTSENTRY,
	SKILL_WAKEOFFIRESENTRY,
	SKILL_WEAPONBLOCK,
	SKILL_CLOAKOFSHADOWS,
	SKILL_COBRASTRIKE,
	SKILL_BLADEFURY,
	SKILL_FADE,
	SKILL_SHADOWWARRIOR,
	SKILL_CLAWSOFTHUNDER,
	SKILL_DRAGONTAIL,
	SKILL_LIGHTNINGSENTRY,
	SKILL_INFERNOSENTRY,
	SKILL_MINDBLAST,
	SKILL_BLADESOFICE,
	SKILL_DRAGONFLIGHT,
	SKILL_DEATHSENTRY,
	SKILL_BLADESHIELD,
	SKILL_VENOM,
	SKILL_SHADOWMASTER,
	SKILL_ROYALSTRIKE,
	SKILL_WAKEOFDESTRUCTIONSENTRY,
	SKILL_IMPINFERNO,
	SKILL_IMPFIREBALL,
	SKILL_BAALTAUNT,
	SKILL_BAALCORPSEEXPLODE,
	SKILL_BAALMONSTERSPAWN,
	SKILL_CATAPULTCHARGEDBALL,
	SKILL_CATAPULTSPIKEBALL,
	SKILL_SUCKBLOOD,
	SKILL_CRYHELP,
	SKILL_HEALINGVORTEX,
	SKILL_TELEPORT2,
	SKILL_SELF_RESURRECT,
	SKILL_VINEATTACK,
	SKILL_OVERSEERWHIP,
	SKILL_BARBSAURA,
	SKILL_WOLVERINEAURA,
	SKILL_OAKSAGEAURA,
	SKILL_IMPFIREMISSILE,
	SKILL_IMPREGNATE,
	SKILL_SIEGEBEASTSTOMP,
	SKILL_MINIONSPAWNER,
	SKILL_CATAPULTBLIZZARD,
	SKILL_CATAPULTPLAGUE,
	SKILL_CATAPULTMETEOR,
	SKILL_BOLTSENTRY,
	SKILL_CORPSECYCLER,
	SKILL_DEATHMAUL,
	SKILL_DEFENSECURSE,
	SKILL_BLOODMANA,
	SKILL_MONINFERNOSENTRY,
	SKILL_MONDEATHSENTRY,
	SKILL_SENTRYLIGHTNING,
	SKILL_FENRISRAGE,
	SKILL_BAALTENTACLE,
	SKILL_BAALNOVA,
	SKILL_BAALINFERNO,
	SKILL_BAALCOLDMISSILES,
	SKILL_MEGADEMONINFERNO,
	SKILL_EVILHUTSPAWNER,
	SKILL_COUNTESSFIREWALL,
	SKILL_IMPBOLT,
	SKILL_HORRORARCTICBLAST,
	SKILL_DEATHSENTRYLTNG,
	SKILL_VINECYCLER,
	SKILL_BEARSMITE,
	SKILL_RESURRECT2,
	SKILL_BLOODLORDFRENZY,
	SKILL_BAALTELEPORT,
	SKILL_IMPTELEPORT,
	SKILL_BAALCLONETELEPORT,
	SKILL_ZAKARUMLIGHTNING,
	SKILL_VAMPIREMISSILE,
	SKILL_MEPHISTOMISSILE,
	SKILL_DOOMKNIGHTMISSILE,
	SKILL_ROGUEMISSILE,
	SKILL_HYDRAMISSILE,
	SKILL_NECROMAGEMISSILE,
	SKILL_MONBOW,
	SKILL_MONFIREARROW,
	SKILL_MONCOLDARROW,
	SKILL_MONEXPLODINGARROW,
	SKILL_MONFREEZINGARROW,
	SKILL_MONPOWERSTRIKE,
	SKILL_SUCCUBUSBOLT,
	SKILL_MEPHFROSTNOVA,
	SKILL_MONICESPEAR,
	SKILL_SHAMANICE,
	SKILL_DIABLOGEDDON,
	SKILL_DELERIUMCHANGE,
	SKILL_NIHLATHAKCORPSEEXPLOSION,
	SKILL_SERPENTCHARGE,
	SKILL_TRAPNOVA,
	SKILL_UNHOLYBOLTEX,
	SKILL_SHAMANFIREEX,
	SKILL_IMPFIREMISSILEEX,
	SKILL_FIXEDSIEGEBEASTSTOMP,
};
