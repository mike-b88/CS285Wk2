#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include "bankAccount.h"

//Added includes for complex Random number Gen/Key pair Gen


//Class Implementation File, required std namespace

using namespace std;



void bankAccount::printAll() const
{
	cout << "#####################################################" << endl;
	cout << "		 Account Summary			" << endl;
	cout << "//////////////////////////////////////////////////////" << endl;
	//int tmp;
	getName();
	getAccNum();

	getAccTypes();

	getBal();
	getIntRate();

}



void bankAccount::getName() const 
{
	cout<<"Account Holder's Name: " << accountName << endl;
}


void bankAccount::storeAccNum()
{
	accountNumber = genAccountNum();
}

int bankAccount::getAccNum() const
{
	
	return accountNumber;
}

void bankAccount::getIntRate()const
{
	cout << "The interest Rates offered for your account(s) is: " << interestRate << "%" << endl;
}

void bankAccount::depositMon()
{
	double cashIn;

	if (userChoice == 1)
	{
		cout << "*****Checkings Deposit******" << endl;
		cout << "Please enter amount: " << endl;
		cin >> cashIn;
		checkingBal = checkingBal + cashIn;
	}
	else if (userChoice == 2)
	{
		cout << "*****Savings Deposit*****" << endl;
		cout << "Please enter amount: " << endl;
		cin >> cashIn;
		savingsBal = savingsBal + cashIn;
	}

	else if (userChoice == 3)
	{
		int decVal;
		cout << "		****** Checkings or Savings ******		" << endl;
		cout << "Which account would you like to make your deposit into?" << endl;
		cout << "Select (1) for checkings" << endl;
		cout << "Select (2) for Savings" << endl;
		cin >> decVal;

		if (decVal == 1)
		{
			cout << "*****Checkings Deposit******" << endl;
			cout << "Please enter amount: " << endl;
			cin >> cashIn;
			checkingBal = checkingBal + cashIn;
		}
		else if (decVal == 2)
		{
			cout << "*****Savings Deposit*****" << endl;
			cout << "Please enter amount: " << endl;
			cin >> cashIn;
			savingsBal = savingsBal + cashIn;
		}




	}

	else
	{
		cout << "Invalid Entry!! Please Re-enter!!" << endl;
		depositMon();
	}

}

void bankAccount::withDraw()
{
	double cashOut;
	if (userChoice == 1)
	{
		cout << "*****Checkings Withdraw******" << endl;
		cout << "Please enter amount: " << endl;
		cin >> cashOut;
		if (cashOut > checkingBal)
		{
			cout << "Nice Try, You have attempted to over draw your account, please enter "
				<< "a minimum withdraw of: " << checkingBal << endl;
			withDraw();
		}
		else if (cashOut < checkingBal)
		{
			checkingBal = checkingBal - cashOut;
		}
	
	}

	else if (userChoice == 2)
	{
		cout << "*****Savings Withdraw*****" << endl;
		cout << "Please enter amount: " << endl;
		cin >> cashOut;

		if (cashOut > savingsBal)
		{
			cout << "Nice Try, You have attempted to over draw your account, please enter "
				<< "a minimum withdraw of: " << savingsBal << endl;
			withDraw();
		}
		else if (cashOut < savingsBal)
		{
			savingsBal = savingsBal - cashOut;
		}


		
	}

	else if (userChoice == 3)
	{
		int decVal;
		cout << "		****** Checkings or Savings ******		" << endl;
		cout << "Which account would you like to make your withdraw from?" << endl;
		cout << "Select (1) for checkings" << endl;
		cout << "Select (2) for Savings" << endl;
		cin >> decVal;

		if (decVal == 1)
		{
			cout << "*****Checkings Withdraw******" << endl;
			cout << "Please enter amount: " << endl;
			cin >> cashOut;

			if (cashOut > checkingBal)
			{
				cout << "Nice Try, You have attempted to over draw your account, please enter "
					<< "a minimum withdraw of: " << checkingBal << endl;
				withDraw();
			}
			else if (cashOut < checkingBal)
			{
				checkingBal = checkingBal - cashOut;
			}


			
		}
		else if (decVal == 2)
			cout << "*****Savings Withdraw*****" << endl;
		cout << "Please enter amount: " << endl;
		cin >> cashOut;

		if (cashOut > savingsBal)
		{
			cout << "Nice Try, You have attempted to over draw your account, please enter "
				<< "a minimum withdraw of: " << savingsBal << endl;
			withDraw();
		}
		else if (cashOut < savingsBal)
		{
			savingsBal = savingsBal - cashOut;
		}





	}





}


