#pragma once


class Frame {
private:
	int knocks_;
	int bonus_;
public:
	Frame(int knocks);
	Frame(int knocks, int bonus);

	int Knocks();
	int Bonus();
};

