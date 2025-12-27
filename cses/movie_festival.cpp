#include<bits/stdc++.h>
using namespace std;


int solve(vector<pair<int,int>> &time) {
    int ans = 0;
    auto cmp = [](const auto &a, const auto &b) -> bool {
        return a.second > b.second;
    };
    using pii = pair<int,int>;
    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
    int last = -1;
    for(auto t: time) {
        pq.push(t);
    }
    while(pq.size() > 0) {
        auto top = pq.top();
        pq.pop();
        if(last <= top.first) {
            ans += 1;
            last = top.second;
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<pair<int,int>> time(n, {0, 0});
    for(int i=0;i<n;i++) {
        cin>>time[i].first>>time[i].second;
    }
    cout<<solve(time)<<endl;
    return 0;
}