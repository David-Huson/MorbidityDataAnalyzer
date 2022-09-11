#include "catch/catch.hpp"
#include "../state.hpp"
#include <sstream>

TEST_CASE("Testing State object")
{
	State bama("Alabama");
	CHECK("Alabama" == bama.GetName());

	bama.AddWeek("2020-05-02,2000");
	bama.AddWeek("2020-05-09,2000");
	bama.AddWeek("2020-05-16,100");
	bama.AddWeek("2020-05-23,2000");
	bama.AddWeek("2020-05-30,2000");
	bama.AddWeek("2020-06-06,2000");

	CHECK(Approx(1683.33).epsilon(0.01) == bama.GetMeanDeaths());

	CHECK(Approx(708.08).epsilon(0.01) == bama.Stdev());

	CHECK(1 == bama.GetOutlierCount());
	std::string* outliers = bama.GetOutliers();
	CHECK("2020-05-16 - total deaths: 100" == outliers[0]);
	delete [] outliers;
}
