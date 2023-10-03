#include <bits/stdc++.h>
using namespace std;

// check for prime
int sieve[1000005];

// REMEMBER

// 10^7 array
// YES - Int Main
// NO  - Global

// 10^8 array
// NO  - Int Main
// YES - Global


// Create Sieve
// T.C: O(N + sqrt(N) * loglogN)
// S.C:- O(N)
void createSieve(){
  int N=1000000;
  // 1. Mark from 2 till end as 1

  for(int i=2;i<=N;++i){
    sieve[i]=1;
  }

  // 2. Traver Sieve

  for(int i=2;i*i<=N;++i){
    
    if(sieve[i]==1){
      // 3. If i is Prime
      //  Mark all its multiple as 0
      for(int j=i*i;j<=N;j=j+i){
        sieve[j]=0;
      }
    
    }
  }
}

// IS Prime
// T.C: O(N + sqrt(N) * loglogN)
// S.C:- O(N)
bool isPrime(int target){
  createSieve();

  if(sieve[target]==1) return true;
  
  return false;
}

int main(){
  
  cout<<isPrime(216)<<endl;
  cout<<isPrime(133)<<endl;
  cout<<isPrime(13)<<endl;

  return 0;
}