#include <algorithm>
#include<bits/stdc++.h>

using namespace std;


vector<int> solve(int x, vector<int> &q) {
    vector<int> ans(q.size() , 0);
    map<int, int> mp, rangeMap;
    // current range
    rangeMap[x] += 1;

    for(int i = 0;i< q.size();i++) {
        auto cq = q[i];
        // printf("current query:%d\n", cq);
        if(mp.size() == 0) {
            mp[cq] = 1;
            rangeMap[cq] += 1;
            rangeMap[x - cq] += 1;
            ans[i] = max(cq, x - cq);
            // printf("first insert new range: %d %d\n", cq, x - cq);
            rangeMap[x] -= 1;
            if(rangeMap[x] == 0) {
                // printf("erasing %d in first insert\n",x);
                rangeMap.erase(x);
            }
            continue;
        }
        auto beg = mp.begin();
        if(cq < (*beg).first) {
            int rg = (*beg).first;

            mp[cq] = 1;

            rangeMap[rg] -= 1;
            if(rangeMap[rg] == 0) {
                rangeMap.erase(rg);
            }
            // printf("begin: new ranges: %d %d\n",cq, rg-cq);
            rangeMap[cq] += 1;
            rangeMap[rg - cq] += 1;

            auto rg_val = *(--rangeMap.end());
            ans[i] = (rg_val.first);
        } else {
            auto it = mp.upper_bound(cq);
            if(it == mp.end()) {
                // check if cq is greater than last range.
                auto last_light = *(--mp.end());
                int cr = x - last_light.first;
                // printf("end: deducting range %d with last %d\n", cr, last_light.first);
                rangeMap[cr] -= 1;
                if(rangeMap[cr] == 0) {
                    // printf("erasing range\n");
                    rangeMap.erase(cr);
                }
                rangeMap[cq - last_light.first] += 1;
                rangeMap[x - cq] += 1;
                
                mp[cq] = 1;

                // printf("after end : new ranges %d %d\n", cq-last_light.first, x - cq);
                auto rg_val = *(--rangeMap.end());
                ans[i] = (rg_val.first);

            } else {
                auto upper = *it;
                auto lower = *(--it);
                int rr = upper.first - cq;
                int lr = cq - lower.first;
                int cr = upper.first - lower.first;

                mp[cq] = 1;

                rangeMap[cr] -= 1;
                if(rangeMap[cr] == 0) {
                    rangeMap.erase(cr);
                }
                rangeMap[lr] += 1;
                rangeMap[rr] += 1;
                // printf("mid: new ranges %d %d\n", lr, rr);
                // get largest range.
                auto rg_val = *(--rangeMap.end());
                ans[i] = (rg_val.first);
            }
        }
    }
    return ans;
}

int main() {
    int x, n;
    cin>>x>>n;
    vector<int> arr(n , 0);
    for(int i=0;i < n;i++) {
        cin>>arr[i];
    }
    auto ans = solve(x, arr);
    for(int i=0;i<ans.size();i++) {
        if(i == ans.size() - 1) {
            printf("%d\n", ans[i]);
        }else {
            printf("%d ", ans[i]);
        }
    }
    return 0;
}