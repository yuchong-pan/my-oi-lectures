#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = (int) 1e6 + 5;
const long long MOD = 998244353;

long long w[MAXN], presum[MAXN];

namespace case1 {
    const int MAXN = (int) 1e6 + 5;

    long long a[MAXN], pow2[MAXN], dp[MAXN], dpsum[MAXN];

    void init(int N) {
        pow2[0] = 1;
        for (int i = 1; i <= N; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
            long long temp = a[i - 1], temp2 = 1ll * i * (i + 1);
            for (; 2 * temp * (temp + 1) < temp2; temp++);
            a[i] = temp;
        }
    }

    long long solve(int N, int K) {
        init(N);
        long long sum = K;
        for (int i = K - 1; i >= 1; i--) {
            if (sum > presum[i]) {
                dp[K] = pow2[i + 1];
                break;
            }
            sum += i;
        }
        dpsum[K] = dp[K];
        for (int i = K + 1; i <= N; i++) {
            if (a[i] >= K) {
                dp[i] = ((dpsum[i - 1] - dpsum[a[i] - 1]) % MOD + MOD) % MOD;
            } else {
                dp[i] = dpsum[i - 1];
            }
            dpsum[i] = (dpsum[i - 1] + dp[i]) % MOD;
        }
        return dp[N];
    }
}

namespace case2 {
    const int MAXN = 500 + 5;

    long long dp[MAXN];
    long long f[MAXN][MAXN], g[MAXN][MAXN];

    inline void inc(long long &x, long long y) {
        if ((x += y) >= MOD) {
            x -= MOD;
        }
    }

    inline long long sum(int l, int r) {
        return presum[r] - presum[l - 1];
    }

    void init_dp(int N) {
        for (int i = 1; i <= N; i++) {
            f[i][i] = g[i][i] = 1;
        }
        for (int delta = 2; delta <= N; delta++) {
            for (int i = 1; i + delta - 1 <= N; i++) {
                int j = i + delta - 1;
                for (int k = i + 1; k <= j; k++) {
                    long long sum1 = sum(i, k - 1), sum2 = sum(k, j);
                    if (i == 1) {
                        if (sum2 > sum1) {
                            inc(f[i][j], f[i][k - 1] * f[k][j] % MOD);
                        } else {
                            inc(g[i][j], f[i][k - 1] * f[k][j] % MOD);
                        }
                    }
                    if (j == N) {
                        if (sum2 > sum1) {
                            inc(f[i][j], g[i][k - 1] * g[k][j] % MOD);
                        } else {
                            inc(g[i][j], g[i][k - 1] * g[k][j] % MOD);
                        }
                    }
                    if (sum2 > sum1) {
                        inc(f[i][j], g[i][k - 1] * f[k][j] % MOD);
                    } else {
                        inc(g[i][j], g[i][k - 1] * f[k][j] % MOD);
                    }
                }
            }
        }
    }

    long long dp_left(int N, int K) {
        for (int i = 1; i <= N; i++) {
            dp[i] = 0;
        }
        dp[K] = 1;
        for (int i = K; i >= 1; i--) {
            for (int j = i - 1; j >= 1; j--) {
                if (sum(i, K) <= sum(j, i - 1)) {
                    break;
                }
                if (j != 1) {
                    inc(dp[j], dp[i] * g[j][i - 1] % MOD);
                } else {
                    inc(dp[j], dp[i] * (f[j][i - 1] + g[j][i - 1]) % MOD);
                }
            }
        }
        dp[K] = dp[1];
        for (int i = K; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                if (sum(1, i) < sum(i + 1, j)) {
                    break;
                }
                if (j != N) {
                    inc(dp[j], dp[i] * f[i + 1][j] % MOD);
                } else {
                    inc(dp[j], dp[i] * (f[i + 1][j] + g[i + 1][j]) % MOD);
                }
            }
        }
        return dp[N];
    }

    long long dp_right(int N, int K) {
        for (int i = 1; i <= N; i++) {
            dp[i] = 0;
        }
        dp[K] = 1;
        for (int i = K; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                if (sum(K, i) < sum(i + 1, j)) {
                    break;
                }
                if (j != N) {
                    inc(dp[j], dp[i] * f[i + 1][j] % MOD);
                } else {
                    inc(dp[j], dp[i] * (f[i + 1][j] + g[i + 1][j]) % MOD);
                }
            }
        }
        dp[K] = dp[N];
        for (int i = K; i >= 1; i--) {
            for (int j = i - 1; j >= 1; j--) {
                if (sum(i, N) <= sum(j, i - 1)) {
                    break;
                }
                if (j != 1) {
                    inc(dp[j], dp[i] * g[j][i - 1] % MOD);
                } else {
                    inc(dp[j], dp[i] * (f[j][i - 1] + g[j][i - 1]) % MOD);
                }
            }
        }
        return dp[1];
    }

    long long solve(int N, int K) {
        init_dp(N);
        long long ans = 0;
        inc(ans, dp_left(N, K));
        inc(ans, dp_right(N, K));
        return ans;
    }
}

int main() {
    freopen("hungry.in", "r", stdin);
    freopen("hungry.out", "w", stdout);
    int N, K;
    scanf("%d%d", &N, &K);
    if (N == 1 && K == 1) {
        puts("2");
        return 0;
    }
    bool check_case1 = true;
    for (int i = 1; i <= N; i++) {
        cin >> w[i];
        presum[i] = presum[i - 1] + w[i];
        if (w[i] != i) {
            check_case1 = false;
        }
    }
    if (check_case1) {
        cout << case1::solve(N, K) << endl;
    } else {
        cout << case2::solve(N, K) << endl;
    }
    return 0;
}
