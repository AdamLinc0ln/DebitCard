# DebitCard

Debit Card tracking program that reads information about a debit card account from a file of sample data. The program parses the data and keeps a list of 
transactions, total number of transactions and the account balance. Each "transaction" is a separate transaction object and tracks the following information:
1. Transaction number
2. Date of Transaction
3. Description of Transaction
4. Transaction amount
5. If the transaction is pending or cleared

Transactions are "pending" if they are under 48 hours old and "clear" after that time frame. After all the data has been read from the file the program will display
the following data:
1. Total Transactions
2. Total Deposits
3. Account balance
4. list of all cleared transactions
5. list of all pending transactions
