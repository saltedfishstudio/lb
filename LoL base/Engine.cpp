#include "Windows.h"
#include "Engine.h"

void Engine::CastSpellSelf(int slotID)
{
	if (me->IsAlive())
	{
		auto spellbook = reinterpret_cast<DWORD>(me) + oObjSpellBook;
		auto spellslot = me->GetSpellBook()->GetSpellSlotById(slotID);

		if(spellslot->IsReady())
		{
			Functions.CastSpell(spellbook, spellslot, slotID, &me->GetPos(), &me->GetPos(), 0);
		}

	}
}

void Engine::CastSpellPos(int slotID, Vector pos)
{
	auto spellbook = reinterpret_cast<DWORD>(me) + oObjSpellBook;
	auto spellslot = me->GetSpellBook()->GetSpellSlotById(slotID);

	auto targetpos = &pos;

	//if(spellslot->IsReady())
	{
		Functions.CastSpell(spellbook, spellslot, slotID, targetpos, &me->GetPos(), 0x0);
	}
}

void Engine::CastSpellTargetted(int slotID, CObject* obj)
{
	auto spellbook = reinterpret_cast<DWORD>(me) + oObjSpellBook;
	auto spellslot = me->GetSpellBook()->GetSpellSlotById(slotID);

	if(spellslot->IsReady())
	{
		Functions.CastSpell(spellbook, spellslot, slotID, &obj->GetPos(), &me->GetPos(), obj->GetNetworkID());
	}
}


