#include "Frame.h"

Frame::Frame(int knocks) : knocks_(knocks) {
}

int Frame::Knocks() {
	return knocks_;
}
