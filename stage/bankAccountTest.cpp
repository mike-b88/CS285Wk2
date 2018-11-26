// bankAccount.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "bankAccount.h"


//Program meets Criteria
//I still have to implement user input valididation
// To avoid program crashes, For now Please Enter 
// Correct Data Types.
//Password Features have been commented out, 
// But they do Work well
//I run my programs with left-crtl + F5

using namespace std;

bankAccount userAccounts[10];			//should be instantiated just once

void printGreetings();
int getChoice();
static int accountsCounter = 0;
static int accInd = 0;


void accountCreator(int);

void accountManager();

void accountSelection();

void accountMenu();



bool checkUserEntry();


int main()
{
	int userChoice;
	//static int accounts = 0;			//use as a counter for less than 10 accounts
	printGreetings();
	userChoice = getChoice();

	if (userChoice == 1)
		accountManager();

	else if (userChoice == 2)
	{
		if (accountsCounter < 10)
			accountCreator(accountsCounter);    //Don't come back to this, just add to the counter
		else
		{
			cout << "!!!!!    WARNING   !!!!!!!" << endl;
			cout << "We have reached our limit of accounts, please pay more for added accounts" << endl;
			printGreetings();  //Hopefully goes back to main
		}
	}
	else if (userChoice == 3)
	{
		cout << "Good Bye." << endl;

		exit(0);
		//return (0);
	}
	cout << "The accounts counter is at: " << accountsCounter << endl;    //Here for debugging

	main();


	return 0;
}



void accountManager()
{

	//cout << "ready to code" << endl; Debugging purpose
	if (checkUserEntry() == true)
	{
		cout << "Your account number is valid !! " << endl; //and password match, congrats" << endl;
		accountSelection();

	}
	else
	{
		cout << "Invalid creditials!!!" << endl;
		cout << "Please re-enter your login information!!!!" << endl;
		main();

	}

}

void accountSelection()
{

	userAccounts[accInd].getName();
	cout << "Welcome to your Account's Main Menu " << endl << endl;;
	userAccounts[accInd].printAll();

	cout << "##########################################################" << endl;

	accountMenu();



}

void accountMenu()
{


	int choice;
	cout << endl << endl;
	cout << "Please choose from the Following Options: " << endl;
	cout << " (1) To Make A deposit \n(2) To Withdraw Money \n "
		<< "(3) To Return to Account Summary: " << endl;
	cout << "(4) Log out: " << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		userAccounts[accInd].depositMon();   //pass value to class for choice add actual and formals
		cout << "Deposit Complete" << endl;
		system("CLS");
		accountMenu();
		break;
	case 2:
		userAccounts[accInd].withDraw(); // pass value to class for choice, add actuals and formals
		system("CLS");
		accountSelection();
		break;
	case 3:
		system("CLS");
		accountSelection();
		break;
	case 4:
		system("CLS");
		main();
	default:
		cout << "Invalid Option!!" << endl;
		accountSelection();
	}

	//accountSelection();


}

bool checkUserEntry()
{

	int accnEntry = 0;
	//string pssEntry = "";			Used for password feature

	cin.sync();
	cin.clear();
	//system("CLS");
	cout << "Please enter your account Number: " << endl;
	cin >> accnEntry;
	system("CLS");
	//cout << "Please Enter your password: " << endl; //Password feature

	//cin.ignore();
	//std::getline(std::cin, pssEntry);				//Password feature

	for (int i = 0; i < accountsCounter; i++)
	{
		int tmpAccNm = userAccounts[i].getAccNum();
		//string tmpNm = userAccounts[i].getKey();			//Password feautre

		if (accnEntry == tmpAccNm)//&& pssEntry == tmpNm)	//password feature commented out
		{
			accInd = i;
			//cout << "CORRECT!" << endl;  debugging purposes
			return true;
		}
	}
	//cout << "for DEBUG PASSWORD IS: " << userAccounts[accInd].getKey() << endl;
	//cout << "Invalid creditials!!!" << endl;
	return false;
}

void printGreetings()
{
	cout << "=======================================================================" << endl;
	cout << "*****Welcome to Tier 1 Banking, Please choose from the following: *****" << endl;
	cout << "***********************************************************************" << endl;
	cout << "                     Enter (1) to login                                " << endl;
	if (accountsCounter < 10)
		cout << "                  Enter (2) to create an account                       " << endl;
	cout << "                      Enter (3) to exit								" << endl;
	cout << "=======================================================================" << endl;

}

int getChoice()
{
	int choice;
	cin >> choice;

	while (!cin)
	{
		cout << "	! ! NUMBERS ONLY ! ! NUMBERS ONLY!!!	 ";
		cin.clear();
		cin.ignore();
		
			cin >> choice;
	}

	//Print the integer entered by the user to the screen.
	//cout << "The integer entered is " << choice << endl;







	if (choice != 1 && choice != 2 && choice != 3)
	{
		cout << "!!!!! Please enter valid choice !!!!!" << endl;
		main();

	}

	return choice;


}




void accountCreator(int j)
{

	//string tmpk;						//Password feature
	//cout << "Lets get Here" << endl;	//debugging
	userAccounts[j].enterAccountName();
	//userAccounts[j].getAccNum();		//Debugging
	userAccounts[j].storeAccNum();
	//userAccounts[j].genAccountNum();	//Debugging
	userAccounts[j].chooseAccTypes();
	//userAccounts[j].secretKey();		//Password Feature

	cout << "Your account has been created" << endl;
	cout << "Write down your account number: " << userAccounts[j].getAccNum() << endl;
	//cout << "And Write Your password down " << endl;		//Password Feature
	//userAccounts[j].getKey();							   //
	cout << "To log in to Your Account :) " << endl;
	cout << "Press enter to enter to main Bank Home Page: " << endl;
	system("PAUSE");
	system("CLS");
	accountsCounter++;


}