#pragma once
#include <string>

enum class Gears
{
	rear = -1,
	neutral,
	first,
	second,
	third,
	fourth,
	fifth
};

enum class MovementDirection
{
	backward = -1,
	standingStill,
	forward
};

class HelpUtils
{
public:
	std::string DirectionToString(MovementDirection direction);

	bool IsGearInSpeedRange(Gears gear, int speed, MovementDirection direction);

	bool CheckInSpeedRange(int speed, Gears gear, int m_speed);

private:

};