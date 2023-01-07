#include "bank.h"

void Bank::BankMenu() {
  char selection = '?';

  while ((selection != 'X') || (selection != 'x')) {
    cout << "Eligible services for " << this->GetBankName() << endl;
    cout << "   A -- Number of Bank-Accounts" << endl;
    cout << "   S -- Number of Saving-Accounts" << endl;
    cout << "   H -- Number of Checking-Accounts" << endl;
    cout << "   O -- Open Bank-Account" << endl;
    cout << "   C -- Close Bank-Account" << endl;
    cout << "   M -- Modify Bank-Account" << endl;
    cout << "   D -- Detailed Bank-Accounts" << endl;
    cout << "   B -- Briefed Bank-Accounts Info Sorted Based on Aggregated Balances" << endl;
    cout << "   X -- Exit" << endl;
    cout << "Please enter your selection:";

    cin >> selection;
    cout << endl;

    if ((selection == 'A') || (selection == 'a')) {
      cout << " | The number of Bank-Accounts is " << this->bankAccount.size() << endl << endl;
    }

    else if ((selection == 'S') || (selection == 's')) {
      //Loop to traverse total saving accounts across all bank accounts
      unsigned int i;
      int savingAccounts = 0;
      for (i = 0; i < this->bankAccount.size(); ++i) {
        savingAccounts += this->bankAccount.at(i).savingSubAccount.size();
      }
      cout << " | The number of Saving-Accounts is " << savingAccounts << endl << endl;
    }

    else if ((selection == 'H') || (selection == 'h')) {
      //Loop to traverse total checking accounts across all bank accounts
      unsigned int i;
      int checkingAccounts = 0;
      for (i = 0; i < this->bankAccount.size(); ++i) {
        checkingAccounts += this->bankAccount.at(i).checkingSubAccount.size();
      }
      cout << " | The number of Checking-Accounts is " << checkingAccounts << endl << endl;
    }

    else if ((selection == 'O') || (selection == 'o')) {
      string firstName;
      string lastName;
      string SSN;

      cout << "Enter the first name of the account holder: ";
      cin >> firstName;

      cout << endl << "Enter the last name of the account holder: ";
      cin >> lastName;

      cout << endl << "Enter the SSN of the account holder (with \"-\"): ";
      cin >> SSN;
      cout << endl << endl;

      //Ensure SSN is accurate with 11 digits (including '-')
      //only runs for loop to check for non-digit and '-' chars if size == 11
      //this saves time because no need to check if size != 11
      //Must run once before while loop to check initial input and verify isValid
      unsigned int i;
      bool isValid = false;
      if (SSN.size() == 11) {
        for (i = 0; i < 3; ++i) {
          if (!isdigit(SSN.at(i))) {
            isValid = false;
            break;
          }
          else {
            isValid = true;
          }
        }
      }

      if (isValid == true) {
        if (SSN.at(3) != '-' && SSN.at(6) != '-') {
          isValid = false;
          }
        if (!isdigit(SSN.at(4)) && !isdigit(SSN.at(5))) {
          isValid = false;
        }
        for (i = 7; i < 11; ++i) {
          if (!isdigit(SSN.at(i))) {
            isValid = false;
            break;
          }
          else {
            isValid = true;
          }
        }
      }
      
      while (isValid == false) {
        cout << "Please enter a valid 9 digit SSN (with \"-\"): ";
        cin >> SSN;
        cout << endl << endl;
        bool almostValid = false;

        if (SSN.size() == 11) {
          for (i = 0; i < 3; ++i) {
            if (!isdigit(SSN.at(i))) {
              isValid = false;
            }
            else {
              almostValid = true;
            }
          }
        }
        //use almostValid before all conditions are met to make isValid true
        if (almostValid == true) {
          if (SSN.at(3) != '-' && SSN.at(6) != '-') {
            isValid = false;
            }
          if (!isdigit(SSN.at(4)) && !isdigit(SSN.at(5))) {
            isValid = false;
            }
          for (i = 7; i < 11; ++i) {
            if (!isdigit(SSN.at(i))) {
              isValid = false;
              break;
            }
            else {
              isValid = true;
            }
          }
        }
      }

      cout << endl;

      //use vector to store multple accounts
      //numberBankAccounts used to increment BNK10000 for new accounts
      BankAccount userAccount = BankAccount(firstName, lastName, SSN, numberBankAccounts);
      this->bankAccount.push_back(userAccount);
      ++numberBankAccounts;

      cout << " | A new Bank Account "  << this->bankAccount.back().GetBankAccountNumber() << " was successfully created." << endl << endl;

      this->bankAccount.back().BankAccountMenu();
    }

    else if ((selection == 'C') || (selection == 'c')) {
      if (this->bankAccount.size() == 0) {
        cout << " | There are no bank accounts to be deleted" << endl << endl;
      }
      else {
        string temp;
        cout << "Enter the name of the account to delete (enter 'X' to exit): " << endl;

        //traverse vector to show account number available
        unsigned int i;
        for (i = 0; i < this->bankAccount.size(); ++i) {
          cout << bankAccount.at(i).GetBankAccountNumber() << endl;
        }
        cin >> temp;
        cout << endl << endl;

        bool found = false;
        while (found == false) {
          if (temp == "X" || temp == "x") {
            break;
          }
          //Read each vector element until account number matches
          unsigned int i;
          for (i = 0; i < this->bankAccount.size(); ++i) {
            if (this->bankAccount.at(i).GetBankAccountNumber() == temp) {
              cout << " | Bank Account " << this->bankAccount.at(i).GetBankAccountNumber() << " was successfully deleted." <<   endl << endl;
              this->bankAccount.erase(bankAccount.begin() + i);
              found = true;
              break;
            }
          }
          //traverse vector to show account number available
          cout << "Enter the name of the account to delete (enter 'X' to exit): " << endl;
          cin >> temp;
          cout << endl << endl;
        }
      }
    }

    else if ((selection == 'M') || (selection == 'm')) {
      if (this->bankAccount.size() == 0) {
        cout << " | There are no bank accounts to be modified" << endl << endl;
      }
      else {
        string accountNumber;
        cout << "Enter the bank account number to be modified (enter 'X' to exit): " << endl;

        //traverse vector to show account number available
        unsigned int i;
        for (i = 0; i < this->bankAccount.size(); ++i) {
          cout << bankAccount.at(i).GetBankAccountNumber() << endl;
        }
        
        cin >> accountNumber;
        bool found = false;

        while (found == false) {
          if (accountNumber == "X" || accountNumber == "x") {
            break;
          }
          //Read each vector element until account number matches
         unsigned int i;
          for (i = 0; i < this->bankAccount.size(); ++i) {
            if (this->bankAccount.at(i).GetBankAccountNumber() == accountNumber) {
              found = true;
              this->bankAccount.at(i).BankAccountMenu();
            }
          }
          cout << "Please enter a valid account number to modify (enter 'X' to exit):" << endl;

          //traverse vector to show account number available
          for (i = 0; i < this->bankAccount.size(); ++i) {
            cout << bankAccount.at(i).GetBankAccountNumber() << endl;
          }

          cin >> accountNumber;
          cout << endl << endl;
        }
      }
    }

    else if ((selection == 'D') || (selection == 'd')) {
      this->PrintDetailedInfo();
    }

    else if ((selection == 'B') || (selection == 'b')) {
      this->PrintBriefInfo();
    }

    else if ((selection == 'X') || (selection == 'x')) {
      cout << " | End of service for bank " << this->GetBankName() << endl << endl;
      break;
    }
    else {
      cout << "Please enter a valid selection" << endl << endl;
    }
  }
}

