#pragma once
#define TARGET_GAMEVERSION "Version 10.6.313.2784 [PUBLIC]"

#define oGetAttackDelay 0x2A6850 // 0x2A2F20 // 0x2A0470 // 0x29C000 // 									8B 44 24 04 51 F3									//
#define oGetAttackCastDelay 0x2A6760 // 0x2A2E30 // 0x2A0380												83 EC 0C 53 8B 5C 24 14 8B CB 56 57 8B 03 FF 90	// 
#define oDrawCircle 0x4F1720 // 0x4A8910 // 0x49F6A0 // 0x496CD0 // 0x468940 // 0x43FB20  // 10.03 //		E8 ? ? ? ? 83 C4 1C 8B 7C 24 28 
#define oIsAlive 0x133CB0 // 0x1310F0 // 0x19DD50 // 0x198980 // 0x198980									56 8B F1 8B 06 8B 80 ? ? ? ? FF D0 84 C0 74 19		//
#define oIsInhib 0x1E1E50 // 0x1E0F30 // 0x1DFD00 // 0x1DB8A0 // 0x1DB8A0 // 0x1D9290 // 0x1D7690 //0x1D5750														 E8 ? ? ? ? 83 C4 04 84 C0 74 38					//
#define oIsNexus 0x1E1F50 // 0x1E1030 // 0x1DFE00 // 0x1DB9A0 // 0x1D9390 // 0x1D7790 // 0x1D5850           E8 ? ? ? ? 83 C4 04 84 C0 75 1E 57 

#define oIsTurret 0x1E21C0 // 0x1E12A0 // 0x1E0070 // 0x1DBC10 //											E8 ? ? ? ? 83 C4 04 84 C0 74 09 5F					//
#define oIsMinion 0x1E2010 // 0x1E10F0 // 0x1DFEC0 // 0x1DBA60 // 0x1DBA60//  0x1D9450 // 0x1D7850 //0x1D5910													 	 E8 ? ? ? ? 83 C4 04 84 C0 74 4A 8B 45				//
#define oIsDragon 0x184600 // 0x1817A0 // 0x174400 // 0x1703D0 // 0x1703D0 // 0x16CDC0 // 0x16B610  // 0x169480 													 83 EC 10 A1 ? ? ? ? 33 C4 89 44 24 0C 56 E8		//
#define oIsBaron 0x185980 // 0x182B20 // 0x175B50 // 0x171A70  // 0x16E450 // 0x16CBB0 // 0x16AA10 // 10.03 // 56 E8 ? ? ? ? 68 ? ? ? ? 8B 30 
#define oIsHero 0x1E1FD0 // 0x1E10B0 // 0x1DFE80 // 0x1DBA20 // 0x1DBA20 // 0x1D9410 // 0x1D7810   //0x1D58D0														 E8 ? ? ? ? 83 C4 04 84 C0 75 22 8B 8D				//
#define oIsMissile 0x1E2030 // 0x1E1110 // 0x1DFEE0 // 0x1DBA80 // 0x1DBA80 // 0x1D9470 // 0x1D7870 //0x1D5930												   		 E8 ? ? ? ? 83 C4 04 84 C0 74 1C FF					//
#define oIsTargetable 0x1DCF80 // 0x1DBBF0 // 0x1DB870 // 0x1D60B0 // 0x1D3A60 // 0x1D1DE0 // 0x1CF020 // 10.03 // 56 8B F1 E8 ? ? ? ? 84 C0 74 2E 
#define oIssueOrder 0x1859C0 // 0x182B60 // 0x175C00 // 0x171B20 // 0x171B20 // 0x171B20 // 0x16E500 //0x16CC60 //0x16AAC0 											 81 EC ? ? ? ? 56 57 8B F9 C7						//
#define oGetSpellState 0x4D74F0 // 0x48E310 // 0x485D00 // 0x47D270 // 0x47CF20 // 0x45AE10 // 0x44F6B0// 0x428290													 E8 ? ? ? ? 8B F8 8B CB 89  						//	
#define oCastSpell 0x580050 // 0x4993D0 // 0x490E70 // 0x488A90 // 0x488740 // 0x464E50 // 0x459860 // 0x430C80 // 10.03 // 83 EC 38 56 8B 74 24 40 
#define oGetBasicAttack	0x1CAE30 // 0x1C9340 // 0x1CBDF0 // 0x1C4990 // 0x1C4990 // 0x1C1940 // 0x1BF9D0  // 0x1BCC60												 53 8B D9 B8 ? ? ? ? 8B 93							//
#define oUpdateChargeableSpell 0x433D00 // 0x433E40 // 9.24.1 // E8 ? ? ? ? 8B 43 24 8B 0D ? ? ? ? 
#define oIsNotWall 0x8A1280 // 0x858130// 0x849390 // 0x83B010 // 0x83AC80 //0x804270 // 0x7FB280 //0x7C70F0														 E8 ? ? ? ? 33 C9 83 C4 0C 84						//

