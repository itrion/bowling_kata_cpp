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

		WHEN("knocks in every roll but no spare or strike") {
			THEN("score is the sum of all rolls knocks") {
				REQUIRE(Score{Line{"44444444444444444444"}}.Total() == 80);
			}
		}

		WHEN("a spare in the first frame and no more knocks") {
			THEN("the score is 10") {
				REQUIRE(Score{Line{"4/------------------"}}.Total() == 10);
			}
		}

		WHEN("a spare in the second frame and no more knocks") {
			THEN("the score is 10") {
				REQUIRE(Score{Line{"--4/----------------"}}.Total() == 10);
			}
		}

		WHEN("a spare has knocks in the next roll") {
			THEN("the score of the spare frame is 10 plus the knocks of the next roll") {
				REQUIRE(Score{Line{"1/9-----------------"}}.Total() == 28);
			}
		}

		WHEN("all frames are strike") {
			THEN("score is 300") {
				REQUIRE(Score(Line("XXXXXXXXXXXX")).Total() == 300);
			}
		}

		WHEN("all rolls are nine and miss") {
			THEN("score is 300") {
				REQUIRE(Score(Line("9-9-9-9-9-9-9-9-9-9-")).Total() == 90);
			}
		}


		WHEN("all rolls are 5"){
			THEN("score is 150") {
				REQUIRE(Score(Line("5/5/5/5/5/5/5/5/5/5/5")).Total() == 150);
			}
		}
	}
}