#pragma once


#include "Roll.h"

class SpareRoll : public Roll {

public:
	SpareRoll(int knocks);

	virtual bool IsSpare() override;

	virtual int Knocks() override;
};

