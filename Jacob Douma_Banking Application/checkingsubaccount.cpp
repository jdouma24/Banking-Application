#include "checkingsubaccount.h"

void CheckingSubAccount::ModifyCheckingAccount() {
  char selection = '?';

  while (selection != 'X' && selection != 'x') {
    cout << "Eligible services for sub-account " << this->GetCheckingAccountNumber() << endl;
    cout << "   D -- Deposit" << endl;
    cout << "   W -- Withdrawal" << endl;
    cout << "   C -- Max Capacity" << endl;
    cout << "   L -- Lock Sub-Account" << endl;
    cout << "   U -- Unlock Sub-Account" << endl;
    cout << "   X -- Exit" << endl;
    cout << "Please enter your selection: ";

    cin >> selection;
    cout << endl << endl;

    if (selection == 'D' || selection == 'd') {
      unsigned int amount;
      cout << " Enter the amount to deposit: ";
      cin >> amount;
      cout << endl << endl;

      this->DepositCheckingAmount(amount);
    }
    else if (selection == 'W' || selection == 'w') {
      unsigned int amount;
      cout << " Enter the amount to withdrawal: ";
      cin >> amount;
      cout << endl << endl;

      this->WithdrawalCheckingAmount(amount);
    }
    else if (selection == 'C' || selection == 'c') {
      unsigned int maxCap;

      cout << "Max Capacity is " << this->GetMaxCap() << endl;
      cout << "Enter new Max Capacity: ";

      cin >> maxCap;
      cout << endl << endl;

      this->ChangeMaxCapacity(maxCap);
      
      cout << endl << "Max Capacity is now " << this->GetMaxCap() << endl << endl;
    }
    else if (selection == 'L' || selection == 'l') {
      //boolean value true to lock account
      bool locked = true;
      this->ChangeAccountStatus(locked);
      cout << " | The sub-account " << this->GetCheckingAccountNumber() << " is locked now!" << endl << endl;
    }
    else if (selection == 'U' || selection == 'u') {
      //boolean value false to unlock account
      bool locked = false;
      this->ChangeAccountStatus(locked);
      cout << " | The sub-account " << this->GetCheckingAccountNumber() << " is unlocked now!" << endl << endl;
    }
    else if (selection == 'X' || selection == 'x') {
      cout << " | End of service for sub-account " << this->GetCheckingAccountNumber() << endl << endl;
      break;
    }
    else {
          cout << "Please enter a valid selection" << endl << endl;
    }
  }
}