#include<vector>
#include<memory>
#include "UserAccount.h"

class GreaterThan{
  public:
  bool operator()( shared_ptr<UserAccount> a, shared_ptr<UserAccount>b);
  
  
};