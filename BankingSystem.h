//
// Created by Lenovo on 9.07.2022.
//

#ifndef HW3_BANKINGSYSTEM_H
#define HW3_BANKINGSYSTEM_H
#include <string>
#include "Account.h"
#include "Customer.h"


using namespace std;

class BankingSystem {
public :
    BankingSystem () ;
    ~ BankingSystem () ;
    void addCustomer ( const int customerId , const string firstName , const
    string lastName );
    void deleteCustomer ( const int customerId ) ;
    int addAccount ( const int customerId , const double amount ) ;
    void deleteAccount ( const int accountId ) ;
    void showAllAccounts () ;
    void showAllCustomers () ;
    void showCustomer ( const int customerId ) ;
    bool isEmptyAcc();
    bool isEmptyCus();
    Customer* findCus(const int cusID, bool& found);

private:
    struct CustomerNode{
        Customer* customer;
        CustomerNode* nextCus;

    };

    struct AccountNode{
        Account* account;
        AccountNode* nextAcc;

    };

    int sizeCus;
    int sizeAcc;

    CustomerNode* headCus;

    AccountNode* headAcc;

};


#endif //HW3_BANKINGSYSTEM_H
