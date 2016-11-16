#pragma once
#include <iostream>
#include <string>
using namespace std;

class Computer
{
  private:
    char computerType;
    int computerID;
    string brand;
    string model;
    double price;

    void copy(const Computer& other);
    void destroy();
  public:
    Computer(char, int, string, string, double);
    Computer(const Computer& other);
    Computer& operator=(const Computer& other);
    virtual ~Computer();

    char getComputerType() const;
    int getComputerID() const;
    string getBrand() const;
    string getModel() const;
    double getPrice() const;

    friend ostream& operator<<(ostream& os, const Computer& computer);
};
