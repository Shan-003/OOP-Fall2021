
#include "Bank.h"
#include <iostream>
#include <sstream>
#include <memory>
#include <algorithm>
#include "GreaterThan.h"

void Bank::fillVector (ifstream &input,vector<shared_ptr<UserAccount>> &accountsVector){

   string accountName;
   string lastName;
   string firstName, inputLine, type;
   int id, accountNumber;
   double accountBalance;

  //while not eof getline from file
  // parse the line and create shared pointer to BankAccount
  //push the pointe onto the accounts vector
    getline(input,inputLine);
    istringstream streamLine(inputLine);
    streamLine >> firstName >> lastName >> id >> accountNumber >> accountBalance >> type;
    
    accountName = firstName + " " + lastName;

    if(type == "S"){
      shared_ptr<UserAccount> temp = make_shared<SavingsAccount>(accountName,id,accountNumber,accountBalance);
      accountsVector.push_back(temp);
    }
    else{
      shared_ptr<UserAccount> temp = make_shared<CheckingAccount>(accountName,id,accountNumber,accountBalance);
      accountsVector.push_back(temp);      
    }
    
    
  
}

void Bank::displayAccounts(){
  
  for (int i=0;i<accountsVector.size();i++){
    cout<<accountsVector[i]->toString()<<endl;
  }
}



// copy constructor needed for backup
Bank::Bank(const Bank &other){
  //cout<<" In copy constructor  "<<endl;
  //accountsVector.resize(other.accountsVector.size());
  
  //cout<<accountsVector.size()<<endl;
  //create a cop constructor that copies the two vectors
  for(int i = 0;i<other.accountsVector.size();i++){
    shared_ptr<UserAccount> temp = make_shared<UserAccount>(other.accountsVector[i]->getAccountName(),other.accountsVector[i]->getId(), other.accountsVector[i]->getAccountNumber(),other.accountsVector[i]->getAccountBalance());
    accountsVector.push_back(temp);
  }


 
}


Bank::Bank(string filename){
 // throw File Open Error - File Exception -99 if file cannot be opened
//use try catch statement
  ifstream datafile(filename);

  try{
  if (datafile){
  while (!datafile.eof()){
      fillVector(datafile, accountsVector);
    }
  }
  else throw (int)-99;
  }
  catch (int v){
    cout<< "File Error " << FileException(v).getValue() << endl;
    exit(0);
  }


}


void Bank::addAccount(shared_ptr<UserAccount> a)//should sort vector
{
  //add an account
      accountsVector.push_back(a);
  // be sure to keep vector sorted
  //use STL sort using Greater THan Function Object
  GreaterThan comp;
  sort(accountsVector.begin(), accountsVector.end(), comp);


}

void Bank::sortAccounts(){
  
  // use the STL sort by passing the beginning, end and Greater Than Functor
  GreaterThan comp;
  sort(accountsVector.begin(), accountsVector.end(), comp);
  
}

bool Bank::accountDeposit(shared_ptr<UserAccount> a, double amount){
 // return false if amount is negative
 // return true after depositing into account
 if(amount < 0){
   return false;
 }
 else{
   a->deposit(amount);
   return true;
 }

}


// Withdrawal not permitted in Savings Account. Checking Accounts need a minimum balance but allow withdrawal within this balance.
bool Bank::accountWithdraw(shared_ptr<UserAccount> a, double amount){
  // if the withdraw amount is suitable then withdraw from account and return true
  if(amount <= a->getAccountBalance()  && amount > 0){
    if(a->withdraw(amount)){
      return true;
    }
  }
  
 //otherwise return false
 return false;
}


// compares the original data base with the backup
bool Bank::checkSame( Bank &other){
 // check if this bank has the exact same accounts as the other bank
 //use equalTo method created in the UserAccount class (that implments Comparable)
 // return true if same, false otherwise  
  // equalTo should check if each and every field matches
  for(int i=0;i<accountsVector.size();i++){
    if((this->accountsVector[i]->equalTo(other.accountsVector[i])) == false){
      return false;
    }  

  }
    return true;
}



bool Bank::removeAccount(shared_ptr<UserAccount> a){

  //search for the the given account a, if found
  //use vector.erase method to remove it and return true
  for(int i=0;i<accountsVector.size();i++){
    if(accountsVector[i]->equalTo(a)){
        accountsVector.erase(accountsVector.begin()+i);
        return true;
    }
  }
  //otherwise return false
    return false;

}

