#pragma once

#define O_SS_TIME_USED 0x28

class SpellSlot
{
public:

	int GetLevel();
	float GetTime();

	float GetTimeUsed();
	float GetCooldown();
};

