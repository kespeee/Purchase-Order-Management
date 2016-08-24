#ifndef DIW
#define DIW

#pragma once

#include "Item.h"
#include "SalesManager.h"

class DailyItemWise{
private:
	int itemWiseID;
	string date;
	int itemID;
	int totalSales;
	int salesManagerID;

public:
	DailyItemWise(int itemWiseID, string date, int itemID, int totalSales){
		this->itemWiseID = itemWiseID;
		this->date = date;
		this->itemID = itemID;
		this->totalSales = totalSales;
	}

	DailyItemWise(){}

	~DailyItemWise(){}

	void setItemWiseID(int itemWiseID){
		this->itemWiseID = itemWiseID;
	}

	void setDate(string date){
		this->date = date;
	}

	void setItemID( int itemID){
		this->itemID = itemID;
	}

	void setTotalSales(int totalSales){
		this->totalSales = totalSales;
	}

	int getItemWiseID(){
		return itemWiseID;
	}

	string getDate(){
		return date;
	}

	int getItemID(){
		return itemID;
	}

	int getTotalSales(){
		return totalSales;
	}

	int getSalesManagerID(){
		return salesManagerID;
	}

	void setSalesManagerID(int salesManagerID){
		this->salesManagerID = salesManagerID;
	}
};

#endif