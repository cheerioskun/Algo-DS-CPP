#include<bits/stdc++.h>
#define f first
#define s second
#define MOD 1000000007L
typedef long long int ll;
typedef std::vector<int> vi;
typedef std::pair<int, int> pii;
using namespace std;

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

template<typename T>
T modinv(T x,T m){
    return modpow<T>(x, m - 2, m);
}

int main(){
    int X, N;
    cin>>X>>N;
    cout<<modpow<ll>(X, N, MOD)<<endl;
    cout<<modinv<ll>(X, MOD)<<endl;   
}