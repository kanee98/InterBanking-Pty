/**  
* Created by KanishkaUdapitiya on 11/01/2018.  
*/

#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
	int accountNumber;
	double balance;
	static const double annualRate;

public:
	BankAccount();
	void computeInterest();
	void enterAccountData();
	void displayAccount();
	void deposit();
	void withdrawal();
	double getBalance();
};

const double BankAccount::annualRate=3.0;

BankAccount::BankAccount(){
	this->accountNumber = 0;
	this->balance = 0;
}

double BankAccount :: getBalance()
{
	return this->balance;
};

void BankAccount :: computeInterest()
{
	if (this->accountNumber == 0){
		return;
	}

	int years;
	do{
		cout<<"Enter the number of years of Account Number "<<accountNumber<<" : ";
		cin>>years;

		if(years<0 || years>40){
			cout<<"Error! Enter a year between 1 and 40"<<endl;
		}	
	}
	while(years<0 || years>40);
	
	double Balance=balance;

	for(int i=1; i<=years; i++){
		for(int j=1; j<=12;j++){
			double interest = Balance*((this->annualRate)/12/100);
			Balance+=interest;
			Balance;
		}
		cout<<"Year "<<i<<" end balance is "<<Balance<<endl;
	}
	cout<<endl;
}

void BankAccount :: displayAccount(){
	if (this->accountNumber == 0){
		return;
	}

	cout<<"The Account Number is\t\t: "<< this->accountNumber<<endl;
	cout<<"The Account Balance is\t\t: "<<this->balance<<endl;
	cout<<"The Annual Rate is\t\t: "<<this->annualRate<<"%"<<endl;
};

void BankAccount::enterAccountData(){
	do{
		cout<<"Input Account Number\t\t: ";
		cin>>this->accountNumber;

		if(accountNumber==0){
			cout<<"Exited from the program"<<"\n";
			system("pause");
			exit(0);
		}

		if(accountNumber<1000 || accountNumber>9999){
			cout<<"****************************************"<<endl;
			cout<<"Invalid Account Number!"<<endl;
			cout<<"Check the account number and try again!"<<endl;
			cout<<"****************************************"<<endl;
		}
	}
	while(accountNumber<1000 || accountNumber>9999);

	do{
		cout<<"Input Account "<<accountNumber<<" Balance 	: $";
		cin>>this->balance;

		if(balance<0 || balance>100000){
			cout<<"****************************************"<<endl;
			cout<<"Warning! Account Balance cannot be a (-)tive value or a value greater than $100,000"<<endl;
			cout<<"Please re-enter again!"<<endl;
			cout<<"****************************************"<<endl;
		}
	}
	while(balance<0 || balance>100000);
};

void BankAccount :: deposit()
{
    int deposit;
	cout<<"Account No."<<accountNumber<<" Balance Amount	: "<<balance<<endl;
	cout<<"Enter Deposit Amount		: ";
	cin>>deposit;
	balance=balance+deposit;
	cout<<"After Deposit Balance		: "<<balance<<endl;
	cout<<endl;
};

void BankAccount :: withdrawal()
{
    int withdraw;
	cout<<"Account No."<<accountNumber<<" Balance Amount	: "<<balance<<endl;
	cout<<"Enter Withdraw Amount		: ";
	cin>>withdraw;
	
	if(withdraw>balance)
	{
		cout<<"Error! Cannot Withdraw Amount. Insufficient Funds";
	}

	balance=balance-withdraw;
	cout<<"After Withdraw Balance		: "<<balance<<endl; 
	cout<<endl;
};