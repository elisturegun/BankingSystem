//
// Created by Lenovo on 9.07.2022.
//

#include "Account.h"

Account::Account() {
    id = 0;
    amount = 0;
}

Account::Account(const int id, const int amount) {
    this->id = id;
    this->amount = amount;
}

int Account::getAmount() {
    return this->amount;
}

int Account::getID() {
    return this->id;
}

void Account::setAmount(int namount) {
    this->amount = namount;
}

void Account::setID(int nid) {
    this->id = nid;
}

