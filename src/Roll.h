#pragma once

class Roll {
private:
	int knocks_;

public:
	Roll(int knocks);
	virtual ~Roll();
	virtual int Knocks();

	virtual bool IsSpare();
	virtual bool IsStrike();
};

