#pragma once
#include "personalComputer.h"

class Laptop : public PersonalComputer
{
  private:
    double screenSize;
    int batteryLife;

    void copy(const Laptop& other);
    void destroy();
  public:
    Laptop(char, int, string, string, double, int, int, double, int);
    Laptop(const Laptop& other);
    Laptop& operator=(const Laptop& other);
    virtual ~Laptop();

    double getScreenSize();
    int getBatteryLife();

    friend ostream& operator<<(ostream& os, const Laptop& laptop);
};
