#include<bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> &h, vector<int> &t) {
    int m = t.size();
    int n = h.size();
    vector<int> res(m, -1);
    map<int,int> ticketMap;
    for(int i=0;i<n;i++) {
        ticketMap[h[i]] += 1;
    }
    for(int i=0;i<m;i++) {
        int curr = t[i];
        if(ticketMap.find(curr) != ticketMap.end()) {
            ticketMap[curr] -= 1;
            if(ticketMap[curr] == 0) {
                ticketMap.erase(curr);
            }
            res[i] = curr;
        } else {
            if(ticketMap.size() > 0) {
                auto it = ticketMap.lower_bound(curr);
                if(it != ticketMap.begin()) {
                    --it;
                    auto pp = *it;
                    if(pp.first < curr) {
                        if(pp.second == 1){
                            ticketMap.erase(pp.first);
                        } else {
                            ticketMap[pp.first] -= 1;
                        }
                    }
                    res[i] = pp.first;
                } else {
                    res[i] = -1;
                }
            } else {
                res[i] = -1;
            }
        }
    }
    return res;
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<int> h(n, 0), t(m, 0);
    for(int i=0;i<n;i++) {
        cin>>h[i];
    }
    for(int i=0;i<m;i++) {
        cin>>t[i];
    }
    auto res = solve(h, t);
    for(auto a: res) {
        cout<<a<<endl;
    }
    return 0;
}