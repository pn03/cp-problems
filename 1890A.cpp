// #include<iostream>
// #include<vector>
// #include<string>
// #include<map>

#include<bits/stdc++.h>

using namespace std;

string solve(vector<int> &arr, int len) {
    if(len == 2) {
        return "Yes";
    }
    unordered_map<int,int> mp;
    for(int i = 0;i<len;i++) {
        mp[arr[i]] += 1;
    }
    int sz = mp.size();
    if(sz == 1) {
        return "Yes";
    }
    if(sz == 2) {
        vector<int> two;
        for(auto x: mp) {
            two.push_back(x.second);
        }
        int tt = abs(two[0] - two[1]);
        if((len%2 == 1 && tt == 1) || (len%2 == 0 && tt == 0)){
            return "Yes";
        }
    }
    return "No";
}

int main() {
    int t;
    cin>>t;
    vector<int> arr(101, 0);
    while(t-- > 0) {
        int n;
        cin>>n;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        cout<<solve(arr, n)<<endl;
    }
    return 0;
}