#include<bits/stdc++.h>

using namespace std;

int lineSweep(vector<pair<int,int>> &time) {
    int ans = 0;
    map<int,int> mp;
    for(auto &kv: time ) {
        mp[kv.first] += 1;
        mp[kv.second] -= 1;
    }
    int ct = 0;
    for(auto x: mp) {
        ct += x.second;
        ans = max(ans, ct);
    }
    return ans;
}

int heapSolution(vector<pair<int,int>> &time) {
    int ans = 0;
    using pii = pair<int,int>;
    priority_queue<pii, vector<pii>, greater<>> pq;
    sort(time.begin(), time.end());
    int ct = 0;
    for(auto &t: time) {
        if(pq.size() == 0) {
            pq.push({t.second, t.first});
            ct += 1;
            continue;
        }
        int arrT = t.first;
        while(pq.size() > 0 && pq.top().first < arrT) {
            pq.pop();
        }
        int cap = pq.size() + 1;// new arrival inserted
        pq.push({t.second, t.first});
        ans = max(ans, cap);
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<pair<int,int>> t(n, {0,0});
    for(int i=0;i<n;i++) {
        cin>>t[i].first>>t[i].second;
    }
    cout<<lineSweep(t)<<endl;
    // cout<<heapSolution(t)<<endl;
}