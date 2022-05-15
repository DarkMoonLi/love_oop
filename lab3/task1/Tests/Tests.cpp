#include <iostream>
#include <sstream>
#include "../task1/Car.h"
#define CATCH_CONFIG_MAIN 
#include "../catch2/catch.hpp"

SCENARIO("Testing the engine on and off")
{
    Car car;

    WHEN("Initial Value Test")
    {
        REQUIRE(car.IsTurnedOn() == false);
    }

    WHEN("turning on the engine")
    {
        REQUIRE(car.TurnOnEngine() == true);
    }

    WHEN("turning off the engine")
    {
        REQUIRE(car.TurnOffEngine() == false);

        car.TurnOnEngine(); 
        car.SetGear(Gears::first);
        car.SetSpeed(1);
        car.SetGear(Gears::neutral);
        REQUIRE(car.TurnOffEngine() == false);
        car.SetSpeed(0);

        car.TurnOnEngine();
        REQUIRE(car.TurnOffEngine() == true);

        car.TurnOnEngine();
        car.SetGear(Gears::first);
        REQUIRE(car.TurnOffEngine() == false);

        car.TurnOnEngine();
        car.SetGear(Gears::neutral);
        REQUIRE(car.TurnOffEngine() == true);
    }
}

SCENARIO("Testing the speed setting")
{
    Car car;
    car.TurnOnEngine();

    WHEN("Initial Value Test")
    {
        REQUIRE(car.GetSpeed() == 0);
    }

    WHEN("Setting an invalid speed")
    {
        REQUIRE(car.SetSpeed(-10) == false);
        REQUIRE(car.SetSpeed(200) == false);
    }

    WHEN("Setting the speed in reverse gear")
    {
        car.SetGear(Gears::rear);
        REQUIRE(car.SetSpeed(0) == true);
        REQUIRE(car.SetSpeed(10) == true);
        REQUIRE(car.SetSpeed(25) == false);
    }

    WHEN("Setting the speed in neutral gear")
    {
        car.SetGear(Gears::first);
        car.SetSpeed(8);
        car.SetGear(Gears::neutral);
        REQUIRE(car.SetSpeed(5) == true);
        REQUIRE(car.SetSpeed(10) == false);
        REQUIRE(car.SetSpeed(0) == true);
    }

    WHEN("Setting the speed in first gear")
    {
        car.SetGear(Gears::first);
        REQUIRE(car.SetSpeed(5) == true);
        REQUIRE(car.SetSpeed(35) == false);
    }

    WHEN("Setting the speed in second gear")
    {
        car.SetGear(Gears::first);
        car.SetSpeed(20);
        car.SetGear(Gears::second);
        REQUIRE(car.SetSpeed(15) == false);
        REQUIRE(car.SetSpeed(25) == true);
        REQUIRE(car.SetSpeed(55) == false);
    }

    WHEN("Setting the speed in third gear")
    {
        car.SetGear(Gears::first);
        car.SetSpeed(30);
        car.SetGear(Gears::third);
        REQUIRE(car.SetSpeed(25) == false);
        REQUIRE(car.SetSpeed(45) == true);
        REQUIRE(car.SetSpeed(65) == false);
    }

    WHEN("Setting the speed in fourth gear")
    {
        car.SetGear(Gears::first);
        car.SetSpeed(30);
        car.SetGear(Gears::second);
        car.SetSpeed(40);
        car.SetGear(Gears::fourth);
        REQUIRE(car.SetSpeed(35) == false);
        REQUIRE(car.SetSpeed(75) == true);
        REQUIRE(car.SetSpeed(95) == false);
    }

    WHEN("Setting the speed in fifth gear")
    {
        car.SetGear(Gears::first);
        car.SetSpeed(30);
        car.SetGear(Gears::second);
        car.SetSpeed(40);
        car.SetGear(Gears::fourth);
        car.SetSpeed(50);
        car.SetGear(Gears::fifth);
        REQUIRE(car.SetSpeed(45) == false);
        REQUIRE(car.SetSpeed(125) == true);
        REQUIRE(car.SetSpeed(155) == false);
    }
}

