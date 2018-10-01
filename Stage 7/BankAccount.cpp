/**  
* Created by KanishkaUdapitiya on 02/04/2018.  
*/

#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include "BankAccount.h"
#include "BankBranch.h"

using namespace std;

int BankAccount::account = 1000;

BankAccount :: BankAccount(BankBranch* branch, double accountBalance){
	this->accountNumber=account++;
	this->accountBalance=accountBalance;
	this->branch = branch;
};

void BankAccount :: displayAccount(){
	if (this->accountNumber == 0){
		return;
	}
	cout<<"	>>>>> Bank Account Details <<<<< "<<endl;
	cout<<"__________________________________________________"<<endl;
	cout<<"The Account Number is\t\t: "<< this->accountNumber<<endl;
	cout<<"The Account Balance is\t\t: "<<this->accountBalance<<endl;
	cout<<"	>>>>> Bank Branch Details <<<<< "<<endl;
	cout<<"__________________________________________________"<<endl;
	cout<<"The Branch Number is\t\t: "<<this->getBranch()->getBSB()<<endl;
	cout<<"The Branch Adress is\t\t: "<<this->getBranch()->getAddress()<<endl;
	cout<<"The Branch PostCode is\t\t: "<<this->getBranch()->getPostCode()<<endl;
};


double BankAccount::getAccountBalance(){
	return this->accountBalance;
}

int BankAccount::getAccountNumber(){
	return this->accountNumber;
}

BankBranch* BankAccount::getBranch(){
	return branch;
}

SavingsAccount::SavingsAccount(BankBranch* branch, double accountBalance, double interestRate=0.02):BankAccount(branch, accountBalance){
	this->interestRate=interestRate;
}

void SavingsAccount::displayAccount()
{
	BankAccount::displayAccount();
	cout<<"The Interest Rate is\t\t: "<<this->interestRate<<endl;
}

double SavingsAccount::getInterest()
{
	return this->interestRate;
}

CheckingAccount::CheckingAccount(BankBranch* branch, double monthlyFee, int checksPerMonth, double accountBalance=0):BankAccount(branch, accountBalance){
	this->monthlyFee =  monthlyFee;
	this->checksPerMonth = checksPerMonth;
}

double CheckingAccount::getMonthlyFee(){
	return this->monthlyFee;
}

double CheckingAccount::getChecksPerMonth(){
	return this->checksPerMonth;
}

void CheckingAccount::displayAccount()
{
	BankAccount::displayAccount();
	cout << "Monthly Fee		: " << this->monthlyFee << endl;
	cout << "Number of checks per month	: " << this->checksPerMonth << endl;
}

CheckingAccountWithInterest::CheckingAccountWithInterest(BankBranch* branch, double accountBalance, double monthlyFee, int checksPerMonth):SavingsAccount(branch, accountBalance, 3.0),CheckingAccount(branch,monthlyFee,checksPerMonth){
}

void CheckingAccountWithInterest::displayAccount(){
	SavingsAccount::displayAccount();
	CheckingAccount::displayAccount();
}