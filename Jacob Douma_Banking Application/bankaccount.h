#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "savingsubaccount.h"
#include "checkingsubaccount.h"
#include "subaccount.h"

class BankAccount {
  public:
    BankAccount() {
      //Default constructor is never used because it would interfere with numBankAccounts and account info. less efficient to set info with Set functions
      firstName = "N/A";
      lastName = "N/A";
      SSN = "N/A";
    }
    BankAccount(string first, string last, string ssn, int temp) {
      firstName = first;
      lastName = last;
      SSN = ssn;
      string number = "BNK";
      int baseNum = 10000;

      //This append function appends digits to the string
      number.append(to_string(baseNum + temp));
      bankAccountNumber = number;
    }

    //Bank Account menu
    void BankAccountMenu();

    //Getter functions to access bank info
    //Setter functions are not needed because they are initalized in the constructor
    string GetFirstName() { return firstName; }
    string GetLastName() { return lastName; }
    string GetSSN() { return SSN; }
    string GetBankAccountNumber() { return bankAccountNumber; }

    void SetFirstName(string firstName) { this-> firstName = firstName; }
    void SetLastName(string lastName) { this-> lastName = lastName; }
    void SetSSN(string ssn) { SSN = ssn; }

    //having these accounts public creates a connection that can be inherited by bankAccount. This allows their information to be accessed
    vector<SavingSubAccount> savingSubAccount;
    vector<CheckingSubAccount> checkingSubAccount;
  private:
    string bankAccountNumber;
    string firstName;
    string lastName;
    string SSN;

    // numCheckingSubAccounts may decrease. This prevents repeats in CHK account number
    int numberCheckingAccounts = 0;

    // numSavingSubAccounts may decrease. This prevents repeats in SAV account number
    int numberSavingAccounts = 0;
};

#endif