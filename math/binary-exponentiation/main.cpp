#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll binPow(ll base, ll power) {
    ll mod = 1e9 + 7;

    ll ans = 1;
    while(power > 0) {

        if(power%2 == 1) {
            ans = (ans * base) % mod;
        }

        base = (base * base) % mod;
        power /= 2;
    }

    return ans;
}

int main() {

    int base = 2;
    int power = 3;

    cout<<binPow(base, power)<<endl;
    return 0;
}