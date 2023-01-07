#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "bankaccount.h"

class Bank {
  public:
    //default constructor is never used. more efficient to throw info into constructor rather than use Set functions
    Bank() {
      bankName = "N/A";
      bankAddress = "N/A";
      bankWorkingHours = "N/A";
    }
    Bank(string name, string address, string hours) {
      bankName = name;
      bankAddress = address;
      bankWorkingHours = hours;
    }

    //Getter functions to access bank info
    //Setter functions are not needed because they are initalized in the constructor
    string GetBankName() const { return bankName; }
    string GetBankAddress() const { return bankAddress; }
    string GetWorkingHours() const { return bankWorkingHours; }
    
    void SetBankName(string name) { bankName = name; }
    void SetBankAddress(string address) { bankAddress = address; }
    void SetWorkingHours(string hours) { bankWorkingHours = hours; }

    void BankMenu();
    void PrintBriefInfo();
    void PrintDetailedInfo();
  private:
    string bankName;
    string bankAddress;
    string bankWorkingHours;
    
    //stores bankAccounts in vector in main
    vector<BankAccount> bankAccount;

    // numberBankAccounts may decrease. This prevents repeats in BNK account number
    int numberBankAccounts = 0;
};

#endif