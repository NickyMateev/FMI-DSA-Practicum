#include "pcShop.h"
#include <sstream>
#include <fstream>


void PCShop::constructPC(string str)
{
  char computerType;
  int computerID, coreCount, ram;
  string brand, model;
  double price;

  stringstream(str) >> computerType >> computerID >> brand >> model >> price >> coreCount >> ram;

  this->personalComputers.push_back(PersonalComputer(computerType, computerID, brand, model, price, coreCount, ram));
}

void PCShop::constructLaptop(string str)
{
  char computerType;
  int computerID, coreCount, ram, batteryHours;
  string brand, model;
  double price, screenSize;

  stringstream(str) >> computerType >> computerID >> brand >> model >> price >> coreCount >> ram >> screenSize >> batteryHours;

  this->laptops.push_back(Laptop(computerType, computerID, brand, model, price, coreCount, ram, screenSize, batteryHours));
}


void PCShop::constructSmartphone(string str)
{
  char computerType;
  int computerID, simCardCount;
  string brand, model;
  double price, backCameraResolution, frontCameraResolution;

  stringstream(str) >> computerType >> computerID >> brand >> model >> price >> backCameraResolution >> frontCameraResolution >> simCardCount;

  this->smartphones.push_back(Smartphone(computerType, computerID, brand, model, price, backCameraResolution, frontCameraResolution, simCardCount));
}

void PCShop::getProductsFromFile(string path)
{
  ifstream productsFile(path);

  if(productsFile.is_open())
  {
    string line;
    while(getline(productsFile, line))
    {
      if(line[0] == PC_CONSTANT)
      {
        this->constructPC(line);
      }
      else if(line[0] == LAPTOP_CONSTANT)
      {
        this->constructLaptop(line);
      }
      else if (line[0] == SMARTPHONE_CONSTANT)
      {
        this->constructSmartphone(line);
      }

    }

    productsFile.close();
  }

}

PCShop::PCShop(string productsPath)
{
  this->getProductsFromFile(productsPath);
}

void PCShop::findComputersByType(char computerType)
{
  ofstream destinationFile(this->OPTION1_PATH);

  if(destinationFile.is_open())
  {
      if(computerType == PC_CONSTANT)
      {
        for(int i = 0; i < personalComputers.size(); i++)
        {
          destinationFile << personalComputers[i] << endl;
          destinationFile << endl;
        }
      }
      else if(computerType == LAPTOP_CONSTANT)
      {
        for(int i = 0; i < laptops.size(); i++)
        {
          destinationFile << laptops[i] << endl;
          destinationFile << endl;
        }
      }
      else if(computerType == SMARTPHONE_CONSTANT)
      {
        for(int i = 0; i < smartphones.size(); i++)
        {
          destinationFile << smartphones[i] << endl;
          destinationFile << endl;
        }
      }

      destinationFile.close();
  }
}

void PCShop::findComputersByBrand(string brand)
{
  ofstream destinationFile(this->OPTION2_PATH);

  if(destinationFile.is_open())
  {
    for(int i = 0; i < personalComputers.size(); i++)
    {
      if(personalComputers[i].getBrand().compare(brand) == 0)
      {
        destinationFile << personalComputers[i] << endl;
        destinationFile << endl;
      }
    }

    for(int i = 0; i < laptops.size(); i++)
    {
      if(laptops[i].getBrand().compare(brand) == 0)
      {
        destinationFile << laptops[i] << endl;
        destinationFile << endl;
      }
    }

    for(int i = 0; i < smartphones.size(); i++)
    {
      if(smartphones[i].getBrand().compare(brand) == 0)
      {
        destinationFile << smartphones[i] << endl;
        destinationFile << endl;
      }
    }

    destinationFile.close();
  }
}

void PCShop::findComputersByBrandModel(string brand, string model)
{
  ofstream destinationFile(this->OPTION3_PATH);

  if(destinationFile.is_open())
  {
    for(int i = 0; i < personalComputers.size(); i++)
    {
      if((personalComputers[i].getBrand().compare(brand) == 0) && (personalComputers[i].getModel().compare(model) == 0))
      {
        destinationFile << personalComputers[i] << endl;
        destinationFile << endl;
      }
    }

    for(int i = 0; i < laptops.size(); i++)
    {
      if((laptops[i].getBrand().compare(brand) == 0) && (laptops[i].getModel().compare(model) == 0))
      {
        destinationFile << laptops[i] << endl;
        destinationFile << endl;
      }
    }

    for(int i = 0; i < smartphones.size(); i++)
    {
      if((smartphones[i].getBrand().compare(brand) == 0) && (smartphones[i].getModel().compare(model) == 0))
      {
        destinationFile << smartphones[i] << endl;
        destinationFile << endl;
      }
    }

    destinationFile.close();
  }
}

void PCShop::findComputersByTypeMaxPrice(char computerType, double maxPrice)
{
  ofstream destinationFile(this->OPTION4_PATH);

  if(destinationFile.is_open())
  {
      if(computerType == PC_CONSTANT)
      {
        for(int i = 0; i < personalComputers.size(); i++)
        {
          if(personalComputers[i].getPrice() <= maxPrice)
          {
            destinationFile << personalComputers[i] << endl;
            destinationFile << endl;
          }
        }
      }
      else if(computerType == LAPTOP_CONSTANT)
      {
        for(int i = 0; i < laptops.size(); i++)
        {
          if(laptops[i].getPrice() <= maxPrice)
          {
            destinationFile << laptops[i] << endl;
            destinationFile << endl;
          }
        }
      }
      else if(computerType == SMARTPHONE_CONSTANT)
      {
        for(int i = 0; i < smartphones.size(); i++)
        {
          if(smartphones[i].getPrice() <= maxPrice)
          {
            destinationFile << smartphones[i] << endl;
            destinationFile << endl;
          }
        }
      }

      destinationFile.close();
  }

}

void PCShop::findComputersByTypeBrandMaxPrice(char computerType, string brand, double maxPrice)
{
  ofstream destinationFile(this->OPTION5_PATH);

  if(destinationFile.is_open())
  {
      if(computerType == PC_CONSTANT)
      {
        for(int i = 0; i < personalComputers.size(); i++)
        {
          if((personalComputers[i].getPrice() <= maxPrice) && (personalComputers[i].getBrand().compare(brand) == 0))
          {
            destinationFile << personalComputers[i] << endl;
            destinationFile << endl;
          }
        }
      }
      else if(computerType == LAPTOP_CONSTANT)
      {
        for(int i = 0; i < laptops.size(); i++)
        {
          if((laptops[i].getPrice() <= maxPrice) && (laptops[i].getBrand().compare(brand) == 0))
          {
            destinationFile << laptops[i] << endl;
            destinationFile << endl;
          }
        }
      }
      else if(computerType == SMARTPHONE_CONSTANT)
      {
        for(int i = 0; i < smartphones.size(); i++)
        {
          if((smartphones[i].getPrice() <= maxPrice) && (smartphones[i].getBrand().compare(brand) == 0))
          {
            destinationFile << smartphones[i] << endl;
            destinationFile << endl;
          }
        }
      }

      destinationFile.close();
  }
}

