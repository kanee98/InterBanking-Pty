/**  
* Created by KanishkaUdapitiya on 02/04/2018.  
*/

#include "stdafx.h"
#pragma once
#include <iostream>
#include <string>
#include "BankAccount.h"
#include "BankBranch.h"

#define SIZE 5

using namespace std;

template <class T>

void produceReport(string Stage7_Report, T* arr[])
{
	cout<<"		-> -> -> Report <- <- <- "<<endl;
	cout<<"___________________________________________________"<<endl;
	cout << Stage7_Report << endl;
	for(int i=0; i<SIZE; i++){
		cout<<"	* * * Account "<<(i+1)<<" Details * * *"<<endl;
		cout<<"-------------------------------------------------- "<<endl;
		arr[i]->displayAccount();
		cout<<endl;
	}
	cout << "      End of Report " << endl;
}

int main()
{
	int bsbNumber, postCode;
	double accountBalance;
	string address;

	cout<<"***************************************************"<<endl;
	cout<<"	- - - - - W E L C O M E !  - - - - - "<<endl;
	cout<<"***************************************************"<<endl;
	cout<<"	>>>Enter the Branch Details<<< "<<endl;
	cout<<"___________________________________________________"<<endl;
	cout<<"Enter BBS Number\t\t: ";
	cin>>bsbNumber;
	cout<<"Enter Address\t\t\t: ";
	cin>>address;
	cout<<"Enter PostCode\t\t\t: ";
	cin>>postCode;
	cout<<endl;

	BankBranch branch(bsbNumber, address,  postCode);

	CheckingAccountWithInterest* arr[5];

	for (int i = 0; i < SIZE; i++)
	{
		int accountNumber;
		double accountBalance;
		double interestRate = 0.02;
		double monthlyFee;
		int checksPerMonth;

		cout<<"	>>>Enter Account "<<(i+1)<<" Details<<<"<<endl;
		cout<<"___________________________________________________"<<endl;
		cout <<"Enter the Account Balance\t: $";
		cin >> accountBalance;
		cout <<"Interest Rate\t\t\t: " << interestRate<<endl;

		cout << "Enter the monthly fee\t\t: $";
		cin >> monthlyFee;
		cout << "Enter the checks per month	: ";
		cin >> checksPerMonth;
		arr[i] = new CheckingAccountWithInterest(&branch, accountBalance, monthlyFee, checksPerMonth);
		cout<<"___________________________________________________"<<endl;
		cout<<endl;
	}

	produceReport("		* * * Stage_7 Final Report * * * ", arr);

	system("pause");
	return 0;
}



