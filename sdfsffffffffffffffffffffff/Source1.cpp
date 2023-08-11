#include <iostream>
#include <iomanip>
using namespace std;

#include "CompoundInterest.h"

//function used to calculate and display yearly interest
void CompoundInterest::yearlyInterest(double investment, double interest, int years) {
    

    
    
    //defines and initializes local variables
    double m_monthlyEndBalance = investment;
    int month = years * 12;
    double total = 0;
    double m_int = 0;
    double intEnd = 0;

    // output header
    cout << "\n\n";
    cout << setw(66) << setfill('=') << "\n";
    cout << " Balance and Interest Without Additional Monthly Balances\n";
    cout << setw(66) << setfill('=') << "\n";
    cout << " Year\t\tYear End Balance\tYear End Earned Interest" << endl;
    cout << setw(66) << setfill('-') << "\n";

    // for loop which prints the 3 figures based on year
    for (int i = 1; i < month + 1; i++) {
        total = m_monthlyEndBalance;
        m_int = (total) * ((interest / 100) / 12);
        m_monthlyEndBalance = m_int + total;
        intEnd = intEnd + m_int;
        if (i % 12 == 0) {  // if statement used to only print once a year
            cout << setprecision(2) << fixed << "  " << (i / 12) << setfill(' ') << setw(20);
            cout << "$" << m_monthlyEndBalance << setw(23) << "$" << intEnd << "\n";
            cout << endl;
            intEnd = 0;
        }
    }
}

//function used to calculate and display yearly interest with a deposit
void CompoundInterest::yearlyInterestWithDeposit(double investment, double deposit, double interest, int years) {
    
     

    //defines and initializes local variables
    double m_monthlyEndBalance = investment;
    int month = years *12;
    double total = 0;
    double m_int = 0;
    double intEnd = 0;
    

    // output header
    cout << "\n\n";
    cout << setw(66) << setfill('=') << "\n";
    cout << " Balance and Interest With Additional Monthly Balances\n";
    cout << setw(66) << setfill('=') << "\n";
    cout << " Year" << "\t\tYear End Balance" << "\tYear End Earned Interest" << endl;
    cout << setw(66) << setfill('-') << "\n";

    // for loop which prints the 3 figures based on year
    for (int i = 1; i < month + 1; i++) {
        total = m_monthlyEndBalance + deposit;
        m_int = (total) * ((interest / 100) / 12);
        m_monthlyEndBalance = m_int + total;
        intEnd = intEnd + m_int;
        if (i % 12 == 0) {  // if statement used to only print once a year
            cout << setprecision(2) << fixed << "  " << (i / 12) << setfill(' ') << setw(20);
            cout << "$" << m_monthlyEndBalance << setw(23) << "$" << intEnd << "\n";
            cout << endl;
            intEnd = 0;
            }
    }

    
}