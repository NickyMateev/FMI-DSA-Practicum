#pragma once
#include "computer.h"

class Smartphone : public Computer
{
  private:
    double backCameraResolution;
    double frontCameraResolution;
    int simCardCount;

    void copy(const Smartphone& other);
    void destroy();
  public:
    Smartphone(char, int, string, string, double, double, double, int);
    Smartphone(const Smartphone& other);
    Smartphone& operator=(const Smartphone& other);
    virtual ~Smartphone();

    double getBackCameraResolution();
    double getFrontCameraResolution();
    int getSIMCardCount();

    friend ostream& operator<<(ostream& os, const Smartphone& smartphone);
};
