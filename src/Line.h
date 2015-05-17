#pragma once
#include <string>
#include "Roll.h"

using std::string;

class Line{

private:
	string const& line_;
	int index_;

public:
	Line(const string& input);
	~Line();

	bool HasRolls();

	Roll NextRoll();
};