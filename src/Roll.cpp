#include "Roll.h"

Roll::Roll(int knocks) : knocks_(knocks) {
}

Roll::~Roll() {
}

int Roll::Knocks() {
	return knocks_;
}

bool Roll::IsSpare() {
	return false;
}

bool Roll::IsStrike() {
	return false;
}
