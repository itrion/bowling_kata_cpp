#include "Frame.h"

Frame::Frame(int knocks) : Frame(knocks, 0) {
}

Frame::Frame(int knocks, int bonus) : knocks_(knocks), bonus_(bonus) {

}

int Frame::Knocks() {
	return knocks_;
}

int Frame::Bonus() {
	return bonus_;
}
