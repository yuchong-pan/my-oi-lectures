#include <cstdio>
#include <cstdlib>

using namespace std;

char cmd[100];

int main() {
    for (int i = 1; i <= 10; i++) {
        sprintf(cmd, "cp collinear%d.in collinear.in", i);
        system(cmd);
        sprintf(cmd, "./collinear");
        system(cmd);
        sprintf(cmd, "diff collinear.out collinear%d.out", i);
        system(cmd);
        sprintf(cmd, "rm collinear.in");
        system(cmd);
        sprintf(cmd, "rm collinear.out");
        system(cmd);
    }
}
