#include <cstdio>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main() {
    char cmd[100];
    for (int i = 0; i < 9; i++) {
        sprintf(cmd, "./gen");
        system(cmd);
        sprintf(cmd, "./gcd");
        system(cmd);
        sprintf(cmd, "mv gcd.in gcd%d.in", i);
        system(cmd);
        sprintf(cmd, "mv gcd.out gcd%d.out", i);
        system(cmd);
        sleep(2);
    }
    return 0;
}
