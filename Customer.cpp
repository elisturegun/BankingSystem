//
// Created by Lenovo on 9.07.2022.
//
#include "Customer.h"
#include "Account.h"
#include <iostream>
using namespace std;

Customer::Customer() {
    this->id = 0;
    this->firstName = "";
    this->lastName ="";
    this->head = NULL;
    this->accNum = 0;
    head = NULL;
}
Customer::~Customer() {
    AccNode *cur = head;
    while(cur!=NULL){
        AccNode *temp = cur;
        cur = cur->next;
        delete temp;
        head = cur;
    }
}

Customer::Customer(const int cusID, const string firstN, const string lastN) {
    this->id = cusID;
    this->firstName = firstN;
    this->lastName = lastN;
    this->accNum = 0;
}

void Customer::setLastName(const string nLast) {
    lastName = nLast;
}

void Customer::setFirstName(const string nFirst) {
    firstName = nFirst;
}

void Customer::setID(const int nID) {
    id = nID;
}

int Customer::getID() {
    return this->id;
}

string Customer::getFirstName() {
    return this->firstName;
}

string Customer::getLastName() {
    return this->lastName;
}

void Customer::addAccount(int addID, int money,int accNumber) {

    Account* newPtr = new Account;

    newPtr->setAmount(money);

    if(accNum == 0){
        AccNode* added = new AccNode;
        newPtr->setID(accNumber+1);
        added->acc = newPtr;
        head = added;

        added->next = NULL;
        cout << "Account   " << added->acc->getID() << "  is added ";
    }
    else{
        AccNode* cur = head;

        AccNode* newNode = new AccNode;
        newNode->acc->setID(accNumber+1);
        newNode->acc->setAmount(money);


        while(cur != NULL) {
            newNode->next = cur->next;
            cur->next = newNode;
            cur->next = NULL;
            accNum = accNum + 1;
            cout << "Account   " << cur->next->acc->getID() << "  is added ";

        }
    }

}

void Customer::deleteAcc(int accID) {
    AccNode *prev = NULL;
    AccNode *cur = head;

    while( cur!=NULL ){
        if(  accID == cur->acc->getID()){
            AccNode* temp = cur;

            if(head == cur){
                cur->acc->setID(0);
                cur = cur->next;
                head = cur;
                accNum = accNum-1;
                delete temp;


                return;
            }
            else{
                prev->next= cur->next;
                cur->acc->setID(0);
                cur = cur->next;

                accNum = accNum-1;
                delete temp;



                return;
            }
        }
        else{
            prev = cur;
            cur = cur->next;
        }
    }

}

void Customer::showCustAccounts() {
    AccNode* cur = head;
    while(cur!= NULL){
        cout << cur->acc->getID() << "     " << cur->acc->getAmount() << endl;
        cout<<endl;
        cur = cur->next;
    }
}

void Customer::showAllAcc() {

    AccNode* cur = head;

        while (cur != NULL) {
            cout << cur->acc->getID() << "       " << this->getID() << "      " <<this->getFirstName() << " " << this->getLastName() << "     "
                 << cur->acc->getAmount() << endl;
            cur = cur->next;
            return;
        }

}



