#pragma once


#include "stdafx.h"
#include "SalesManager.cpp"
#include "PurchaseManager.cpp"

class Administrator : public SalesManager, public PurchaseManager{
public:
	Administrator(string userID, string password, string firstName, string lastName) : 
	SalesManager(userID, password, firstName, lastName), PurchaseManager(userID, password, firstName, lastName){
		category = "Administrator";
	}

	Administrator(){}

	~Administrator(){}

	void displayMenu(){
		addPurchaseRequisition();
	}

private:

	void addUser(){}

	void editUser(){}

	void deleteUser(){}

	void addPurchaseRequisition(){}

	void addPurchaseOrder(){}

};