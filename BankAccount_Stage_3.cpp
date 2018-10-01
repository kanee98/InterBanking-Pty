/**  
* Created by KanishkaUdapitiya on 02/01/2018.  
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <vector>
#include <Windows.h>
#include <fstream>

using namespace std;

struct BankAccount{
	int accountNumber;
	double accountBalance;
	char customerName[100];
	char password[25];
	double interestRate;
};

double savings_plan(double, double, double, double, int);

int main(){
	BankAccount acc[2];

	double automaticDeposit;
	double automaticWithdrawal;

	cout<<" *** Welcome to InterBanking Pty ***"<<endl;
	cout<<"---------------------------------------"<<endl;
	
	int x=0;
	int y=1;
	while(x<2){
		do{
			cout<<"Input Account Number "<<y<<"		: ";
			cin>>acc[x].accountNumber;

			if((acc[x].accountNumber<1000 || acc[x].accountNumber>9999)||(acc[x].accountNumber==acc[x-1].accountNumber)){
				cout<<"****************************************"<<endl;
				cout<<"Invalid Account Number!"<<endl;
				cout<<"Check the account number and try again!"<<endl;
				cout<<"****************************************"<<endl;
			}
		}
		while((acc[x].accountNumber<1000 || acc[x].accountNumber>9999)||(acc[x].accountNumber==acc[x-1].accountNumber));

		do{
			cout<<"Input Account "<<acc[x].accountNumber<<" Balance 	: $";
			cin>>acc[x].accountBalance;

			if(acc[x].accountBalance<0 || acc[x].accountBalance>100000){
				cout<<"****************************************"<<endl;
				cout<<"Warning! Account Balance cannot be a (-)tive value or a value greater than $100,000"<<endl;
				cout<<"Please re-enter again!"<<endl;
				cout<<"****************************************"<<endl;
			}
		}
		while(acc[x].accountBalance<0 || acc[x].accountBalance>100000);

		cout<<"Input Customer Name		: ";
		cin>>acc[x].customerName;
		cout<<"Input Password			: ";
		cin>>acc[x].password;

		do{
			cout<<"Input Interest Rate		: ";
			cin>>acc[x].interestRate;
			acc[x].interestRate/=100;

			if(acc[x].interestRate<0.01 || acc[x].interestRate>15){
				cout<<"****************************************"<<endl;
				cout<<"Warning! Invalid Interest Rate."<<endl;
				cout<<"Please re-enter again!"<<endl;
				cout<<"****************************************"<<endl;
			}
		}
		while(acc[x].interestRate<0.01 || acc[x].interestRate>15);
		cout<<endl;

		x++;
		y++;
	}	

	int a=0;
	int b=1;
	while(a<2){
		cout<<" ** Display Details of "<<b<<" Account **"<<endl;
		cout<<"----------------------------------------"<<endl;
		cout<<"Account Number			: "<<acc[a].accountNumber<<endl;
		cout<<"Account Balance			: $"<<acc[a].accountBalance<<endl;
		cout<<"Customer Name			: "<<acc[a].customerName<<endl;
		cout<<"Password			: "<<acc[a].password<<endl;
		cout<<"----------------------------------------"<<endl;
		cout<<endl;
		a++;
		b++;
	}

	cout<<"Input Automatic Deposit Value	: $";
	cin>>automaticDeposit;
	cout<<"Input Automatic Withdrawal Value: $";
	cin>>automaticWithdrawal;
	cout<<endl;

	int accountNumber[2];
	string customerName[2];

	int r=0;
	int s=1;
	while(r<2){
		cout<<" ** Enter The Following Account Details **"<<endl;
		cout<<"----------------------------------------"<<endl;
		do{
			cout<<"Input Account Number "<<s<<"		: ";
			cin>>accountNumber[r];

			if(accountNumber[r] != acc[r].accountNumber){
			cout<<"****************************************"<<endl;
			cout<<"Warning! Enter a Valid Account Number"<<endl;
			cout<<"****************************************"<<endl;
			}
		}
		while(accountNumber[r] != acc[r].accountNumber);

		do{
			cout<<"Input Customer Name "<<s<<"		: ";
			cin>>customerName[r];

			if(customerName[r] != acc[r].customerName){
				cout<<"****************************************"<<endl;
				cout<<"Warning! Enter a Valid Customer Name"<<endl;
				cout<<"****************************************"<<endl;
			}
		}
		while(customerName[r] != acc[r].customerName);	

		cout<<endl;
		cout<<" ** View Account Details "<<s<<" Account **"<<endl;
		cout<<"----------------------------------------"<<endl;
		cout<<"The Account Number is		: "<<acc[r].accountNumber<<endl;
		cout<<"The Account Balance is		: $"<<acc[r].accountBalance<<endl;
		cout<<"The Customer Name is		: "<<acc[r].customerName<<endl;
		cout<<endl;
		r++;
		s++;
	}
	
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
		if((acc[0].accountBalance-amount<0)||(acc[1].accountBalance-amount<0)){
			cout<<"****************************************"<<endl;
			cout<<"Insufficient Funds! Transfer Money Aborted."<<endl;
			cout<<"****************************************"<<endl;
		}
		else if((acc[0].accountBalance-amount<10)||(acc[1].accountBalance-amount<10)){
			cout<<"****************************************"<<endl;
			cout<<"Warning! Account Balance is low"<<endl;
			cout<<"****************************************"<<endl;
			if(acc[0].accountNumber==fromAccountNumber){
				acc[0].accountBalance-=amount;
				acc[1].accountBalance+=amount;
			}
			else{
				acc[1].accountBalance-=amount;
				acc[0].accountBalance+=amount;
			}
		}
		else{
			if(acc[0].accountNumber==fromAccountNumber){
				acc[0].accountBalance-=amount;
				acc[1].accountBalance+=amount;
			}
			else{
				acc[1].accountBalance-=amount;
				acc[0].accountBalance+=amount;
			}
		}
		if((acc[0].accountBalance>100000)||(acc[1].accountBalance>100000)){
			cout<<"****************************************"<<endl;
			cout<<"Warning! Account Balance is too high"<<endl;
			cout<<"****************************************"<<endl;
		}
	}

	int p=0;
	int q=1;
	while(p<2){
		cout<<" ** Display Details of "<<q<<" Account **"<<endl;
		cout<<"----------------------------------------"<<endl;
		cout<<"Account Number			: "<<acc[p].accountNumber<<endl;
		cout<<"Ending Balance			: $"<<acc[p].accountBalance<<endl;
		cout<<"----------------------------------------"<<endl;
		cout<<endl;
		p++;
		q++;
	}

	cout<<" * * * * >>>>> Bank Statement for Account No."<<acc[0].accountNumber<<"<<<<< * * * * "<<endl;
	double end_Balance1 = savings_plan(acc[0].accountBalance, automaticDeposit, automaticWithdrawal, acc[0].interestRate, 5);
	cout<<" * * * * >>>>> Bank Statement for Account No."<<acc[1].accountNumber<<"<<<<< * * * * "<<endl;
	double end_Balance2 = savings_plan(acc[1].accountBalance, automaticDeposit, automaticWithdrawal, acc[1].interestRate, 5);

	system("pause");
	return 0;

	string  output;

	ifstream inFile;
	inFile.open("text.txt");
	while(getline(inFile,output)){
		cout<<output;
	}

	inFile.close();
}

double savings_plan(double startingBalance, double automaticDeposit, double automaticWithdrawal, double interestRate, int years){
	int month;
	double endingBalance=0, interest=0;
	
	cout<<"------------------------------------------------------------------"<<endl;
	std::cout	<<"| "<<"Year"<<setw(5)	<<"| "
				<<"Month"<<setw(4)	<<"| "
				<<"Starting Balance"<<setw(10)	<<"| "
				<<"End Balance"<<setw(10)	<<"| "<<endl;
	cout<<"------------------------------------------------------------------"<<endl;
	
	for(int year=1; year<=years; year++){
		for(month=1; month<=12; month++){
			interest = startingBalance*(interestRate/12)+automaticDeposit-automaticWithdrawal;
			endingBalance = startingBalance + interest;

			std::cout <<"| "<<year<<setw(8)						<<"| "
							<<month<<setw(8)					<<"| "
							<<"$"<<startingBalance<<setw(10)	<<"| "
							<<"$"<<endingBalance<<setw(10)		<<"|"<<endl;
			cout<<"------------------------------------------------------------------"<<endl;
			
			startingBalance=endingBalance;
		}
	}
	cout<<"****************************************"<<endl;
	cout<<"    * * * * End of statement * * * * "<<endl;
	cout<<"****************************************"<<endl;
	
	return endingBalance;
}