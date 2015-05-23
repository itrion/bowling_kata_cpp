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

	vector<shared_ptr<Frame>> Frames();

private:
	vector<shared_ptr<Roll>> rolls_;
	vector<shared_ptr<Frame>> frames_;

	int AsInt(const char& rollChar);

	shared_ptr<Roll> AsRoll(const string& input, int& index);

	void BuildRolls(const string& input);

	void BuildFrames();
};