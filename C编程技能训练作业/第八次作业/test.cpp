#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    string num;
    cin >> num;

    vector<int> f(10);
    for (int i = 1; i <= 9; i++) {
        cin >> f[i];
    }

    int i = 0;
    while (i < n && f[num[i] - '0'] <= (num[i] - '0')) {
        // 找到第一个映射后值大于原始值的位置
        i++;
    }

    while (i < n && f[num[i] - '0'] >= (num[i] - '0')) {
        // 对于之后所有的位置，如果映射后的值大于原始值，就替换
        num[i] = f[num[i] - '0'] + '0';
        i++;
    }

    cout << num << endl;

    return 0;
}
