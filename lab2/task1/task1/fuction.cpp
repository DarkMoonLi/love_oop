#include "task1.h"

bool IsPositiveNumber(double& item)
{
    return (item > 0) ? true : false;
}
// передать поток ввода и считать
void FillingVectorFromConsole(std::vector<double>& arrayNumbers)
{
    double number;

    while (std::cin >> number)
    {
        arrayNumbers.push_back(number);

        if (std::cin.get() == '\n')
        {
            break;
        }// ne obyaz
    }
}

//transform
void AddVectorElementAndArithmeticMean(std::vector<double>& arrayNumbers, double arithmeticMean)
{
    for (int i = 0; i < arrayNumbers.size(); i++)
    {
        arrayNumbers[i] += arithmeticMean;
    }
}
//how to calculate ArithmeticMean
void CalculateArithmeticMean(std::vector<double>& arrayNumbers)
{
    int countPositiveNumbers = 0;
    long double sumPositiveNumbers = 0;
    long double arithmeticMean = 0;

    for (double item : arrayNumbers)
    {

        countPositiveNumbers = std::count_if(arrayNumbers.begin(), arrayNumbers.end(), IsPositiveNumber);

        if (IsPositiveNumber(item))
        {
            sumPositiveNumbers += item;
        }

        if (countPositiveNumbers != 0)
        {
            arithmeticMean = sumPositiveNumbers / countPositiveNumbers;
        }
    }

    AddVectorElementAndArithmeticMean(arrayNumbers, arithmeticMean);
}

void OutputVectorToConsole(std::vector<double>& arrayNumbers)
{
    for (double item : arrayNumbers)
    {
        std::cout << std::fixed << std::setprecision(3) << item << ' ';
    }
}