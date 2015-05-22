#pragma once


#include "Roll.h"

class StrikeRoll : public Roll{

public:
	StrikeRoll(int knocks) : Roll(knocks) { }

	virtual bool IsStrike() override;
};

