#pragma once
#include "CSpellEntry.h"
#include "SpellSlot.h"

class CSpellBook
{
public:
	CSpellEntry* GetActiveSpellEntry();
	SpellSlot* GetSpellSlotById(int id);

	static bool IsSpellReady(int ID);

	enum SpellSlotId : int
	{
		Q = 0,
		W = 1,
		E = 2,
		R = 3,
		Summoner1 = 4,
		Summoner2 = 5,
		Item1 = 6,
		Item2 = 7,
		Item3 = 8,
		Item4 = 9,
		Item5 = 10,
		Item6 = 11,
		Trinket = 12,
		Recall = 13
	};
};