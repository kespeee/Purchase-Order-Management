#ifndef USER
#define USER

#pragma once

#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

class User {
protected:
	int userID;
	string password;
	string category;
	string firstName;
	string lastName;

public:
	User(int userID, string password, string category, string firstName, string lastName){
		this->userID = userID;
		this->password = password;
		this->category = category;
		this->firstName = firstName;
		this->lastName = lastName;
	}

	User(){}

	~User(){}

	string getCurrentDate()
	{
		auto t = std::time(nullptr);
		auto tm = *std::localtime(&t);

		std::ostringstream oss;
		oss << std::put_time(&tm, "%d-%m-%Y");
		auto str = oss.str();

		return str;
	}

	virtual void displayMenu(){}

	void setUserID(int userID){
		this->userID = userID;
	}

	int getUserID(){
		return userID;
	}

	void setPassword(string password){
		this->password = password;
	}

	string getPassword(){
		return password;
	}

	void setCategory(string category){
		this->category = category;
	}

	string getCategory(){
		return category;
	}

	void setFirstName(string firstName){
		this->firstName = firstName;
	}

	string getFirstName(){
		return firstName;
	}

	void setLastName(string lastName){
		this->lastName = lastName;
	}

	string getLastName(){
		return lastName;
	}
};

#endif