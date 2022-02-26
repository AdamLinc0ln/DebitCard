#include"DebitCard.h"
#include "Transaction.h"
#include "DynamicArray.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

DebitCard::DebitCard()
{
	totalTransactions = 0;
	accountBalance = 0;
	totalDeposits = 0;//?
	//DynamicArray transactions;//?
}

DebitCard::~DebitCard()
{
}

double DebitCard::Deposit(double deposit) // used to add money to the DebitCard. Returns current ballance
{
	totalDeposits = totalDeposits + deposit;
	accountBalance = accountBalance + deposit;
	return accountBalance;
}

double DebitCard::PostTransaction(int idNumber, std::string date, std::string description, double amount)  // adds a new transaction to the transactions array. Returns account balance
{

	Transaction newTransaction(idNumber, date, description, amount);//add to array?
	transactions.push_back(newTransaction); //call array made by constructor? push back not working
	totalTransactions++;
	accountBalance = accountBalance - transactions.at(idNumber - 1).amount;
	return accountBalance;
}

bool DebitCard::ClearTransaction(int idNumber) // marks the pending transaction in the transactions array as "cleared"
{
	transactions.at(idNumber - 1).cleared = true;//Does this work?
	//accountBalance = accountBalance - transactions.at(idNumber - 1).amount;
	return false;
}

void DebitCard::DisplayActivity() // properly displays the DebitCard data to the console screen
{
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "Total Transactions: " << totalTransactions << endl;
	cout << "Total Deposits: $" << totalDeposits << endl;//?
	cout << "Account Balance: $" << accountBalance << endl << endl;

	cout << "List of Cleared Transactions: " << endl;
	cout.setf(ios::fixed);
	cout.precision(2);
	for (size_t i = 0; i < transactions.size(); i++)//9?//returning reference to transactions?transactions.size()
	{
		if (transactions.at(i).cleared == true)
		{
			cout << transactions.at(i).date << "    $" << transactions.at(i).amount << "   " << transactions.at(i).description << endl;
		}

	}
	cout << endl;
	cout << "List of Pending Transactions: " << endl;
	for (size_t i = 0; i < transactions.size(); i++)//9?transactions.size()
	{
		if (transactions.at(i).cleared == false)
		{

			cout << transactions.at(i).date << "    $" << transactions.at(i).amount << "   " << transactions.at(i).description << endl;
		}
	}
}
