#pragma once

#include "stdafx.h"
#include "SalesManager.h"
#include "PurchaseManager.h"
#include "UsersDAO.h"

class Administrator : public SalesManager, public PurchaseManager{
public:
	Administrator(int userID, string password, string firstName, string lastName) :
		SalesManager(userID, password, firstName, lastName), PurchaseManager(userID, password, firstName, lastName){
		category = "Administrator";
	}

	Administrator(){}

	~Administrator(){}

	void displayMenu(){
		int option;
		cout << endl;
		cout << "--- MAIN MENU ---" << endl;
		cout << "1. Items" << endl;
		cout << "2. Suppliers" << endl;
		cout << "3. Daily Item Wise" << endl;
		cout << "4. Purchase Requisitions" << endl;
		cout << "5. Purchase Orders" << endl;
		cout << "6. Users" << endl;
		cout << "7. Exit" << endl;
		cout << "Option: ";
		cin >> option;

		switch (option){
		case 1: {
					cout << " | --- ITEMS ---" << endl;
					SalesManager::displayItems();
					cout << endl;
					cout << " | 1. Add new item" << endl;
					cout << " | 2. Edit item" << endl;
					cout << " | 3. Delete item" << endl;
					cout << " | 4. Main menu" << endl;
					cout << " | Option: ";
					cin >> option;

					switch (option) {
					case 1: {
								addItem();
								break;
					}
					case 2: {
								editItem();
								break;
					}
					case 3: {
								deleteItem();
								break;
					}
					case 4: {
								displayMenu();
								break;
					}
					default: {
								 cout << " * Invalid input!" << endl;
								 displayMenu();
								 break;
					}
					}

					break;
		}
		case 2: {
					cout << " | --- SUPPLIERS ---" << endl;
					SalesManager::displaySuppliers();
					cout << endl;
					cout << " | 1. Add new supplier" << endl;
					cout << " | 2. Edit supplier" << endl;
					cout << " | 3. Delete supplier" << endl;
					cout << " | 4. Main menu" << endl;
					cout << " | Option: ";
					cin >> option;

					switch (option) {
					case 1: {
								addSupplier();
								break;
					}
					case 2: {
								editSupplier();
								break;
					}
					case 3: {
								deleteSupplier();
								break;
					}
					case 4: {
								displayMenu();
								break;
					}
					default: {
								 cout << " * Invalid input!" << endl;
								 displayMenu();
								 break;
					}
					}
					break;
		}
		case 3: {

					cout << " | --- DAILY ITEM WISE ---" << endl;
					displayDailyItemWises();
					cout << endl;
					cout << " | 1. Add daily item wise" << endl;
					cout << " | 2. Delete item wise" << endl;
					cout << " | 3. Main menu" << endl;
					cout << " | Option: ";
					cin >> option;

					switch (option) {
					case 1: {
								addDailyItemWise();
								break;
					}
					case 2: {
								deleteDailyItemWise();
								break;
					}
					case 3: {
								displayMenu();
								break;
					}

					default: {
								 cout << " * Invalid input!" << endl;
								 displayMenu();
								 break;
					}
					}
					break;
		}
		case 4: {
					cout << " | --- PURCHASE REQUISITIONS ---" << endl;
					SalesManager::displayPurchaseRequisitions();
					cout << endl;
					cout << " | 1. Add purchase requisition" << endl;
					cout << " | 2. Delete purchase requisition" << endl;
					cout << " | 3. Main menu" << endl;
					cout << " | Option: ";
					cin >> option;

					switch (option) {
					case 1: {
								addPurchaseRequisition();
								break;
					}
					case 2: {
								deletePurchaseRequisition();
								break;
					}
					case 3: {
								displayMenu();
								break;
					}

					default: {
								 cout << " * Invalid input!" << endl;
								 displayMenu();
								 break;
					}
					}
					break;
		}
		case 5: {
					cout << " | --- PURCHASE ORDERS ---" << endl;
					PurchaseManager::displayPurchaseOrders();
					cout << endl;
					cout << " | 1. Add Purchase Order" << endl;
					cout << " | 2. Delete Purchase Order" << endl;
					cout << " | 3. Main menu" << endl; \
						cout << " | Option: ";

					cin >> option;

					switch (option) {
					case 1: {
								addPurchaseOrder();
								break;
					}
					case 2: {
								deletePurchaseOrders();
								break;
					}
					case 3: {
								displayMenu();
								break;
					}

					default: {
								 cout << " * Invalid input!" << endl;
								 displayMenu();
								 break;
					}
					}
					break;
		}
		case 6: {
					cout << " | --- USERS ---" << endl;
					displayUsers();
					cout << endl;
					cout << " | 1. Add User" << endl;
					cout << " | 2. Edit User" << endl;
					cout << " | 3. Delete User" << endl;
					cout << " | 4. Main menu" << endl; \
						cout << " | Option: ";

					cin >> option;

					switch (option) {
					case 1: {
								addUser();
								break;
					}
					case 2: {
								editUser();
								break;
					}
					case 3: {
								deleteUser();
								break;
					}
					case 4: {
								displayMenu();
								break;
					}

					default: {
								 cout << " * Invalid input!" << endl;
								 displayMenu();
								 break;
					}
					}
					break;
		}
		case 7: {
					cout << " * The session is finished. Good bye!" << endl;
					break;
		}
		default: {
					 cout << " * Invalid input!" << endl;
					 displayMenu();
					 break;
		}
	}
	}

private:

