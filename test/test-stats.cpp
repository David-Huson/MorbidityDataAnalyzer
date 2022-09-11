#include "catch/catch.hpp"
#include "../stats.hpp"
#include "../week-data.hpp"

WeekData data[] = {
	WeekData("1776-07-04,1"), // Just some static test data.
	WeekData("1776-07-11,2"), // The dates are not important
	WeekData("1776-07-18,3"), //  since we are just trying to test the 
	WeekData("1776-07-25,5"), //  statistical calculations
	WeekData("1776-08-02,6")
};

TEST_CASE("Testing Mean")
{
	// Comparing doubles, can use Approx() to allow some epsilon difference
	CHECK(Approx(3.4) == Stats::GetMean(data, 5));
}

TEST_CASE("Testing Stdev")
{
	CHECK(Approx(1.85).epsilon(0.01) == Stats::StDev(data, 5));
}

TEST_CASE("Testing Degenerate data")
{
	// let's call the mean of no numbers: 0
	CHECK(Approx(0) == Stats::GetMean({}, 0));
	CHECK(Approx(0) == Stats::StDev({}, 0));
}

// Compile & run:
// make clean test
