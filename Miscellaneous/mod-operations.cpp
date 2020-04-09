// MODDED factorial array

ll* factorial = new ll[N];
factorial[0] = 1;
for(int i = 1;i < N; ++i){
    factorial[i] = (factorial[i] * i) % MOD;
}

// MODDED POW

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

// MOD-INV

template<typename T>
T modinv(T x,T m){
    return modpow<T>(x, m - 2, m);
}