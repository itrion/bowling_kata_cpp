#include <iostream>
#include "Line.h"
#include "SpareRoll.h"
#include "StrikeRoll.h"

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
	for (int roll_index = 0; roll_index < 20; roll_index += 2) {
		int bonus = 0;
		auto current_roll = AsRoll(roll_index);
		auto second_roll = AsRoll(roll_index + 1);
		int knocks = current_roll->Knocks();
		if (current_roll->IsStrike()) {
			bonus = second_roll->Knocks() + AsRoll(roll_index + 2)->Knocks();
			knocks -= second_roll->Knocks();
		}
		knocks += second_roll->Knocks();
		if (second_roll->IsSpare()) bonus = AsRoll(roll_index + 2)->Knocks();
		frames.push_back(std::make_shared<Frame>(knocks, bonus));
	}
	return frames;
}

int Line::AsInt(const char& rollChar) {
	return rollChar - 48;
}

shared_ptr<Roll> Line::AsRoll(int index) {
	char roll_char = line_[index];
	if (roll_char == '-') return std::make_shared<Roll>(0);
	if (roll_char == '/') return std::make_shared<SpareRoll>(10 - AsRoll(index - 1)->Knocks());
	if (roll_char == 'X') return std::make_shared<StrikeRoll>(10);
	return std::make_shared<Roll>(AsInt(roll_char));
}
