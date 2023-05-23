//
// Created by Lenovo on 9.07.2022.
//

#include "BankingSystem.h"
#include <string>
#include <iostream>
using namespace std;
BankingSystem::BankingSystem() {
    headAcc = NULL;
    headCus = NULL;

    sizeAcc = 0;
    sizeCus = 0;

}

BankingSystem::~BankingSystem() {
    CustomerNode *cur= headCus;
    AccountNode *temp = headAcc;
    while(cur!=NULL){
        deleteCustomer(cur->customer->getID());
        cur = cur->nextCus;
    }

    while(headAcc != NULL){
        deleteAccount(temp->account->getID());
        temp = temp->nextAcc;
    }
}

void BankingSystem::addCustomer(const int customerId, const string firstName, const string lastName) {

    Customer *cusPtr = new Customer;
    cusPtr->setID(customerId);
    cusPtr->setFirstName(firstName);
    cusPtr->setLastName(lastName);

    if(headCus == NULL) {
        CustomerNode *customerNode= new CustomerNode;
        customerNode->customer = cusPtr;
        headCus = customerNode;
        customerNode->nextCus = NULL;
        sizeCus++;

        cout << "Customer   " << customerId << "   has been added " << endl;
    }
    else{
        CustomerNode *cur = headCus;
        while(cur != NULL){
            if(cur->customer->getID() == customerId){
                if(cur->customer->getLastName() == lastName && cur->customer->getFirstName() == firstName ){
                    cout << "Customer   " << firstName << "   " << lastName << "  already exists " << endl;
                }
                else{
                    cout << "Customer   " << customerId << "  already exists" << endl;
                }
                delete cusPtr;
                cusPtr = NULL;
                return;
            }

            else{
                if(cur->customer->getLastName() == lastName && cur->customer->getFirstName() == firstName){
                    cout << "Customer " << firstName << " " << lastName << " already exists " << endl;
                }
            }
            cur = cur->nextCus;
        }
        cur = headCus;
        while(cur != NULL){
            if ( cur->customer->getLastName() != lastName){
                if( (cur->nextCus!= NULL) && (lastName > cur->customer->getLastName()) && (cur->nextCus->customer->getLastName() > lastName) ){
                    CustomerNode *newNode = new CustomerNode;
                    newNode->customer = cusPtr;
                    newNode->nextCus = cur->nextCus;
                    cur->nextCus = newNode;
                    cout << "Customer " << customerId << " has been added"   << endl;
                    return;
                }
                else if( cur->nextCus == NULL && lastName > cur->customer->getLastName()){
                    CustomerNode *newNode = new CustomerNode;
                    newNode->customer = cusPtr;
                    cur->nextCus = newNode;
                    newNode->nextCus = NULL;
                    cout << "Customer " << customerId << " has been added " << endl;
                    return;
                }
                else if(cur == headCus && lastName < cur->customer->getLastName()){
                    CustomerNode *newNode = new CustomerNode;
                    newNode->customer = cusPtr;
                    newNode->nextCus =headCus;
                    headCus = newNode;
                    cout << "Customer " << customerId << " has been added " << endl;
                    return;
                }
            }
            else if(cur->customer->getLastName() == lastName){
                if( (cur->nextCus!= NULL) && (cur->nextCus->customer->getFirstName() > firstName) && (firstName > cur->customer->getFirstName()) ){
                    CustomerNode *newNode = new CustomerNode;
                    newNode->customer = cusPtr;
                    newNode->nextCus = cur->nextCus;
                    cur->nextCus = newNode;

                    cout << "Customer  " << customerId << " has been added"   << endl;
                    return;
                }
                else if( cur->nextCus == NULL && firstName > cur->customer->getFirstName()){
                    CustomerNode *newNode = new CustomerNode;
                    newNode->customer = cusPtr;
                    cur->nextCus = newNode;
                    newNode->nextCus = NULL;
                    cout << "Customer   " << customerId << " has been added " << endl;
                    return;
                }
                else if(cur == headCus && firstName < cur->customer->getFirstName()){
                    CustomerNode *newNode = new CustomerNode;
                    newNode->customer = cusPtr;
                    newNode->nextCus =headCus;
                    headCus = newNode;
                    cout << "Customer   " << customerId << " has been added " << endl;
                    return;
                }

            }
            cur = cur->nextCus;
            sizeCus++;
        }
       /* for (CustomerNode* t = headCus;  t != NULL; t = t->nextCus) {
            cout << t->customer->getID() << endl;
        }*/
    }
}

