//
// Created by Lenovo on 9.07.2022.
//

#ifndef HW3_CUSTOMER_H
#define HW3_CUSTOMER_H
#include <string>
#include "Account.h"
using namespace std;
class Customer{
public:
    Customer();
    ~Customer();
    Customer(const int cusID, const string firstN, const string lastN);
    void setID(const int nID);
    void setFirstName(const string nFirst);
    void setLastName(const string nLast);
    int getID();
    string getFirstName();
    string getLastName();
    void addAccount(int addID, int money,int accNumber);
    void deleteAcc(int accID);
    void showCustAccounts();
    void showAllAcc();


    int accNum;
    struct AccNode{
        Account* acc;
        AccNode* next;
    };
    AccNode* head;
private:
    int id;
    string firstName;
    string lastName;
};
#endif //HW3_CUSTOMER_H
