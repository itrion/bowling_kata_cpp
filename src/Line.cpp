#include <iostream>
#include "Line.h"

using std::vector;
using std::shared_ptr;

Line::Line(const string& input) : line_(input), roll_factory_{}, index_(0) {
}

Line::~Line() { }

bool Line::HasRolls() {
	return index_ < line_.length();
}

Roll Line::NextRoll() {
	return Roll(0);
}

vector<shared_ptr<Frame>> Line::GetFrames() {
	vector<shared_ptr<Frame>> frames;
	for (int roll_index = 0; roll_index < line_.size(); roll_index += 2) {
		frames.push_back(std::make_shared<Frame>(Knocks(roll_index) + Knocks(roll_index + 1)));
	}
	return frames;
}

int Line::Knocks(int roll_index){
	char roll = line_[roll_index];
	if (roll == '-') return 0;
	if (roll == '/') return 10 - Knocks(roll_index - 1);
	return AsInt(roll);
}

int Line::AsInt(const char& rollChar) {
	if (rollChar == '-') return 0;
	return rollChar - 48;
}
