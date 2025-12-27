#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr1, int i, int j, int m, int n, vector<int> &res) {
    int ri = 0;
    while(i < m && j < n) {
        if(arr1[i] <= arr1[j]) {
            res[ri] = arr1[i];
            ri += 1;
            i += 1;
        }else {
            res[ri] = arr1[j];
            j += 1;
            ri += 1;
        }
    }
    while(i < m) {
        res[ri] = arr1[i];
        ri += 1;
        i+= 1;
    }
    while(j < n) {
        res[ri] = arr1[j];
        ri += 1;
        j+= 1;
    }
    // return res;
}

void mergeSort(vector<int> &arr, int l, int r) {
    if(l == r || l > r) {
        return;
    }
    if(r - l + 1 == 2) {
        if(arr[l] > arr[r]) {
            swap(arr[l], arr[r]);
        }
        return;
    }
    int len = r - l + 1;
    vector<int> dup(len, 0);

    int mid = l + (r - l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    
    merge(arr, l, mid + 1, mid + 1, r + 1, dup);
    // copying the array back
    // for(int i=l;i<len;i++) {
    //     arr[i] = dup[i];
    // }
    for(int i = l, ri = 0; i <= r; i++, ri ++) {
        arr[i] = dup[ri];
    }
}
vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> dup(n, 0);
    for(int i=0;i<n;i++) {
        dup[i] = nums[i];
    }
    mergeSort(dup, 0, n - 1);
    return dup;
    // return nums;
}

int main() {
    vector<int> arr { 0, -1, -2, 4, 6, 5};
    auto res = sortArray(arr);
    for(auto c: res) {
        cout<<c << " ";
    }
    cout<<endl;
    return 0;
}