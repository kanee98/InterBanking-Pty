/**  
* Created by KanishkaUdapitiya on 21/11/2017.  
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
	BankAccount obj;

	cout<<"Welcome to InterBanking Pty"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"Input Account Number	: ";
	cin>>obj.accountNumber;
	cout<<"Input Account Balance	: $";
	cin>>obj.accountBalance;
	cout<<"Input Customer Name	: ";
	cin>>obj.customerName;
	cout<<"Input Password		: ";
	cin>>obj.password;
	cout<<""<<endl;

	cout<<"Display Details"<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"Account Number	: "<<obj.accountNumber<<endl;
	cout<<"Account Balance	: $"<<obj.accountBalance<<endl;
	cout<<"Customer Name	: "<<obj.customerName<<endl;
	cout<<"Password	: "<<obj.password<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<""<<endl;

	int accountNumber;
	string customerName;

	cout<<"Input Account Number	: ";
	cin>>accountNumber;
	cout<<"Input Customer Name	: ";
	cin>>customerName;
	cout<<""<<endl;

	if((accountNumber == obj.accountNumber) && (customerName == obj.customerName)){
		cout<<"View Account Details"<<endl;
		cout<<"--------------------------------"<<endl;
		cout<<"The Account Number is	: "<<obj.accountNumber<<endl;
		cout<<"The Account Balance is	: $"<<obj.accountBalance<<endl;
		cout<<"The Customer Name is	: "<<obj.customerName<<endl;
	}
	else{
		cout<<"Warning! Customer Records are not in the database"<<endl;
	}  

	system("pause");
	return 0;
}

