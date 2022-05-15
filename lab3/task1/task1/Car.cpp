#include "Car.h"
#include "HelpUtils.h"

//Utils убрать, не использовать и подумать над ним

HelpUtils utils;

Car::Car()
{
	m_speed = 0;
	m_gear = Gears::neutral;
	m_isEngineOn = false;
	m_movementDirection = MovementDirection::standingStill;
}

bool Car::IsTurnedOn() const
{
	return m_isEngineOn;
}

MovementDirection Car::GetDirection() const
{
	return m_movementDirection;
}

int Car::GetSpeed() const
{
	return m_speed;
}

Gears Car::GetGear() const
{
	return m_gear;
}

bool Car::TurnOffEngine()
{
	if ((m_isEngineOn == true) && (m_gear == Gears::neutral) && (m_speed == 0))
	{
		m_isEngineOn = false;
		return true;
	}

	return false;
}

bool Car::TurnOnEngine()
{
	if (m_isEngineOn == false)
	{
		m_isEngineOn = true;
		m_gear = Gears::neutral;
		m_speed = 0;
	}

	return m_isEngineOn;
}

bool Car::SetGear(Gears gear)
{
	if (m_isEngineOn && (gear >= Gears::rear) && (gear <= Gears::fifth) && utils.IsGearInSpeedRange(gear, m_speed, m_movementDirection))
	{
		m_gear = gear;
		return true;
	}
	return false;
}

bool Car::SetSpeed(int newSpeed)
{
	if (m_isEngineOn && utils.CheckInSpeedRange(newSpeed, m_gear, m_speed))
	{
		m_speed = newSpeed;

		if (newSpeed == 0)
		{
			m_movementDirection = MovementDirection::standingStill;
		};

		if ((m_gear == Gears::rear || m_gear == Gears::neutral) && newSpeed > 0)
		{
			m_movementDirection = MovementDirection::backward;
		}

		if (newSpeed > 0 && m_gear != Gears::rear && m_movementDirection != MovementDirection::backward)
		{
			m_movementDirection = MovementDirection::forward;
		}

		return true;
	}

	return false;
}
