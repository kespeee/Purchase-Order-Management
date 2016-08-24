#pragma once


#include "stdafx.h"

class PurchaseOrder{
private:
	int purchaseOrderID;
	int purchaseManagerID;
	int purchaseRequisitionID;
	string date;

public:
	PurchaseOrder(int purchaseOrderID, int purchaseManagerID, int purchaseRequisitionID, string date){
		this->purchaseOrderID = purchaseOrderID;
		this->purchaseManagerID = purchaseManagerID;
		this->purchaseRequisitionID = purchaseRequisitionID;
		this->date = date;
	}

	PurchaseOrder(){}

	~PurchaseOrder(){}

	void setPurchaseOrderID(int purchaseOrderID){
		this->purchaseOrderID = purchaseOrderID;
	}

	int getPurchaseOrderID(){
		return purchaseOrderID;
	}

	void setPurchaseManagerID(int purchaseManagerID){
		this->purchaseManagerID = purchaseManagerID;
	}

	int getPurchaseManagerID(){
		return purchaseManagerID;
	}

	void setPurchaseRequisitionID(int purchaseRequisitionID){
		this->purchaseRequisitionID = purchaseRequisitionID;
	}

	int getPurchaseRequisitionID(){
		return purchaseRequisitionID;
	}

	void setDate(string date){
		this->date = date;
	}

	string getDate(){
		return date;
	}
};
