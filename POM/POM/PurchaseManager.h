#pragma once

#include "stdafx.h"
#include "User.h"

class PurchaseManager : public virtual User{
public:
	PurchaseManager(int userID, string password, string firstName, string lastName) : User(userID, password, "PurchaseManager", firstName, lastName){}

	PurchaseManager(){}

	~PurchaseManager(){}

	void displayMenu(){
		int option;
		cout << endl;
		cout << "--- MAIN MENU ---" << endl;
		cout << "1. Suppliers" << endl;
		cout << "2. Purchase Requisitions" << endl;
		cout << "3. Purchase Orders" << endl;
		cout << "4. Exit" << endl;
		cout << "Option: ";
		cin >> option;

		switch (option){
		case 1: {
					cout << " | --- SUPPLIERS ---" << endl;
					displaySuppliers();
					cout << endl;
					cout << " | 1. Main menu" << endl;
					cout << " | Option: ";
					cin >> option;

					switch (option) {
					case 1: {
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
					cout << " | --- PURCHASE REQUISITIONS ---" << endl;
					displayPurchaseRequisitions();
					cout << endl;
					cout << " | 1. Main menu" << endl;
					cout << " | Option: ";
					cin >> option;

					switch (option) {
					case 1: {
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
					cout << " | --- PURCHASE ORDERS ---" << endl;
					displayPurchaseOrders();
					cout << endl;
					cout << " | 1. Add Purchase Order" << endl;
					cout << " | 2. Delete PurchaseOrder" << endl;
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
		case 4: {
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

protected:

	void displayItems(){
		vector<Item> *items = NULL;

		ItemsDAO itemsDAO;
		items = itemsDAO.getAllItems();
		if (items->size() != 0){
			for (unsigned int i = 0; i < items->size(); i++) {
				cout << items->at(i).getItemID() << " " << items->at(i).getItemName() << " " << items->at(i).getSupplierID() << " " << items->at(i).getQuantity() << endl;
			}
		}
	}

	void displaySuppliers(){
		vector<Supplier> *suppliers = NULL;

		SuppliersDAO suppliersDAO;
		suppliers = suppliersDAO.getAllSuppliers();
		if (suppliers->size() != 0){
			for (unsigned int i = 0; i < suppliers->size(); i++) {
				cout << suppliers->at(i).getSupplierID() << " " << suppliers->at(i).getSupplierName() << endl;
			}
		}
	}

	void displayPurchaseRequisitions(){
		vector<PurchaseRequisition> *purchaseRequisitions = NULL;

		PurchaseRequisitionDAO purchaseRequisitionDAO;
		purchaseRequisitions = purchaseRequisitionDAO.getAllPurchaseRequisitions();
		if (purchaseRequisitions->size() != 0){
			for (unsigned int i = 0; i < purchaseRequisitions->size(); i++) {
				cout << purchaseRequisitions->at(i).getPurchaseRequisitionID() << " " << purchaseRequisitions->at(i).getDate() << " " << purchaseRequisitions->at(i).getItemID() << " " << purchaseRequisitions->at(i).getQuantity() << " " << purchaseRequisitions->at(i).getSalesManagerID();
				if (purchaseRequisitions->at(i).isApproved()){
					cout << "Approved" << endl;
				}
				else {
					cout << "Pending" << endl;
				}
			}
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

		int purchaseRequisitionID, quantity;
		PurchaseRequisition purchaseRequisition;
		bool exist = false;
		PurchaseRequisitionDAO purchaseRequisitionDAO;

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
					purchaseRequisition = purchaseRequisitions->at(i);
					purchaseOrder.setPurchaseRequisitionID(purchaseRequisition.getPurchaseRequisitionID());
					exist = true;

					purchaseOrder.setDate(getCurrentDate());
					purchaseOrder.setPurchaseManagerID(this->userID);
					purchaseOrders->push_back(purchaseOrder);
					purchaseOrdersDAO.save(purchaseOrders);

					cout << " * Purchase Order (ID: " << purchaseOrder.getPurchaseOrderID() << ") has been successfully added!\n" << endl;
					displayMenu();

					break;
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

	void deletePurchaseOrders(){
		// deletes purchase order

		// DELETE PURCHASE ORDER - LEVEL 1

		cout << "   | --- DELETE PURCHASE ORDER ---" << endl;

		vector<PurchaseOrder> *purchaseOrders = NULL;
		PurchaseOrdersDAO purchaseOrdersDAO;
		purchaseOrders = purchaseOrdersDAO.getAllPurchaseOrders();

		int id;

		cout << "   | Purchase Order ID: ";
		cin >> id;

		// add for loop to all delete methods
		if (purchaseOrders->size() == 0){
			cout << " * Purchase Order with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
			displayMenu();
		}
		else {
			for (unsigned int i = 0; i < purchaseOrders->size(); i++){
				if (purchaseOrders->at(i).getPurchaseOrderID() == id){
					purchaseOrders->erase(purchaseOrders->begin() + i);

					purchaseOrdersDAO.save(purchaseOrders);

					cout << " * Purchase Order (ID: " << i << ") has been successfully deleted!\n" << endl;
					displayMenu();
					break;
				}
			}
		}
	}

	void displayPurchaseOrders(){
		vector<PurchaseOrder> *purchaseOrders = NULL;

		PurchaseOrdersDAO purchaseOrdersDAO;
		purchaseOrders = purchaseOrdersDAO.getAllPurchaseOrders();
		if (purchaseOrders->size() != 0){
			for (unsigned int i = 0; i < purchaseOrders->size(); i++) {

				cout << purchaseOrders->at(i).getPurchaseOrderID() << " " << purchaseOrders->at(i).getDate() << " " << purchaseOrders->at(i).getPurchaseRequisitionID() << " " << purchaseOrders->at(i).getPurchaseManagerID() << endl;
			}
		}
	}

};

