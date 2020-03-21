#pragma once
#include "CSpellEntry.h"
#include "SpellSlot.h"

class CSpellBook
{
public:
	CSpellEntry* GetActiveSpellEntry();
	SpellSlot* GetSpellSlotById(int id);
};

