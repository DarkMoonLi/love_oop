#include <iostream>
#include <fstream>
#include <string>

const std::string FILE_OUTPUT_NAME = "output.txt";

void PrintLineInFile(const int lineIndex, std::ofstream& output)
{
	output << lineIndex << "\n";
}

bool FindStringInStream(std::istream& input, char*& line, std::ofstream& output)
{
	std::string row;
	bool found = false;

	for (int lineIndex = 1; getline(input, row); ++lineIndex)
	{
		auto position = row.find(line);

		if (position != std::string::npos)
		{
			found = true;
			PrintLineInFile(lineIndex, output);
		}
	}

	return found;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid arguments count.\n";
		std::cout << "Usage: FindText.exe <input file name> <output file name>\n";
		return 1;
	}

	std::ifstream input;
	input.open(argv[1]);
	if (!input.is_open())
	{
		std::cout << "Failed to open '" << argv[1] << "' for reading.\n";
		return 1;
	}

	std::ofstream output;
	output.open(FILE_OUTPUT_NAME);
	if (!output.is_open())
	{
		std::cout << "Failed to open '" << FILE_OUTPUT_NAME << "' for writing.\n";
		return 1;
	}

	if (!FindStringInStream(input, argv[2], output))
	{
		output << "Text not found\n";
	}

	return 0;
}
