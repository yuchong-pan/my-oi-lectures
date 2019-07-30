#include <algorithm>
#include <bitset>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 500 + 5, MOD = (int) 1e9 + 7;

typedef bitset<MAXN> matrix[MAXN];

bool flag[MAXN];
int pow2[MAXN];
matrix A;
vector<int> pr;

int gauss(matrix A, int m, int n) {
    int i = 0, j = 0;
    while (i < m && j < n) {
        int r = i;
        for (int k = i; k < m; k++) {
            if (A[k][j]) {
                r = k;
                break;
            }
        }
        if (A[r][j]) {
            if (r != i) {
                swap(A[r], A[i]);
            }
            for (int u = i + 1; u < m; u++) {
                if (A[u][j]) {
                    A[u] ^= A[i];
                }
            }
            i++;
        }
        j++;
    }
    return i;
}

int main() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    pow2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }
    for (int i = 2; i < MAXN; i++) {
        if (!flag[i]) {
            pr.push_back(i);
            for (int j = i + i; j < MAXN; j += i) {
                flag[j] = true;
            }
        }
    }
    int T;
    for (scanf("%d", &T); T--; ) {
        int n;
        scanf("%d", &n);
        int max_prime = 0;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            for (int j = 0; j < pr.size(); j++) {
                while (x % pr[j] == 0) {
                    max_prime = max(max_prime, j);
                    x /= pr[j];
                    A[j] ^= 1 << i;
                }
            }
        }
        int r = gauss(A, max_prime + 1, n);
        printf("%d\n", (pow2[n - r] - 1 + MOD) % MOD);
        for (int i = 0; i <= max_prime; i++) {
            A[i] = 0;
        }
    }
    return 0;
}
