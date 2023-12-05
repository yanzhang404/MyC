#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

vector<int> temp;  // 全局变量

LL mergesort(int l, int r, vector<int> q) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    LL res = mergesort(l, mid, q) + mergesort(mid + 1, r, q); // 逆序对都在一侧的情况
    int i = l, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) {
            temp[k++] = q[i++];
        } else {
            temp[k++] = q[j++];
            res += mid - i + 1;  // 加上逆序对分在两侧的情况
        }
    }
    while (i <= mid) {
        temp[k++] = q[i++];
    }
    while (j <= r) {
        temp[k++] = q[j++];
    }
    for (int i = l, j = 0; i <= r; i++, j++) {
        q[i] = temp[j];
    }
    return res;
}

int main() {
    // 示例数组
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    temp.resize(arr.size());  // 初始化全局变量 temp
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // 计算逆序对数量
    LL result = mergesort(0, arr.size() - 1, arr);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout << "The number of inversions is: " << result << endl;

    return 0;
}
