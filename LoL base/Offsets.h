#pragma once
#define TARGET_GAMEVERSION "Version 10.5.311.166 [PUBLIC]"


//#define oObjSourceIndex 0x2CC
//#define oObjTargetID 0x318

#define oNetClient 0x34397D0 // 0x3431140 // 				   8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B																	//

#define oChatClientPtr 0x1B944C0 // 0x1B8C12C //  				 8B 0D ? ? ? ? 56 6A 01 FF 
#define oObjManager 0x1B96C7C // 0x1B8E67C // 										 8B 0D ? ? ? ? E8 ? ? ? ? FF 77						//
#define oZoomClass 0x3431784 // 0x3429178 // 												 A3 ? ? ? ? 83 FA 10 72 32							//
#define oGameTime 0x34317D8 // 0x34291C8 // 												 F3 0F 11 05 ? ? ? ? 8B 49							//
#define oGameInfo 0x3432DD8 // 0x342A5B4 // 												 A1 ? ? ? ? 83 78 08 02 0F 94 C0
#define oLocalPlayer 0x34387F4 // 0x34301E4 // 												 A1 ?? ?? ?? ?? 85 C0 74 07 05 ?? ?? ?? ?? EB 02 33 C0 56  //
#define oHudInstance 0x1B96CB4 // 0x1B8E6B4 // 												 8B 0D ? ? ? ? 6A 00 8B 49 34 E8 ? ? ? ? B0         //
#define oRenderer 0x3875330 // 0x344C908 //												     8B 15 ? ? ? ? 83 EC 08 F3
#define oUnderMouseObject 0x3426384 // 0x341DD24 //			NO UPDATE 10.3.2				 8B 0D ? ? ? ? 89 0D 
#define oD3DRenderer 0x345791C // 0x344EF04 //												 A1 ? ? ? ? 33 D2 56 57 8B 7C 24 14					//
#define oGameVersion 0x4E2620 // 0x507180 // 												 8B 44 24 04 BA ? ? ? ? 2B D0						//

// FUNCTIONS
#define oGetSpellSlotPtr 0x3FCCB0 // 10.1 10.2????????????????											 ????? 
#define oCastSpell 0x4993D0 //  0x490E70 // 0x488A90 													    E8 ? ? ? ? 8B 7C 24 10 5D							//
#define oDrawCircle 0x4A8910 // 0x49F6A0 // 0x497030 														E8 ? ? ? ? 83 C4 1C 5F 5E 83 C4 20					//
#define oGetBasicAttack	0x1C9340 // 0x1CBDF0 																53 8B D9 B8 ? ? ? ? 8B 93							//
#define oGetAttackCastDelay 0x2A2E30 // 0x2A0380 															83 EC 0C 53 8B 5C 24 14 8B CB 56 57 8B 03 FF 90	// 
#define oGetAttackDelay 0x2A2F20 // 0x2A0470 																8B 44 24 04 51 F3									//
#define oGetPing 0x326060 // 0x321CA0 																		E8 ? ? ? ? 8B E8 3B 6B								//
#define oGetSpellState 0x48E310 // 0x485D00 															    E8 ? ? ? ? 8B F8 8B CB 89  						//	
#define oIsTargetable 0x1DBBF0 // 0x1DB870 																	56 8B F1 E8 ? ? ? ? 84 C0 74 2E					//
#define oIsAlive 0x1310F0 // 0x19DD50  																		56 8B F1 8B 06 8B 80 ? ? ? ? FF D0 84 C0 74 19		//
#define oIsBaron 0x182B20 // 0x175B50 																		56 E8 ? ? ? ? 68 ? ? ? ? 8B 30						//	
#define oIsTurret 0x1E12A0 // 0x1E0070 																		E8 ? ? ? ? 83 C4 04 84 C0 74 09 5F					//
#define oIsInhib 0x1E0F30 // 0x1DFD00 																		E8 ? ? ? ? 83 C4 04 84 C0 74 38					//
#define oIsHero 0x1E10B0 // 0x1DFE80 						 												E8 ? ? ? ? 83 C4 04 84 C0 75 22 8B 8D				//
#define oIsMinion 0x1E10F0 // 0x1DFEC0 												 						E8 ? ? ? ? 83 C4 04 84 C0 74 4A 8B 45				//
#define oIsDragon 0x1817A0 // 0x174400  																	83 EC 10 A1 ? ? ? ? 33 C4 89 44 24 0C 56 E8		//
#define oIsMissile 0x1E1110 // 0x1DFEE0 											   						E8 ? ? ? ? 83 C4 04 84 C0 74 1C FF					//
#define oIsNexus 0x1E1030 // 0x1DFE00 																		E8 ? ? ? ? 83 C4 04 84 C0 75 05 5F					//
#define oIsNotWall 0x8580D0 // 0x849390 																	E8 ? ? ? ? 33 C9 83 C4 0C 84						//
#define oIsTroy 0x1E01A0 // 0x1DBD40 													
#define oIssueOrder 0x182B60 // 0x175C00 																	81 EC ? ? ? ? 56 57 8B F9 C7						//
#define oPrintChat 0x509370 // 0x4FEEF0 											     
#define oWorldToScreen 0x8D82D0 // 0x8C97F0 																83 EC 10 56 E8 ? ? ? ? 8B 08						//


#define oObjIndex 0x20 //NOT VERIFIED
#define oObjTeam 0x4C // 10.3 no change
#define oObjName 0x6C // 10.3 no change
#define oObjNetworkID 0xCC //NOT VERIFIED
#define oObjPos 0x1D8 //  10.3 no change
#define oObjVisibility 0x450 //NOT VERIFIED
#define oObjHealth 0xF90  // 10.3 no change
#define oObjMaxHealth 0xFA0 // 10.3 no change
#define oObjMana 0x47C //  10.3 no change
#define oObjMaxMana 0x48C //  10.3 no change
#define oObjLethality 0x137C // 10.2 no change
#define oObjBonusAtk 0x13BC // 0x13B8  //10.3 no change
#define oObjBaseAtk 0x143C // 0x1438 // 10.3 no change
#define oObjArmor 0x1464//0x1460 // 10.3 no change
#define oObjBonusArmor 0x1468 // 0x1464 // 10.3 no change
#define oObjMagicRes 0x146C // 0x1468 // 10.3 no change
#define oObjBonusMagicRes 0x1470 // 0x146C // 10.3 no change
#define oObjMoveSpeed 0x1A58 // 0x1A50  // 10.3 no change
#define oObjAtkRange 0x1484 // 0x1480  // 10.3 no change
#define oObjBuffMgr 0x2308 // 0x2300 // 10.3 no change
#define oObjSpellBook 0x2AB8 //0x2AB0  //  10.3 no change
#define oObjChampionName 0x354C // 0x3544 //  10.3 no change
#define oObjLevel 0x4D94 // 0x4D5C //  10.3 no change
#define oObjAP 0x18E0 // 10.01