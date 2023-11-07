#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<double> pizzas(n);

    double max_radius = 0.0;
    for (int i = 0; i < n; i++) {
        cin >> pizzas[i];
        pizzas[i] = pizzas[i] * pizzas[i] * M_PI; // 计算每个披萨的面积
        max_radius = max(max_radius, pizzas[i]);
    }

    double left = 0, right = max_radius;
    double ans = 0.0;

    while (right - left > 1e-6) {
        double mid = (left + right) / 2.0;
        int pieces = 0;

        for (int i = 0; i < n; i++) {
            pieces += int(pizzas[i] / mid);
        }

        if (pieces >= m + 1) {
            left = mid;
            ans = mid;
        } else {
            right = mid;
        }
    }

    cout << fixed << setprecision(4) << ans << endl;
    return 0;
}
