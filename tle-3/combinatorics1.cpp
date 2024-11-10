#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7; // Use a large prime modulus

// Function to perform modular multiplication
long long mod_mul(long long a, long long b, long long mod) {
    return (a * b) % mod;
}

// Function to perform modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = mod_mul(result, base, mod);
        }
        base = mod_mul(base, base, mod);
        exp /= 2;
    }
    return result;
}

// Function to precompute factorials and inverse factorials
void precompute_factorials(int maxN, vector<long long>& fact, vector<long long>& ifact) {
    fact[0] = 1;
    for (int i = 1; i <= maxN; i++) {
        fact[i] = mod_mul(fact[i - 1], i, MOD);
    }
    ifact[maxN] = mod_exp(fact[maxN], MOD - 2, MOD); // Inverse of fact[maxN] mod MOD
    for (int i = maxN - 1; i >= 0; i--) {
        ifact[i] = mod_mul(ifact[i + 1], i + 1, MOD);
    }
}

// Function to compute combinations C(n, r) mod MOD
long long combination(int n, int r, const vector<long long>& fact, const vector<long long>& ifact) {
    if (r > n || r < 0) return 0;
    return mod_mul(fact[n], mod_mul(ifact[r], ifact[n - r], MOD), MOD);
}

int main() {
    int maxN = 1e7; // Set an upper limit based on the constraints
    vector<long long> fact(maxN + 1), ifact(maxN + 1);
    
    // Precompute factorials and inverse factorials up to maxN
    precompute_factorials(maxN, fact, ifact);

    // Example usage: Compute C(8, 6) mod MOD
    int n, r;
    cin>>n>>r;
    cout << "C(" << n << ", " << r << ") mod " << MOD << " = " << combination(n, r, fact, ifact) << endl;

    return 0;
}
