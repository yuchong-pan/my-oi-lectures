#include <cstdio>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main() {
    char cmd[100];
    for (int i = 0; i < 9; i++) {
        sprintf(cmd, "./gen");
        system(cmd);
        sprintf(cmd, "./recurrence");
        system(cmd);
        sprintf(cmd, "mv recurrence.in recurrence%d.in", i);
        system(cmd);
        sprintf(cmd, "mv recurrence.out recurrence%d.out", i);
        system(cmd);
        sleep(2);
    }
    return 0;
}
