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
void createSievePrimeFactors(){
  int N=1000000;
  // 1. Mark from 2 till end as 1

  for(int i=2;i<=N;++i){
    sieve[i]=i;
  }

  // 2. Traverse Sieve

  for(int i=2;i*i<=N;++i){
    
    if(sieve[i]==i){
      // 3. If i is Prime
      //  Mark all its multiple as i itself
      // Denotes that i is the smallest prime factor of that number 
      for(int j=i*i;j<=N;j=j+i){
        sieve[j]=i;
      }
    
    }
  }
}

// IS Prime
// T.C: O(N + sqrt(N) * loglogN + sqrt(N))
// S.C:- O(N)
void ETF(int target){
  createSievePrimeFactors();

  int num=target;

  int ans=target;
  while(num>1){
    int smallestPrimeFactor=sieve[num];

    // gives one less??    
    ans*=(1-((float)1/smallestPrimeFactor));
    
    while(num % smallestPrimeFactor == 0){
      num/=smallestPrimeFactor;
    }
    
  }

  cout<<ans<<endl;
}

int main(){
  
  ETF(36);

  return 0;
}