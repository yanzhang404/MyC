#include <iostream>
#include <vector>

using namespace std;

// 1 2 3 4 5 
// l=1; r=5; mid=3 => 123 45 
void merge(vector<int> &arr, int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> arr1(n1 + 10);
    for(int i =1; i <= n1; i++) arr1[i] = arr[l+ i - 1];

    vector<int> arr2(n2 + 10);
    for(int i =1; i <= n2; i++) arr2[i] = arr[i + mid];

    int i=1, j= 1;
    int k=l; //控制arr数组 

    while(i <= n1 && j <= n2){ //挨个比较 
      arr[k++] = arr1[i] <=arr2[j]?arr1[i++]:arr2[j++];
    } 

    while(i <= n1){
        arr[k++] = arr1[i++];
    }

    while(j <= n2){
        arr[k++] = arr2[j++];
    }


}
void mergeSort(vector<int> &arr, int l, int r){
    if(l >= r) return;
    int mid = l + (r - l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid +1, r);
    merge(arr, l, mid, r);
}

void printArr(const vector<int> & arr, int n){
    for(int i = 1; i <= n; i++) cout << arr[i] <<" ";
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n+10);
    for(int i = 1; i <= n; i++) cin >> arr[i];

    mergeSort(arr, 1, n);

    printArr(arr,n);
    return 0;
}
