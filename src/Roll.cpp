#include "Roll.h"

Roll::Roll(int knocks) : knocks_(knocks) {
}

int Roll::Knocks() {
	return knocks_;
}

bool Roll::IsSpare() {
	return false;
}

Roll::~Roll() {

}
