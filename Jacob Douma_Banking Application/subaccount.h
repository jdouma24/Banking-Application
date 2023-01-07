#ifndef SUBACCOUNT_H
#define SUBACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//this class has functions and data that both saving and checking accounts inherit
class SubAccount {
  public:
    SubAccount() { balance = 0; }
    void DepositAmount(int amount) {
        balance += amount;
        cout << " | Deposit was successful." << endl;
        cout << " | The current balance is " << balance << "." << endl << endl;
    }
    void WithdrawalAmount(int amount) {
      //cannot withdrawal funds that exceed balance
      if (balance - amount < 0) {
        cout << " | Withdrawal was unsuccessful. Exceeds account balance of " << balance << endl << endl;
      }
      else {
        balance -= amount;
        cout << " | Withdrawal was successful." << endl;
        cout << " | The current balance is " << balance << "." << endl << endl;
      }
    }
    int GetBalance() { return balance; }
  private:
    int balance = 0;
};

#endif