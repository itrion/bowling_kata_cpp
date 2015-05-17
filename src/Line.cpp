#include "Line.h"

Line::Line(const string& input) : line_(input) {
	index_ = 0;
}

Line::~Line() { }

bool Line::HasRolls() {
	return index_ < line_.length();
}

Roll Line::NextRoll() {
	int current_index = index_++;
	if (line_[current_index] == '-')
		return Roll(0);
	if (line_[current_index] == '/')
		return Roll(10 - AsInt(line_[current_index - 1]));
	else
		return Roll(AsInt(line_[current_index]));
}

int Line::AsInt(const char& rollChar) {
	return rollChar - 48;
}
