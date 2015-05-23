#include "FrameBuilder.h"

FrameBuilder::FrameBuilder() : knocks_(0), bonus_(0) { }

FrameBuilder& FrameBuilder::Knocks(int knocks) {
	knocks_ = knocks;
	return *this;
}

FrameBuilder& FrameBuilder::Bonus(int bonus) {
	bonus_ = bonus;
	return *this;
}

shared_ptr<Frame> FrameBuilder::Build() {
	return std::make_shared<Frame>(knocks_, bonus_);
}
