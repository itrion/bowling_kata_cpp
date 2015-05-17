#include <iostream>
#include "Line.h"

Line::Line(const string& input) : line_(input), roll_factory_{} {
	index_ = 0;
	roll_factory_['-'] = []() { return Roll(0); };
	roll_factory_['1'] = []() { return Roll(1); };
	roll_factory_['2'] = []() { return Roll(2); };
	roll_factory_['3'] = []() { return Roll(3); };
	roll_factory_['4'] = []() { return Roll(4); };
	roll_factory_['5'] = []() { return Roll(5); };
	roll_factory_['6'] = []() { return Roll(6); };
	roll_factory_['7'] = []() { return Roll(7); };
	roll_factory_['8'] = []() { return Roll(8); };
	roll_factory_['9'] = []() { return Roll(9); };
	roll_factory_['/'] = [=]() { return Roll(10 - AsInt(line_[index_])); };
}

Line::~Line() { }

bool Line::HasRolls() {
	return index_ < line_.length();
}

Roll Line::NextRoll() {
	return roll_factory_[line_[index_++]]();
}

int Line::AsInt(const char& rollChar) {
	return rollChar - 48;
}
