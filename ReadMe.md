# Bank Account Class

A C++ class for representing a bank account in a banking system.

## Data Dictionary

|Attribute	             |Data Type		|Description               |
|----------------------------|------------------|--------------------------|
|accountNumber	             |std::string	|The account number.       |
|accountHolderName           |std::string	|The account holder's name.|
|balance	             |double	        |The account balance.      |



## Methods List    
            
|Method Signature          				|Return Type	|Description                    |
|-------------------------------------------------------|---------------|-------------------------------|
|BankAccount()	            				|(Constructor)	|Default constructor.           |
|BankAccount(accountNumber, accountHolderName, balance) |(Constructor)	|Parameterized constructor.     |
|getAccountNumber() const      				|std::string	|Gets the account number.       |
|getAccountHolderName() const			        |std::string	|Gets the account holder's name.|
|getBalance() const					|double	        |Gets the account balance.      |
|setAccountHolderName(name)  				|void	        |Sets the account holder's name.|
|deposit(amount)	     				|void	        |Deposits money.                |
|withdraw(amount)	   			        |void	        |Withdraws money.               |