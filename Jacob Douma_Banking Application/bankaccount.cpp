#include "bankaccount.h"

void BankAccount::BankAccountMenu() {
  char selection = '?';
      
  while ((selection != 'X') || (selection != 'x')) {
    cout << "Eligible services for Bank-Account " << this->GetBankAccountNumber() << endl;
    cout << "   S -- Open Saving Sub-Account" << endl;
    cout << "   C -- Open Checking Sub-Account" << endl;
    cout << "   M -- Modify Sub-Account" << endl;
    cout << "   E -- Close a Sub-Account" << endl;
    cout << "   D -- Detailed Bank Account Info Sorted Based on Balances of Sub-Accounts" << endl;
    cout << "   B -- Brief Bank Account Info" << endl;
    cout << "   X -- Exit" << endl;
    cout << "Please enter your selection:";

    cin >> selection;
    cout << endl << endl;

    if ((selection == 'S') || (selection == 's')) {
      int initBalance;

      cout << "Enter the inital balance: ";
      cin >> initBalance;
      cout << endl << endl;

      //use vector to store multple accounts
      if (this->savingSubAccount.size() == 0) {
        initBalance += 100;

        SavingSubAccount savingAccount = SavingSubAccount(initBalance, numberSavingAccounts);

        this->savingSubAccount.push_back(savingAccount);

        //first saving account created gets a $100 bonus
        cout << "An initial $100 was desposited to sub-account " << this->savingSubAccount.back().GetSavingAccountNumber() << " for being the first saving account opened!" << endl << endl;
      }
      else {
        SavingSubAccount savingAccount = SavingSubAccount(initBalance, numberSavingAccounts);

        this->savingSubAccount.push_back(savingAccount);
      }

      ++numberSavingAccounts;

      cout << " | A new Saving Sub-Account " << this->savingSubAccount.back().GetSavingAccountNumber() << " was successfully created." << endl << endl;

      this->savingSubAccount.back().ModifySavingAccount();
    }

    else if ((selection == 'C') || (selection == 'c')) {
      int initBalance;
      int maxCap;
      char initState;
          
      cout << "Enter the inital balance: ";
      cin >> initBalance;
      cout << endl;

      cout << "Enter the desired maximum capacity: ";
      cin >> maxCap;
      cout << endl;

      cout << "Define inital state: (L - Locked, Otherwise - Unlocked)";
      cin >> initState;
      cout << endl << endl;

      //use vector to store multple accounts
      CheckingSubAccount checkingAccount(initBalance, maxCap, initState, numberCheckingAccounts);

      this->checkingSubAccount.push_back(checkingAccount);

      ++numberCheckingAccounts;

      cout << " | A new Checking Sub-Account " << this->checkingSubAccount.back().GetCheckingAccountNumber() << " was successfully created." << endl << endl;

      this->checkingSubAccount.back().ModifyCheckingAccount();
    }

    else if ((selection == 'M') || (selection == 'm')) {
      if (this->savingSubAccount.size() == 0 && this->checkingSubAccount.size() == 0) {
        cout << " | There are no sub-accounts to be modified" << endl << endl;
      }
      else {
        string accountNumber;
        cout << " Enter the sub-account number to modify (enter 'x' to exit: " << endl;

        unsigned int i;
        for (i = 0; i < checkingSubAccount.size(); ++i) {
          cout << checkingSubAccount.at(i).GetCheckingAccountNumber() << endl;
        }
        for (i = 0; i < savingSubAccount.size(); ++i) {
          cout << savingSubAccount.at(i).GetSavingAccountNumber() << endl;
        }

        cin >> accountNumber;
        cout << endl << endl;
        bool worked = false;

        while (worked == false) {
          if (accountNumber == "X" || accountNumber == "x") {
            break;
          }
        //Read each vector element until account number matches
        //First letter C verifies CHK account
        if (accountNumber.at(0) == 'C') {
          for (i = 0; i < this->checkingSubAccount.size(); ++i) {
            if (this->checkingSubAccount.at(i).GetCheckingAccountNumber() == accountNumber) {
              this->checkingSubAccount.at(i).ModifyCheckingAccount();
              worked = true;
              break;
            }
          }
        }

        //First letter S verifies SAV account
        if (accountNumber.at(0) == 'S') {
          for (i = 0; i < savingSubAccount.size(); ++i) {
            if (this->savingSubAccount.at(i).GetSavingAccountNumber() == accountNumber) {
              this->savingSubAccount.at(i).ModifySavingAccount();
              worked = true;
              break;
            }
          }
        }
        cout << "Please enter a valid account number to modify:" << endl;

        unsigned int i;
        for (i = 0; i < checkingSubAccount.size(); ++i) {
          cout << checkingSubAccount.at(i).GetCheckingAccountNumber() << endl;
        }
        for (i = 0; i < savingSubAccount.size(); ++i) {
          cout << savingSubAccount.at(i).GetSavingAccountNumber() << endl;
        }

        cin >> accountNumber;
        cout << endl << endl;
        }
      }
    }

    else if ((selection == 'E') || (selection == 'e')) {
      if (this->savingSubAccount.size() == 0 && this->checkingSubAccount.size() == 0) {
        cout << " | There are no sub-accounts to be closed" << endl << endl;
      }
      else {
        string accountNum;

        cout << "Enter the sub-account number to be closed (enter 'X' to exit): " << endl;

        unsigned int i;
        for (i = 0; i < checkingSubAccount.size(); ++i) {
          cout << checkingSubAccount.at(i).GetCheckingAccountNumber() << endl;
        }
        for (i = 0; i < savingSubAccount.size(); ++i) {
          cout << savingSubAccount.at(i).GetSavingAccountNumber() << endl;
        }
        cin >> accountNum;
        cout << endl << endl;

        bool worked = false;

        while (worked == false) {
          if (accountNum == "x" || accountNum == "X") {
            break;
          }

        //Read each vector element until account number matches
        //First letter C verifies CHK account
        if (accountNum.at(0) == 'C') {
          unsigned int i;
          for (i = 0; i < checkingSubAccount.size(); ++i) {
            if (this->checkingSubAccount.at(i).GetCheckingAccountNumber() == accountNum) {
              this->checkingSubAccount.at(i).DelNumCheckingSubAccounts();
              cout << " | Sub-account " << this->checkingSubAccount.at(i).GetCheckingAccountNumber() << " was successfully closed." << endl << endl;
              this->checkingSubAccount.erase(checkingSubAccount.begin() + i);
            }
          }
        }

        //First letter S verifies SAV account
        else if (accountNum.at(0) == 'S') {
          unsigned int i;
          for (i = 0; i < savingSubAccount.size(); ++i) {
            if (this->savingSubAccount.at(i).GetSavingAccountNumber() == accountNum) {
              this->savingSubAccount.at(i).DelNumSavingSubAccounts();
              cout << " | Sub-account " << this->savingSubAccount.at(i).GetSavingAccountNumber() << " was successfully closed." << endl << endl;
              this->savingSubAccount.erase(savingSubAccount.begin() + 1);
            }
          }
        }
        cout << "Please enter a valid account number to delete: (enter 'X' to exit): " << endl;

        unsigned int i;
        for (i = 0; i < checkingSubAccount.size(); ++i) {
          cout << checkingSubAccount.at(i).GetCheckingAccountNumber() << endl;
        }
        for (i = 0; i < savingSubAccount.size(); ++i) {
          cout << savingSubAccount.at(i).GetSavingAccountNumber() << endl;
        }
        cin >> accountNum;
        cout << endl << endl;
      }
      }
    }

    else if ((selection == 'D') || (selection == 'd')) {
      if (this->savingSubAccount.size() == 0 && this->checkingSubAccount.size() == 0) {
        cout << " | There are no sub-accounts to be detailed" << endl << endl;
      }
      else {
        string subAccountNumber;

        cout << " | Sub-account number (enter 'X' to exit): " << endl;

        unsigned int i;
        for (i = 0; i < checkingSubAccount.size(); ++i) {
          cout << checkingSubAccount.at(i).GetCheckingAccountNumber() << endl;
        }
        for (i = 0; i < savingSubAccount.size(); ++i) {
          cout << savingSubAccount.at(i).GetSavingAccountNumber() << endl;
        }


        cin >> subAccountNumber;
        cout << endl << endl;

        bool worked = false;

        while (worked == false) {

          if (subAccountNumber == "x" || subAccountNumber == "X") {
            break;
          }
      
        //Outputs each sub-account and balance
        //First letter C verifies CHK account
        if (subAccountNumber.at(0) == 'C') {
          for (i = 0; i < this->checkingSubAccount.size(); ++i) {
            if (this->checkingSubAccount.at(i).GetCheckingAccountNumber() == subAccountNumber) {
              cout << " | Sub-account number: " << this->checkingSubAccount.at(i).GetCheckingAccountNumber() << endl;
              cout << " | Balance: " << this->checkingSubAccount.at(i).GetCheckingBalance() << endl << endl;
            }
          }
        }

        //First letter S verifies SAV account
        if (subAccountNumber.at(0) == 'S') {
          for (i = 0; i < this->savingSubAccount.size(); ++i) {
            if (this->savingSubAccount.at(i).GetSavingAccountNumber() == subAccountNumber) {
              cout << " | Sub-account number: " << savingSubAccount.at(i).GetSavingAccountNumber() << endl;
              cout << " | Balance: " << this->savingSubAccount.at(i).GetSavingBalance() << endl << endl;
            }
          }
        }
        cout << "Please enter a valid account number to detail (enter 'X' to exit):" << endl;

        unsigned int i;
        for (i = 0; i < this->checkingSubAccount.size(); ++i) {
          cout << checkingSubAccount.at(i).GetCheckingAccountNumber() << endl;
        }
        for (i = 0; i < savingSubAccount.size(); ++i) {
          cout << savingSubAccount.at(i).GetSavingAccountNumber() << endl;
        }
        cin >> subAccountNumber;
        cout << endl << endl;
        }
      }
    }

    else if ((selection == 'B') || (selection == 'b')) {
      //receives balance of bank account by totaling amounts from all saving and checking accounts
      //Separate loops so not to access element out of range in one vector
      unsigned int i;
      int totalBalance = 0;
      for (i = 0; i < this->checkingSubAccount.size(); ++i) {
        totalBalance += this->checkingSubAccount.at(i).GetCheckingBalance();
      }
      for (i = 0; i < this->savingSubAccount.size(); ++i) {
        totalBalance += this->savingSubAccount.at(i).GetSavingBalance();
      }

      cout << " | Aggregated Balance of the bank account : " << this->GetBankAccountNumber() << " with " << this->checkingSubAccount.size() + this->savingSubAccount.size() << " Sub-Accounts is " << totalBalance << endl << endl;
    }

    else if ((selection == 'X') || (selection == 'x')) {
      cout << " | End of service for bank account " << this->GetBankAccountNumber() << endl << endl;
      break;
    }
    else {
          cout << "Please enter a valid selection" << endl << endl;
    }
  }
}