#define oChatClientPtr 0x1BE712C // 0x1B944C0 // 0x1B8C12C // 0x1B767A8//0x34085E4 // 0x2788FC8 /// 0x1B2EB70 // 0x1AF7C7C				MAY BE WRONG					 8B 35 ? ? ? ? 52 
#define oLocalPlayer 0x348B45C // 0x34387F4 // 0x34301E4 // 0x341A974 // 0x341A934 // 0x33DE098 // 0x33D2A90 // 0x339BC30												 A1 ?? ?? ?? ?? 85 C0 74 07 05 ?? ?? ?? ?? EB 02 33 C0 56  //
#define oObjManager 0x1BE967C // 0x1B96C7C // 0x1B8E67C // 0x1B78EBC //0x1B78E7C //  0x2788EEC // 0x277D96C // 10.1 10.2????											 8B 0D ? ? ? ? E8 ? ? ? ? FF 77						//
#define oGameTime 0x34841DC // 0x34317D8 // 0x34291C8 // 0x3413734 // 0x34136F4 // 0x33D7014 // 0x33CBA9C// 0x3394BF4													 F3 0F 11 05 ? ? ? ? 8B 49							//
#define oHudInstance 0x1BE96B4 // 0x1B96CB4 // 0x1B8E6B4 // 0x1B78EF4 // 0x1B78EB4 // 0x1B3C858 // 0x1B312D8 // 0x1AFA418												 8B 0D ? ? ? ? 6A 00 8B 49 34 E8 ? ? ? ? B0         //
#define oGameVersion 0x52BF40 // 0x4E2620 // 0x507180 // 0x4FCE90 // 0x4FCB60 //0x4A9970 // 0x49D050 // 0x443184													 8B 44 24 04 BA ? ? ? ? 2B D0						//
#define oRenderer 0x34A8D98 // 0x3875330 // 0x344C908 // 0x3436D38 // 0x3436CF8 // 0x33FA288 //  0x33EE818 // 0x33B70B8											     8B 15 ? ? ? ? 83 EC 08 F3
#define oD3DRenderer 0x34AB384 // 0x345791C // 0x344EF04 // 0x3439244 // 0x3439204 // 0x33FC78C // 0x33F0D1C // 0x33BD5C4 // 10.03 //									 A1 ? ? ? ? 89 54 24 18 
#define oZoomClass 0x3484180 // 0x3431784 // 0x3429178 // 0x3413638 // 0x34135F8 // 0x33D6FC4 // 0x33CBA4C// 0x339496C													 A3 ? ? ? ? 83 FA 10 72 32							//
#define oNetClient 0x348C420 // 0x34397D0 // 0x3431140 // 0x341B89C //0x341B85C  //  0x33DF260 // 0x33D3BC0 // 0x339CB34												 8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B

// WorldToScreenSpace
#define oW2S 0x921DE0 // 0x8D8320 // 0x8C97F0 // 0x8BADF0 // 0x8BAAB0 // 0x8842F0 // 0x87B040 // 0x846F10 // 10.03 //												 83 EC 10 56 E8 ? ? ? ? 8B 08 

