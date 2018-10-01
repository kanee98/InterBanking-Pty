/**  
* Created by KanishkaUdapitiya on 02/04/2018.  
*/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "stdafx.h"
#include <iostream>
#include "BankBranch.h"

using namespace std;

class BankAccount{
private:
	int accountNumber;
	double accountBalance;
	BankBranch* branch;
	static int account;

public:
	BankAccount(BankBranch*, double);
	void displayAccount();
	double getAccountBalance();
	int getAccountNumber();
	BankBranch* getBranch();
};

class SavingsAccount : public BankAccount{
private:
	double interestRate;
public:
	SavingsAccount(BankBranch*, double, double);
	void displayAccount();
	double getInterest();
};

class CheckingAccount : public BankAccount{
private:
	double monthlyFee;
	int checksPerMonth;

public:
	CheckingAccount(BankBranch*, double, int, double);
	void displayAccount();
	double getMonthlyFee();
	double getChecksPerMonth();
};

class CheckingAccountWithInterest:public SavingsAccount, public CheckingAccount{
public:
	CheckingAccountWithInterest(BankBranch*, double, double, int);
	void displayAccount();
};

#endif