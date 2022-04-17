#define CATCH_CONFIG_MAIN 
#include <sstream>
#include <../task1/catch2/catch.hpp>
#include <../task1/task1/task1.h>

void OutputVectorToStringStream(std::vector<double>& arrayNumbers, std::ostringstream& output)
{
	for (double item : arrayNumbers)
	{
		output << std::fixed << std::setprecision(3) << item << ' ';
	}
}

SCENARIO("")
{
	std::ostringstream output;

	WHEN("input stream is empty")
	{
		std::vector<double> arrayNumbers = {};

		THEN("output stream also is empty")
		{
			CalculateArithmeticMean(arrayNumbers);

			OutputVectorToStringStream(arrayNumbers, output);

			CHECK(output.str().empty());
		}
	}

	WHEN("the input stream has all negative numbers")
	{
		std::vector<double> arrayNumbers = {-1.15, -2.34, -0.08, -45.8};

		THEN("the same values, but with three decimal places")
		{
			CalculateArithmeticMean(arrayNumbers);

			OutputVectorToStringStream(arrayNumbers, output);

			CHECK(output.str() == "-1.150 -2.340 -0.080 -45.800 ");
		}
	}

	WHEN("the input stream has positive and negative numbers")
	{
		std::vector<double> arrayNumbers = {1.25, 1.25, 1.25, -1.25};

		THEN("the average value is found and adds up with each element")
		{
			CalculateArithmeticMean(arrayNumbers);

			OutputVectorToStringStream(arrayNumbers, output);

			CHECK(output.str() == "2.500 2.500 2.500 0.000 ");
		}
	}

	WHEN("the input stream has integers")
	{
		std::vector<double> arrayNumbers = {-5, 2, 4, -10};

		THEN("the average value is found and adds up with each element, but with three decimal places")
		{
			CalculateArithmeticMean(arrayNumbers);

			OutputVectorToStringStream(arrayNumbers, output);

			CHECK(output.str() == "-2.000 5.000 7.000 -7.000 ");
		}
	}
}