#include <iostream>
#include "HelpUtils.h"
#include "Car.h"
#include <string>

void Print(std::string line)
{
	std::cout << line << '\n';
}

int main()
{
	bool switcher = true;
	Print("You can control the machine with these commands:");
	Print("Info");
	Print("EngineOn");
	Print("EngineOff");
	Print("SetGear 'gear'");
	Print("SetSpeed 'speed'\n");

	std::string commandLine;
	Car car;
	HelpUtils utils;

	//разделить строку на 2 подстроки и гетлайн
	while (std::getline(std::cin, commandLine))
	{
		int delimiterPosition = commandLine.find(' ');

		std::string command = commandLine.substr(0, delimiterPosition);

		if (command == "Info")
		{
			if (car.IsTurnedOn())
			{
				std::cout << "Engine on\n";
			}
			else
			{
				std::cout << "Engine off\n";
			}

			std::cout << "Direction of movement: " << utils.DirectionToString(car.GetDirection()) << '\n';
			std::cout << "Speed: " << car.GetSpeed() << '\n';
			std::cout << "Gear: " << (int)car.GetGear() << '\n';
		};

		if (command == "EngineOn")
		{
			if (car.TurnOnEngine())
			{
				Print("The engine is on");
			}
			else
			{
				Print("The operation could not be completed successfully.");
			}
		};

		if (command == "EngineOff")
		{
			if (car.TurnOffEngine())
			{
				Print("The engine is off");
			}
			else
			{
				Print("The operation could not be completed successfully.");
			}
		};

		if (command == "SetGear")
		{
			int gear = stoi(commandLine.substr(delimiterPosition + 1));
			if (car.SetGear((Gears)gear))
			{
				std::cout << "Gear:" << gear << "\n";
			}
			else
			{
				Print("The operation could not be completed successfully.");
			}
		};

		if (command == "SetSpeed")
		{
			int speed = stoi(commandLine.substr(delimiterPosition + 1));

			if (car.SetSpeed(speed))
			{
				std::cout << "Speed:" << speed << "\n";
			}
			else
			{
				Print("The operation could not be completed successfully.");
			}
		};

		Print("\n");
	}
}