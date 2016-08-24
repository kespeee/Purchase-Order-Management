#pragma once

#include "stdafx.h"
#include "Item.h"
#include "DAO.h"
#include <vector>

class ItemsDAO : public DAO{
private:
	Item item;
	vector<Item> *items;

public:

	vector<Item>* getAllItems(){
		items = NULL;
		items = new vector<Item>();
		readFile();

		return items;
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
		ifstream file("Items.txt");
		string stringLine;
		while (getline(file, stringLine))
		{
			fileContent = readLine(stringLine);

			item.setItemID(atoi(fileContent.at(0).c_str()));
			item.setItemName(fileContent.at(1));
			item.setQuantity(atoi(fileContent.at(2).c_str()));
			item.setSupplierID(atoi(fileContent.at(3).c_str()));
			items->push_back(item);
		}
	}

	void writeFile(){
		ofstream ofs;
		ofs.open("Items.txt", std::ofstream::out | std::ofstream::trunc);

		for (unsigned int i = 0; i < items->size(); i++) {
			ofs << items->at(i).getItemID() << delimeter << items->at(i).getItemName() << delimeter << items->at(i).getQuantity() << delimeter << items->at(i).getSupplierID() << endl;
		}

		ofs.close();
	}

	void open(){}

	void save(vector<Item> *items){
		this->items = items;
		writeFile();
	}


	void close(){}
};