#include "computer.h"

void Computer::copy(const Computer& other)
{
  this->computerType = other.computerType;
  this->computerID = other.computerID;
  this->brand = other.brand;
  this->model = other.model;
  this->price = other.price;
}

void Computer::destroy()
{
  // nothing to destroy...
}

Computer::Computer(char computerType, int computerId, string brand, string model, double price)
{
  this->computerType = computerType;
  this->computerID = computerID;
  this->brand = brand;
  this->model = model;
  this->price = price;
}

Computer::Computer(const Computer& other)
{
  this->copy(other);
}

Computer& Computer::operator=(const Computer& other)
{
  if(this != &other)
  {
    this->destroy();
    this->copy(other);
  }

  return *this;
}

Computer::~Computer()
{
  this->destroy();
}

char Computer::getComputerType() const
{
  return this->computerType;
}

int Computer::getComputerID() const
{
  return this->computerID;
}

string Computer::getBrand() const
{
  return this->brand;
}

string Computer::getModel() const
{
  return this->model;
}

double Computer::getPrice() const
{
  return this->price;
}

ostream& operator<<(ostream& os, const Computer& computer)
{
  os << "Computer type: " << computer.computerType << endl;
  os << "ComputerID: " << computer.computerID << endl;
  os << "Brand: " << computer.brand << endl;
  os << "Model: " << computer.model << endl;
  os << "Price: " << computer.price;

  return os;
}
