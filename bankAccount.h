#pragma once
#include <string>


//Class definition
//with extra features, password implementation is user program is optional

class bankAccount
{
public:

	void printAll() const;

	void getName() const;
	int getAccNum()const;
	void storeAccNum();
	void getIntRate() const;
	void getAccTypes() const;

	//void compare(int&, string&);

	void depositMon();
	void withDraw();

	void getBal() const;
	
	void enterAccountName();

	void storeAccNum(int&);

	static int genAccountNum();

	//void deposit();
	
	void secretKey();
	//string getKey()const;
	// void X9.17KeyGen();

	int chooseAccTypes();
	std::string  getKey()const;
	bankAccount();  //use as default constructor!!!

	
private:
	std::string accountName;
	int accountNumber;
	std::string checkingsAcc;
	std::string savingsAcc;
	std::string passWord;
	double checkingBal;
	double savingsBal;
	double interestRate = 0.0001;
	int userChoice;

};