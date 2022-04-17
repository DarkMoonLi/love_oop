#include <iostream>
#include <string>

int StringToInt(const std::string& str, int radix, bool& wasError)
{
    for (char symbol : str)
    {
        if ((symbol >= '0') and (symbol <= '9'))
        {
            radix = radix + radix * 10 - '0';
        }
    }

    return radix;
}

int main(int argc, char* argv[])
{
    bool wasError;

    int initialBasis = 0;
    StringToInt(argv[1], initialBasis, wasError);
    std::cout << initialBasis;

    int finalBase = 0;
    StringToInt(argv[2], finalBase, wasError);
    std::cout << finalBase;


}