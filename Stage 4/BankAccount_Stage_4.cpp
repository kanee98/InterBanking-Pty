/**  
* Created by KanishkaUdapitiya on 11/01/2018.  
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct BankAccount{
	int accountNumber;
	double accountBalance;
	string customerName;
	string password;
	double interestRate;
};

BankAccount enterAccountData();
void dataPersistency(string, string, int, double);
void displayAccount(int, double, string);
void computeInterest(double, double);
void viewTransaction(int, double);

double savings_plan(double, double, double, double, int);

int main(){
	BankAccount acc1;
	BankAccount acc2;

	double automaticDeposit;
	double automaticWithdrawal;

	cout<<" *** Welcome to InterBanking Pty ***"<<endl;
	cout<<"---------------------------------------"<<endl;

	acc1=enterAccountData();
	acc2=enterAccountData();
	
	cout<<" ** Display Details of 1st Account **"<<endl;
	displayAccount(acc1.accountNumber, acc1.accountBalance, acc1.customerName);
	cout<<" ** Display Details of 2nd Account **"<<endl;
	displayAccount(acc2.accountNumber, acc2.accountBalance, acc2.customerName);

	cout<<" ** Interests calculated for 1st Account **"<<endl;
	computeInterest(acc1.accountBalance, acc1.interestRate);
	cout<<" ** Interests calculated for 2nd Account **"<<endl;
	computeInterest(acc2.accountBalance, acc2.interestRate);

	cout<<"Input Automatic Deposit Value	: $";
	cin>>automaticDeposit;
	cout<<"Input Automatic Withdrawal Value: $";
	cin>>automaticWithdrawal;
	cout<<endl;

	int amount;
	int fromAccountNumber;
	int toAccountNumber;
	char choice;

	do{
		cout<<"Do you want to do a transfer? <Yes=y/Y> <No=n/N> - ";
		cin>>choice;

		if((choice!='n'&&choice!='N')&&(choice!='y'&&choice!='Y')){
			cout<<"****************************************"<<endl;
			cout<<"Invalid choice! Try Agin."<<endl;
			cout<<"****************************************"<<endl;
		}
	}
	while((choice!='n'&&choice!='N')&&(choice!='y'&&choice!='Y'));

	if(choice=='n'||choice=='N'){
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
		cout<<"Thank you for Banking with us!"<<endl;
		system("pause");
		return 0;
	}

	do{
		cout<<"Enter the From Account Number	: ";
		cin>>fromAccountNumber;

		if(fromAccountNumber<1000 || fromAccountNumber>9999){
			cout<<"****************************************"<<endl;
			cout<<"Invalid Account Number, try again!"<<endl;
			cout<<"****************************************"<<endl;
		}
	}
	while(fromAccountNumber<1000 || fromAccountNumber>9999);

	do{
		cout<<"Enter the To Account Number	: ";
		cin>>toAccountNumber;

		if(toAccountNumber<1000 || toAccountNumber>9999){
			cout<<"****************************************"<<endl;
			cout<<"Invalid Account Number, try again!"<<endl;
			cout<<"****************************************"<<endl;
		}
	}
	while(toAccountNumber<1000 || toAccountNumber>9999);

	cout<<"Amount to transfer		: $";
	cin>>amount;
	cout<<endl;

	if(fromAccountNumber==toAccountNumber){
		cout<<"****************************************"<<endl;
		cout<<"Error! From & To account cannot be the same"<<endl;
		cout<<"****************************************"<<endl;
	}

	else{
		if((acc1.accountBalance-amount<0)||(acc2.accountBalance-amount<0)){
			cout<<"****************************************"<<endl;
			cout<<"Insufficient Funds! Transfer Money Aborted."<<endl;
			cout<<"****************************************"<<endl;
		}
		else if((acc1.accountBalance-amount<10)||(acc2.accountBalance-amount<10)){
			cout<<"****************************************"<<endl;
			cout<<"Warning! Account Balance is low"<<endl;
			cout<<"****************************************"<<endl;
			if(acc1.accountNumber==fromAccountNumber){
				acc2.accountBalance-=amount;
				acc2.accountBalance+=amount;
			}
			else{
				acc2.accountBalance-=amount;
				acc1.accountBalance+=amount;
			}
		}
		else{
			if(acc1.accountNumber==fromAccountNumber){
				acc1.accountBalance-=amount;
				acc2.accountBalance+=amount;
			}
			else{
				acc2.accountBalance-=amount;
				acc1.accountBalance+=amount;
			}
		}
		if((acc1.accountBalance>100000)||(acc2.accountBalance>100000)){
			cout<<"****************************************"<<endl;
			cout<<"Warning! Account Balance is too high"<<endl;
			cout<<"****************************************"<<endl;
		}
	}

	cout<<" ** Display Details of 1st Account **"<<endl;
	viewTransaction(acc1.accountNumber, acc1.accountBalance);
	cout<<" ** Display Details of 2nd Account **"<<endl;
	viewTransaction(acc2.accountNumber, acc2.accountBalance);

	cout<<" * * * * >>>>> Bank Statement for Account No."<<acc1.accountNumber<<"<<<<< * * * * "<<endl;
	double end_Balance1 = savings_plan(acc1.accountBalance, automaticDeposit, automaticWithdrawal, acc1.interestRate, 2);
	cout<<" * * * * >>>>> Bank Statement for Account No."<<acc2.accountNumber<<"<<<<< * * * * "<<endl;
	double end_Balance2 = savings_plan(acc2.accountBalance, automaticDeposit, automaticWithdrawal, acc2.interestRate, 2);

	dataPersistency(acc1.customerName, acc1.password, acc1.accountNumber, acc1.interestRate);
	dataPersistency(acc2.customerName, acc2.password, acc2.accountNumber, acc2.interestRate);
	
	system("pause");
	return 0;
}

double savings_plan(double startingBalance, double automaticDeposit, double automaticWithdrawal, double interestRate, int years){
	int month;
	double endingBalance=0, interest=0;
	
	cout<<"------------------------------------------------------------------"<<endl;
	cout<<"| Year | Month  | Starting Balance\t|\tEnd Balance\t|"<<endl;
	cout<<"------------------------------------------------------------------"<<endl;
	
	for(int year=1; year<=years; year++){
		for(month=1; month<=12; month++){
			interest = startingBalance*(interestRate/12)+automaticDeposit-automaticWithdrawal;
			endingBalance = startingBalance + interest;

			cout<<"| "<<year<<"    | "<<month<<"\t|\t"<<"$"<<startingBalance<<"\t|\t"<<"$"<<endingBalance<<"\t|"<<endl;
			cout<<"------------------------------------------------------------------"<<endl;
			startingBalance=endingBalance;
		}
	}
	cout<<"****************************************"<<endl;
	cout<<"    * * * * End of statement * * * * "<<endl;
	cout<<"****************************************"<<endl;
	
	return endingBalance;
}

BankAccount enterAccountData(){
	BankAccount acc1;
	do{
		cout<<"Input Account Number\t\t: ";
		cin>>acc1.accountNumber;

		if(acc1.accountNumber==0){
			cout<<"Exited from the program"<<"\n";
			system("pause");
			exit(0);
		}

		if(acc1.accountNumber<1000 || acc1.accountNumber>9999){
			cout<<"****************************************"<<endl;
			cout<<"Invalid Account Number!"<<endl;
			cout<<"Check the account number and try again!"<<endl;
			cout<<"****************************************"<<endl;
		}
	}
	while(acc1.accountNumber<1000 || acc1.accountNumber>9999);

	do{
		cout<<"Input Account "<<acc1.accountNumber<<" Balance 	: $";
		cin>>acc1.accountBalance;

		if(acc1.accountBalance<0 || acc1.accountBalance>100000){
			cout<<"****************************************"<<endl;
			cout<<"Warning! Account Balance cannot be a (-)tive value or a value greater than $100,000"<<endl;
			cout<<"Please re-enter again!"<<endl;
			cout<<"****************************************"<<endl;
		}
	}
	while(acc1.accountBalance<0 || acc1.accountBalance>100000);

	cout<<"Input Customer Name		: ";
	cin>>acc1.customerName;
	cout<<"Input Password			: ";
	cin>>acc1.password;

	do{
		cout<<"Input Interest Rate		: ";
		cin>>acc1.interestRate;
		acc1.interestRate/=100;

		if(acc1.interestRate<0.01 || acc1.interestRate>15){
			cout<<"****************************************"<<endl;
			cout<<"Warning! Invalid Interest Rate."<<endl;
			cout<<"Please re-enter again!"<<endl;
			cout<<"****************************************"<<endl;
		}
	}
	while(acc1.interestRate<0.01 || acc1.interestRate>15);
	cout<<endl;

	return acc1;
}

void displayAccount(int accountNumber, double accountBalance, string customerName)
{
	cout<<"----------------------------------------"<<endl;
	cout<<"Account Number			: "<<accountNumber<<endl;
	cout<<"Account Balance			: $"<<accountBalance<<endl;
	cout<<"Customer Name			: "<<customerName<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<endl;
}

void computeInterest(double accountBalance, double interestRate)
{
	cout<<"----------------------------------------"<<endl;
	int year;
	cout<<"Enter the number of years : ";
	cin>>year;

	double Balance=accountBalance;

	for(int i=1; i<=year; i++){
		for(int j=1; j<=12;j++){
			Balance+=Balance*interestRate/12;
		}
		cout<<"Year "<<i<<" end balance is "<<Balance<<endl;
	}
	cout<<endl;
}

void dataPersistency(string customer_Name, string customer_Password, int accountNumber, double interestRate)
{
	ofstream BankAccountFile;
	BankAccountFile.open("BankAccountDetails.txt", ofstream::out | ofstream::app);

	BankAccountFile << endl;
	BankAccountFile<<"Customer Name is : \t"<<customer_Name<<endl;
	BankAccountFile<<"Customer Password is : \t"<<customer_Password<<endl;
	BankAccountFile<<"Account Number is : \t"<<accountNumber<<endl;
	BankAccountFile<<"Monthly Interest is :\t"<<interestRate<<endl;
	BankAccountFile << endl;

	cout << "Bank Account Details Text File Created Successfully " << endl;

	string fileLines;
	ifstream readFile("BankAccountDetails.txt");

	if (readFile.is_open())
	{
		while (getline(readFile, fileLines))
		{
			cout << fileLines << '\n';
		}
		readFile.close();
	}

	else
	{
		cout << "Unable To Open File";
	}
	system("pause");
}

void viewTransaction(int accountNumber, double accountBalance){
		cout<<"----------------------------------------"<<endl;
		cout<<"Account Number			: "<<accountNumber<<endl;
		cout<<"Ending Balance			: $"<<accountBalance<<endl;
		cout<<"----------------------------------------"<<endl;
		cout<<endl;
}