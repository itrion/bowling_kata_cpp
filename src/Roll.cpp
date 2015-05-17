#include "Roll.h"

Roll::Roll(char knocks) {
	knocks_ = knocks;
}

int Roll::Knocks() {
	if (knocks_ == '-') return 0;
	return knocks_ - 48;
}
