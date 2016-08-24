#pragma once

#include "stdafx.h"
#include "User.h"
#include "SalesManager.h"
#include "DAO.h"
#include <vector>

class UsersDAO : public DAO{
private:
	User user;
	vector<User> *users;

public:

	vector<User>* getAllUsers(){
		users = NULL;
		users = new vector<User>();
		
		readFile();

		return users;
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
		ifstream file("Users.txt");
		string stringLine;
		while (getline(file, stringLine))
		{
			fileContent = readLine(stringLine);

			user.setUserID(atoi(fileContent.at(0).c_str()));
			user.setPassword(fileContent.at(1));
			user.setCategory(fileContent.at(2));
			user.setFirstName(fileContent.at(3));
			user.setLastName(fileContent.at(4));
			users->push_back(user);
		}
	}

	void writeFile(){
		ofstream ofs;
		ofs.open("Users.txt", std::ofstream::out | std::ofstream::trunc);

		for (unsigned int i = 0; i < users->size(); i++) {
			ofs << users->at(i).getUserID() << delimeter << users->at(i).getPassword() << delimeter << users->at(i).getCategory() << delimeter << users->at(i).getFirstName() << delimeter << users->at(i).getLastName() << endl;
		}

		ofs.close();
	}

	void open(){}

	void save(vector<User> *users){
		this->users = users;
		writeFile();
	}

	void close(){}

};