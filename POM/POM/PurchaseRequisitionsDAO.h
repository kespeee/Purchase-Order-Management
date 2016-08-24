#pragma once

#include "stdafx.h"
#include "PurchaseRequisition.h"
#include "DAO.h"
#include <vector>

class PurchaseRequisitionDAO : public DAO{
private:
	PurchaseRequisition purchaseRequisition;
	vector<PurchaseRequisition> *purchaseRequisitions;

public:

	vector<PurchaseRequisition>* getAllPurchaseRequisitions(){
		purchaseRequisitions = NULL;
		purchaseRequisitions = new vector<PurchaseRequisition>();
		readFile();

		return purchaseRequisitions;
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
		ifstream file("PurchaseRequisitions.txt");
		string stringLine;
		while (getline(file, stringLine))
		{
			fileContent = readLine(stringLine);

			purchaseRequisition.setPurchaseRequisitionID(atoi(fileContent.at(0).c_str()));
			purchaseRequisition.setSalesManagerID(atoi(fileContent.at(1).c_str()));
			purchaseRequisition.setItemID(atoi(fileContent.at(2).c_str()));
			purchaseRequisition.setQuantity(atoi(fileContent.at(3).c_str()));
			purchaseRequisition.setDate(fileContent.at(4));
			purchaseRequisition.setApproved(static_cast<bool>(atoi(fileContent.at(5).c_str())));
			purchaseRequisitions->push_back(purchaseRequisition);
		}
	}

	void writeFile(){
		ofstream ofs;
		ofs.open("PurchaseRequisitions.txt", std::ofstream::out | std::ofstream::trunc);

		for (unsigned int i = 0; i < purchaseRequisitions->size(); i++) {
			ofs << purchaseRequisitions->at(i).getPurchaseRequisitionID() << delimeter << purchaseRequisitions->at(i).getSalesManagerID() << delimeter << purchaseRequisitions->at(i).getItemID() << delimeter << purchaseRequisitions->at(i).getQuantity() << delimeter << purchaseRequisitions->at(i).getDate() << delimeter << purchaseRequisitions->at(i).isApproved() << endl;
		}

		ofs.close();
	}

	void open(){}

	void save(vector<PurchaseRequisition> *purchaseRequisitions){
		this->purchaseRequisitions = purchaseRequisitions;
		writeFile();
	}

	void close(){}

};