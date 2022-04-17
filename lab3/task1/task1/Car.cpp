#include "Car.h"
#include "HelpUtils.h"
//если неправильная команда, то сообщение
//при движении назад переключать передачи нельзя на вторую, написать сперва тест, убедиться, что он не проходит, а потом исправлять баги
// при выключении двигателя пишет engineOn

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

//переделать метод, функция(классная)
bool Car::SetGear(Gears gear)
{
	//не использовать то, что не знаем, как не знаем. Не использовать логические константы.
	if (m_isEngineOn && (gear >= Gears::rear) && (gear <= Gears::fifth) && utils.IsGearInSpeedRange(gear, m_speed, m_gear, m_movementDirection))
	{
		m_gear = gear;
		return true;
	}
	return false;
}

bool Car::SetSpeed(int newSpeed)
{
	if (m_isEngineOn)
	{
		switch (m_gear)
		{
			case Gears::rear:
			{
				if (newSpeed > 0 && newSpeed <= 20)
				{
					m_speed = newSpeed;
					m_movementDirection = MovementDirection::backward;
					return true;
				}

				if (newSpeed == 0)
				{
					m_speed = newSpeed;
					m_movementDirection = MovementDirection::standingStill;
					return true;
				}

				break;
			}

			case Gears::neutral:
			{
				if ((newSpeed > 0) && (newSpeed <= m_speed))
				{
					m_speed = newSpeed;
					return true;
				}

				if (newSpeed == 0)
				{
					m_speed = newSpeed;
					m_movementDirection = MovementDirection::standingStill;
					return true;
				}

				break;
			}

			case Gears::first:
			{
				if (newSpeed > 0 && newSpeed <= 30)
				{
					m_speed = newSpeed;
					m_movementDirection = MovementDirection::forward;
					return true;
				}

				if (newSpeed == 0)
				{
					m_speed = newSpeed;
					m_movementDirection = MovementDirection::standingStill;
					return true;
				}

				break;
			}

			case Gears::second:
			{
				if (newSpeed >= 20 && newSpeed <= 50 && m_gear != Gears::rear)
				{
					m_speed = newSpeed;
					m_movementDirection = MovementDirection::forward;
					return true;
				}

				break;
			}

			case Gears::third:
			{
				if (newSpeed >= 30 && newSpeed <= 60)
				{
					m_speed = newSpeed;
					m_movementDirection = MovementDirection::forward;
					return true;
				}

				break;
			}

			case Gears::fourth:
			{
				if (newSpeed >= 40 && newSpeed <= 90)
				{
					m_speed = newSpeed;
					m_movementDirection = MovementDirection::forward;
					return true;
				}

				break;
			}

			case Gears::fifth:
			{
				if (newSpeed >= 50 && newSpeed <= 150)
				{
					m_speed = newSpeed;
					m_movementDirection = MovementDirection::forward;
					return true;
				}

				break;
			}
		}
	}

	return false;
}
