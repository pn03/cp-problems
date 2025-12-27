#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &arr) {
    int n = arr.size();
    vector<pair<int,int>> ap(n, {0, 0});
    for(int i=0;i<n;i++ ) {
        ap[i].first = arr[i];
        ap[i].second = i + 1;
    }
    sort(ap.begin(), ap.end());
    int rounds = 1; // already a round has started.
    int prev_index = ap[0].second;
    for(int i=1;i<n;i++) {
        auto curr = ap[i];
        // printf("curr: %d at index %d\n", curr.first, curr.second);
        if(curr.second < prev_index) {
            // printf("increasing rounds\n");
            rounds += 1;
        }
        prev_index = curr.second;
    }
    return rounds;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    auto ans = solve(arr);
    cout<<ans<<endl;
    return 0;
}