void Bank::PrintBriefInfo() {
  unsigned int j = 0;
  unsigned int i;
  
  //Balance of each separate bank account
  vector<int> balance(bankAccount.size());

  //Total balance of bank
  int totalBankBalance = 0;

  //loops to total balance for each bank account adding multiple sub-accounts
  //Each balance is stored separately in a vector corresponding to the total balance of the bank account
  //Separate loops so not to access element out of range in one vector because number of saving and checking accounts vary
  for (i = 0; i < this->bankAccount.size(); ++i) {
    for (j = 0; j < this->bankAccount.at(i).checkingSubAccount.size(); ++j) {
      balance.at(i) += this->bankAccount.at(i).checkingSubAccount.at(j).GetCheckingBalance();
    }
  }
  for (i = 0; i < this->bankAccount.size(); ++i) {
    for (j = 0; j < this->bankAccount.at(i).savingSubAccount.size(); ++j) {
      balance.at(i) += this->bankAccount.at(i).savingSubAccount.at(j).GetSavingBalance();
    }
  }
  
  //loop to get total balance of bank
  for (i = 0; i < this->bankAccount.size(); ++i) {
    totalBankBalance += balance.at(i);
  }

  cout << " | Bank Name: " << this->GetBankName() << endl;
  cout << " | Bank Address: " << this->GetBankAddress() << endl;
  cout << " | Bank Working Hours: " << this->GetWorkingHours() << endl;
  cout << " | Aggregated Balance: " << totalBankBalance << endl;
  cout << " | Consists of " << this->bankAccount.size() << " Bank-Accounts" << endl << endl;


  //Loop to traverse the bank accounts and balances in vector
  for (i = 0; i < this->bankAccount.size(); ++i) {
    cout << " | Aggregated Balance of the bank account: " << this->bankAccount.at(i).GetBankAccountNumber() << " with " << this->bankAccount.at(i).checkingSubAccount.size() + this->bankAccount.at(i).savingSubAccount.size() << " sub-accounts is " << balance.at(i) << endl << endl;
  }
}

