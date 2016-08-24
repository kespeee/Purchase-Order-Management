#pragma once

#include "stdafx.h"
#include "Supplier.h"
#include "DAO.h"


class SuppliersDAO : public DAO{
private:
	Supplier supplier;
	vector<Supplier> *suppliers;

public:

	vector<Supplier>* getAllSuppliers(){
		suppliers = NULL;
		suppliers = new vector<Supplier>();
		readFile();

		return suppliers;
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
		ifstream file("Suppliers.txt");
		string stringLine;
		while (getline(file, stringLine))
		{
			fileContent = readLine(stringLine);

			supplier.setSupplierID(atoi(fileContent.at(0).c_str()));
			supplier.setSupplierName(fileContent.at(1));
			suppliers->push_back(supplier);
		}
	}

	void writeFile(){
		ofstream ofs;
		ofs.open("Suppliers.txt", std::ofstream::out | std::ofstream::trunc);

		for (unsigned int i = 0; i < suppliers->size(); i++) {
			ofs << suppliers->at(i).getSupplierID() << delimeter << suppliers->at(i).getSupplierName() << endl;
		}

		ofs.close();
	}

	void open(){}

	void save(vector<Supplier> *suppliers){
		this->suppliers = suppliers;
		writeFile();
	}

	void close(){}
};