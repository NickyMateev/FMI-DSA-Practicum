#pragma once
#include "laptop.h" // this will include personalComputer.h and computer.h automatically
#include "smartphone.h" // this will try to include computer.h automatically as well
#include <string>
#include <vector>

class PCShop
{
  private:
    // private constants:
    static const char PC_CONSTANT = 'P';
    static const char LAPTOP_CONSTANT = 'L';
    static const char SMARTPHONE_CONSTANT = 'S';

    vector<PersonalComputer> personalComputers;
    vector<Laptop> laptops;
    vector<Smartphone> smartphones;

    void constructPC(string);
    void constructLaptop(string);
    void constructSmartphone(string);

    void getProductsFromFile(string path);
  public:
    PCShop(string productsPath);

    // options[1-5]:
    void findComputersByType(char computerType);
    void findComputersByBrand(string brand);
    void findComputersByBrandModel(string brand, string model);
    void findComputersByTypeMaxPrice(char computerType, double maxPrice);
    void findComputersByTypeBrandMaxPrice(char computerType, string brand, double maxPrice);

    // destination file public variables
    string OPTION1_PATH = "option1.txt";
    string OPTION2_PATH = "option2.txt";
    string OPTION3_PATH = "option3.txt";
    string OPTION4_PATH = "option4.txt";
    string OPTION5_PATH = "option5.txt";
};
