#pragma once
#include <string>
#include "HelpUtils.h"

const std::pair<int, int> reverseGearSpeedInterval = { 0, 20 };
const std::pair<int, int> firstGearSpeedInterval = { 0, 30 };
const std::pair<int, int> secondGearSpeedInterval = { 20, 50 };
const std::pair<int, int> thirdGearSpeedInterval = { 30, 60 };
const std::pair<int, int> fourthGearSpeedInterval = { 40, 90 };
const std::pair<int, int> fifthGearSpeedInterval = { 50, 150 };

class Car
{
public:
	Car();

	bool IsTurnedOn() const;

	MovementDirection GetDirection() const;

	int GetSpeed() const;

	Gears GetGear() const;

	bool TurnOffEngine();

	bool TurnOnEngine();

	bool SetGear(Gears gear);

	bool SetSpeed(int speed);

private:
	int m_speed;
	Gears m_gear;
	bool m_isEngineOn;
	MovementDirection m_movementDirection;
};

