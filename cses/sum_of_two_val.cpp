#include<bits/stdc++.h>
using namespace std;


pair<int,int> solve(vector<int> &nums, int x, bool &impossible) {
    int n = nums.size();
    vector<pair<int,int>> arr(n, {0,0});
    for(int i=0;i<n;i++) {
        arr[i].first = nums[i];
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = arr.size() - 1;
    auto ans = make_pair(0, 0);
    while(left < right) {
        int sum = arr[left].first + arr[right].first;
        if(sum < x) {
            left += 1;
        }else if(sum == x) {
            ans.first = arr[left].second;
            ans.second = arr[right].second;
            if(ans.first >  ans.second) {
                swap(ans.first, ans.second);
            }
            impossible = false;
            break;
        }else {
            right -= 1;
        }
    }
    return ans;
}

int main() {
    int n, x;
    cin>>n>>x;
    vector<int> arr(n, 0);
    for(int i=0;i<n;i++) {
        cin>> arr[i];
    }
    bool impossible = true;
    auto ans = solve(arr, x, impossible);
    if(impossible) {
        cout<<"IMPOSSIBLE"<<endl;
    }else {
        cout<<ans.first<<" "<<ans.second<<endl;
    }
    return 0;
}