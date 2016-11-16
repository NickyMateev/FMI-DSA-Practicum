#include "laptop.h"

void Laptop::copy(const Laptop& other)
{
  this->screenSize = other.screenSize;
  this->batteryLife = other.batteryLife;
}

void Laptop::destroy()
{
  // nothing to destroy...
}

Laptop::Laptop(char computerType, int computerID, string brand, string model, double price, int coreCount, int ram, double screenSize, int batteryLife) : PersonalComputer(computerType, computerID, brand, model, price, coreCount, ram)
{
  this->screenSize = screenSize;
  this->batteryLife = batteryLife;
}

Laptop::Laptop(const Laptop& other) : PersonalComputer(other)
{
  this->copy(other);
}

Laptop& Laptop::operator=(const Laptop& other)
{
  if(this != &other)
  {
    PersonalComputer::operator=(other);

    this->destroy();
    this->copy(other);
  }

  return *this;
}

Laptop::~Laptop()
{
  this->destroy();
}

double Laptop::getScreenSize()
{
  return this->screenSize;
}

int Laptop::getBatteryLife()
{
  return this->batteryLife;
}

ostream& operator<<(ostream& os, const Laptop& laptop)
{
  os << (PersonalComputer) laptop << endl;
  os << "Screen size: " << laptop.screenSize << " inches" << endl;
  os << "Battery life: " << laptop.batteryLife << " hrs";

  return os;
}
