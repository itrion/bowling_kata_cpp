#include <iostream>
#include "Line.h"

Line::Line(const string& input) : line_(input), roll_factory_{} , index_(0){
}

Line::~Line() { }

bool Line::HasRolls() {
	return index_ < line_.length();
}

Roll Line::NextRoll() {
	int current_index = index_++;
	char roll = line_[current_index];
	if (roll == '-') return Roll(0);
	if (roll == '/') return Roll(10 - AsInt(line_[current_index - 1]));
	return Roll(AsInt(roll));
}

int Line::AsInt(const char& rollChar) {
	return rollChar - 48;
}
