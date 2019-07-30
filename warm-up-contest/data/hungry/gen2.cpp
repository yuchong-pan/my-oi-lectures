#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int cnt = 10;
    int n2[] = {20};
    int ns2[] = {3};
    char cmd[100];
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < ns2[i]; j++) {
            int n = n2[i] * 3 / 5 + rand() % (n2[i] * 2 / 5) + 1;
            int k = rand() % n + 1;
            FILE *f = fopen("hungry.in", "w");
            fprintf(f, "%d %d\n", n, k);
            for (int i = 1; i <= n; i++) {
                fprintf(f, "%d%c", rand() % (int) 1e9 + 1, " \n"[i == n]);
            }
            fclose(f);
            sprintf(cmd, "./hungry");
            system(cmd);
            f = fopen("hungry.out", "r");
            int ans;
            fscanf(f, "%d", &ans);
            fclose(f);
            printf("Case #%d (Type 2): %d %d => %d\n", ++cnt, n, k, ans);
            sprintf(cmd, "mv hungry.in hungry%d.in", cnt);
            system(cmd);
            sprintf(cmd, "mv hungry.out hungry%d.out", cnt);
            system(cmd);
        }
    }
    return 0;
}
