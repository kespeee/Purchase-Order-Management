#pragma once

#ifndef PR
#define PR

#include "stdafx.h"
#include "Supplier.h"

class Item {
private:
	int itemID;
	string itemName;
	int supplierID;
	int quantity;

public:
	Item(int itemID, string itemName, int supplierID, int quantity){
		this->itemID = itemID;
		this->itemName = itemName;
		this->supplierID = supplierID;
		this->quantity = quantity;
	}

	Item(){}

	~Item(){}

	void setItemID(int itemID){
		this->itemID = itemID;
	}

	int getItemID(){
		return itemID;
	}

	void setItemName(string itemName){
		this->itemName = itemName;
	}

	string getItemName(){
		return itemName;
	}

	void setSupplierID(int supplierID){
		this->supplierID = supplierID;
	}

	int getSupplierID(){
		return supplierID;
	}

	void setQuantity(int quantity){
		this->quantity = quantity;
	}

	int getQuantity(){
		return quantity;
	}
};

#endif