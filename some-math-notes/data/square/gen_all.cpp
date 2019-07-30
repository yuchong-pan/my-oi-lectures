#include <cstdio>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main() {
    char cmd[100];
    for (int i = 0; i < 9; i++) {
        sprintf(cmd, "./gen");
        system(cmd);
        sprintf(cmd, "./square");
        system(cmd);
        sprintf(cmd, "mv square.in square%d.in", i);
        system(cmd);
        sprintf(cmd, "mv square.out square%d.out", i);
        system(cmd);
        sleep(2);
    }
    return 0;
}
