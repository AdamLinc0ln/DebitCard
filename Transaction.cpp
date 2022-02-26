#include "Transaction.h"
#include <string>
Transaction::Transaction(int transactionID, std::string date, std::string description, double amount)
{
	//this->transactionID = transactionID;//increment 
	this->date = date;//??
	this->description = description;
	this->amount = amount;
	cleared = false;
}
