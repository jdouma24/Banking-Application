#ifndef SAVINGSUBACCOUNT_H
#define SAVINGSUBACCOUNT_H

#include "subaccount.h"

class SavingSubAccount : public SubAccount {
  public:
    SavingSubAccount() {
      //Default constructor is never used because it would interfere with numSavingAccounts
      savingAccountNumber = "N/A";
    }
    SavingSubAccount(int initBalance, int temp) {
      savingAccount.DepositAmount(initBalance);
      string accountNum = "SAV";

      //This append function appends digits to the string
      accountNum.append(to_string(1000 + temp));
      savingAccountNumber = accountNum;
      ++numSavingSubAccounts;
    }
    //Saving Account menu
    void ModifySavingAccount();

    //Getter functions to access bank info
    //Setter functions are not needed because they are initalized in the constructor
    int GetSavingBalance() { return savingAccount.GetBalance(); }
    string GetSavingAccountNumber() { return savingAccountNumber; }

    int GetNumSavingSubAccounts() { return numSavingSubAccounts; }
    void DelNumSavingSubAccounts() { numSavingSubAccounts -= 1; }
    void AddNumSavingSubAccounts() { numSavingSubAccounts += 1; }
  private:
    string savingAccountNumber;
    int numSavingSubAccounts = 0;
    SubAccount savingAccount;
};

#endif