#include <cstdio>

using namespace std;

const int MAXN = (int) 4e6, MOD = (int) 1e9 + 7;

int phi[MAXN], f[MAXN], s[MAXN];

int main() {
    freopen("gcd.in", "r", stdin);
    freopen("gcd.out", "w", stdout);
    for (int i = 2; i < MAXN; i++) {
        phi[i] = 0;
    }
    phi[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!phi[i]) {
            for (int j = i; j < MAXN; j += i) {
                if (!phi[j]) {
                    phi[j] = j;
                }
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    for (int i = 1; i < MAXN; i++) {
        for (int n = i + i; n < MAXN; n += i) {
            f[n] = (f[n] + 1ll * i * phi[n / i] % MOD) % MOD;
        }
    }
    s[2] = f[2];
    for (int i = 3; i < MAXN; i++) {
        s[i] = (s[i - 1] + f[i]) % MOD;
    }
    int n;
    for (scanf("%d", &n); n; scanf("%d", &n)) {
        printf("%d\n", s[n]);
    }
    return 0;
}
