#include <algorithm>
#include <climits>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

struct Point {
    int x, y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

vector<Point> points;

int main() {
    freopen("collinear.in", "r", stdin);
    freopen("collinear.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        points.push_back(Point(x, y));
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        map<double, int> slope_map;
        int same = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    same++;;
                } else if (points[i].x == points[j].x) {
                    slope_map[INT_MAX]++;
                } else {
                    double slope = (double) (points[j].y - points[i].y) / (points[j].x - points[i].x);
                    slope_map[slope]++;
                }
            }
        }
        int tmax = 0;
        for (map<double, int>::iterator j = slope_map.begin(); j != slope_map.end(); j++) {
            tmax = max(tmax, j->second);
        }
        ans = max(ans, tmax + same);
    }
    printf("%d\n", ans + 1);
    return 0;
}
