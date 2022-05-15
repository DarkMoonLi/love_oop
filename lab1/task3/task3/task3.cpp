#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <sstream>

const int MATRIX_SIZE = 3;

typedef double TMatrix3x3[MATRIX_SIZE][MATRIX_SIZE];
typedef double TMatrix2x2[2][2];

struct Args
{
    std::string fileIn;
};

bool ParseArgs(int argc, char* argv[], Args& args)
{
    if (argc != 2)
    {
        std::cout << "Incorrect data was entered." << std::endl;
        std::cerr << "Enter in the format: invert.exe <matrix file>" << std::endl;
        return false;
    }

    args.fileIn = argv[1];

    return true;
}

bool IsNumber()
{

}

void InitMatrix(std::ifstream& input, TMatrix3x3& matrix)
{
    std::string line;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        if (std::getline(input, line) && line.empty())
        {
            std::cerr << "Value is empty.";
        }

        std::istringstream lineIn;
    }
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        if()
    }
}

void PrintMatrix(TMatrix3x3 matrix)
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            std::cout << std::fixed << std::setprecision(3) << matrix[i][j] << ' ';
        }
        
        std::cout << std::endl;
    }
}

bool InitFileStream(Args& args, std::ifstream& input)
{
    input.open(args.fileIn);

    if (!input.is_open())
    {
        std::cout << "Error in opening the file." << std::endl;
        return false;
    }

    return true;
}

int CalculateDeterminantMatrix3x3(TMatrix3x3 matrix)
{

    return 1;
}

void CalculateDeterminantMatrix2x2()
{

}

int main(int argc, char* argv[])
{
	TMatrix3x3 matrix;
    Args args;

    if (!ParseArgs(argc, argv, args))
    {
        return 1;
    }

    std::ifstream input;

    if (!InitFileStream(args, input))
    {
        return 1;
    }

    InitMatrix(input, matrix);



    PrintMatrix(matrix);
}
