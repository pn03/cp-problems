#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &app, vector<int> &sz, int k) {
    int n = app.size();
    int m = sz.size();
    sort(sz.begin(), sz.end());
    sort(app.begin(), app.end());
    int i = 0;
    int j = 0;
    int ans = 0;
    while(i < n && j < m) {
        auto req = app[i];
        auto curr = sz[j];
        // printf("req %d apt: %d\n", req, curr);
        if(req - k <= curr && curr <= req + k) {
            ans +=1;
            i += 1;
            j += 1;
        } else {
            // apartment doesn't match
            if(req + k < curr) {
                // request is too small
                // printf("popping request %d\n", req);
                i += 1;
            }else if(curr < req - k) {
                // apartment is too small
                j += 1;
            }
        }
    }
    return ans;
}

int main() {
    int m, n, k;
    cin>>n>>m>>k;
    vector<int> app(n, 0), sz(m , 0);
    for(int i=0;i<n;i++) {
        cin>> app[i];
    }
    for(int i=0;i<m;i++) {
        cin>> sz[i];
    }
    cout<<solve(app, sz, k)<<endl;
    return 0;
}