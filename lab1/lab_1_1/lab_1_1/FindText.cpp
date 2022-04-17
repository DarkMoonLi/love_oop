#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

void PrintLineInFile(const int lineIndex)
{
	std::cout << lineIndex << "\n";
}

bool FindStringInStream(std::istream& input, const std::string& line)
{
	std::string row;
	bool found = false;

	for (int lineIndex = 1; getline(input, row); ++lineIndex)
	{
		size_t position = row.find(line);

		if (position != std::string::npos)
		{
			found = true;
			PrintLineInFile(lineIndex);
		}
	}

	return found;
}

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// parseArgs или иное название
	// optional<Args>

	if (argc != 3)
	{
		std::cerr << "Invalid arguments count.\nUsage: task1.exe <input file name> <the search word>\n";
		return 1;
	}

	std::ifstream input;
	input.open(argv[1]);
	if (!input.is_open())
	{
		std::cerr << "Failed to open '" << argv[1] << "' for reading.\n";
		return 1;
	}

	if (!FindStringInStream(input, argv[2]))
	{
		std::cout << "Text not found\n";
	}

	return 0;
}