
#include <vector>
#include<memory>
#include <string>
#include "UserAccount.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;
class Bank{
public: class FileException{
  public:
  int value;
  FileException(int v){
    value=v;
  }
  int getValue(){
    return value;
  }
};
public:
private:
//static int dataSize;
vector<shared_ptr<UserAccount>> accountsVector;
public:
Bank(string filename);
Bank(const Bank &other);
void fillVector (ifstream &input,vector<shared_ptr<UserAccount>> &accountsVector);

void addAccount(shared_ptr<UserAccount> a);//should sort vector
bool removeAccount(shared_ptr<UserAccount> a);//vector remove method
void sortAccounts();//use STL sort using Greater THan Function Object
void displayAccounts();
bool accountDeposit(shared_ptr<UserAccount> a, double amount);
bool accountWithdraw(shared_ptr<UserAccount> a, double amount);
//bool backupAccounts();
bool checkSame( Bank &other);

};