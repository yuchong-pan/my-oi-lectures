#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    freopen("gcd.in", "w", stdout);
    for (int i = 0; i < 100; i++) {
        printf("%d\n", rand() % (int) (4e6 - 1) + 2);
    }
    puts("0");
    return 0;
}
