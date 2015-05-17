#include "Score.h"

Score::Score(Line line) : line_(line) {

}

Score::~Score() {

}

int Score::Total() {
	int total = 0;
	while (line_.HasRolls())
		total += line_.NextRoll().Knocks();
	return total;
}
