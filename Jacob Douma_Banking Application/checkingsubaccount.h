#ifndef CHECKINGSUBACCOUNT_H
#define CHECKINGSUBACCOUNT_H

#include "subaccount.h"

class CheckingSubAccount : public SubAccount {
  public:
    CheckingSubAccount() {
      //Default constructor is never used because it would interfere with numCheckingAccounts
      checkingAccountNumber = "N/A";
      checkingMaxCap = 0;
      checkingLocked = false;
    }
    CheckingSubAccount(int initBalance, int maxCap, char initState, int temp) {
      checkingAccount.DepositAmount(initBalance);
      checkingMaxCap = maxCap;
      string accountNum = "CHK";

      //This append function appends digits to the string
      accountNum.append(to_string(6000 + temp));
      checkingAccountNumber = accountNum;
      ++numCheckingSubAccounts;

      //Use char to determine boolean value for locked status
      if (initState == 'L') { checkingLocked = true; }
      else { checkingLocked = false; }
    }
    
    void DepositCheckingAmount(int amount) {
      //cannot access if account is locked
      if (checkingLocked == true) {
        cout << " | The account is currently locked!" << endl;
        cout << " | Deposit was unsuccessful." << endl << endl;
      }
      //cannot deposit if exceeds maximum capacity
      else if (checkingAccount.GetBalance() + amount > checkingMaxCap) {
        cout << " | The deposit was unsuccessful. Exceeds maximum capacity of " << checkingMaxCap << endl << endl;
      }
      else {
        //use Deposit function in subaccount.h
        this->checkingAccount.DepositAmount(amount);
      }
    }

    void WithdrawalCheckingAmount(int amount) {
      //cannot access account if locked
      if (checkingLocked == true) {
        cout << " | The account is currently locked!" << endl;
        cout << " | Withdrawal was unsuccessful." << endl << endl;
      }
      else {
        //Use Deposit function in subaccount.h
        this->checkingAccount.WithdrawalAmount(amount);
      }
    }
    
    //Checking Account menu
    void ModifyCheckingAccount();

    //Getter functions to access bank info
    //Setter functions are not needed because they are initalized in the constructor
    int GetCheckingBalance() { return checkingAccount.GetBalance(); }
    int GetMaxCap() { return checkingMaxCap; }
    string GetCheckingAccountNumber() { return checkingAccountNumber; }

    int GetNumCheckingSubAccounts() { return numCheckingSubAccounts; }
    void DelNumCheckingSubAccounts() { numCheckingSubAccounts -= 1; }
    void AddNumCheckingSubAccounts() { numCheckingSubAccounts += 1; }

    void ChangeMaxCapacity(int amount) { checkingMaxCap = amount; }

    void ChangeAccountStatus(bool locked) {
      if (locked == true) {
        checkingLocked = true;
      }
      else {
        checkingLocked = false;
      }
    }
  private:
    string checkingAccountNumber;
    int checkingMaxCap = 0;
    int numCheckingSubAccounts = 0;
    bool checkingLocked;
    SubAccount checkingAccount;
};

#endif