SCENARIO("Testing the gear installation")
{
    Car car;
    car.TurnOnEngine();

    WHEN("Initial Value Test")
    {
        REQUIRE(car.GetGear() == Gears::neutral);
    }

    WHEN("Setting the same value")
    {
        REQUIRE(car.SetGear(Gears::neutral) == true);
    }

    WHEN("Switching gears from neutral to 1")
    {
        REQUIRE(car.SetGear(Gears::first) == true);
    }

    WHEN("Switching to neutral from the first")
    {
        car.SetGear(Gears::first);
        REQUIRE(car.SetGear(Gears::neutral) == true);
    }

    WHEN("Switching to neutral from the rear")
    {
        car.SetGear(Gears::rear);
        REQUIRE(car.SetGear(Gears::neutral) == true);
    }

    WHEN("Switching to neutral from the second")
    {
        car.SetSpeed(25);
        car.SetGear(Gears::second);
        REQUIRE(car.SetGear(Gears::neutral) == true);
    }

    WHEN("Switching to neutral from the third")
    {
        car.SetSpeed(35);
        car.SetGear(Gears::third);
        REQUIRE(car.SetGear(Gears::neutral) == true);
    }

    WHEN("Switching to neutral from the fourth")
    {
        car.SetSpeed(45);
        car.SetGear(Gears::fourth);
        REQUIRE(car.SetGear(Gears::neutral) == true);
    }

    WHEN("Switching to neutral from the fifth")
    {
        car.SetSpeed(55);
        car.SetGear(Gears::fifth);
        REQUIRE(car.SetGear(Gears::neutral) == true);
    }

    WHEN("Switching to neutral from the fifth")
    {
        car.SetSpeed(55);
        car.SetGear(Gears::fifth);
        REQUIRE(car.SetGear(Gears::neutral) == true);
    }

    WHEN("Switching to reverse gear with 0 speed")
    {
        car.SetGear(Gears::first);
        car.SetSpeed(10);
        car.SetGear(Gears::neutral);
        REQUIRE(car.SetGear(Gears::rear) == false);

        car.SetSpeed(0);
        REQUIRE(car.SetGear(Gears::rear) == true);
    }

    WHEN("From the reverse gear to the first one, we switch at a speed of 0")
    {
        car.SetGear(Gears::rear);
        car.SetSpeed(10);
        REQUIRE(car.SetGear(Gears::first) == false);

        car.SetSpeed(0);
        REQUIRE(car.SetGear(Gears::first) == true);
    }

    WHEN("By switching to neutral gear in reverse, you can switch to the first gear only when stopping")
    {
        car.SetGear(Gears::rear);
        car.SetSpeed(10);
        car.SetGear(Gears::neutral);
        REQUIRE(car.SetGear(Gears::first) == false);

        car.SetSpeed(0);
        REQUIRE(car.SetGear(Gears::first) == true);
    }

    WHEN("When we switched with -1 granny 2 at speeds 20")
    {
        car.SetGear(Gears::rear);
        car.SetSpeed(20);
        REQUIRE(car.SetGear(Gears::second) == false);
    }

    WHEN("When the engine is turned off")
    {
        REQUIRE(car.SetGear(Gears::neutral) == true);
    }
}

SCENARIO("Test check of the directions of movements")
{
    Car car;
    car.TurnOnEngine();
    WHEN("Checking the initialized value")
    {
        REQUIRE(car.GetDirection() == MovementDirection::standingStill);
    }

    WHEN("For standing still and gear = -1")
    {
        car.SetGear(Gears::rear);
        REQUIRE(car.GetDirection() == MovementDirection::standingStill);
    }

    WHEN("Test for gear backward")
    {
        car.SetGear(Gears::rear);
        car.SetSpeed(10);
        REQUIRE(car.GetDirection() == MovementDirection::backward);
    }

    WHEN("test for gear forward")
    {
        car.SetSpeed(0);
        car.SetGear(Gears::first);
        car.SetSpeed(5);
        REQUIRE(car.GetDirection() == MovementDirection::forward);
    }
}
