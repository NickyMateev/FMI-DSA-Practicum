#include <iostream>
#include <sstream>
#include "pcShop.h"
using namespace std;

const string PRODUCTS_PATH = "products.txt";

void runApplication();
void printHelp();

int main()
{
  runApplication();

  return 0;
}

void runApplication()
{
  PCShop shop(PRODUCTS_PATH);

  string userInput, userInput2;
  short numericInput;
  char characterInput;
  double priceInput;

  bool isRunning = true;
  while(isRunning)
  {

    printHelp();
    try
    {
      cout << "Input: ";
      getline(cin, userInput);
      stringstream(userInput) >> numericInput;
    }
    catch(...)
    {
      cout << "Invalid input! Try again.\n";
      continue;
    }

    switch(numericInput)
    {
      case 1: cout << "Computer type: ";
              getline(cin, userInput);
              stringstream(userInput) >> characterInput;
              shop.findComputersByType(characterInput);
              cout << "Results saved in: " << shop.OPTION1_PATH << endl;
              break;
      case 2: cout << "Brand: ";
              getline(cin, userInput);
              shop.findComputersByBrand(userInput);
              cout << "Results saved in: " << shop.OPTION2_PATH << endl;
              break;
      case 3: cout << "Brand: ";
              getline(cin, userInput);
              cout << "Model: ";
              getline(cin, userInput2);
              shop.findComputersByBrandModel(userInput, userInput2);
              cout << "Results saved in: " << shop.OPTION3_PATH << endl;
              break;
      case 4: cout << "Computer type: ";
              getline(cin, userInput);
              stringstream(userInput) >> characterInput;
              cout << "Max price: ";
              getline(cin, userInput);
              stringstream(userInput) >> priceInput;
              shop.findComputersByTypeMaxPrice(characterInput, priceInput);
              cout << "Results saved in: " << shop.OPTION4_PATH << endl;
              break;
      case 5: cout << "Computer type: ";
              getline(cin, userInput);
              stringstream(userInput) >> characterInput;
              cout << "Brand: ";
              getline(cin, userInput);
              cout << "Max price: ";
              getline(cin, userInput2);
              stringstream(userInput2) >> priceInput;
              shop.findComputersByTypeBrandMaxPrice(characterInput, userInput, priceInput);
              cout << "Results saved in: " << shop.OPTION5_PATH << endl;
              break;
      case 0: isRunning = false;
              break;
      default: cout << "Invalid selection! Try again.\n";
               break;
    }

  }
}

void printHelp()
{
  cout << "Select an option[1-5]:\n";
  cout << "1) Get computers by type\n";
  cout << "2) Get computers by brand\n";
  cout << "3) Get computers by brand and model\n";
  cout << "4) Get computers by type and a maximum price\n";
  cout << "5) Get computers by type, brand and a maximum price\n";
  cout << "0) Exit program\n\n\n";
}
