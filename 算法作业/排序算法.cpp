#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int t[9] = {3,2,1,100,20,1,19,23,50};
vector<int> num(t,t+9);
int n = num.size();

//冒泡排序
void bubble_sort(vector<int> num){
    int n = num.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(num[j] > num[j+1]){
                int temp = num[j+1];
                num[j+1] = num[j];
                num[j] = temp;
            }
        }
        printf("第%d轮顺序为：",i+1);
        for(int i = 0; i < n; i++){
            
            cout<<num[i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//插入排序
void insert_sort(vector<int> num){
    int n = num.size();
    for(int i =0; i < n; i++){
        int value = num[i];
        int position = i;
        while( position > 0 && num[position-1] > value){
            num[position] = num[position-1];
            position--;
        }
        num[position] = value;
        printf("第%d轮顺序为：",i+1);
        for(int i = 0; i < n; i++){
            
            cout<<num[i]<<" ";
        }
        cout<<endl;
    }
}
//归并排序
vector<int> temp(n);

void mergeSortedArray(vector<int>& num, int l,int m, int r){
    vector<int> temp(n);
    int i = l;
    int j = r;
    int k = 0;
    while( i <= m && j <r){
        temp[k++] = num[i] <= num[j] ? num[i++] : num[j++];
    }
    while( i < m){
        temp[k++] = num[i++];
    }
    while(j < r){
        temp[k++] = num[j++];
    }
    for(int i = 0; i < k; i++){
        num[l+i] = temp[i];
    }
}

//int t[9] = {5,4,3,2,1, 50, 23, 19, 1};
void merge_sort(vector<int>& num,int l, int r){
    if(l >= r)  {
        return;
    }
    int m = ( l + r) >> 1;
 //   printf("%d\n",m);
    merge_sort(num,l,m);
    merge_sort(num,m+1,r);
    int i = l,j = m+1;
    int k = 0;
    while(i <= m && j <= r){
        temp[k++] = num[i] <= num[j] ? num[i++] : num[j++];
    }
    while(i <= m) temp[k++] = num[i++];
    while(j <= r) temp[k++] = num[j++];
    for(i = l,j = 0; i <= r; i++,j++)   num[i] = temp[j];
    for(int i = 0; i < n; i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;
}


int partition(vector<int>& num,int l, int r){
    int pivot = num[l];
    while(l < r){
        while(l < r && num[r] >= pivot){
            --r;
        }
        num[l] = num[r];
        while(l < r && num[l] <= pivot){
            ++l;
        }
        num[r] = num[l]; 
    }
    num[l] = pivot;
    return l;
}

void quick_sort(vector<int>& num,int l, int r){
    if(l < r){
        for(int i = 0; i < n; i++){
        cout<<num[i]<<" ";
        }
    cout<<endl;
        int pivot = partition(num,l,r);
        quick_sort(num, l, pivot - 1);
        quick_sort(num,pivot + 1, r);
    }
}



int main(){
    cout<<"冒泡排序："<<endl;
    bubble_sort(num);
    // cout<<"插入排序："<<endl;
    // // insert_sort(num);
    // cout<<"归并排序："<<endl;
    // merge_sort(num,0,n-1);
    for(int i = 0; i < n; i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;
    cout<<"快速排序："<<endl;
    quick_sort(num,0,n-1);
    for(int i = 0; i < n; i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;
    return 0;
        
}