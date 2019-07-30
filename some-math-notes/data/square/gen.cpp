#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int MAXN = 500 + 5;

bool p[MAXN];
vector<int> pr;

int main() {
    srand(time(0));
    freopen("square.in", "w", stdout);
    puts("100");
    for (int i = 2; i <= 500; i++) {
        if (!p[i]) {
            pr.push_back(i);
            for (int j = i + i; j <= 500; j += i) {
                p[j] = true;
            }
        }
    }
    for (int T = 0; T < 100; T++) {
        int n = rand() % 5 + 96;
        printf("%d\n", n);
        for (int i = 0; i < n; i++) {
            long long prod = 1;
            for (int j = 0; j < pr.size(); j++) {
                int x = rand() % pr.size();
                if (prod * pr[x] <= (long long) 1e15) {
                    prod *= pr[x];
                }
            }
            printf("%lld%c", prod, " \n"[i == n - 1]);
        }
    }
    return 0;
}
