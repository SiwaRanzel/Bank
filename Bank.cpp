#include <iostream>
#include <fstream>
void showBalance(double balance);
double deposite();
double withdraw(double balance);

int main()
{
    int choice = 0;
    double balance = 0;
    double tempDeposit = 0;
    double tempWithdraw = 0;
    double showDeposit = 0;
    double showWithdraw = 0;
    do
    {
        std::cout << "************************\n";
        std::cout << "Welcome BANKiverse\n";
        std::cout << "************************\n";
        std::cout << "Choose from the following option:\n";
        std::cout << "1. Show balance\n";
        std::cout << "2. Deposite money\n";
        std::cout << "3. Withdraw money\n";
        std::cout << "4. EXIT\n";
        std::cout << "Enter your chioce: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            showBalance(balance);
            break;
        case 2:
            tempDeposit = deposite();
            showDeposit += tempDeposit;
            balance += tempDeposit;
            showBalance(balance);
            break;
        case 3:
            tempWithdraw = withdraw(balance);
            showWithdraw += tempWithdraw;
            balance -= withdraw(balance);
            showBalance(balance);
            break;
        case 4:
        {
            std::cout << "Thank you for visiting. View your bank statement\n";
            std::ofstream outFile("Bank_Statement.txt");
            outFile << "Here is your Balance from your transactions:\n"
                    << "Deposited: R" << showDeposit << "\n"
                    << "Withdrew: R" << showWithdraw << "\n"
                    << "Balance: R" << balance << std::endl;
            outFile.close();
            break;
        }
        default:
            std::cout << "Invalid choice\n";
            break;
        }
    } while (choice != 4);

    return 0;
}

void showBalance(double balance)
{
    std::cout << "Balance: R" << balance << std::endl;
}

double deposite()
{
    double amount = 0;
    std::cout << "Enter the amount you are going to deposite: R";
    std::cin >> amount;
    if (amount > 0)
    {
        return amount;
    }
    else
    {
        std::cout << "You cannot deposite and invalid amount\n";
        return 0;
    }
}

double withdraw(double balance)
{
    double withamount = 0;
    std::cout << "Enter the amount you are going to withdraw: R";
    std::cin >> withamount;
    if (withamount <= balance)
    {
        return withamount;
    }
    else
    {
        std::cout << "The amount you are trying to withdraw has gone pass your balance\n";
        return 0;
    }
}