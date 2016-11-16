#include "smartphone.h"

void Smartphone::copy(const Smartphone& other)
{
  this->backCameraResolution = other.backCameraResolution;
  this->frontCameraResolution = other.frontCameraResolution;
  this->simCardCount = other.simCardCount;
}

void Smartphone::destroy()
{
  // nothing to destroy...
}

Smartphone::Smartphone(char computerType, int computerID, string brand, string model, double price, double backCameraResolution, double frontCameraResolution, int simCardCount) : Computer(computerType, computerID, brand, model, price)
{
  this->backCameraResolution = backCameraResolution;
  this->frontCameraResolution = frontCameraResolution;
  this->simCardCount = simCardCount;
}

Smartphone::Smartphone(const Smartphone& other) : Computer(other)
{
  this->copy(other);
}

Smartphone& Smartphone::operator=(const Smartphone& other)
{
  if(this != &other)
  {
    Computer::operator=(other);

    this->destroy();
    this->copy(other);
  }

  return *this;
}

Smartphone::~Smartphone()
{
  this->destroy();
}

double Smartphone::getBackCameraResolution()
{
  return this->backCameraResolution;
}

double Smartphone::getFrontCameraResolution()
{
  return this->frontCameraResolution;
}

int Smartphone::getSIMCardCount()
{
  return this->simCardCount;
}

ostream& operator<<(ostream& os, const Smartphone& smartphone)
{
  os << (Computer) smartphone << endl;
  os << "Back camera resolution: " << smartphone.backCameraResolution << " MP" << endl;
  os << "Front camera resolution: " << smartphone.frontCameraResolution << " MP" << endl;
  os << "Supported SIM cards: " << smartphone.simCardCount;

  return os;
}