void bankAccount::enterAccountName()
{
	std::string name;
	
	cout << "Please Enter your First and Last Name: " << endl;
	
	cin.ignore();
	std::getline(std::cin, name);

	accountName = name;

	//genAccountNum();

}

 int bankAccount::genAccountNum()     
{
	 srand ((unsigned int)time(NULL));			

	 int num;
	 int accountNum[7];
	 int number = 0;


	 for (int i = 0; i < 7; i++)
	 {
		 num = rand() % 9 +1;
		 accountNum[i] = num;
	 }
	 for (int i = 0; i < 7; i++)
	 {
		 number *= 10;
		 number += accountNum[i];
	 }

	 return number;

}

 void bankAccount::storeAccNum(int& accNum)
 {
	 //Pass this to database servers
 }

 void bankAccount::secretKey()
 {
	 //Still have to implemented better security here
	 std::string key;
	 cout << "Please enter the encryption key of your choice: " << endl;

	 cin.ignore();
	 std::getline(std::cin, key);

	 passWord = key;

	 
 }

 std::string bankAccount::getKey()const 
 {
	// cout << passWord << endl;
	 return passWord;
 }
 void bankAccount::getAccTypes() const
 {
	 if (checkingsAcc == "Yes" && savingsAcc == "No")
		 cout << "You only have a checkings account with Tier 1 Banking." << endl;
	 else if (checkingsAcc == "No" && savingsAcc == "Yes")
		 cout << "You only have a savings account with Tier 1 Banking." << endl;
	 else if (checkingsAcc == "Yes" && savingsAcc == "Yes")
		 cout << "You have a checking and savings account with Tier Banking." << endl;
		 


 }

 void bankAccount::getBal() const
 {
	 if (userChoice == 1)
		 cout << "Your checkings account balance with interest is: " << checkingBal + (interestRate*checkingBal) << endl;
	 else if (userChoice == 2)
		 cout << "Your savings account balace with interest is: " << savingsBal + (interestRate*savingsBal) << endl;
	 else if (userChoice == 3)
		 cout << "Your balances with interest added are below" << endl;
	 cout << "Checkings Account: " << checkingBal + (interestRate*checkingBal) << endl;
	 cout << "Savings Account: " << savingsBal + (interestRate*savingsBal) << endl;


 }

 int bankAccount::chooseAccTypes()
 {

	

	 cout << "Which type of Account would you like?" << endl;
	 cout << "Choose: (1) For Checking " << endl;
	 cout << "Choose: (2) For Savings " << endl;
	 cout << "Choose: (3) For Both " << endl;

	 cin >> userChoice;

	 if (userChoice != 1 && userChoice != 2 && userChoice != 3)
	 {
		 cout << "Please Enter a valid choice of 1, 2, or 3: " << endl;
		 chooseAccTypes();
	 }

	 if (userChoice == 1)
	 {
		 checkingsAcc = "Yes";
			 savingsAcc = "No";
	 }

	 else if (userChoice == 2)
	 {
		 checkingsAcc = "No";
		 savingsAcc = "Yes";
	 }
	 else
	 {
		 checkingsAcc = "Yes";
		 savingsAcc = "Yes";
	 }
	 
	 return userChoice;

 }

 bankAccount::bankAccount()
{
	 accountName = "";
	 accountNumber = 0;
	 checkingsAcc = "";
	 savingsAcc = "";
	 checkingBal = 0;
	 savingsBal = 0;
	 passWord = "";
	 userChoice = 0;

}


