//#pragma once
#include "SavingsAccount.h"
#include<iostream>
//#include "Helper.h"
 SavingsAccount::SavingsAccount(){
        UserAccount();
    }
     
SavingsAccount::SavingsAccount(std::string accountName, int id, int accountNumber, double accountBalance):UserAccount(accountName,id,accountNumber,accountBalance){
}



 string SavingsAccount::toString(){
      return "Account Name: "+getAccountName()+"\n"+
               "Account Number: "+std::to_string(getAccountNumber())+"\n"+
              "Account Balance: " +fixPoint(std::to_string(getAccountBalance()))+"\n"
              +
               "Account Type: Savings \n";

    }

 bool SavingsAccount::withdraw(double amount){
   //cout << "Withdrawal not permitted in Savings Account.\n";
   return false;
  }

    
void SavingsAccount::deposit(double amount){
    UserAccount::deposit(amount);
  }
   