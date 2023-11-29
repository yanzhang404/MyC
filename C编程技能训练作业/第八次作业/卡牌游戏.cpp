#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    // 用于存储每张牌的出现次数
    map<char, int> count;

    // 输入每张牌的值
    for (int i = 0; i < n; i++) {
        char card;
        cin >> card;
        count[card]++;
    }

    // 将出现次数存储到数组中
    vector<int> freq;
    for (auto it = count.begin(); it!=count.end();it++) {
        // cout<<it->first<<" "<<it->second<<endl;
        freq.push_back(it->second);
    }

    // 将出现次数降序排列
    sort(freq.rbegin(), freq.rend());

    // 选择前 m 张牌
    int totalScore = 0;
    for(int i = 0; i<freq.size();i++){
        if(m-freq[i] >= 0){
            totalScore += freq[i]*freq[i];
            m-=freq[i];
        }
        else {
            totalScore += m * m;
            break;
        };
    }
    cout<<totalScore<<endl;
    return 0;
}
