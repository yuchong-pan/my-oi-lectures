#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = (int) 2e5 + 5;

vector<int> ans, odd;
vector<pair<int, int> > e[MAXN];
bool visited[MAXN], in_stack[MAXN];
int n, m;
int od[MAXN], ev[MAXN], depth[MAXN], pedge[MAXN];

void dfs(int cur, int prev) {
    visited[cur] = in_stack[cur] = true;
    for (vector<pair<int, int> >::iterator i = e[cur].begin(); i != e[cur].end(); i++) {
        if (i->first != prev) {
            if (!visited[i->first]) {
                pedge[i->first] = i->second;
                depth[i->first] = depth[cur] + 1;
                dfs(i->first, cur);
            } else if (in_stack[i->first]) {
                if (abs(depth[cur] - depth[i->first]) % 2) {
                    ev[cur]++;
                    ev[i->first]--;
                } else {
                    odd.push_back(i->second);
                    od[cur]++;
                    od[i->first]--;
                }
            }
        }
    }
    in_stack[cur] = false;
}

void dfs2(int cur) {
    for (vector<pair<int, int> >::iterator i = e[cur].begin(); i != e[cur].end(); i++) {
        if (depth[i->first] == depth[cur] + 1) {
            dfs2(i->first);
            od[cur] += od[i->first];
            ev[cur] += ev[i->first];
        }
    }
    if (depth[cur] > 0 && od[cur] == odd.size() && ev[cur] == 0) {
        ans.push_back(pedge[cur]);
    }
}

int main() {
    freopen("star.in", "r", stdin);
    freopen("star.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(make_pair(v, i));
        e[v].push_back(make_pair(u, i));
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }
    if (!odd.size()) {
        for (int i = 1; i <= m; i++) {
            ans.push_back(i);
        }
    } else if (odd.size() == 1) {
        ans.push_back(odd[0]);
    }
    if (odd.size()) {
        for (int i = 1; i <= n; i++) {
            if (!depth[i]) {
                dfs2(i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    printf("%lu\n", ans.size());
    for (vector<int>::iterator i = ans.begin(); i != ans.end(); i++) {
        printf("%d%c", *i, " \n"[i == ans.end() - 1]);
    }
    return 0;
}
