/**  
* Created by KanishkaUdapitiya on 03/12/2017.  
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct BankAccount{
	int accountNumber;
	double accountBalance;
	char customerName[100];
	char password[25];
};

int main(){
	BankAccount acc[2];

	cout<<" *** Welcome to InterBanking Pty ***"<<endl;
	cout<<"---------------------------------------"<<endl;
	
	do{
		cout<<"Input Account Number 1		: ";
		cin>>acc[0].accountNumber;

		if(acc[0].accountNumber<1000 || acc[0].accountNumber>9999){
			cout<<"****************************************"<<endl;
			cout<<"Invalid Account Number!"<<endl;
			cout<<"Check the account number and try again!"<<endl;
			cout<<"****************************************"<<endl;
		}
	}
	while(acc[0].accountNumber<1000 || acc[0].accountNumber>9999);

	do{
		cout<<"Input Account "<<acc[0].accountNumber<<" Balance 	: $";
		cin>>acc[0].accountBalance;

		if(acc[0].accountBalance<0){
			cout<<"****************************************"<<endl;
			cout<<"Warning! Account Balance cannot be a (-)tive value."<<endl;
			cout<<"Please enter a postive value"<<endl;
			cout<<"****************************************"<<endl;
		}
	}
	while(acc[0].accountBalance<0);

	cout<<"Input Customer Name		: ";
	cin>>acc[0].customerName;
	cout<<"Input Password			: ";
	cin>>acc[0].password;
	cout<<endl;

	do{
		cout<<"Input Account Number 2		: ";
		cin>>acc[1].accountNumber;

		if((acc[1].accountNumber<1000 || acc[1].accountNumber>9999)||(acc[0].accountNumber==acc[1].accountNumber)){
			cout<<"****************************************"<<endl;
			cout<<"Invalid Account Number!"<<endl;
			cout<<"Check the account number and try again!"<<endl;
			cout<<"****************************************"<<endl;
		}
	}
	while((acc[1].accountNumber<1000 || acc[1].accountNumber>9999)||(acc[0].accountNumber==acc[1].accountNumber));

	do{
		cout<<"Input Account "<<acc[1].accountNumber<<" Balance 	: $";
		cin>>acc[1].accountBalance;

		if(acc[1].accountBalance<0){
			cout<<"****************************************"<<endl;
			cout<<"Warning! Account Balance cannot be a (-)tive value."<<endl;
			cout<<"Please enter a postive value"<<endl;
			cout<<"****************************************"<<endl;
		}
	}
	while(acc[1].accountBalance<0);

	cout<<"Input Customer Name		: ";
	cin>>acc[1].customerName;
	cout<<"Input Password			: ";
	cin>>acc[1].password;
	cout<<endl;

	cout<<" ** Display Details of First Account **"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"Account Number			: "<<acc[0].accountNumber<<endl;
	cout<<"Account Balance			: $"<<acc[0].accountBalance<<endl;
	cout<<"Customer Name			: "<<acc[0].customerName<<endl;
	cout<<"Password			: "<<acc[0].password<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<endl;

	cout<<" ** Display Details of Second Account **"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"Account Number			: "<<acc[1].accountNumber<<endl;
	cout<<"Account Balance			: $"<<acc[1].accountBalance<<endl;
	cout<<"Customer Name			: "<<acc[1].customerName<<endl;
	cout<<"Password			: "<<acc[1].password<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<endl;

	int accountNumber1, accountNumber2;
	string customerName1, customerName2;

	cout<<" ** Enter The Following Account Details **"<<endl;
	cout<<"----------------------------------------"<<endl;

	do{
		cout<<"Input Account Number 1		: ";
		cin>>accountNumber1;

		if(accountNumber1 != acc[0].accountNumber){
			cout<<"****************************************"<<endl;
			cout<<"Warning! Enter a Valid Account Number"<<endl;
			cout<<"****************************************"<<endl;
		}
	}
	while(accountNumber1 != acc[0].accountNumber);

	do{
		cout<<"Input Customer Name 1		: ";
		cin>>customerName1;

		if(customerName1 != acc[0].customerName){
			cout<<"****************************************"<<endl;
			cout<<"Warning! Enter a Valid Customer Name"<<endl;
			cout<<"****************************************"<<endl;
		}
	}
	while(customerName1 != acc[0].customerName);	

	cout<<endl;
	cout<<" ** View Account Details First Account **"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"The Account Number is		: "<<acc[0].accountNumber<<endl;
	cout<<"The Account Balance is		: $"<<acc[0].accountBalance<<endl;
	cout<<"The Customer Name is		: "<<acc[0].customerName<<endl;
	cout<<endl;

	cout<<" ** Enter The Following Account Details **"<<endl;
	cout<<"----------------------------------------"<<endl;

	do{
		cout<<"Input Account Number 2		: ";
		cin>>accountNumber2;

		if(accountNumber2 != acc[1].accountNumber){
			cout<<"****************************************"<<endl;
			cout<<"Warning! Enter a Valid Account Number"<<endl;
			cout<<"****************************************"<<endl;
		}
	}
	while(accountNumber2 != acc[1].accountNumber);

	do{
		cout<<"Input Customer Name 2		: ";
		cin>>customerName2;

		if(customerName2 != acc[1].customerName){
			cout<<"****************************************"<<endl;
			cout<<"Warning! Enter a Valid Customer Name"<<endl;
			cout<<"****************************************"<<endl;
		}
	}
	while(customerName2 != acc[1].customerName);	

	cout<<endl;
	cout<<" ** View Account Details Second Account **"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"The Account Number is		: "<<acc[1].accountNumber<<endl;
	cout<<"The Account Balance is		: $"<<acc[1].accountBalance<<endl;
	cout<<"The Customer Name is		: "<<acc[1].customerName<<endl;
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

	cout<<" ** Display Details of First Account **"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"Account Number			: "<<acc[0].accountNumber<<endl;
	cout<<"Ending Balance			: $"<<acc[0].accountBalance<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<endl;

	cout<<" ** Display Details of Second Account **"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"Account Number			: "<<acc[1].accountNumber<<endl;
	cout<<"Ending Balance			: $"<<acc[1].accountBalance<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<endl;

	system("pause");
	return 0;
}

