#pragma once
//#include "UserAccount.h"
//#include "Helper.h"
#include <string>
using namespace std;
#include <vector>
#include <fstream>
#include<memory>
class UserAccount{
  public:
       const static  double  MIN_BALANCE;
       const static double REWARD_RATE;
       const static double MIN_REWARD_AMOUNT;
    
    private:
      int accountNumber,id;
      std::string accountName;
      double accountBalance;

    public: 
      UserAccount();
      UserAccount(std::string accountName, int id,int accountNumber, double accountBalance);
      
       //getters
      public:
        std::string getAccountName();
        int getAccountNumber();
        double getAccountBalance();
        void setAccountName(string accountName);
        void setAccountNumber(int number);
        
        void setId(int id);
      // setters : cannot change number and accountName
      //setting balance may be needed by admin

      void setAccountBalance(double accountBalance);
       //bool operator==(<shared_ptr<UserAccount> a, shared_ptr<UserAccount> b);
       //bool equals(shared_ptr<UserAccount> a);
      virtual std::string toString();
      virtual bool withdraw(double amount);
      
      std::string fixPoint(std::string number);
      //virtual
      void calculateBalance();
      virtual void deposit(double amount);
      bool equalTo(shared_ptr<UserAccount> a);
      void addReward(double amount);
      int getId();
       


    
};
 