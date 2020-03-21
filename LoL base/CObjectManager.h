#pragma once
#include "Utils.h"
#include "CObject.h"
#include <vector>
#include <iostream>

class CObjectManager {
public:
	union {
		DEFINE_MEMBER_0(void *base, 0x0);
		DEFINE_MEMBER_N(CObject** objectArray, 0x0 + 0x14);
		DEFINE_MEMBER_N(int MaxObjects, 0x8 + 0x8);
		DEFINE_MEMBER_N(int ObjectsUsed, 0x8 + 0x8);
		DEFINE_MEMBER_N(int HighestObjectID, 0xC + 0x8);
	};

	std::vector<CObject*> GetMinions(int exceptTeam)
	{
		std::vector<CObject*> result;
		
		if(objectArray)
		{
			for(int i = 0; i < MaxObjects; i++)
			{
				auto unit = (CObject*)(objectArray[i]);
				if(!unit)
				{
					continue;
				}
				//
				//if(strstr(unit->GetName(), "Minion") == 0)
				//{
				//	continue;
				//}
				//
				//if(exceptTeam != unit->GetTeam())
				//{
				//	if(unit->IsMinion() && unit->GetHealth() > 1)
				//	{
				//		result.push_back(static_cast<CObject*>(unit));
				//	}
				//}
				//
			}
		}

		return result;
	}
};
extern CObjectManager* ObjManager;