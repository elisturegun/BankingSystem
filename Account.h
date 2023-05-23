//
// Created by Lenovo on 9.07.2022.
//

#ifndef HW3_ACCOUNT_H
#define HW3_ACCOUNT_H
using namespace std;
class Account{
public:
    Account();
    Account(const int id, const int amount);
    void setID(int nid);
    void setAmount(int namount);
    int getID();
    int getAmount();

private:
    int id;
    int amount;
};
#endif //HW3_ACCOUNT_H
