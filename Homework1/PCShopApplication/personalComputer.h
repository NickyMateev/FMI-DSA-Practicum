#pragma once
#include "computer.h"

class PersonalComputer : public Computer
{
  private:
    int coreCount;
    int ram;

    void copy(const PersonalComputer& other);
    void destroy();
  public:
    PersonalComputer(char, int, string, string, double, int, int);
    PersonalComputer(const PersonalComputer& other);
    PersonalComputer& operator=(const PersonalComputer& other);
    virtual ~PersonalComputer();

    int getCoreCount();
    int getRAM();

    friend ostream& operator<<(ostream& os, const PersonalComputer& pc);
};
