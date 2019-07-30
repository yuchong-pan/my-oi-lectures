#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = (int) 1e3 + 5;

int id[MAXN];
set<pair<int, int> > eset;
vector<pair<int, int> > edge;

int main() {
    srand(time(0));
    freopen("star3.in", "w", stdout);
    int n = 800 + rand() % 50;
    for (int i = 1; i <= n; i++) {
        id[i] = i;
    }
    random_shuffle(id + 1, id + n + 1);
    for (int i = 2; i <= n; i++) {
        int u = id[i], v = id[i - 1];
        if (u > v) {
            swap(u, v);
        }
        edge.push_back(make_pair(u, v));
        eset.insert(make_pair(u, v));
    }
    int u = rand() % (int) (n * .1) + 1, v = n - rand() % (int) (n * .1);
    while ((v - u) % 2 == 1) {
        u = rand() % (int) (n * .1) + 1;
        v = n - rand() % (int) (n * .1);
    }
    u = id[u];
    v = id[v];
    if (u > v) {
        swap(u, v);
    }
    edge.push_back(make_pair(u, v));
    eset.insert(make_pair(u, v));
    for (int i = 0; i < 10; i++) {
        int u = rand() % n + 1, v = u + (rand() % 3) * 2 + 1;
        u = id[u];
        v = id[v];
        if (u > v) {
            swap(u, v);
        }
        while (eset.find(make_pair(u, v)) != eset.end()) {
            u = rand() % n + 1;
            v = u + (rand() % 3) * 2 + 1;
            u = id[u];
            v = id[v];
            if (u > v) {
                swap(u, v);
            }
        }
        edge.push_back(make_pair(u, v));
        eset.insert(make_pair(u, v));
    }
    random_shuffle(edge.begin(), edge.end());
    printf("%d %lu\n", n, edge.size());
    for (int i = 0; i < edge.size(); i++) {
        if (rand() % 2) {
            printf("%d %d\n", edge[i].first, edge[i].second);
        } else {
            printf("%d %d\n", edge[i].second, edge[i].first);
        }
    }
    return 0;
}
