#ifndef SM
#define SM

#pragma once

#include "stdafx.h"
#include "User.h"
#include "ItemsDAO.h"
#include "SuppliersDAO.h"
#include "DailyItemWiseDAO.h"
#include "PurchaseRequisitionsDAO.h"
#include "PurchaseOrdersDAO.h"

class SalesManager : public virtual User {
public:
	SalesManager(int userID, string password, string firstName, string lastName) : User(userID, password, "SalesManager", firstName, lastName){}

	SalesManager(){}

	~SalesManager(){}

	void displayMenu(){
		int option;
		cout << endl;
		cout << "--- MAIN MENU ---" << endl;
		cout << "1. Items" << endl;
		cout << "2. Suppliers" << endl;
		cout << "3. Daily Item Wise" << endl;
		cout << "4. Purchase Requisitions" << endl;
		cout << "5. Purchase Orders" << endl;
		cout << "6. Exit" << endl;
		cout << "Option: ";
		cin >> option;

		switch (option){
		case 1: {
					cout << " | --- ITEMS ---" << endl;
					displayItems();
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
					displaySuppliers();
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
					displayPurchaseRequisitions();
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
					displayPurchaseOrders();
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
		case 6: {
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

	void addItem(){
		// adds a new item

		// ADD ITEM - LEVEL 1

		cout << "   | --- ADD NEW ITEM ---" << endl;

		Item item;
		vector<Item> *items = NULL;
		ItemsDAO itemsDAO;
		items = itemsDAO.getAllItems();

		bool exist = false;
		int quantity;
		int supplierID;
		string itemName;
		vector<Supplier> *suppliers = NULL;
		SuppliersDAO suppliersDAO;

		if (items->size() == 0){
			items = new vector<Item>();
			item.setItemID(1);
		}
		else {
			unsigned int size = items->size();
			item.setItemID((items->at(size - 1).getItemID()) + 1);
		}

		cout << "   | Item Name: ";
		cin >> itemName;
		item.setItemName(itemName);

		cout << "   | Supplier ID: ";
		cin >> supplierID;
		suppliers = suppliersDAO.getAllSuppliers();
		if (suppliers->size() != 0){
			// ADD ITEM - LEVEL 2 (Handling Suppliers)
			for (unsigned int i = 0; i < suppliers->size();i++) {
				if (supplierID == suppliers->at(i).getSupplierID()) {
					item.setSupplierID(supplierID);
					exist = true;
					cout << "   | Quantity: ";
					cin >> quantity;

					item.setQuantity(quantity);

					items->push_back(item);

					itemsDAO.save(items);

					cout << " * New item (ID: " << item.getItemID() << ") has been successfully added!\n" << endl;
					displayMenu();

					break;
				}
			} 

			if (!exist) {
				cout << " * Supplier with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
				displayMenu();
			}
		}
		else {
			cout << " * Supplier with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
			displayMenu();
		}
	}

	void editItem(){
		// edits item info

		// EDIT ITEM - LEVEL 1

		cout << "   | --- EDIT ITEM ---" << endl;

		vector<Item> *items = NULL;
		ItemsDAO itemsDAO;
		items = itemsDAO.getAllItems();

		unsigned int id;
		int quantity;

		cout << "   | Item ID: ";
		cin >> id;

		bool exist = false;

		if (items->size()==0){
			cout << " * Item with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
			displayMenu();
		}
		else {
			for (unsigned int i = 0; i < items->size(); i++){
				if (items->at(i).getItemID() == id){
					cout << "   | Quantity (Current quantity = " << items->at(i).getQuantity() << "): ";
					cin >> quantity;
					exist = true;
					items->at(i).setQuantity(quantity);

					itemsDAO.save(items);

					cout << " * Item (ID: " << items->at(i).getItemID() << ") has been successfully edited!\n" << endl;
					displayMenu();
					break;
				}
			}

			if (!exist){
				cout << " * Item with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
				displayMenu();
			}
		}
	}

	void deleteItem(){
		// deletes item

		// DELETE ITEM - LEVEL 1

		cout << "   | --- DELETE ITEM ---" << endl;

		vector<Item> *items = NULL;
		ItemsDAO itemsDAO;
		items = itemsDAO.getAllItems();

		int id;

		cout << "   | Item ID: ";
		cin >> id;

		bool exist = false;

		if (items->size() == 0 ){
			cout << " * Item with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
			displayMenu();
		}
		else {
			for (unsigned int i = 0; i < items->size(); i++){
				if (items->at(i).getItemID() == id){
					
					items->erase(items->begin() + (id-1));
					exist = true;
					itemsDAO.save(items);
					cout << " * Item (ID: " << id << ") has been successfully deleted!\n" << endl;
					displayMenu();
					break;
				}
			}

			if (!exist) {
				cout << " * Item with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
				displayMenu();
			}
		}
	}

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

	void addSupplier(){
		// adds a new supplier

		// ADD SUPPLIER - LEVEL 1

		cout << "   | --- ADD NEW SUPPLIER ---" << endl;

		Supplier supplier;
		vector<Supplier> *suppliers = NULL;
		SuppliersDAO suppliersDAO;
		suppliers = suppliersDAO.getAllSuppliers();

		string supplierName;

		if (suppliers->size() == 0){
			suppliers = new vector<Supplier>();
			supplier.setSupplierID(1);
		}
		else {
			unsigned int size = suppliers->size();
			supplier.setSupplierID((suppliers->at(size - 1).getSupplierID()) + 1);
		}

		cout << "   | Supplier Name: ";
		cin >> supplierName;
		supplier.setSupplierName(supplierName);

		suppliers->push_back(supplier);
		suppliersDAO.save(suppliers);

		cout << " * New supplier (ID: " << supplier.getSupplierID() << ") has been successfully added!\n" << endl;
		displayMenu();

	}

	void editSupplier(){
		// edits supplier info

		// EDIT SUPPLIER - LEVEL 1

		cout << "   | --- EDIT SUPPLIER ---" << endl;

		vector<Supplier> *suppliers = NULL;
		SuppliersDAO suppliersDAO;
		suppliers = suppliersDAO.getAllSuppliers();

		unsigned int id;
		bool exist = false;
		string supplierName;

		cout << "   | Supplier ID: ";
		cin >> id;

		if (suppliers->size() == 0){
			cout << " * Supplier with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
			displayMenu();
		}
		else {
			for (unsigned int i = 0; i < suppliers->size(); i++){
				if (suppliers->at(i).getSupplierID() == id){
					cout << "   | Supplier Name (Current supplier name = " << suppliers->at(i).getSupplierName() << "): ";
					cin >> supplierName;
					exist = true;

					suppliers->at(i).setSupplierName(supplierName);

					suppliersDAO.save(suppliers);

					cout << " * Supplier (ID: " << id << ") has been successfully edited!\n" << endl;
					displayMenu();
					break;
				}
			}

			if (!exist) {
				cout << " * Supplier with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
				displayMenu();
			}
		}
	}

	void deleteSupplier(){
		// deletes supplier

		// DELETE SUPPLIER - LEVEL 1

		cout << "   | --- DELETE SUPPLIER ---" << endl;

		vector<Supplier> *suppliers = NULL;
		SuppliersDAO suppliersDAO;
		suppliers = suppliersDAO.getAllSuppliers();

		unsigned int id;

		bool exist = false;

		cout << "   | Supplier ID: ";
		cin >> id;

		if (suppliers->size() == 0){
			cout << " * Supplier with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
			displayMenu();
		}
		else {
			for (unsigned int i = 0; i < suppliers->size(); i++){
				if (suppliers->at(i).getSupplierID() == id){
					cout << "delete" << endl;
					
					suppliers->erase(suppliers->begin() + i);
					cout << suppliers->size() << endl;


					exist = true;
					suppliersDAO.save(suppliers);

					cout << " * Supplier (ID: " << id << ") has been successfully deleted!\n" << endl;
					displayMenu();
					break;
				}
			}
			if (!exist){
				cout << " * Supplier with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
				displayMenu();
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

	void addDailyItemWise(){
		// adds daily item wise

		// ADD DAILY ITEM WISE - LEVEL 1

		cout << "   | --- ADD NEW DAILY ITEM WISE ---" << endl;

		DailyItemWise itemWise;
		vector<DailyItemWise> *itemWises = NULL;
		DailyItemWiseDAO itemWisesDAO;
		itemWises = itemWisesDAO.getAllItemWises();
		bool exist = false;
		int itemID, totalSales;
		Item item;

		ItemsDAO itemsDAO;

		if (itemWises->size() == 0){
			itemWises = new vector<DailyItemWise>();
			itemWise.setItemWiseID(1);
		}
		else {
			int size = itemWises->size();
			itemWise.setItemWiseID((itemWises->at(size - 1).getItemWiseID()) + 1);
		}

		cout << "   | Item ID: ";
		cin >> itemID;

		vector<Item> *items = NULL;
		items = itemsDAO.getAllItems();

		if (items->size() != 0) {

			// ADD DAILY ITEM WISE - LEVEL 2 (Handling Suppliers)

			for (unsigned int i = 0; i < items->size(); i++) {
				if (items->at(i).getItemID() == itemID) {
					item = items->at(i);
					itemWise.setItemID(item.getItemID());
					exist = true;
					break;
				}
			}

			if (exist) {
				cout << "   | Total Sales (" << item.getQuantity() << " in stock): ";
				cin >> totalSales;

				if ((item.getQuantity() - totalSales) >= 0) {
					itemWise.setTotalSales(totalSales);
					itemWise.setDate(getCurrentDate());
					itemWise.setSalesManagerID(userID);
					itemWises->push_back(itemWise);
					itemWisesDAO.save(itemWises);

					items = NULL;
					items = itemsDAO.getAllItems();

					for (unsigned int i = 0; i < items->size(); i++) {
						if (items->at(i).getItemID() == itemWise.getItemID()) {
							int quantity = items->at(i).getQuantity();
							int totalSales = itemWise.getTotalSales();
							items->at(i).setQuantity(quantity - totalSales);
							itemsDAO.save(items);
							break;
						}
					}

					cout << " * Item Wise (ID: " << itemWise.getItemWiseID() << ") has been successfully added!\n" << endl;
					displayMenu();
				}
				else {
					cout << " * Item's stock in quantity can't be exceeded! The operation is aborted.\n" << endl;
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

	void deleteDailyItemWise(){
		// deletes item

		// DELETE ITEM - LEVEL 1

		cout << "   | --- DELETE DAILY ITEM WISE ---" << endl;

		vector<DailyItemWise> *itemWises = NULL;
		DailyItemWiseDAO itemWisesDAO;
		itemWises = itemWisesDAO.getAllItemWises();

		bool exist = false;
		int id;

		cout << "   | Item Wise ID: ";
		cin >> id;

		// add for loop to all delete methods
		if (itemWises->size() == 0){
			cout << " * Item Wise with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
			displayMenu();
		}
		else {
			for (unsigned int i = 0; i < itemWises->size(); i++){
				if (itemWises->at(i).getItemWiseID() == id){
					itemWises->erase(itemWises->begin() + i);
					exist = true;
					itemWisesDAO.save(itemWises);

					cout << " * Item Wise (ID: " << id << ") has been successfully deleted!\n" << endl;
					displayMenu();
					break;
				}
			}
		}
	}

	void displayDailyItemWises(){
		vector<DailyItemWise> *itemWises = NULL;

		DailyItemWiseDAO itemWisesDAO;
		itemWises = itemWisesDAO.getAllItemWises();
		if (itemWises->size() != 0){
			for (unsigned int i = 0; i < itemWises->size(); i++) {
				cout << itemWises->at(i).getItemWiseID() << " " << itemWises->at(i).getDate() << " " << itemWises->at(i).getItemID() << " " << itemWises->at(i).getTotalSales() << " " << itemWises->at(i).getSalesManagerID() << endl;
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

		int itemID, quantity;
		Item item;
		bool exist = false;
		ItemsDAO itemsDAO;

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
				cout << "   | Requested quantity: (" << item.getQuantity() << " in stock): ";
				cin >> quantity;

				purchaseRequisition.setQuantity(quantity);
				purchaseRequisition.setDate(getCurrentDate());
				purchaseRequisition.setSalesManagerID(this->userID);
				purchaseRequisition.setApproved(false);
				purchaseRequisitions->push_back(purchaseRequisition);
				purchaseRequisitionDAO.save(purchaseRequisitions);

				cout << " * Purchase Requisition (ID: " << purchaseRequisition.getPurchaseRequisitionID() << ") has been successfully added!\n" << endl;
				displayMenu();

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

	void deletePurchaseRequisition(){
		// deletes purchase requisition

		// DELETE PURCHASE REQUISITION - LEVEL 1

		cout << "   | --- DELETE PURCHASE REQUISITION ---" << endl;

		vector<PurchaseRequisition> *purchaseRequisitions = NULL;
		PurchaseRequisitionDAO purchaseRequisitionsDAO;
		purchaseRequisitions = purchaseRequisitionsDAO.getAllPurchaseRequisitions();

		int id;

		cout << "   | Purchase Requisition ID: ";
		cin >> id;

		// add for loop to all delete methods
		if (purchaseRequisitions->size() == 0){
			cout << " * Purchase Requisition with such ID doesn't exist in the system! The operation is aborted.\n" << endl;
			displayMenu();
		}
		else {
			for (unsigned int i = 0; i < purchaseRequisitions->size(); i++){
				if (purchaseRequisitions->at(i).getPurchaseRequisitionID() == id){
					purchaseRequisitions->erase(purchaseRequisitions->begin() + i);

					purchaseRequisitionsDAO.save(purchaseRequisitions);

					cout << " * Purchase Requisition (ID: " << i << ") has been successfully deleted!\n" << endl;
					displayMenu();
					break;
				}
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

	void displayPurchaseOrders(){
		vector<PurchaseOrder> *purchaseOrders = NULL;

		PurchaseOrdersDAO purchaseOrdersDAO;
		purchaseOrders = purchaseOrdersDAO.getAllPurchaseOrders();
		if (purchaseOrders->size() != 0){
			for (unsigned int i = 0; i < purchaseOrders->size(); i++) {
				
				cout << purchaseOrders->at(i).getPurchaseOrderID() << " " << purchaseOrders->at(i).getDate() << " " << purchaseOrders->at(i).getPurchaseRequisitionID() << " " << purchaseOrders->at(i).getPurchaseManagerID()  << endl;
			}
		}
	}

};

#endif