void Bank::PrintDetailedInfo() {
  //Get total balance of bank
  int totalBankBalance = 0;
  unsigned int i;
  unsigned int j;
  unsigned int k;
  vector<int> balanced(this->bankAccount.size());

  //loops to total balance for each bank account adding multiple sub-accounts
  //Each balance is stored separately in a vector
  //Separate loops so not to access element out of range in one vector
  for (i = 0; i < this->bankAccount.size(); ++i) {
    for (j = 0; j < this->bankAccount.at(i).checkingSubAccount.size(); ++j) {
      balanced.at(i) += this->bankAccount.at(i).checkingSubAccount.at(j).GetCheckingBalance();
    }
  }
  for (i = 0; i < this->bankAccount.size(); ++i) {
    for (j = 0; j < this->bankAccount.at(i).savingSubAccount.size(); ++j) {
      balanced.at(i)  += this->bankAccount.at(i).savingSubAccount.at(j).GetSavingBalance();
    }
  }
  
  //loop to get total balance of bank
  for (i = 0; i < this->bankAccount.size(); ++i) {
    totalBankBalance += balanced.at(i);
  }

  cout << " | Bank Name: " << this->GetBankName() << endl;
  cout << " | Bank Address: " << this->GetBankAddress() << endl;
  cout << " | Bank Working Hours: " << this->GetWorkingHours() << endl;
  cout << " | Aggregated Balance: " << totalBankBalance << endl;
  cout << " | Consists of " << this->bankAccount.size() << " Bank-Accounts" << endl << endl;

  //For loop to get info for bank accounts from vector
  for (i = 0; i < this->bankAccount.size(); ++i) {
    cout << " | Bank Account Number: " << this->bankAccount.at(i).GetBankAccountNumber() << endl;
    cout << " | Account Holder Full Name: " << this->bankAccount.at(i).GetFirstName() << " " << this->bankAccount.at(i).GetLastName() << endl;
    cout << " | Account Holder SSN " << this->bankAccount.at(i).GetSSN() << endl;
    cout << " | Aggregated Balance: " << balanced[i] << endl;
    cout << " | Consists of " << this->bankAccount.at(i).checkingSubAccount.size() + this->bankAccount.at(i).savingSubAccount.size() << " Sub-Accounts" << endl << endl;

    //Nested for loops to get info from subAccounts stored in each vector
    for (j = 0; j < this->bankAccount.at(i).checkingSubAccount.size(); ++j) {
      cout << " | Sub-Account number: " << this->bankAccount.at(i).checkingSubAccount.at(j).GetCheckingAccountNumber() << endl;
      cout << " | Balance: " << bankAccount.at(i).checkingSubAccount.at(j).GetCheckingBalance() << endl << endl;
    }
    for (j = 0; j < this->bankAccount.at(i).savingSubAccount.size(); ++j) {
      cout << " | Sub-Account number: " << this->bankAccount.at(i).savingSubAccount.at(j).GetSavingAccountNumber() << endl;
      cout << " | Balance: " << this->bankAccount.at(i).savingSubAccount.at(j).GetSavingBalance() << endl << endl;
    }
  }
}