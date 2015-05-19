#include "catch.hpp"
#include "../src/Line.h"
#include "../src/Frame.h"

using std::vector;

SCENARIO("FrameCreation") {

	GIVEN("a line of bowling") {
		WHEN("there were no knocks") {
			THEN("it has ten frames with 0 knocks each") {
				auto frames = Line("--------------------").GetFrames();
				REQUIRE(frames.size() == 10);
				for (auto frame : frames) {
					REQUIRE(frame->Knocks() == 0);
				}
			}
		}

		WHEN("3 knocks in all rolls") {
			THEN("it has 10 frames with 6 knocks each") {
				auto frames = Line("33333333333333333333").GetFrames();
				REQUIRE(frames.size() == 10);
				for (auto frame : frames) {
					REQUIRE(frame->Knocks() == 6);
				}
			}
		}

		WHEN("all frames where spare") {
			THEN("every frame knocks is ten") {
				auto frames = Line("1/2/3/4/5/6/7/8/9/-/-").GetFrames();
				for (auto frame : frames) {
					REQUIRE(frame->Knocks() == 10);
				}
			}
		}
	}

	GIVEN("a spare") {
		WHEN("next roll is 0") {
			THEN("knocks is 10 and bonus is 0") {
				auto frames = Line("1/------------------").GetFrames();
				shared_ptr<Frame> frame = frames[0];
				REQUIRE(frame->Knocks() == 10);
				REQUIRE(frame->Bonus() == 0);
			}
		}
	}
}