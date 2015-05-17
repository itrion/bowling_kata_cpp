#include "catch.hpp"
#include "../src/Line.h"
#include "../src/Score.h"

TEST_CASE("ScoreTest") {

	SECTION("an empty line") {
		Score score{Line{"--------------------"}};
		REQUIRE(score.Total() == 0);
	}
}