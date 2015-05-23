#include <iostream>
#include "Line.h"
#include "SpareRoll.h"
#include "StrikeRoll.h"
#include "FrameBuilder.h"

using std::vector;
using std::shared_ptr;

Line::Line(const string& input) : rolls_(), frames_() {
	BuildRolls(input);
	BuildFrames();
}

Line::~Line() { }

void Line::BuildRolls(const string& input) {
	for (int index = 0; index < input.size(); index++) {
		rolls_.push_back(AsRoll(input, index));
	}
}

shared_ptr<Roll> Line::AsRoll(const string& input, int& index) {
	char roll_char = input[index];
	if (roll_char == '-') return std::make_shared<Roll>(0);
	if (roll_char == '/') return std::make_shared<SpareRoll>(10 - rolls_[index - 1]->Knocks());
	if (roll_char == 'X') return std::make_shared<StrikeRoll>(10);
	return std::make_shared<Roll>(AsInt(roll_char));
}

int Line::AsInt(const char& rollChar) {
	return rollChar - 48;
}

void Line::BuildFrames() {
	int index = 0;
	while (frames_.size() < 10) {

		auto roll = rolls_[index];
		auto second_roll = rolls_[index + 1];

		if (roll->IsStrike()) {
			frames_.push_back(FrameBuilder().Knocks(roll->Knocks())
					                  .Bonus(second_roll->Knocks() + rolls_[index + 2]->Knocks())
					                  .Build());
		}
		else if (second_roll->IsSpare()) {
			frames_.push_back(FrameBuilder().Knocks(roll->Knocks() + second_roll->Knocks())
					                  .Bonus(rolls_[index + 2]->Knocks())
					                  .Build());
			index++;
		}
		else {
			frames_.push_back(FrameBuilder().Knocks(roll->Knocks() + second_roll->Knocks())
					                  .Build());
			index++;
		}
		index++;
	}
}

vector<shared_ptr<Frame>> Line::Frames() {
	return frames_;
}
