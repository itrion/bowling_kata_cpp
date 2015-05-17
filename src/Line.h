#pragma once

#include <string>
#include <map>
#include "Roll.h"

using std::string;

class Line {

private:
	string const& line_;
	int index_;
	std::map<char, std::function<Roll(void)>> roll_factory_;

public:
	Line(const string& input);

	~Line();

	bool HasRolls();

	Roll NextRoll();

	int AsInt(const char& rollChar);
};