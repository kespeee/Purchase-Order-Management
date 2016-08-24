#pragma once

#include "stdafx.h"
#include "DailyItemWise.h"
#include "DAO.h"
#include <vector>

class DailyItemWiseDAO : public DAO{
private:
	DailyItemWise itemWise;
	vector<DailyItemWise> *itemWises;

public:
	vector<DailyItemWise>* getAllItemWises(){
		itemWises = NULL;
		itemWises = new vector<DailyItemWise>();
		readFile();
		// implementation

		return itemWises;
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

	void readFile(){ // decrement itemwises
		vector<string> fileContent;
		ifstream file("DailyItemWises.txt");
		string stringLine;
		while (getline(file, stringLine))
		{
			fileContent = readLine(stringLine);

			itemWise.setItemWiseID(atoi(fileContent.at(0).c_str()));
			itemWise.setDate(fileContent.at(1));
			itemWise.setItemID(atoi(fileContent.at(2).c_str()));
			itemWise.setTotalSales(atoi(fileContent.at(3).c_str()));
			itemWise.setSalesManagerID(atoi(fileContent.at(4).c_str()));
			itemWises->push_back(itemWise);
		}
	}

	void writeFile(){
		ofstream ofs;
		ofs.open("DailyItemWises.txt", std::ofstream::out | std::ofstream::trunc);

		for (unsigned int i = 0; i < itemWises->size(); i++) {
			ofs << itemWises->at(i).getItemWiseID() << delimeter << itemWises->at(i).getDate() << delimeter << itemWises->at(i).getItemID() << delimeter << itemWises->at(i).getTotalSales() << delimeter << itemWises->at(i).getSalesManagerID() << endl;
		}

		ofs.close();
	}

	void open(){}

	void save(vector<DailyItemWise> *itemWises){
		this->itemWises = itemWises;
		writeFile();
	}

	void close(){}
};