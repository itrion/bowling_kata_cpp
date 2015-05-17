#include "Line.h"

Line::Line(const string& input) : line_(input) {
	index_ = 0;
}

Line::~Line() { }

Roll Line::NextRoll() {
	return Roll{line_[index_++]};
}
