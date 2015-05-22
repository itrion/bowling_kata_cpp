#include "catch.hpp"
#include "../src/Line.h"

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
			THEN("knocks is 10") {
				auto frames = Line("1/------------------").GetFrames();
				auto frame = frames.at(0);
				REQUIRE(frame->Knocks() == 10);
				AND_THEN("bonus is 0"){
					REQUIRE(frame->Bonus() == 0);
				}
			}
		}

		WHEN("next roll is 9") {
			THEN("knocks is 10 and ") {
				auto frames = Line("1/9-----------------").GetFrames();
				auto frame = frames.at(0);
				REQUIRE(frame->Knocks() == 10);

				AND_THEN("bonus is 9") {
					REQUIRE(frame->Bonus() == 9);
				}
			}
		}
	}

	GIVEN("a strike"){
		WHEN("next 2 rolls are 0"){
			THEN("knocks is 10"){
				auto frames = Line("X------------------").GetFrames();
				auto strike = frames.at(0);
				REQUIRE(strike->Knocks() == 10);
				AND_THEN("bonus is 0"){
					REQUIRE(strike->Bonus() == 0);
				}
			}
		}

		WHEN("next 2 rolls are 1 each"){
			THEN("knocks is 10"){
				auto frames = Line("X11----------------").GetFrames();
				auto strike = frames.at(0);
				REQUIRE(strike->Knocks() == 10);
				AND_THEN("bonus is 0"){
					REQUIRE(strike->Bonus() == 2);
				}
			}
		}

		/*
		 * TODO next two rolls has different values
		 * TODO next two rolls are spare
		 * TODO next two rolls are strikes
		 * TODO strike in the last frame next rolls are 0
		 * TODO strike in the last frame  next rolls are different values
		 * TODO strike in the last frame  next rolls are 10
		 * */
	}
}