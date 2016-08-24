#pragma once

#include "Item.h"

class PurchaseRequisition{
private:
	int purchaseRequsitionID;
	int salesManagerID;
	int itemID;
	int quantity;
	string date;
	bool approved;

public:
	PurchaseRequisition(int purchaseRequisitionID, int salesManagerID, int itemID, int quantity, string date, bool approved){
		this->purchaseRequsitionID = purchaseRequisitionID;
		this->salesManagerID = salesManagerID;
		this->itemID = itemID;
		this->quantity = quantity;
		this->date = date;
		this->approved = approved;
	}

	PurchaseRequisition(){}

	~PurchaseRequisition(){}

	void setPurchaseRequisitionID(int purchaseRequsitionID){
		this->purchaseRequsitionID = purchaseRequsitionID;
	}

	int getPurchaseRequisitionID(){
		return purchaseRequsitionID;
	}

	void setSalesManagerID(int salesManagerID){
		this->salesManagerID = salesManagerID;
	}

	int getSalesManagerID(){
		return salesManagerID;
	}

	void setItemID(int itemID){
		this->itemID = itemID;
	}

	int getItemID(){
		return itemID;
	}

	void setQuantity(int quantity){
		this->quantity = quantity;
	}

	int getQuantity(){
		return quantity;
	}

	void setDate(string date){
		this->date = date;
	}

	string getDate(){
		return date;
	}

	void setApproved(bool approved){
		this->approved = approved;
	}

	bool isApproved(){
		return approved;
	}
};

