#pragma once

#include "stdafx.h"
#include "PurchaseOrder.h"
#include "DAO.h"
#include <vector>

class PurchaseOrdersDAO : public DAO{
private:
	PurchaseOrder purchaseOrder;
	vector<PurchaseOrder> *purchaseOrders;

public:

	vector<PurchaseOrder>* getAllPurchaseOrders(){
		purchaseOrders = NULL;
		purchaseOrders = new vector<PurchaseOrder>();
		readFile();

		return purchaseOrders;
	}

	vector<string> readLine(string stringLine){
		vector<string> fileContent;
		int count = 0;

		istringstream iss(stringLine);
		string word;

		while (iss >> word) {
			fileContent.push_back(word);
			count++;
		}

		return fileContent;
	}

	void readFile(){
		vector<string> fileContent;
		ifstream file("PurchaseOrders.txt");
		string stringLine;
		while (getline(file, stringLine))
		{
			fileContent = readLine(stringLine);

			purchaseOrder.setPurchaseOrderID(atoi(fileContent.at(0).c_str()));
			purchaseOrder.setPurchaseManagerID(atoi(fileContent.at(1).c_str()));
			purchaseOrder.setPurchaseRequisitionID(atoi(fileContent.at(2).c_str()));
			purchaseOrder.setDate(fileContent.at(3));
			purchaseOrders->push_back(purchaseOrder);
		}
	}

	void writeFile(){
		ofstream ofs;
		ofs.open("PurchaseOrders.txt", std::ofstream::out | std::ofstream::trunc);

		for (unsigned int i = 0; i < purchaseOrders->size(); i++) {
			ofs << purchaseOrders->at(i).getPurchaseOrderID() << delimeter << purchaseOrders->at(i).getPurchaseManagerID() << delimeter << purchaseOrders->at(i).getPurchaseRequisitionID() << delimeter << purchaseOrders->at(i).getDate() << endl;
		}

		ofs.close();
	}

	void open(){}

	void save(vector<PurchaseOrder> *purchaseOrders){
		this->purchaseOrders = purchaseOrders;
		writeFile();
	}

	void close(){}

};