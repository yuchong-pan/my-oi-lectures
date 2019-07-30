#include <cstdio>
#include <cstdlib>

using namespace std;

char cmd[100];

int main() {
    for (int i = 1; i <= 10; i++) {
        sprintf(cmd, "cp star%d.in star.in", i);
        system(cmd);
        sprintf(cmd, "./star");
        system(cmd);
        sprintf(cmd, "mv star.out star%d.out", i);
        system(cmd);
        sprintf(cmd, "rm star.in");
        system(cmd);
    }
    return 0;
}
