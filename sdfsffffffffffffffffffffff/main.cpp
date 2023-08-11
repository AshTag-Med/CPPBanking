#include <iostream>
using namespace std;

#include "CompoundInterest.h"


// function used to display menu, and obtain user input
void InvestmentMenu(double& investment, double& deposit, double& interest, int& years) {
    
    cout << "\n\n********************************" << endl;
    cout << "********** Data Input **********" << endl;

    cout << "Initial Investment Amount: ";
    cin >> investment;

    // if user input is less than 1 or not a number for initial investment amount
    while (investment < 1 || cin.fail()) {

        // clears input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // prompts user for value again.
        cout << "\n\Enter a number above 0.\n\n";
        cout << "Initial Investment Amount: ";
        cin >> investment;
    }

    cout << "Monthly Deposit: ";
    cin >> deposit;

    // if user input is less than 1 or not a number for monthly deposit
    while (deposit < 1 || cin.fail()) {

        // clears input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // prompts user for value again.
        cout << "\n\nEnter a number above 0.\n\n";
        cout << "Monthly Deposit: ";
        cin >> deposit;
    }

    cout << "Annual Interest: %";
    cin >> interest;

    // if user input is less than 1 or not a number for yearly interest
    while (interest < 1 || cin.fail()) {

        // clears input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // prompts user for value again.
        cout << "\n\nEnter a number above 0.\n\n";
        cout << "Annual Interest: %";
        cin >> interest;
    }

    cout << "Number of Years: ";
    cin >> years;

    // If user input is less than 1 or not a number for years
    while (years < 1 || cin.fail()) {

        // clears input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // prompts user for value again.
        cout << "\n\nEnter a number above 0.\n\n";
        cout << "Number of Years: ";
        cin >> years;
    }
}

int main() {

    // variable declaration
    double investmentAmount, monthlyDeposit, annualInterest;
    int numYears;

    // calls the menu function to obtain user input
    InvestmentMenu(investmentAmount, monthlyDeposit, annualInterest, numYears);

    // see footnote ** 
#if defined(__APPLE__) || defined(__linux__)
    cout << "\n\nPress any key to continue...";
    system("read"); 
#elif defined(_WIN32) || defined(_WIN64)
    system("pause");
#elif
    system("pause");
#endif

    // calls function for compounding interest calculations, and displaying values 
    CompoundInterest::yearlyInterest(investmentAmount, annualInterest, numYears);
    CompoundInterest::yearlyInterestWithDeposit(investmentAmount, monthlyDeposit, annualInterest, numYears);

    return 0;

}
// **
// Initially began writing code on windows, then finished on mac, had issues with compile.
//  The code worked fine on online compilers however would crash everytime on VisualStudio.
//  Eventually adding lines 88-94 fixed it. 