#include <string>
#include "catch/catch.hpp"
#include "../morbidity.hpp"

const std::string INVALID_STATE = "foo";

TEST_CASE("Testing File Reading")
{
	Morbidity dataset;
	bool validFile = dataset.SetInputFile("foo.bar");
	CHECK(false == validFile);
	validFile = dataset.SetInputFile("data.csv");
	CHECK(true == validFile);

	dataset.LoadData();
	CHECK(Approx(-1.0) == dataset.GetMean(INVALID_STATE));
	CHECK(Approx(1036.78).epsilon(0.01) == dataset.GetMean("Alabama"));
	CHECK(Approx(81.17).epsilon(0.01) == dataset.GetMean("Alaska"));

	CHECK(16 == dataset.GetOutlierCount("Alabama"));
	std::string* outliers = dataset.GetOutliers("Alabama");
	CHECK("2020-07-25 - total deaths: 1333" == outliers[0]);
	CHECK("2021-02-06 - total deaths: 1503" == outliers[12]);
	delete [] outliers;

	CHECK_THAT(dataset.GetOutlierInfoForAllStates(), Catch::Contains("West Virginia: 19"));
}
