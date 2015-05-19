#pragma once

#include <string>
#include <vector>
#include <map>
#include "Roll.h"
#include "Frame.h"

using std::string;
using std::vector;
using std::shared_ptr;

class Line {

private:
	int index_;
	string const& line_;
	std::map<char, std::function<Roll(void)>> roll_factory_;

	int AsInt(const char& rollChar);
public:

	Line(const string& input);

	~Line();

	bool HasRolls();

	Roll NextRoll();

	vector<shared_ptr<Frame>> GetFrames();

	shared_ptr<Roll> AsRoll(int index);
};