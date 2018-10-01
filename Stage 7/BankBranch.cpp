/**  
* Created by KanishkaUdapitiya on 02/04/2018.  
*/

#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include "BankBranch.h"

BankBranch::BankBranch(int bsbNumber, string addres, int postCode){
	this->bsbNumber = bsbNumber;
	this->address = address;
	this->postCode = postCode;
}

int BankBranch :: getBSB(){
	return this->bsbNumber;
}

string BankBranch :: getAddress(){
	return this->address;
}

int BankBranch :: getPostCode(){
	return this->postCode;
}

