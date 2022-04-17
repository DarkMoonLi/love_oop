#include "HelpUtils.h"
#include <map>
#include "Car.h"

std::map <MovementDirection, std::string> directionString = {
	{MovementDirection::backward, "backward"},
	{MovementDirection::standingStill, "standing still"},
	{MovementDirection::forward, "forward"}
};

std::string HelpUtils::DirectionToString(MovementDirection direction)
{
	return directionString[direction];
}

bool InSpeedRange(int speed, std::pair<int, int> limits)
{
	return (speed >= limits.first && speed <= limits.second);
}

bool HelpUtils::IsGearInSpeedRange(Gears gear, int speed, Gears m_gear, MovementDirection direction)
{
	switch (gear)
	{
		case Gears::rear:
			return (speed == 0);

		case Gears::first:
			return InSpeedRange(speed, firstGearSpeedInterval) && direction != MovementDirection::backward;

		case Gears::second:
			return InSpeedRange(speed, secondGearSpeedInterval) && direction != MovementDirection::backward;

		case Gears::third:
			return InSpeedRange(speed, thirdGearSpeedInterval);

		case Gears::fourth:
			return InSpeedRange(speed, fourthGearSpeedInterval);

		case Gears::fifth:
			return InSpeedRange(speed, fifthGearSpeedInterval);

		default:
			return true;
	}
}
