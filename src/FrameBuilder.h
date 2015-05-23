#pragma once


#include <memory>
#include "Frame.h"

using std::shared_ptr;

class FrameBuilder {

public:
	FrameBuilder();

	FrameBuilder& Knocks(int knocks);

	FrameBuilder& Bonus(int bonus);

	shared_ptr<Frame> Build();

private:
	int knocks_;
	int bonus_;
};

