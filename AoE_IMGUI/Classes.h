#pragma once
// Generated using ReClass 2016
#include <cstdint>



enum EnumUnitDataClass
{
	InvalidClass = -1,
	Archer = 0,
	Artifact = 1,
	TradeBoat = 2,
	Building = 3,
	Civilian = 4,
	OceanFish = 5,
	Infantry = 6,
	BerryBush = 7,
	StoneMine = 8,
	PreyAnimal = 9,
	PredatorAnimal = 10,
	Miscellaneous = 11,
	Cavalry = 12,
	SiegeWeapon = 13,
	Terrain = 14,
	Tree = 15,
	TreeStump = 16,
	Healer = 17,
	Monk = 18,
	TradeCart = 19,
	TransportBoat = 20,
	FishingBoat = 21,
	Warship = 22,
	Conquistador = 23,
	WarElephant = 24,
	Hero = 25,
	ElephantArcher = 26,
	Wall = 27,
	Phalanx = 28,
	DomesticAnimal = 29,
	Flag = 30,
	DeepSeaFish = 31,
	GoldMine = 32,
	ShoreFish = 33,
	Cliff = 34,
	Petard = 35,
	CavalryArcher = 36,
	Doppelganger = 37,
	Bird = 38,
	Gate = 39,
	SalvagePile = 40,
	ResourcePile = 41,
	Relic = 42,
	MonkWithRelic = 43,
	HandCannoneer = 44,
	TwoHandedSwordsman = 45,
	Pikeman = 46,
	Scout = 47,
	OreMine = 48,
	Farm = 49,
	Spearman = 50,
	PackedUnit = 51,
	Tower = 52,
	BoardingBoat = 53,
	UnpackedSiegeUnit = 54,
	Ballista = 55,
	Raider = 56,
	CavalryRaider = 57,
	LIvestock = 58,
	King = 59,
	MiscBuilding = 60,
	ControlledAnimal = 61
};

struct Vector4
{
	float x;
	float y;
	float z;
	float w;

	Vector4(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
};

struct Vector3
{
	float x;
	float y;
	float z;

	Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

struct Vector2
{
	float x;
	float y;