	void displayUsers(){
		vector<User> *users = NULL;

		UsersDAO usersDAO;
		users = usersDAO.getAllUsers();
		if (users->size() != 0){
			for (unsigned int i = 0; i < users->size(); i++) {
				cout << users->at(i).getUserID() << " " << users->at(i).getPassword() << " " << users->at(i).getCategory() << " " << users->at(i).getFirstName() << " " << users->at(i).getLastName() << endl;
			}
		}
	}

	void addUser(){
		// adds a new user

		// ADD USER - LEVEL 1

		cout << "   | --- ADD NEW USER ---" << endl;

		User user;
		vector<User> *users = NULL;
		UsersDAO usersDAO;
		users = usersDAO.getAllUsers();

		string firstName, lastName, password; 
		int category;

		if (users->size() == 0){
			users = new vector<User>();
			user.setUserID(1);
		}
		else {
			unsigned int size = users->size();
			user.setUserID((users->at(size - 1).getUserID()) + 1);
		}

		cout << "   | Select Cateogory: " << endl;
		cout << "   | 1. Sales Manager" << endl;
		cout << "   | 2. Purchase Manager" << endl;
		cin >> category;

		switch (category){
		case 1: {
					user.setCategory("SalesManager");
					break;
		}
		case 2: {
					user.setCategory("PurchaseManager");
					break;
		}
		
		default: {
					 cout << " * Invalid input! The operation is aborted.\n" << endl;
					 displayMenu();
					 break;
		}
		}

		cout << "   | Password: ";
		cin >> password;
		cout << "   | First Name: ";
		cin >> firstName;
		cout << "   | Last Name: ";
		cin >> lastName;

		user.setFirstName(firstName);
		user.setLastName(lastName);
		user.setPassword(password);

		users->push_back(user);
		usersDAO.save(users);

		cout << " * New user (ID: " << user.getUserID() << ") has been successfully added!\n" << endl;
		displayMenu();
	}

