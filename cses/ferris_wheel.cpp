#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &wt, int x) {
    int ans = 0;
    sort(wt.begin(), wt.end());
    int n = wt.size();
    int left = 0;
    int right = n - 1;
    if(wt[right] > x) {
        return -1;
    }
    while(left <= right) {
        int a = wt[left];
        int b = wt[right];
        if(a + b <= x) {
            ans += 1;
            left += 1;
            right -= 1;
        }else {
            ans += 1;
            right -= 1;
        }
    }
    return ans;
}

int main() {
    int n, x;
    cin>> n >> x;
    vector<int> p(n, 0);
    for(int i=0;i<n;i++) {
        cin>>p[i];
    }
    cout<<solve(p, x)<<endl;
    return 0;
}