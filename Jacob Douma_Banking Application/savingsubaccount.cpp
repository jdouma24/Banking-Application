#include "savingsubaccount.h"

void SavingSubAccount::ModifySavingAccount() {
  char selection = '?';

  while (selection != 'X' && selection != 'x') {
    cout << "Eligible services for sub-account " << this->GetSavingAccountNumber() << endl;
    cout << "   D -- Deposit" << endl;
    cout << "   W -- Withdrawal" << endl;
    cout << "   X -- Exit" << endl;
    cout << "Please enter your selection: ";

    cin >> selection;
    cout << endl << endl;

    if (selection == 'D' || selection == 'd') {
      if (numSavingSubAccounts == 0) {
        cout << " | There are no checking accounts to deposit to." << endl << endl;
      }
      else {
       unsigned int amount;
        cout << " Enter the amount to deposit: ";
        cin >> amount;
        cout << endl << endl;

        //use Deposit function in subaccount.h
        this->savingAccount.DepositAmount(amount);
      }
    }
    else if (selection == 'W' || selection == 'w') {
      if (numSavingSubAccounts == 0) {
        cout << " | There are no checking accounts to withdrawal from." << endl << endl;
      }
      else {
        unsigned int amount;
        cout << " Enter the amount to withdrawal: ";
        cin >> amount;
        cout << endl << endl;

        this->savingAccount.WithdrawalAmount(amount);
      }
    }
    else if (selection == 'X' || selection == 'x') {
      cout << " | End of service for sub-account " << this->GetSavingAccountNumber() << endl << endl;
      break;
    }
    else {
          cout << "Please enter a valid selection" << endl << endl;
    }
  }
}