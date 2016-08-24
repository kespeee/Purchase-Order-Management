#pragma once


#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Supplier{
private:
	int supplierID;
	string supplierName;
public:
	Supplier(int supplierID, string name){
		this->supplierID = supplierID;
		this->supplierName = supplierName;
	}

	Supplier(){}

	~Supplier(){}

	void setSupplierID(int supplierID){
		this->supplierID = supplierID;
	}

	int getSupplierID(){
		return supplierID;
	}

	void setSupplierName(string supplierName){
		this->supplierName = supplierName;
	}

	string getSupplierName(){
		return supplierName;
	}
};

