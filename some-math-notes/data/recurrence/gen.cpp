#include <climits>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    freopen("recurrence.in", "w", stdout);
    for (int T = 0; T < 100; T++) {
        int d = rand() % 15 + 1, n = rand() % INT_MAX + 1, m = rand() % (int) 2e9 + 1;
        printf("%d %d %d\n", d, n, m);
        for (int i = 1; i <= d; i++) {
            printf("%lld%c", 1ll * rand() * rand() % UINT_MAX, " \n"[i == d]);
        }
        for (int i = 1; i <= d; i++) {
            printf("%lld%c", 1ll * rand() * rand() % UINT_MAX, " \n"[i == d]);
        }
    }
    puts("0 0 0");
    return 0;
}
