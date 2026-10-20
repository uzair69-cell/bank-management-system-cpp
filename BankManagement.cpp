#include <iostream>
#include <string>
using namespace std;

bool isFiveDigitId(const string &id)
{
    if (id.length() != 5)
        return false;

    for (int i = 0; i < 5; i++)
    {
        if (id[i] < '0' || id[i] > '9')
            return false;
    }
    return true;
}

class Bank
{
private:
    string accountId;
    double balance;
    bool valid;

public:
    Bank();
    Bank &deposit();
    Bank &withdraw();
    Bank &showBalance();
    double getBalance() const;
    bool isValid() const;
};

Bank::Bank() : accountId(""), balance(0), valid(false)
{
    cout << "Enter Account Id (5 digits): ";
    if (!(cin >> accountId))
    {
        cout << "Invalid account ID.\n";
        return;
    }

    if (!isFiveDigitId(accountId))
    {
        cout << "Invalid account ID. It must be five digits.\n";
        return;
    }

    cout << "Enter Your Balance: ";
    if (!(cin >> balance) || balance < 0)
    {
        cout << "Invalid balance.\n";
        return;
    }

    valid = true;
}

Bank &Bank::deposit()
{
    double amount;
    cout << "Enter deposit amount: ";
    if (!(cin >> amount) || amount <= 0)
    {
        cout << "Enter a valid amount greater than zero.\n";
        return *this;
    }

    balance += amount;
    cout << "Deposit successful.\n";
    return *this;
}

Bank &Bank::withdraw()
{
    double amount;
    cout << "Enter withdrawal amount: ";
    if (!(cin >> amount) || amount <= 0 || amount > balance)
    {
        cout << "Invalid amount or insufficient balance.\n";
        return *this;
    }

    balance -= amount;
    cout << "Withdrawal successful.\n";
    return *this;
}

double Bank::getBalance() const
{
    return balance;
}

Bank &Bank::showBalance()
{
    cout << "Current Balance: " << balance << '\n';
    return *this;
}

bool Bank::isValid() const
{
    return valid;
}

int main()
{
    cout << "\n========= Hello User! =========\n";
    string transaction;
    cout << "Do you want to perform any transaction? (yes/no): ";
    if (!(cin >> transaction))
        return 0;

    if (transaction == "yes" || transaction == "Yes" || transaction == "YES")
    {
        Bank account;
        if (!account.isValid())
        {
            cout << "Account creation failed. Exiting.\n";
            return 1;
        }

        int choice;
        do
        {
            cout << "\nWhat would you like to do?\n";
            cout << "1. Deposit\n2. Withdraw\n3. Check balance\n4. Exit\n";
            cout << "Choose an option: ";
            if (!(cin >> choice))
            {
                cout << "Invalid choice.\n";
                return 1;
            }

            if (choice == 1)
                account.deposit().showBalance();
            else if (choice == 2)
                account.withdraw().showBalance();
            else if (choice == 3)
                account.showBalance();
            else if (choice != 4)
                cout << "Please choose 1, 2, 3, or 4.\n";
        } while (choice != 4);

        cout << "Final Balance: " << account.getBalance() << '\n';
    }
    else
    {
        cout << "Goodbye!\n";
    }

    return 0;
}
