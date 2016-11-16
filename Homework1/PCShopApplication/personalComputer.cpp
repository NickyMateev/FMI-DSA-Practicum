#include "personalComputer.h"

void PersonalComputer::copy(const PersonalComputer& other)
{
  this->coreCount = other.coreCount;
  this->ram = other.ram;
}

void PersonalComputer::destroy()
{
  // nothing to destroy...
}

PersonalComputer::PersonalComputer(char computerType, int computerID, string brand, string model, double price, int coreCount, int ram) : Computer(computerType, computerID, brand, model, price)
{
  this->coreCount = coreCount;
  this->ram = ram;
}

PersonalComputer::PersonalComputer(const PersonalComputer& other) : Computer(other)
{
  this->copy(other);
}

PersonalComputer& PersonalComputer::operator=(const PersonalComputer& other)
{
  if(this != &other)
  {
    Computer::operator=(other);

    this->destroy();
    this->copy(other);
  }

  return *this;
}

PersonalComputer::~PersonalComputer()
{
  this->destroy();
}

int PersonalComputer::getCoreCount()
{
  return this->coreCount;
}

int PersonalComputer::getRAM()
{
  return this->ram;
}

ostream& operator<<(ostream& os, const PersonalComputer& pc)
{
  os << (Computer) pc << endl;
  os << "Core count: " << pc.coreCount << endl;
  os << "RAM: " << pc.ram;

  return os;
}
