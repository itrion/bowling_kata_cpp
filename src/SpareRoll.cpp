#include "SpareRoll.h"

SpareRoll::SpareRoll(int knocks) : Roll(knocks) {
}

int SpareRoll::Knocks() {
	return Roll::Knocks();
}

bool SpareRoll::IsSpare() {
	return true;
}
