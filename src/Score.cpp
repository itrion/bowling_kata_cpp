#include "Score.h"

Score::Score(Line line) : line_(line) {

}

Score::~Score() {

}

int Score::Total() {
	int total = 0;
	for (auto frame : line_.Frames()) {
		total += frame->Knocks() + frame->Bonus();
	}
	return total;
}
