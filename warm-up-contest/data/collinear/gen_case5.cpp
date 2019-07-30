// N <= 1000, same co-ordinates

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main() {
    srand(time(0));
    freopen("collinear.in", "w", stdout);
    int N = 950 + rand() % 50;
    printf("%d\n", N);
    int individual = N / 10 + rand() % 10 - 5;
    for (int i = 0; i < individual; i++) {
        printf("%d %d\n", rand() % (int) 2e9 - (int) 1e9, rand() % (int) 2e9 - (int) 1e9);
    }
    N -= individual;
    int lines = (int) sqrt(N) + rand() % 10 - 5;
    vector<int> line_vec[1000];
    for (int i = 0; i < N; i++) {
        line_vec[rand() % lines].push_back(i);
    }
    int init_x[lines], init_y[lines], dx[lines], dy[lines];
    for (int i = 0; i < lines; i++) {
        init_x[i] = rand() % (int) 1e9 - (int) 5e8;
        init_y[i] = rand() % (int) 1e9 - (int) 5e8;
        dx[i] = rand() % 200 - 100;
        dy[i] = rand() % 200 - 100;
    }
    int x[N], y[N];
    for (int i = 0; i < lines; i++) {
        int prev_x = INT_MAX, prev_y = INT_MAX;
        for (vector<int>::iterator j = line_vec[i].begin(); j != line_vec[i].end(); j++) {
            if (prev_x < INT_MAX && prev_y < INT_MAX && rand() % 5 == 0) {
                x[*j] = prev_x;
                y[*j] = prev_y;
            } else {
                int k = rand() % (int) 1e7 - (int) 5e6;
                prev_x = x[*j] = init_x[i] + dx[i] * k;
                prev_y = y[*j] = init_y[i] + dy[i] * k;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d %d\n", x[i], y[i]);
    }
    return 0;
}
