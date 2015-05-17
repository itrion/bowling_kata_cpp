#include "Score.h"

Score::Score(Line line) : line_(line) {

}

Score::~Score() {

}

int Score::Total() {
	return line_.NextRoll().Knocks();
}