	void editUser(){
		// edits item info

		// EDIT ITEM - LEVEL 1

		cout << "   | --- EDIT USER ---" << endl;

		vector<User> *users = NULL;
		UsersDAO usersDAO;
		users = usersDAO.getAllUsers();

		unsigned int id;
		string firstName;
		string lastName;

		cout << "   | User ID: ";
		cin >> id;

		bool exist = false;

		if (users->size() == 0){
			cout << " * User with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
			displayMenu();
		}
		else {
			for (unsigned int i = 0; i < users->size(); i++){
				if (users->at(i).getUserID() == id){
					cout << "   | First Name (Current first name = " << users->at(i).getFirstName() << "): ";
					cin >> firstName;

					cout << "   | Last Name (Current last name = " << users->at(i).getLastName() << "): ";
					cin >> lastName;

					exist = true;
					users->at(i).setFirstName(firstName);
					users->at(i).setLastName(lastName);

					usersDAO.save(users);

					cout << " * User (ID: " << users->at(i).getUserID() << ") has been successfully edited!\n" << endl;
					displayMenu();
					break;
				}
			}

			if (!exist){
				cout << " * User with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
				displayMenu();
			}
		}
	}

	void deleteUser(){
		// deletes item

		// DELETE ITEM - LEVEL 1

		cout << "   | --- DELETE USER ---" << endl;

		vector<User> *users = NULL;
		UsersDAO usersDAO;
		users = usersDAO.getAllUsers();

		int id;

		cout << "   | User ID: ";
		cin >> id;

		bool exist = false;

		if (users->size() == 0){
			cout << " * User with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
			displayMenu();
		}
		else {
			for (unsigned int i = 0; i < users->size(); i++){
				if (users->at(i).getUserID() == id){

					users->erase(users->begin() + i);
					exist = true;
					usersDAO.save(users);
					cout << " * User (ID: " << id << ") has been successfully deleted!\n" << endl;
					displayMenu();
					break;
				}
			}

			if (!exist) {
				cout << " * User with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
				displayMenu();
			}
		}
	}

	void addPurchaseRequisition(){
		// adds purchase requisition

		// ADD PURCHASE REQUISITION - LEVEL 1

		cout << "   | --- ADD NEW PURCHASE REQUISITION ---" << endl;

		PurchaseRequisition purchaseRequisition;
		vector<PurchaseRequisition> *purchaseRequisitions = NULL;
		PurchaseRequisitionDAO purchaseRequisitionDAO;
		purchaseRequisitions = purchaseRequisitionDAO.getAllPurchaseRequisitions();

		int itemID, quantity, salesManagerID;
		Item item;
		bool exist = false;
		ItemsDAO itemsDAO;
		UsersDAO usersDAO;

		if (purchaseRequisitions->size() == 0){
			purchaseRequisitions = new vector<PurchaseRequisition>();
			purchaseRequisition.setPurchaseRequisitionID(1);
		}
		else {
			int size = purchaseRequisitions->size();
			purchaseRequisition.setPurchaseRequisitionID((purchaseRequisitions->at(size - 1).getPurchaseRequisitionID()) + 1);
		}

		cout << "   | Item ID: ";
		cin >> itemID;

		vector<Item> *items = NULL;
		items = itemsDAO.getAllItems();

		if (items->size() != 0) {

			// ADD PURCHASE REQUISITION - LEVEL 2 (Handling Items)

			for (unsigned int i = 0; i < items->size(); i++) {
				if (items->at(i).getItemID() == itemID) {
					item = items->at(i);
					purchaseRequisition.setItemID(item.getItemID());
					exist = true;
					break;
				}
			}

			if (exist) {

				cout << "   | Sales Manager ID: ";
				cin >> salesManagerID;

				vector<User> *users = NULL;
				users = usersDAO.getAllUsers();
				exist = false;

				if (users->size() != 0) {
					

					for (unsigned int i = 0; i < users->size(); i++){
						if (users->at(i).getUserID()==salesManagerID) {
							exist = true;
							if (users->at(i).getCategory()=="SalesManager") {
								cout << "   | Requested quantity: (" << item.getQuantity() << " in stock): ";
								cin >> quantity;

								purchaseRequisition.setQuantity(quantity);
								purchaseRequisition.setDate(getCurrentDate());
								purchaseRequisition.setSalesManagerID(salesManagerID);
								purchaseRequisition.setApproved(false);
								purchaseRequisitions->push_back(purchaseRequisition);
								purchaseRequisitionDAO.save(purchaseRequisitions);

								cout << " * Purchase Requisition (ID: " << purchaseRequisition.getPurchaseRequisitionID() << ") has been successfully added!\n" << endl;
								displayMenu();
								break;
							}
							else {
								exist = false;
							}
						}
					}

					if (!exist) {
						cout << " * Sales Manager with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
						displayMenu();
					}
				}
				else {
					cout << " * Sales Manager with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
					displayMenu();
				}

			}
			else {
				cout << " * Item with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
				displayMenu();
			}

		}
		else {
			cout << " * There are no items stored in the system! The operation is aborted.\n" << endl;
			displayMenu();
		}
	}