#define oUnderMouseObject 0x3478D84 // 0x3426384 // 0x341DD24 // 0x3408568 // 0x3408528 // 0x2788F0C // 0x2DE6ACC // 0x2746ACC			NO UPDATE 10.3.2				 8B 0D ? ? ? ? 89 0D 
#define oGameInfo 0x34857F8 // 0x3432DD8 // 0x342A5B4 // 0x3414D38 // 0x3414CF8 //  0x33D86F8 // 0x33CD130// 0x339A240													 A1 ? ? ? ? 83 78 08 02 0F 94 C0
//
//
////#define oObjSourceIndex 0x2CC
////#define oObjTargetID 0x318
//
//// 10.6
//#define oLocalPlayer 0x348B45C // 0x34301E4 // 												 A1 ?? ?? ?? ?? 85 C0 74 07 05 ?? ?? ?? ?? EB 02 33 C0 56  //
//#define oGameTime 0x34841DC // 0x34317D8 // 0x34291C8 // 									F3 0F 11 05 ? ? ? ? 8B 49							//
//
//// 10.5
//#define oNetClient 0x34397D0 // 0x3431140 // 				   8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B																	//
//#define oChatClientPtr 0x1B944C0 // 0x1B8C12C //  				 8B 0D ? ? ? ? 56 6A 01 FF 
//#define oObjManager 0x1B96C7C // 0x1B8E67C // 										 8B 0D ? ? ? ? E8 ? ? ? ? FF 77						//
//#define oZoomClass 0x3431784 // 0x3429178 // 												 A3 ? ? ? ? 83 FA 10 72 32							//
//#define oGameInfo 0x3432DD8 // 0x342A5B4 // 												 A1 ? ? ? ? 83 78 08 02 0F 94 C0
//#define oHudInstance 0x1B96CB4 // 0x1B8E6B4 // 												 8B 0D ? ? ? ? 6A 00 8B 49 34 E8 ? ? ? ? B0         //
//#define oRenderer 0x3875330 // 0x344C908 //												     8B 15 ? ? ? ? 83 EC 08 F3
//#define oUnderMouseObject 0x3426384 // 0x341DD24 //			NO UPDATE 10.3.2				 8B 0D ? ? ? ? 89 0D 
//#define oD3DRenderer 0x345791C // 0x344EF04 //												 A1 ? ? ? ? 33 D2 56 57 8B 7C 24 14					//
//#define oGameVersion 0x4E2620 // 0x507180 // 												 8B 44 24 04 BA ? ? ? ? 2B D0						//
//
//// FUNCTIONS
//
//// 10.6
//// 0x1131720
//#define oDrawCircle 0x4F1720 //0x4ED793 // 0x1CAE30 // 0x4A8910 // 0x49F6A0 // 0x497030 					E8 ? ? ? ? 83 C4 1C 8B 7C 24 28
//#define oIsAlive 0x133CB0 // 0x1310F0 // 0x19DD50  															56 8B F1 8B 06 8B 80 ? ? ? ? FF D0 84 C0 74 19		//
//
//// 10.5
//#define oGetSpellSlotPtr 0x3FCCB0 // 10.1 10.2????????????????											 ????? 
//#define oCastSpell 0x4993D0 //  0x490E70 // 0x488A90 													    E8 ? ? ? ? 8B 7C 24 10 5D							//
//#define oGetBasicAttack	0x1C9340 // 0x1CBDF0 																53 8B D9 B8 ? ? ? ? 8B 93							//
//#define oGetAttackCastDelay 0x2A2E30 // 0x2A0380 															83 EC 0C 53 8B 5C 24 14 8B CB 56 57 8B 03 FF 90	// 
//#define oGetAttackDelay 0x2A2F20 // 0x2A0470 																8B 44 24 04 51 F3									//
//#define oGetPing 0x326060 // 0x321CA0 																		E8 ? ? ? ? 8B E8 3B 6B								//
//#define oGetSpellState 0x48E310 // 0x485D00 															    E8 ? ? ? ? 8B F8 8B CB 89  						//	
//#define oIsTargetable 0x1DBBF0 // 0x1DB870 																	56 8B F1 E8 ? ? ? ? 84 C0 74 2E					//
//#define oIsBaron 0x182B20 // 0x175B50 																		56 E8 ? ? ? ? 68 ? ? ? ? 8B 30						//	
//#define oIsTurret 0x1E12A0 // 0x1E0070 																		E8 ? ? ? ? 83 C4 04 84 C0 74 09 5F					//
//#define oIsInhib 0x1E0F30 // 0x1DFD00 																		E8 ? ? ? ? 83 C4 04 84 C0 74 38					//
//#define oIsHero 0x1E10B0 // 0x1DFE80 						 												E8 ? ? ? ? 83 C4 04 84 C0 75 22 8B 8D				//
//#define oIsMinion 0x1E10F0 // 0x1DFEC0 												 						E8 ? ? ? ? 83 C4 04 84 C0 74 4A 8B 45				//
//#define oIsDragon 0x1817A0 // 0x174400  																	83 EC 10 A1 ? ? ? ? 33 C4 89 44 24 0C 56 E8		//
//#define oIsMissile 0x1E1110 // 0x1DFEE0 											   						E8 ? ? ? ? 83 C4 04 84 C0 74 1C FF					//
//#define oIsNexus 0x1E1030 // 0x1DFE00 																		E8 ? ? ? ? 83 C4 04 84 C0 75 05 5F					//
//#define oIsNotWall 0x8580D0 // 0x849390 																	E8 ? ? ? ? 33 C9 83 C4 0C 84						//
//#define oIsTroy 0x1E01A0 // 0x1DBD40 													
//#define oIssueOrder 0x182B60 // 0x175C00 																	81 EC ? ? ? ? 56 57 8B F9 C7						//
//#define oPrintChat 0x509370 // 0x4FEEF0 											     
//#define oWorldToScreen 0x8D82D0 // 0x8C97F0 																83 EC 10 56 E8 ? ? ? ? 8B 08						//
//
//

#define oIsTroy 0x1E01A0 // 0x1DBD40

#define oObjIndex 0x20 //NOT VERIFIED
#define oObjTeam 0x4C // 10.3 no change
#define oObjName 0x6C // 10.3 no change
#define oObjNetworkID 0xCC //NOT VERIFIED
#define oObjPos 0x1D8 //  10.3 no change
#define oObjVisibility 0x450 //NOT VERIFIED
#define oObjHealth 0xF88 //0xF90  // 10.3 no change
#define oObjMaxHealth 0xF98 //0xFA0 // 10.3 no change
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
#define oObjAtkRange 0x147C// 0x1484 // 0x1480  // 10.3 no change
#define oObjBuffMgr 0x2308 // 0x2300 // 10.3 no change
#define oObjSpellBook 0x2AB8 //0x2AB0  //  10.3 no change
#define oObjChampionName 0x3570 //0x354C // 0x3544 //  10.3 no change
#define oObjLevel 0x4D94 // 0x4D5C //  10.3 no change
#define oObjAP 0x18E0 // 10.01