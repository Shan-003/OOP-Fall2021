//#pragma once
#include "UserAccount.h"
//#include "Helper.h"
#include <cstdlib>
#include <memory>
#include <vector>
#include<iostream>

      UserAccount::UserAccount(){
         this->id=0;
         this->accountBalance=0;
         this->accountNumber=0;
         this->accountName="";
         
       }

     UserAccount::UserAccount(std::string accountName, int id, int accountNumber, double accountBalance){
       // regular constructor
        this->id=id;
        this->accountNumber=accountNumber;
        this->accountName=accountName;
        this->accountBalance=accountBalance;
      }
      
       //getters
      
         std::string UserAccount::getAccountName(){
         return accountName;
        }

        int UserAccount::getAccountNumber(){
          return accountNumber;
        }
        double UserAccount::getAccountBalance(){
          return accountBalance;
        }
      // setters : cannot change number and accountName
      //setting balance may be needed by admin

      void UserAccount::setAccountBalance(double accountBalance){
        this->accountBalance = accountBalance;
      }
      //helper method
      std::string UserAccount::fixPoint(std::string number){
          int i= number.find('.');
          return number.substr(0,i+3);
      }
     
      bool UserAccount::equalTo (shared_ptr<UserAccount> a ){
        // compare all fields of this user account with a
        if (accountName == a->accountName && id == a->id && accountNumber == a->accountNumber && accountBalance == a->accountBalance)
          return true;
        else 
          return false;
      }
      
      std::string UserAccount::toString(){
        //std::cout<<fixPoint(std::to_string(accountBalance));
        return "Account Name: "+accountName+"\n"+
               "Account Number: "+std::to_string(accountNumber)+"\n"+
               "Account Balance: " +fixPoint(std::to_string(accountBalance))+"\n"
               ;
                
      }
       void UserAccount::setAccountName(string accountName){
         this->accountName = accountName;
       }
        void UserAccount::setAccountNumber(int number){
          this->accountNumber = number;
        }
        
        void UserAccount::setId(int id){
          this->id = id;
        }

      bool UserAccount::withdraw(double amount){
        
        if ((accountBalance - amount) > MIN_BALANCE){
             accountBalance -= amount;
             return true;
        }
        else 
          return false; // do nothing
      }
      
      
      void UserAccount::deposit(double amount){
        // deposit and
        //check if eligible for reward
        accountBalance += amount;
        if (amount > MIN_REWARD_AMOUNT)
           addReward(amount);
      
        
      }
      
     
      void  UserAccount::addReward(double amount){
          accountBalance = accountBalance+ REWARD_RATE*amount;
      }


      int UserAccount::getId(){
        return id;
      }
     



  const double UserAccount::MIN_BALANCE=9.99;
  const double UserAccount::MIN_REWARD_AMOUNT=1000.0;
  const double UserAccount::REWARD_RATE=0.04;
 