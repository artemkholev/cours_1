#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isPrime(int n) {
    if (n == 1) return false;
    if (n < 4) return true;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

vector<bool> function(int n) {
    vector<bool> a(n, true);
    a[1] = false;
    for (int i = 2; i < n; ++i) {
        if (a[i]) {
            for (int j = 2 * i; j < n; j += i) {
                a[i] = false;
            }
        }
    }
    return a;
}

int bin_pow(int a, int p, int mod) {
    int res = 1;
    while (p) {
        if (p % 2) {
            (res *= a) %= mod;
        }
        (a *= a) %= mod;
        p /= 2;
    }
    return res;
}

#define FERMA_ITERATIONS 10

bool isPrimeFerma(int n) {
    if (n == 1) return false;
    if (n < 4) return true;
    for (int i = 0; i < FERMA_ITERATIONS; ++i) {
        int a = 1 + rand() % (n - 1);
        int value = bin_pow(a, n - 1, n);
        if (value != 1) return false;
    }
    return true;
}

bool helperRM(int t, int n) {
    int a = 2 + rand() % (n - 4);
    int value = bin_pow(a, t, n);
    if (value == 1 || value == n - 1) return true;
    while (t < n) {
        (value *= value) %= n;
        if (value == n - 1) return true;
        if (value == 1) return false;
        t *= 2;
    }
    return false;
}

bool isPrimeRM(int n) {
    if (n == 1) return false;
    if (n < 4) return true;
    int t = n - 1;
    while (t % 2 == 0) {
        t /= 2;
    }
    for (int i = 0; i < FERMA_ITERATIONS; ++i) {
        if (!helperRM(t, n)) return false;
    }
    return true;
}

int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            res -= res / i;
        }
    }
    if (n != 1) res -= res / n;
    return res;
}

map<int, int> fact(int n) {
    map<int, int> counter;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            n /= i;
            counter[i]++;
        }
    }
    if (n != 1) counter[n]++;
    return counter;
}

int main() {
    srand(time(nullptr));
    int n;
    cin >> n;
    cout << phi(n);
    return 0;
}
