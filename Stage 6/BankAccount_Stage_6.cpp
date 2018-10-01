/**  
* Created by KanishkaUdapitiya on 11/01/2018.  
*/

#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include "BankAccount.h"

using namespace std;

class Transaction
{
private:
	double amount;
	bool completed;
	BankAccount fromAccount;
	BankAccount toAccount;
	
public:
	Transaction(double, BankAccount*, BankAccount*);
	bool transfer(double amount);
	bool rollback();
};

int main()
{
	BankAccount acc[2];

	string customerName;
	string password;
	string conti;

	cout<<"        - - - - - W E L C O M E ! P L E A S E  L O G I N ! - - - - - "<<endl;
	cout<<"----------------------------------------------------------------------------"<<endl;
	
	cout<<"Input Customer Name		: ";
	cin>>customerName;
	
	for(int i=0; i < customerName.size(); ++i){
		customerName[i]=toupper(customerName[i]);
	}

	cout<<"Input Password			: ";
	cin>>password;

	cout<<"-------------------------- Login Successful ! ------------------------------"<<endl;

	cout<<endl;
	cout<<"                 WELCOME "<<customerName<<" TO INTERBANKING PTY             "<<endl;
	cout<<endl;

	for(int i=0; i<2; i++){
		cout<<"    * * * * * * * * Enter Account Number "<<(i+1)<<" Details * * * * * * * * "<<endl;
		cout<<"----------------------------------------------------------------------------"<<endl;
		acc[i].enterAccountData();
		cout<<"----------------------------------------------------------------------------"<<endl;
		acc[i].displayAccount();
		cout<<"----------------------------------------------------------------------------"<<endl;
	}

	for(int i=0; i<2; i++){
		acc[i].computeInterest();
	}	

	cout<<"Do you want to do any transactions?"<<endl;
	cout<<"type \"yes\" to continue, type \"no\ to terminate the program : ";
	cin>>conti;
	cout<<"----------------------------------------------------------------------------"<<endl;
		
		if(conti != "yes"){
			cout<<"             * * * Thank you for Banking with us! * * * "<<endl;
			cout<<"----------------------------------------------------------------------------"<<endl;
		}

		else{
			cout<<"           Welcome to the Main Menu. Please select your option !"<<endl;
			cout<<"----------------------------------------------------------------------------"<<endl;
			cout<<"			1 - Deposit"<<endl;
			cout<<"			2 - Withdraw"<<endl;
			cout<<"			3 - Transfer Money"<<endl;

			int choice;
			do{
				cout<<"Enter your choice : ";
				cin>>choice;
				cout<<"----------------------------------------------------------------------------"<<endl;
				
				if(choice != 1 && choice != 2 && choice != 3 && choice != 0){
					cout<<"Invalid choice. Re-enter a valid number !"<<endl;
				}

				else if(choice==1){
					for(int i=0; i<2; i++){
						acc[i].deposit();
					}					
				}

				else if(choice==2){
					for(int i=0; i<2; i++){
						acc[i].withdrawal();
					}					
				}

				else if(choice==3){

					int amount;
					string contin;
					cout<<"Enter Amount			: $";
					cin>>amount;
					Transaction trans(amount, &acc[0], &acc[1]);
					trans.transfer(amount);

					cout<<endl;
					cout<<"Do you want to rollback?"<<endl;
					cout<<"type \"yes\" to continue, type \"no\ to terminate the program : ";
					cin>>contin;
					if(contin != "yes"){
						cout<<"             * * * Thank you for Banking with us! * * * "<<endl;
						cout<<"----------------------------------------------------------------------------"<<endl;
					}

					else{
						trans.rollback();
					}
				}

				else if(choice==0){
					cout<<"Exited from the program"<<"\n";
					system("pause");
					exit(0);
				}
			}
			while(choice != 1 && choice != 2 && choice != 3 && choice != 0);
		}

	system("pause");
};

Transaction :: Transaction(double amount, BankAccount* fromAccount, BankAccount* toAccount)
{
	this->completed = false;
	this->amount = amount;
	this->fromAccount = *fromAccount;
	this->toAccount = *toAccount;
};

bool Transaction :: transfer(double amount)
{
	if ((fromAccount.getBalance()-amount)>=0)
	{
		cout<<"             > > > Transaction Completed! < < < "<<endl;
		cout<<"----------------------------------------------------------------------------"<<endl;
		cout<<"From Account Balance		: $"<<fromAccount.getBalance() - amount<<endl;
		cout<<"To Account Balance		: $"<<toAccount.getBalance() + amount<<endl;
		this->completed=true;
	}
	else{
		cout<<"Error! Insufficient Funds !"<<endl;
		this->completed=false;
	}
	return completed;
};

bool Transaction ::rollback(){
	bool rollbackSuccess=false;
	if(completed){
		cout<<"             > > > Rollback Completed! < < < "<<endl;
		cout<<"----------------------------------------------------------------------------"<<endl;
		cout<<"From Account Balance		: $"<<fromAccount.getBalance()<<endl;
		cout<<"To Account Balance		: $"<<toAccount.getBalance()<<endl;
		completed=false;
		rollbackSuccess=true;
	}
	return rollbackSuccess;
}

