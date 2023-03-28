//#pragma once
#include "CheckingAccount.h"
 //#include "Helper.h"
#include<iostream>
 CheckingAccount::CheckingAccount():UserAccount(){
}

CheckingAccount::CheckingAccount(std::string accountName, int id, int accountNumber, double accountBalance):UserAccount(accountName,id,accountNumber,accountBalance){
}

 string CheckingAccount::toString(){
    return  "Account Name: "+getAccountName()+"\n"+
               "Account Number: "+std::to_string(getAccountNumber())+"\n"+
               "Account Balance: "+fixPoint(std::to_string(getAccountBalance()))+"\n"
               +
               "Account Type: Checking \n";
     }

// overrides useraccount method to prohibit negative withdrawal amount
//overrides useraccount method to permit any number of withdrawals, keeping the miminum balance.
bool CheckingAccount::withdraw(double amount){
    
  if(amount < 0){
    return false;
  }
  else{
    if((this->getAccountBalance() - amount) < MIN_BALANCE_CHECKING ){
      return false;
    }
    else{
      setAccountBalance(this->getAccountBalance() - amount);
      return true;
    }
  }
   
}


void CheckingAccount::deposit(double amount){
  UserAccount::deposit(amount);
}

const  double  CheckingAccount::MIN_BALANCE_CHECKING=99.99;