	void addPurchaseOrder(){
		// adds purchase order

		// ADD PURCHASE ORDER - LEVEL 1

		cout << "   | --- ADD NEW PURCHASE ORDER ---" << endl;

		PurchaseOrder purchaseOrder;
		vector<PurchaseOrder> *purchaseOrders = NULL;
		PurchaseOrdersDAO purchaseOrdersDAO;
		purchaseOrders = purchaseOrdersDAO.getAllPurchaseOrders();

		int purchaseRequisitionID, quantity, purchaseManagerID;
		PurchaseRequisition purchaseRequisition;
		bool exist = false;
		PurchaseRequisitionDAO purchaseRequisitionDAO;
		UsersDAO usersDAO;
		if (purchaseOrders->size() == 0){
			purchaseOrders = new vector<PurchaseOrder>();
			purchaseOrder.setPurchaseOrderID(1);
		}
		else {
			int size = purchaseOrders->size();
			purchaseOrder.setPurchaseOrderID((purchaseOrders->at(size - 1).getPurchaseOrderID()) + 1);
		}

		cout << "   | Purchase Requisition ID: ";
		cin >> purchaseRequisitionID;

		vector<PurchaseRequisition> *purchaseRequisitions = NULL;
		purchaseRequisitions = purchaseRequisitionDAO.getAllPurchaseRequisitions();

		if (purchaseRequisitions->size() != 0) {

			// ADD PURCHASE REQUISITION - LEVEL 2 (Handling Items)

			for (unsigned int i = 0; i < purchaseRequisitions->size(); i++) {
				if (purchaseRequisitions->at(i).getPurchaseRequisitionID() == purchaseRequisitionID) {

					cout << "   | Purchase Manager ID: ";
					cin >> purchaseManagerID;

					vector<User> *users = NULL;
					users = usersDAO.getAllUsers();
					exist = false;

					if (users->size() != 0) {
						for (unsigned int i = 0; i < users->size(); i++){
							if (users->at(i).getUserID() == purchaseManagerID) {
								exist = true;
								if (users->at(i).getCategory() == "PurchaseManager") {

									purchaseRequisition = purchaseRequisitions->at(i);
									purchaseOrder.setPurchaseRequisitionID(purchaseRequisition.getPurchaseRequisitionID());
									exist = true;

									purchaseOrder.setDate(getCurrentDate());
									purchaseOrder.setPurchaseManagerID(purchaseManagerID);
									purchaseOrders->push_back(purchaseOrder);
									purchaseOrdersDAO.save(purchaseOrders);

									cout << " * Purchase Order (ID: " << purchaseOrder.getPurchaseOrderID() << ") has been successfully added!\n" << endl;
									displayMenu();

									break;
								}
								else {
									exist = false;
								}
							}
						}

						if (!exist) {
							cout << " * Purchase Manager with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
							displayMenu();
						}
					}
				}
			}

			if (!exist){
				cout << " * Purchase Requisition with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
				displayMenu();
			}
		}
		else {
			cout << " * There are no items stored in the system! The operation is aborted.\n" << endl;
			displayMenu();
		}
	}

};