#include "catch.hpp"
#include "../src/Line.h"
#include "../src/Score.h"

SCENARIO() {
	GIVEN("A bowling line") {
		WHEN("no knocks at all") {
			THEN("score is 0") {
				REQUIRE(Score{Line{"--------------------"}}.Total() == 0);
			}
		}

		WHEN("only five knocks") {
			THEN("score is 5") {
				REQUIRE(Score{Line{"5-------------------"}}.Total() == 5);
			}
		}
	}
}