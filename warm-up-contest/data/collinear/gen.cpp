#include <cstdio>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main() {
    char cmd[100];
    int num[] = {0, 2, 1, 3, 1, 1, 2};
    for (int i = 1, cnt = 0; i <= 6; i++) {
        sprintf(cmd, "clang++ gen_case%d.cpp -o gen_case%d", i, i);
        system(cmd);
        for (int j = 0; j < num[i]; j++) {
            sleep(2);
            sprintf(cmd, "./gen_case%d", i);
            system(cmd);
            sprintf(cmd, "./collinear");
            system(cmd);
            FILE *f = fopen("collinear.out", "r");
            int ans;
            fscanf(f, "%d", &ans);
            printf("Case #%d: %d\n", ++cnt, ans);
            fclose(f);
            sprintf(cmd, "mv collinear.in collinear%d.in", cnt);
            system(cmd);
            sprintf(cmd, "mv collinear.out collinear%d.out", cnt);
            system(cmd);
        }
    }
    return 0;
}
