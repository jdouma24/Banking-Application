#include <iostream>
#include "bank.h"
using namespace std;

//Jacob Douma

int main() {
  string name;
  string address;
  string hours;

  cout << "Enter the name of the bank: ";
  getline(cin, name);
      
  cout << endl << "Enter the address of the bank: ";
  getline(cin, address);

  cout << endl << "Enter the working hours: ";
  getline(cin, hours);
  cout << endl << endl;

  Bank bank(name, address, hours);

  bank.BankMenu();

  return 0;
}