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

		WHEN("spare in the first frame but no one knocks") {
			THEN("only the first frame should have 10 knocks") {
				auto frames = Line("4/------------------").GetFrames();

				REQUIRE(frames[0]->Knocks() == 10);

				std::for_each(
						frames.begin() + 1,
						frames.end(),
						[](shared_ptr<Frame> frame) { REQUIRE(frame->Knocks() == 0); });
			}
		}
	}
}