#include "DVDStoreManagementSystem.h"
#include <iostream>
#include <string>
//#include "DVD.h"
//#include "Customer.h"
using namespace std;
DVDStoreManagementSystem::DVDStoreManagementSystem(){
    dvds=nullptr;
    customers=nullptr;
    history=nullptr;
    dvdsSize=0;
    customersSize=0;
    historySize=0;
}
DVDStoreManagementSystem::~DVDStoreManagementSystem(){
    if(dvds!=nullptr)
        delete [] dvds;
    if(customers!=nullptr)
        delete [] customers;
    if(history!=nullptr)
        delete [] history;
}
void DVDStoreManagementSystem::addDVD( const string serialNo, const string title, const string director ){

    DVD* newDvds = new DVD[dvdsSize+1];
    bool add=true;
    for(int i=0;i<dvdsSize;i++){
        if(dvds[i].getSerialNo()==serialNo){
            add=false;
        }
        newDvds[i]=dvds[i];
    }
    if(add){
        DVD dvd(serialNo,title,director);
        newDvds[dvdsSize]=dvd;
        if(dvds!=nullptr)
            delete[] dvds;
        dvdsSize++;
        dvds=newDvds;
        cout<<"DVD with serial number "<<serialNo<<" successfully added.\n";

    }
    else{
        delete[] newDvds;
        newDvds=nullptr;
        cout<<"Cannot add DVD. DVD with serial number "<<serialNo<<" already exists.\n";
    }

}
void DVDStoreManagementSystem::removeDVD( const string serialNo ){
    bool remove=false;
    bool isRented=false;
    DVD* newDvds=nullptr;
    if(dvdsSize!=0){
        newDvds = new DVD[dvdsSize-1];
        int j=0;
        for(int i=0;i<dvdsSize;i++){
            if(dvds[i].getSerialNo()!=serialNo){
                if(j<dvdsSize-1){
                    newDvds[j]=dvds[i];
                    j++;
                }
            }
            else{
                if(!dvds[i].getRented())
                    remove=true;
                else
                    isRented=true;
            }
        }
    }
    else{
        remove=false;
    }

    if(remove){
        if(dvds!=nullptr)
            delete[] dvds;
        dvdsSize--;
        dvds=newDvds;
        cout<<"DVD with serial number "<<serialNo<<" successfully removed.\n";
    }
    else{
        if(newDvds!=nullptr)
            delete[] newDvds;
        if(isRented)
            cout<<"Cannot remove DVD. DVD with serial number "<<serialNo<<" is currently rented by a customer.\n";
        else
            cout<<"Cannot remove DVD. DVD with serial number "<<serialNo<<" not found.\n";
    }
}
void DVDStoreManagementSystem::addCustomer( const int customerID, const string name ){
    Customer* newCustomers = new Customer[customersSize+1];
    bool add=true;
    for(int i=0;i<customersSize;i++){
        //newCustomers[i]->setCustomerId(customers[i].getCustomerId());
        //newCustomers[i]->setName(customers[i].getName());
        if(customers[i].getCustomerId()==customerID){
            add=false;
        }
        newCustomers[i]=customers[i];
    }
    if(add){
        Customer customer(customerID,name);
        newCustomers[customersSize]=customer;
        if(customers!=nullptr)
            delete[] customers;
        customersSize++;
        customers=newCustomers;
        cout<<"Customer with ID "<<customerID<<" successfully added.\n";

    }
    else{
        delete[] newCustomers;
        cout<<"Cannot add customer. Customer with ID "<<customerID<<" already exists.\n";
    }
}
void DVDStoreManagementSystem::removeCustomer( const int customerID ){
    bool remove=false;
    bool hasRentedDvd=false;
    Customer* newCustomers=nullptr;
    if(customersSize!=0){
        newCustomers = new Customer[customersSize-1];
        int j=0;
        for(int i=0;i<customersSize;i++){
            //newCustomers[i]->setCustomerId(customers[i].getCustomerId());
            //newCustomers[i]->setName(customers[i].getName());

            if(customers[i].getCustomerId()!=customerID){
                if(j<customersSize-1){
                    newCustomers[j]=customers[i];
                    j++;
                }
            }
            else{
                if(customers[i].getDvds()==nullptr)
                    remove=true;
                else{
                    hasRentedDvd=true;
                    remove=false;
                }
            }

        }
    }
    else{
        remove=false;
    }

    if(remove){
        if(customers!=nullptr)
            delete[] customers;
        customersSize--;
        customers=newCustomers;
        cout<<"DVD with serial number "<<customerID<<" successfully removed.\n";
    }
    else{
        if(newCustomers!=nullptr)
            delete[] newCustomers;
        if(!hasRentedDvd)
            cout<<"Cannot remove DVD. DVD with serial number "<<customerID<<" not found.\n";
        else
            cout<<"Cannot remove customer. Customer with ID "<<customerID<<" has rented DVDs.\n";
    }
}
void DVDStoreManagementSystem::rentDVD( const int customerID, const string serialNo ){
    DVD* dvd=getDVDBySerialNo(serialNo);
    Customer* customer=getCustomerById(customerID);
    if(dvd==nullptr && customer==nullptr){
        cout<<"Cannot rent DVD. Customer with ID "<<customerID<<" and DVD with serial number "<<serialNo<<" not found.\n";
    }
    else if(dvd==nullptr){
        cout<<"Cannot rent DVD. DVD with serial number "<<serialNo<<" not found.\n";
    }
    else if(dvd->getRented()){
        cout<<"Cannot rent DVD. DVD with serial number "<<serialNo<<" is not available.\n";
    }
    else if(customer==nullptr){
        cout<<"Cannot rent DVD. Customer with ID "<<customerID<<" not found.\n";
    }
    else{
        dvd->setRented(true);
        customer->addDvd(*dvd);

        string* newHistory=new string[historySize+1];
        for(int i=0;i<historySize;i++){
            newHistory[i]=history[i];
        }
        newHistory[historySize]="Transaction: Rental, Customer: "+to_string(customerID)+", DVD: "+serialNo+"\n";
        delete[] history;
        history=newHistory;
        historySize++;
        cout<<"DVD with serial number "<<serialNo<<" successfully rented by customer with ID "<<customerID<<".\n";
    }
}
void DVDStoreManagementSystem::returnDVD( const int customerID, const string serialNo ){
    DVD* dvd=getDVDBySerialNo(serialNo);
    Customer* customer=getCustomerById(customerID);
    if(dvd==nullptr && customer==nullptr){
        cout<<"Cannot return DVD. Customer with ID "<<customerID<<" and DVD with serial number "<<serialNo<<" not found.\n";
    }
    else if(dvd==nullptr){
        cout<<"Cannot return DVD. DVD with serial number "<<serialNo<<" not found.\n";
    }
    else if(customer==nullptr){
        cout<<"Cannot return DVD. Customer with ID "<<customerID<<" not found.\n";
    }
    else{

        bool isRemoved=customer->removeDvd(*dvd);
        if(!isRemoved){
            cout<<"Cannot return DVD. DVD with serial number "<<serialNo<<" not rented by customer with ID "<<customerID<<".\n";
        }
        else{
            dvd->setRented(false);
            string* newHistory=new string[historySize+1];
            for(int i=0;i<historySize;i++){
                newHistory[i]=history[i];
            }
            newHistory[historySize]="Transaction: Return, Customer: "+to_string(customerID)+", DVD: "+serialNo+"\n";
            delete[] history;
            history=newHistory;
            historySize++;
            cout<<"DVD with serial number "<<serialNo<<" successfully returned by customer with ID "<<customerID<<".\n";
        }

    }
}
void DVDStoreManagementSystem::showAllDVDs() const{
    cout<<"DVDs in the system:\n";
    if(dvdsSize==0)
        cout<<"None\n";
    else{
        for(int i=0;i<dvdsSize;i++){
            cout<<dvds[i].toString();
        }
    }
}
void DVDStoreManagementSystem::showAllCustomers() const{
    cout<<"Customers in the system:\n";
    if(customersSize==0)
        cout<<"None\n";
    else{
        for(int i=0;i<customersSize;i++){
            cout<<customers[i].toString();
        }
    }
}
void DVDStoreManagementSystem::showDVD( const string serialNo ) const{
    DVD* dvd=getDVDBySerialNo(serialNo);
    if(dvd==nullptr){
        cout<<"DVD with serial number "<<serialNo<<" not found.";
    }
    else
        cout<<dvd->toString();
}
void DVDStoreManagementSystem::showCustomer( const int customerID ) const{
    Customer* customer=getCustomerById(customerID);
    if(customer==nullptr){
        cout<<"Customer with ID "<<customerID<<" not found.";
    }
    else
        cout<<customer->toString();
}
void DVDStoreManagementSystem::showTransactionHistory() const{
    cout<<"Transactions in the system:\n";
    if(historySize==0)
        cout<<"None\n";
    else{
        for(int i=0;i<historySize;i++){
            cout<<history[i];
        }
    }
}
Customer* DVDStoreManagementSystem::getCustomerById(int customerId)const{
    for(int i=0;i<customersSize;i++){
        if(customers[i].getCustomerId()==customerId)
            return &(customers[i]);
    }
    return nullptr;
}
DVD* DVDStoreManagementSystem::getDVDBySerialNo(string serialNo)const{
    for(int i=0;i<dvdsSize;i++){
        if(dvds[i].getSerialNo()==serialNo)
            return &(dvds[i]);
    }
    return nullptr;
}
int DVDStoreManagementSystem::findCustomerOfDvd(string serialNo){
    for(int i=0;i<customersSize;i++){
        for(int j=0;j<customers[i].getDvdsSize();j++){
            DVD* dvdList=customers[i].getDvds();
            if(dvdList[j].getSerialNo()==serialNo){
                return customers[i].getCustomerId();
            }
        }
    }
    return -1;
}
int main(){
    DVDStoreManagementSystem dvdsms;
cout << "Initial state:" << endl << endl;
dvdsms.showAllDVDs();
cout << endl;
dvdsms.showAllCustomers();
cout << endl;
dvdsms.showTransactionHistory();
cout << endl;
// Add some DVDs
dvdsms.addDVD("001", "Inception", "Christopher Nolan");
dvdsms.addDVD("002", "The Shawshank Redemption", "Frank Darabont");
dvdsms.addDVD("003", "Pulp Fiction", "Quentin Tarantino");
dvdsms.addDVD("004", "The Godfather", "Francis Ford Coppola");
dvdsms.addDVD("005", "The Dark Knight", "Christopher Nolan");
cout << endl << "After adding DVDs:" << endl << endl;
dvdsms.showAllDVDs();
cout << endl;
// Add an existing DVD
dvdsms.addDVD("003", "Pulp Fiction", "Quentin Tarantino");
cout << endl;
// Remove a few DVDs
dvdsms.removeDVD("004");
dvdsms.removeDVD("005");
cout << endl << "After removing DVDs:" << endl << endl;
dvdsms.showAllDVDs();
cout << endl;
// Remove a non-existing DVD
dvdsms.removeDVD("006");
cout << endl;
// Add some customers
dvdsms.addCustomer(1001, "Alice");
dvdsms.addCustomer(1002, "Bob");
dvdsms.addCustomer(1003, "Charlie");
dvdsms.addCustomer(1004, "Diana");
dvdsms.addCustomer(1005, "Edward");
cout << endl << "After adding customers:" << endl << endl;
dvdsms.showAllCustomers();
cout << endl;
// Add an existing customer
dvdsms.addCustomer(1001, "Alice");
cout << endl;
// Remove a few customers
dvdsms.removeCustomer(1004);
dvdsms.removeCustomer(1005);
cout << endl << "After removing customers:" << endl << endl;
dvdsms.showAllCustomers();
cout << endl;
// Remove a non-existing customer
dvdsms.removeCustomer(1006);
cout << endl;
// Rent some DVDs (successful)
dvdsms.rentDVD(1001, "001");
dvdsms.rentDVD(1002, "002");
dvdsms.rentDVD(1003, "003");
cout << endl << "After renting DVDs:" << endl << endl;
dvdsms.showTransactionHistory();
cout << endl;
// Rent a non-existing DVD with an existing customer
dvdsms.rentDVD(1001, "006");
// Rent an existing DVD with a non-existing customer
dvdsms.rentDVD(1006, "001");
// Rent a non-existing DVD with a non-existing customer
dvdsms.rentDVD(1006, "006");
// Rent a non-available DVD with an existing customer
dvdsms.rentDVD(1002, "001");
cout << endl;
// Return a few DVDs (successful)
dvdsms.returnDVD(1001, "001");
dvdsms.returnDVD(1002, "002");
cout << endl << "After returning DVDs:" << endl << endl;
dvdsms.showTransactionHistory();
cout << endl;
// Return a non-existing DVD with an existing customer
dvdsms.returnDVD(1001, "999");
// Return an existing DVD with a non-existing customer
dvdsms.returnDVD(999, "001");
// Return a non-existing DVD with a non-existing customer
dvdsms.returnDVD(999, "999");
// Return a rented DVD with an existing customer but not rented by this customer
dvdsms.returnDVD(1001, "003");
// Remove a rented DVD
dvdsms.removeDVD("003");
// Remove a customer who rented a DVD
dvdsms.removeCustomer(1003);
cout << endl;
// Show an existing DVD
dvdsms.showDVD("002");
// Show a non-existing DVD
dvdsms.showDVD("999");
// Show an existing customer
dvdsms.showCustomer(1003);
// Show a non-existing customer
dvdsms.showCustomer(999);
cout << endl << "Final state:" << endl << endl;
dvdsms.showAllDVDs();
cout << endl;
dvdsms.showAllCustomers();
cout << endl;
dvdsms.showTransactionHistory();
    return 0;
}
