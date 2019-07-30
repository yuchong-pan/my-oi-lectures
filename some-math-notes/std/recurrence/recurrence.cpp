#include <cassert>
#include <cstdio>

using namespace std;

const int MAXN = 15 + 5;

struct matrix {
    int n, m;
    unsigned mat[MAXN][MAXN];
    matrix(int _n, int _m) : n(_n), m(_m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = 0;
            }
        }
    }
};

matrix mat_mul(matrix a, matrix b, int mod) {
    assert(a.m == b.n);
    int n = a.n, m = a.m, p = b.m;
    matrix ans(n, p);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                ans.mat[i][j] = (ans.mat[i][j] + 1ll * a.mat[i][k] * b.mat[k][j] % mod) % mod;
            }
        }
    }
    return ans;
}

matrix mat_pow(matrix a, int b, int mod) {
    assert(a.n == a.m);
    int n = a.n;
    matrix ans(n, n);
    for (int i = 0; i < n; i++) {
        ans.mat[i][i] = 1;
    }
    for (; b > 0; b /= 2, a = mat_mul(a, a, mod)) {
        if (b % 2) {
            ans = mat_mul(ans, a, mod);
        }
    }
    return ans;
}

int main() {
    freopen("recurrence.in", "r", stdin);
    freopen("recurrence.out", "w", stdout);
    int d, n, m;
    for (scanf("%d%d%d", &d, &n, &m); !(d == 0 && n == 0 && m == 0); scanf("%d%d%d", &d, &n, &m)) {
        matrix A(d, d);
        for (int i = 1; i < d; i++) {
            A.mat[i][i - 1] = 1;
        }
        for (int i = 1; i <= d; i++) {
            unsigned a;
            scanf("%u", &a);
            A.mat[d - i][d - 1] = a % m;
        }
        matrix x(1, d);
        for (int i = 0; i < d; i++) {
            unsigned f;
            scanf("%u", &f);
            x.mat[0][i] = f % m;
        }
        x = mat_mul(x, mat_pow(A, n - d, m), m);
        printf("%u\n", x.mat[0][d - 1]);
    }
    return 0;
}