	Vector2()
	{
		x = 0;
		y = 0;
	}

	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};


// Created with ReClass.NET 1.2 by KN4CK3R

class Ressources
{
public:
	float food; //0x0000
	float wood; //0x0004
	float stone; //0x0008
	float gold; //0x000C
	float popSpaceLeft; //0x0010
	char pad_0014[4]; //0x0014
	float age; //0x0018
	char pad_001C[16]; //0x001C
	float CurrentPop; //0x002C
	char pad_0030[28]; //0x0030
	float unitProduced; //0x004C
	char pad_0050[4]; //0x0050
	float techUpgradeCount; //0x0054
	float percentExplored; //0x0058
	char pad_005C[36]; //0x005C
	float gameMaxPop; //0x0080
	char pad_0084[12]; //0x0084
	float farmFoodAmount; //0x0090
	float villagerCount; //0x0094
	char pad_0098[8]; //0x0098
	float infantryCount; //0x00A0
	char pad_00A4[24]; //0x00A4
	float goldRate; //0x00BC
	char pad_00C0[124]; //0x00C0
	float stoneRate; //0x013C
	float unitsQueueCount; //0x0140
	float builingProducingCount; //0x0144
	char pad_0148[24]; //0x0148
	float fishTrapAmount; //0x0160
	char pad_0164[400]; //0x0164
	float chopRate; //0x02F4
	float foodRate; //0x02F8
	float relicGoldRate; //0x02FC
	char pad_0300[12]; //0x0300
	float construcRateMaybe; //0x030C
	char pad_0310[48]; //0x0310
}; //Size: 0x0340

class Main
{
public:
	class GameData *GameData; //0x0000
}; //Size: 0x0004

class Player
{
public:
	char pad_0000[16]; //0x0000
	int32_t PriceCount; //0x0010
	class PriceTable *priceTablePtr; //0x0014
	class ObjectManager *objectManager; //0x0018
	char pad_001C[8]; //0x001C
	class VictoryConditions *victoryConditions; //0x0024
	char pad_0028[20]; //0x0028
	class Ressources *Ressources; //0x003C
	char pad_0040[60]; //0x0040
	int32_t Diplo0; //0x007C
	int32_t Diplo1; //0x0080
	int32_t Diplo2; //0x0084
	int32_t Diplo3; //0x0088
	int32_t Diplo4; //0x008C
	int32_t Diplo5; //0x0090
	int32_t Diplo6; //0x0094
	int32_t Diplo7; //0x0098
	int32_t Diplo8; //0x009C
	char pad_00A0[92]; //0x00A0
	class Color *colorPtr; //0x00FC
	char pad_0100[16]; //0x0100
	float camX; //0x0110
	float camY; //0x0114
	char pad_0118[68]; //0x0118
	class Unit *LastSelectedUnitPtr; //0x015C
	class Unit *SelectedUnitsArray[60]; //0x0160
	char pad_0250[4]; //0x0250
	int32_t SelectedUnitsCount; //0x0254
	char pad_0258[232]; //0x0258
	int32_t WrongSelectedUnitsCount; //0x0340
	char pad_0344[6028]; //0x0344
	class PlayerName *pName; //0x1AD0
	char pad_1AD4[12]; //0x1AD4
	class Civilization *N00000C58; //0x1AE0
	char pad_1AE4[1588]; //0x1AE4
}; //Size: 0x2118

class GameData
{
public:
	char pad_0000[104]; //0x0000
	int32_t gameTime; //0x0068
	char pad_006C[24]; //0x006C
	class Map *pMap; //0x0084
	char pad_0088[80]; //0x0088
	Vector3 unkCam; //0x00D8
	float speedMaybe; //0x00E4
	char pad_00E8[156]; //0x00E8
	class PlayerArray *pPlayerArray; //0x0184
}; //Size: 0x0188

class PlayerData
{
public:
	class Player *player; //0x0000
	int32_t unk; //0x0004
}; //Size: 0x0008

class PlayerArray
{
public:
	char pad_0000[8]; //0x0000
	class PlayerData playerData[8]; //0x0008
	char pad_0048[44]; //0x0048
}; //Size: 0x0074

class VictoryConditions
{
public:
	char pad_0000[28]; //0x0000
	int32_t Points; //0x001C
	char pad_0020[52]; //0x0020
}; //Size: 0x0054

class ObjectManager
{
public:
	char pad_0000[4]; //0x0000
	class Unit **untis; //0x0004
	int32_t iObjectCount; //0x0008
	char pad_000C[4]; //0x000C
}; //Size: 0x0010

class Unit
{
public:
	char pad_0000[8]; //0x0000
	int32_t iNetworkID; //0x0008
	class UnitData *pUnitData; //0x000C
	void *pOwner; //0x0010
	void *currentGraphicPtr; //0x0014
	void *currentGraphic2Ptr; //0x0018
	char pad_001C[24]; //0x001C
	float fHealth; //0x0034
	int16_t unk_38; //0x0038
	int16_t bIsSelected; //0x003A
	Vector3 vPosReadOnly; //0x003C
	float RessourcesCarryingCount; //0x0048
	int32_t iStatus; //0x004C
	char pad_0050[50]; //0x0050
	int16_t deadMaybe; //0x0082
	int32_t issuedOrder; //0x0084
	int32_t moving; //0x0088
	char pad_008C[4]; //0x008C
	double totalMileage; //0x0090
	char pad_0098[4]; //0x0098
	float strangeX; //0x009C
	float strangeY; //0x00A0
	float strangeZ; //0x00A4
	float vectorX; //0x00A8
	float vectorY; //0x00AC
	float vectorZ; //0x00B0
	float selectionX; //0x00B4
	float selectionY; //0x00B8
	float selectionZ; //0x00BC
	float velocity; //0x00C0
	char pad_00C4[20]; //0x00C4
	uint8_t rotation1; //0x00D8
	uint8_t rotation2; //0x00D9
	uint8_t rotation3; //0x00DA
	uint8_t rotation4; //0x00DB
	char pad_00DC[28]; //0x00DC
	class RallyArray *pRallyArray; //0x00F8
	int32_t RallyCount; //0x00FC
	char pad_0100[4]; //0x0100
	Vector3 vPos; //0x0104
	float Rotation; //0x0110
	char pad_0114[32]; //0x0114
	int32_t mileage; //0x0134
	char pad_0138[24]; //0x0138
	class TargetPtr *pTarget; //0x0150
	char pad_0154[1]; //0x0154
	int8_t commandsReceivedCount; //0x0155
	char pad_0156[2]; //0x0156
	int32_t AssignatedKey; //0x0158
	char pad_015C[52]; //0x015C
	float reloadCooldown; //0x0190
	char pad_0194[56]; //0x0194
	float projectilesCount; //0x01CC
	char pad_01D0[76]; //0x01D0
	int16_t iQueuesize; //0x021C
	char pad_021E[4]; //0x021E
}; //Size: 0x0222

class UnitData
{
public:
	char pad_0000[4]; //0x0000
	int32_t Type; //0x0004
	int32_t languageFileName; //0x0008
	int32_t languageFileCreation; //0x000C
	int16_t ID; //0x0010
	int16_t Copy_ID; //0x0012
	int16_t Base_ID; //0x0014
	int16_t Class; //0x0016
	void *standingGraphicPtr; //0x0018
	char pad_001C[4]; //0x001C
	void *dyingGraphicPtr; //0x0020
	char pad_0024[6]; //0x0024
	int16_t MaxHP; //0x002A
	float LOS; //0x002C
	int16_t garisonCapacity; //0x0030
	char pad_0032[2]; //0x0032
	float collisionX; //0x0034
	float collisionY; //0x0038
	float collisionZ; //0x003C
	void *soundPtr; //0x0040
	void *soundPtr2; //0x0044
	char pad_0048[8]; //0x0048
	int16_t DeadUnitTypeID; //0x0050
	int16_t sortNumber; //0x0052
	int16_t icon; //0x0054
	int16_t hideInEditor; //0x0056
	char pad_0058[2]; //0x0058
	int16_t isAvailableForTraining; //0x005A
	char pad_005C[8]; //0x005C
	float clearanceSizeX; //0x0064
	float clearanceSizeY; //0x0068
	int8_t hillMode; //0x006C
	char pad_006D[1]; //0x006D
	int16_t validTerrain; //0x006E
	int16_t projectilesMaybe; //0x0070
	int16_t ressourceStorageType1; //0x0072
	int16_t ressourceStorageType2; //0x0074
	int16_t ressourceStorageType3; //0x0076
	float ressourceStorageAmount1; //0x0078
	float ressourceStorageAmount2; //0x007C
	float ressourceStorageAmount3; //0x0080
	int32_t ressourceCapacity; //0x0084
	float ressourceDecay; //0x0088
	float attributeModeMaybe; //0x008C
	uint8_t ressourceStorageMode1; //0x0090
	uint8_t ressourceStorageMode2; //0x0091
	uint8_t ressourceStorageMode3; //0x0092
	uint8_t blastDefenceLevel; //0x0093
	uint8_t combatLevel; //0x0094
	uint8_t interactionMode; //0x0095
	uint8_t minimapMode; //0x0096
	uint8_t interfaceKind; //0x0097
	uint8_t minimapColor; //0x0098
	uint8_t atkReactionObsolete; //0x0099
	char pad_009A[1]; //0x009A
	uint8_t N00000EF4; //0x009B
	void *dmgGraphicForBuildingPtr; //0x009C
	uint8_t occlusionMode; //0x00A0
	uint8_t obstructionType; //0x00A1
	uint8_t blockageClass; //0x00A2
	char pad_00A3[1]; //0x00A3
	int16_t unitAttributes; //0x00A4
	char pad_00A6[6]; //0x00A6
	int32_t langFileHelp; //0x00AC
	char pad_00B0[12]; //0x00B0
	int32_t langFileHotkeyText; //0x00BC
	int32_t hotkey; //0x00C0
	int16_t projectilesMaybe2; //0x00C4
	char pad_00C6[2]; //0x00C6
	uint8_t selectionEffect; //0x00C8
	uint8_t editorSelectColor; //0x00C9
	char pad_00CA[2]; //0x00CA
	float selectionOutlineX; //0x00CC
	float selectionOutlineY; //0x00D0
	float selectionOutlineZ; //0x00D4
	char *name; //0x00D8
	int16_t unkInt16; //0x00DC
	char pad_00DE[6]; //0x00DE
	float speed; //0x00E4
	void *walkingGraphicPtr; //0x00E8
	void *runningGraphicPtr; //0x00EC
	float rotationSpeed; //0x00F0
	char pad_00F4[2]; //0x00F4
	int16_t trailingUnit; //0x00F6
	int16_t trailMode; //0x00F8
	char pad_00FA[2]; //0x00FA
	float trailDensity; //0x00FC
	char pad_0100[8]; //0x0100
	float turnRadiusSpeed; //0x0108
	float maxYPSMoving; //0x010C
	float YawRoundTime; //0x0110
	float maxYPSStationary; //0x0114
	void *taskListPtr; //0x0118
	int16_t defaultTask; //0x011C
	char pad_011E[2]; //0x011E
	float searchRadius; //0x0120
	float workRate; //0x0124
	int16_t dropSite1; //0x0128
	int16_t dropSite2; //0x012A
	uint8_t taskSwapGroup; //0x012C
	char pad_012D[3]; //0x012D
	void *sounds3Ptr; //0x0130
	void *sounds4Ptr; //0x0134
	char pad_0138[4]; //0x0138
	void *atkGraphicPtr; //0x013C
	int16_t baseArmor; //0x0140
	int16_t numberOfArmorType; //0x0142
	void *armorsPtr; //0x0144
	int32_t numberOfAtkType; //0x0148
	void *atkPtr; //0x014C
	int16_t terrainDefenceBonus; //0x0150
	char pad_0152[2]; //0x0152
	float range; //0x0154
	float blastRadius; //0x0158
	float blastAtkLevel; //0x015C
	float reloadTime; //0x0160
	int16_t projectileUnit; //0x0164
	int16_t accuracyPercent; //0x0166
	char pad_0168[2]; //0x0168
	int16_t atkDelayFrame; //0x016A
	float graphicDisplacementX; //0x016C
	float graphicDisplacementY; //0x0170
	float graphicDisplacementZ; //0x0174
	float minimumRange; //0x0178
	int16_t displayedMeleeArmor; //0x017C
	int16_t displayedMeleeAtk; //0x017E
	float displayedRange; //0x0180
	float displayedReloadTime; //0x0184
	float atkDispersion; //0x0188
	int16_t costType1; //0x018C
	int16_t costAmount1; //0x018E
	int16_t costPaid1; //0x0190
	int16_t costType2; //0x0192
	int16_t costAmount2; //0x0194
	int16_t costPaid2; //0x0196
	int16_t costType3; //0x0198
	int16_t costAmount3; //0x019A
	int16_t costPaid3; //0x019C
	int16_t trainTime; //0x019E
	int16_t trainLocation; //0x01A0
	int16_t trainButton; //0x01A2
	int16_t displayedPierceArmor; //0x01A4
	char pad_01A6[10]; //0x01A6
	uint8_t creatableTypeObsolete; //0x01B0
	char pad_01B1[3]; //0x01B1
	float totalProjectiles; //0x01B4
	uint8_t maxTotalProjectiles; //0x01B8
	char pad_01B9[3]; //0x01B9
	float projectileSpawnWidth; //0x01BC
	float projectileSpawnHeight; //0x01C0
	float projectileSpawnRandomness; //0x01C4
	int32_t secondaryProjectileUnitId; //0x01C8
	int32_t specialGraphic; //0x01CC
	uint8_t N00000458; //0x01D0
	uint8_t heroMode; //0x01D1
	uint8_t projectiles4; //0x01D2
	char pad_01D3[1]; //0x01D3
	void *garrisonGraphicPtr; //0x01D4
	void *sounds5Ptr; //0x01D8
	void *constructionGraphicPtr; //0x01DC
	void *snowGraphicPtr; //0x01E0
	uint8_t adjacentMode; //0x01E4
	char pad_01E5[3]; //0x01E5
}; //Size: 0x01E8

class String
{
public:
	char pad_0000[64]; //0x0000
}; //Size: 0x0040

class PriceTablePtr
{
public:
	char pad_0000[64]; //0x0000
}; //Size: 0x0040

class BaseGameScreen
{
public:
	class GameScreen *gameScreenPtr; //0x0000
	char pad_0004[1332]; //0x0004
}; //Size: 0x0538

class GameScreen
{
public:
	char pad_0000[44]; //0x0000
	int32_t posMouseX; //0x002C
	int32_t posMouseY; //0x0030
	char pad_0034[68]; //0x0034
	int32_t ScreenResX1; //0x0078
	int32_t ScreenResX2; //0x007C
	int32_t ScreenResY1; //0x0080
	int32_t ScreenResY2; //0x0084
	char pad_0088[56]; //0x0088
	int32_t ScreenResX3; //0x00C0
	int32_t ScreenResY3; //0x00C4
	char pad_00C8[48]; //0x00C8
	class MainView *mainViewPtr; //0x00F8
	char pad_00FC[384]; //0x00FC
}; //Size: 0x027C

class MainView
{
public:
	char pad_0000[420]; //0x0000
	Vector3 PosScreen; //0x01A4
	char pad_01B0[92]; //0x01B0
}; //Size: 0x020C

class Map
{
public:
	char pad_0000[8]; //0x0000
	int32_t SizeX; //0x0008
	int32_t SizeY; //0x000C
	char pad_0010[244]; //0x0010
}; //Size: 0x0104

class PriceTable
{
public:
	char pad_0000[64]; //0x0000
}; //Size: 0x0040

class PlayerName
{
public:
	char pad_0000[68]; //0x0000
}; //Size: 0x0044

class RallyPoint
{
public:
	Vector3 RallyPos; //0x0000
}; //Size: 0x000C

class RallyArray
{
public:
	class RallyPoint N00000E19[8]; //0x0000
}; //Size: 0x0060

class N00000E17
{
public:
	char pad_0000[4]; //0x0000
}; //Size: 0x0004

class N00000E61
{
public:
	char pad_0000[4]; //0x0000
}; //Size: 0x0004

class N00000ECA
{
public:
	char pad_0000[4]; //0x0000
}; //Size: 0x0004

class TargetPtr
{
public:
	char pad_0000[8]; //0x0000
	class Target *pTarget; //0x0008
}; //Size: 0x000C

class Target
{
public:
	class TargetData *pTargetData; //0x0000
}; //Size: 0x0004

class TargetData
{
public:
	char pad_0000[8]; //0x0000
	class Unit *pUnit; //0x0008
	char pad_000C[4]; //0x000C
	class Unit *pTargetUnit; //0x0010
	char pad_0014[4]; //0x0014
	int32_t TargetId; //0x0018
	char pad_001C[4]; //0x001C
	Vector2 Destination; //0x0020
	char pad_0028[28]; //0x0028
}; //Size: 0x0044

class N0000110E
{
public:
	char pad_0000[4]; //0x0000
}; //Size: 0x0004

class N00001156
{
public:
	char pad_0000[4]; //0x0000
}; //Size: 0x0004

class Color
{
public:
	char pad_0000[8]; //0x0000
	int32_t playerColor; //0x0008
}; //Size: 0x000C

class Civilization
{
public:
	char pad_0000[4]; //0x0000
	char civName[8]; //0x0004
}; //Size: 0x000C