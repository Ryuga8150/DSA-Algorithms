#include <bits/stdc++.h>
typedef long long int ll;

/*

"p": a prime number roughly equal to the number of characters in the input alphabet
"m": is a large number, but still small enough so that we can perform multiplication
     of two values using 64-bit integers

If the input is composed of only lowercase letters of the English alphabet,
p = 31 is a good choice. 
If the input may contain both uppercase and lowercase letters, then
p = 53 is a possible choice.

REMEMBER
Sometimes  
m = 2^{64}  is chosen, since then the integer 
overflows of 64-bit integers work exactly like the modulo operation

But in practice is not recommended
*/
ll compute_hash(string &s){
  const int p=31; 
  const int m=1e9+9;

  ll hashValue=0;
  long long powP = 1;
    for (char c : s) {
      hashValue = (hashValue + (c - 'a' + 1) * powP) % m;
      powP = (powP * p) % m;
    }
    return hash_value;
}