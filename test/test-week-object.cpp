#include "catch/catch.hpp"
#include "../week-data.hpp"
#include <sstream>

TEST_CASE("Testing default constructor")
{
	WeekData w;
	CHECK(0 == w.GetDeathCount());
	std::ostringstream wOut;
	wOut << w;
	CHECK("0000-00-00 - total deaths: 0" == wOut.str());
}

TEST_CASE("Testing Week object")
{
	WeekData w("2020-05-16,1132");
	CHECK(1132 == w.GetDeathCount());
	std::ostringstream wOut;
	wOut << w;
	CHECK("2020-05-16 - total deaths: 1132" == wOut.str());
}
