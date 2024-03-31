/*
Consider a scenario : 
We have 1 base class "Vehicle" and 3 child classes like following
 - PassengerVehicle
 - SportsVehicle
 - OffRoadVehicle

Vehicle class has drive() function and all child classes has overrided this function.

After overriding, it seems SportsVehicle and OffRoadVehicle has same code inside drive function. 

This leads to code duplication.

To solve this issue, we have solution -> Strategy Design
*/

#include <bits/stdc++.h>
using namespace std;

class DriveStrategy
{
public:
	virtual void drive() {};
};

class SportsDriveStrategy : public DriveStrategy
{
public:
	void drive()
	{
		cout << "Sports drive capability\n";
	}
};

class NormalDriveStrategy : public DriveStrategy
{
public:
	void drive()
	{
		cout << "Normal drive capability\n";
	}
};

class Vehicle
{
private:
	DriveStrategy *driveStrategy;
public:
	// constructor injection
	Vehicle(DriveStrategy *driveStrategyObj)
	{
		this -> driveStrategy = driveStrategyObj;
	}

	void drive()
	{
		driveStrategy->drive();
	}
};

class PassengerVehicle : public Vehicle 
{
public:
	PassengerVehicle() : Vehicle(new NormalDriveStrategy()) {};
};

class SportsVehicle : public Vehicle
{
public:
	SportsVehicle() : Vehicle(new SportsDriveStrategy()) {};
};

class OffRoadVehicle : public Vehicle
{
public:
	OffRoadVehicle() : Vehicle(new SportsDriveStrategy()) {};
};


int main()
{
	Vehicle *sportsVehicle = new SportsVehicle();
	Vehicle *passengerVehicle = new PassengerVehicle();
	Vehicle *offRoadVehicle = new OffRoadVehicle();

	sportsVehicle -> drive();
	passengerVehicle -> drive();
	offRoadVehicle -> drive();
	return 0;
}