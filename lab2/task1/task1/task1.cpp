#include "task1.h"

int main()
{
    std::vector<double> arrayNumbers;

    FillingVectorFromConsole(arrayNumbers);
    //тест для заполнения чисел через консоль, также для вывода
    CalculateArithmeticMean(arrayNumbers);

    OutputVectorToConsole(arrayNumbers);

    return 0;
}