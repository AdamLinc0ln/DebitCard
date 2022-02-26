#include "DynamicArray.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

DynamicArray::DynamicArray()
{

	capacity = 2;
	used = 0;
	transactions = new Transaction[2];//this is a pointer

	//transactions = trans;//Array of Transactions
	//Transaction *transactions[2];
}

DynamicArray::~DynamicArray()
{
	delete[] transactions;
}

void DynamicArray::push_back(const Transaction& newTransaction)// adds newTransaction to the end of the dynamic array
{
	if (used == capacity)
	{
		Realloc();
	}

	transactions[used++] = newTransaction;

}

int DynamicArray::size() const // returns the number of Transactions currently stored in the dynamic array
{
	return used;
}

Transaction& DynamicArray::at(int index) // returns a reference to the Transaction stored at the specified index
{
	if (index < 0 || index >= used)
	{
		throw(std::runtime_error("invalid index"));
	}
	return transactions[index];
	// TODO: insert return statement here //References and Pointers?
}

void DynamicArray::Realloc()//Pointers?!?! // make the current array bigger when the current array is full and push_back() is called
{

	// grow array larger
	Transaction* tmpData = new Transaction[capacity * 2];
	//cout << used << endl;
	// save old data
	for (int i = 0; i < used; i++)
	{
		//cout << "Made it this far!" << endl;
		tmpData[i] = transactions[i];
	}

	// destroy old data
	delete[] transactions;

	// updata data ptr
	transactions = tmpData;//?

	capacity *= 2;
}
