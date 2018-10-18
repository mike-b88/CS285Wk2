// 		bankAccount Class
/*
	Menu driven Program that allows user to create 
	a banking account
	
	1) Ask to login
	2) Ask to create account		******Use switch statements  !!!!!
	3) exit							****** While program is running, save new accounts to login to 
											and perform the operations
	
	
	*************************************************************************************************************
	|				Option 2: create account																	|
	|============================================================================================================
	|	*To create account, create new object of class bankAccount
	|	*Set UserName  --type String
	|	*Set password  -- Type String
	|
	|	*Account number has to be static -- only called when new user creates account of type bankAccount
	|									 -- Generates random 8 digit account number
	|									 -- Static function is called and the account number will be returned
	|						  				  for new accounts.
	|
	|
	|
	|
	|	** Have user choose which types of accounts to create
	|		Save the value of userChoice, pass to main, or figure out what to do;
	|		print values and create objects based off this, and allow access to 
	|		either checkings, savings, or BOTH with the return value.
	|
	|
	|
	|
	| *Constructor: 
					bankAccount(string, string, string, string, double, double, int);
	|
	|				string1 = accountName
	|				string2 = checkingsAcc(checking)
	|				string3 = savingsAcc (savings)
	|			    string4 = passWord
	|				
	|				double1 = sets balance
	|				double2 = interest rate
	|				int1 = account num generator
	|
	|
	|		*maybe add a second constructor for login
	|
	
		enterAccountName();
		genAccountNumber();
		secretKey();
		chooseAccTypes();

	
	
	4673191 - both 1500.15
					15002.5
	
	4315295 -savings
	
	
	8222118 - checkings
	
	
	
	
	
	
	==========================================================================================
	|							bankAccount					 					             |
	__________________________________________________________________________________________
	|											+											 |
	| 			***********************			+		*****************					 | 
	| 			*   DATA		      *			+		*   Methods	    *                    |	
	|			***********************			+		*****************					 | 
	|  -Account holders Name					+  -deposit ( after account creation)        |
	|  -Account Number(int)						+  -withdraw (after acccount creation)       |
	|  -Account type(string checking or			+  -getInterest(balanceTimes interest rate)  |
	|             savings or both)				+  -updateBalance(adds interest amount to 	 |
	|	-Balance(double)						+        balance)							 |
	|   -interest rate(double, stored			+  -print(displays all account info)		 |	
	|				as decimal value)			+  -getAccountNumber						 |
	|	-Static member(int named anything)	    +  -getAccountHolderName				     |
	|	used to automatically assign account    +  -getAccountTypes          				 |
	|	numbers during account creation.		+  -getAccountType							 |
	|											+   -getBalance								 |
	|											+   -getInterestRate						 |
	|											+										     |
	|											+											 |
	|											+											 |
	|----------------------------------------------------------------------------------------|
	|		*********************
	|		*    Constructor	*
	|		*********************
	|	-sets account holders name
	|	-sets account type
	|	-sets balance
	|	-sets interest rate
	|	-Sets password
	|	-account number is auto generated
	|
	|
	
	
	
	

*/