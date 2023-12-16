#include <bits/stdc++.h>
using namespace std;
int main() {
    string num;
    cin >> num;
    int n = num.length(), halfN = n >> 1, cnt4 = 0, cnt7 = 0;
    vector<int> pos4Index;
    string ret;
    auto helper = [&](int len){
        ret.insert(ret.end(), len - cnt4, '4');
        ret.insert(ret.end(), len - cnt7, '7');
    };
    auto modify4To7 = [&](int index){
        ret[index] = '7';
        ret.erase(ret.begin() + index + 1, ret.end());
        cnt7 = count_if(ret.begin() , ret.end(), [&](char c){return c == '7';});
        cnt4 = ret.length() - cnt7;
        helper(halfN);
    };
    auto handler = [&](){
        if(pos4Index.empty()){ret.clear(), cnt4 = cnt7 = 0; helper(halfN + 1);}
        else if(cnt7 < halfN){
            modify4To7(pos4Index.back());
        } else{
            pos4Index.push_back(ret.length());
            for(int i = pos4Index.size() - 2; i >= 0; --i){
                if(pos4Index[i] + 1 < pos4Index[i + 1]){modify4To7(pos4Index[i]);return;}
            }
            ret.clear(), cnt4 = cnt7 = 0; helper(halfN + 1);
        }
    };
    if(n & 1){helper(halfN + 1);}
    else{
        for(int i = 0; i < n; ++i){
            if(num[i] > '7'){ handler(); break;}
            else if(num[i] > '4'){
                if(cnt7 == halfN){handler(); break;}
                ret.push_back('7'), ++cnt7;
                if(num[i] < '7'){helper(halfN); break;}
            }else{
                if(cnt4 == halfN){helper(halfN);break;}
                ++cnt4, pos4Index.push_back(i), ret.push_back('4');
                if(num[i] < '4'){helper(halfN); break;}
            }
        }
    }
    cout << ret << endl;
    return 0;
}