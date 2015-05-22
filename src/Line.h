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

public:
	Line(const string& input);

	~Line();

	vector<shared_ptr<Frame>> GetFrames();

private:
	string const& line_;

	int AsInt(const char& rollChar);

	shared_ptr<Roll> AsRoll(int index);
};