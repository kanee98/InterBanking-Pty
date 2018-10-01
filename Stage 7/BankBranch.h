/**  
* Created by KanishkaUdapitiya on 02/04/2018.  
*/

#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class BankBranch{
private:
	int bsbNumber;
	string address;
	int postCode;

public:
	BankBranch(int, string, int);
	int getBSB();
	string getAddress();
	int getPostCode();
};