void BankingSystem::deleteCustomer(const int customerId) {

    CustomerNode *prev = NULL;
    CustomerNode *cur = headCus;

    while(cur!=NULL){
        if(  cur->customer->getID()  ==  customerId){
            CustomerNode *temp = cur;

            while(cur->customer->head != NULL) {
                int delID = cur->customer->head->acc->getID();
                cur->customer->deleteAcc(delID);
            }
            if(cur == headCus){
                cur = cur->nextCus;
                headCus = cur;
                cout<<" Customer   "  <<  customerId  << "   has been deleted."<<endl;

                delete temp->customer;
                delete temp;

                return;
            }
            else{
                prev->nextCus =cur->nextCus;
                cout<<" Customer   "<<  customerId  << "   has been deleted."<<endl;

                delete temp->customer;
                delete temp;

                return;
            }
        }
        else {
            prev = cur;
            cur = cur->nextCus;
        }
    }
    cout<<"Customer   "<<   customerId   << "   does not exist."<<endl;
}

int BankingSystem::addAccount(const int customerId, const double amount) {
    Customer* cus;
    bool cusFound;
    cus = findCus(customerId,cusFound);

    if(!cusFound){
        cout << "Customer  " << customerId << "  doesn't exist" << endl;
        return -1;

    }
    else{
        cus->addAccount(customerId, amount, sizeAcc);
        sizeAcc++;
        cout << " for customer  " << customerId << endl;
        return sizeAcc;
    }
}

void BankingSystem::deleteAccount(const int accountId) {

    CustomerNode* cur = headCus;
    while(cur != NULL) {
        cur->customer->deleteAcc(accountId);

            cout<< "Account "<< accountId <<" has been deleted."<< endl;
            return;

    }
    cout << "Account "<< accountId << " does not exist"<< endl;

}

void BankingSystem::showAllAccounts() {

    CustomerNode* cust = headCus;
    cout << "Account id      Customer id     Customer name     Balance " << endl;
    while(cust!= NULL){
        if(cust != NULL) {
            cust->customer->showAllAcc();
            cust = cust->nextCus;
        }
        else{
            cout << "There is no account" << endl;
        }
    }
}

void BankingSystem::showAllCustomers() {
    CustomerNode* cust = headCus;
    if(cust != NULL){
        cout << "Customer id       Customer name" << endl;
        while(cust!= NULL){
            cout << cust->customer->getID() << "        " << cust->customer->getFirstName() << "  "
                 << cust->customer->getLastName() << endl;
            cust = cust->nextCus;
        }
    }
    else{
        cout << "There is no customer " << endl;
    }
}

void BankingSystem::showCustomer(const int customerId) {
    bool cusFound;
    Customer* cust =  findCus(customerId,cusFound);

    if(!cusFound){
        cout << "Customer  " << customerId << "  doesn't exist" << endl;
    }
    else{
        cout << "Customer id:  " << cust->getID() << "  Customer name:  " << cust->getFirstName() << " " << cust->getLastName() << "  Number of accounts:  " << cust->accNum << endl;
        if(cust->head != NULL){
            cout << "Accounts of user:  " << endl;
            cout << "Account id:           Balance:  "<< endl;
            cust->showCustAccounts();
        }
    }
}

bool BankingSystem::isEmptyAcc() {
    return sizeAcc == 0;
}

bool BankingSystem::isEmptyCus() {
    return sizeCus == 0;
}

Customer *BankingSystem::findCus(const int cusID, bool& found){
    found = false;
    CustomerNode* cur = headCus;

    while( cur != NULL && !found){
        if(cusID == cur->customer->getID() ){
            found = true;
            return cur->customer;
        }
        cur = cur ->nextCus;
    }
    return NULL;
}


