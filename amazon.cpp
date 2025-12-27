#include<iostream>
#include<vector>

using namespace std;


int solve(vector<int> &schedule, vector<int> &refactoringDays) {
    int m = refactoringDays.size();
    vector<int> release_day(m + 1, -1);
    int total = 0;
    for(auto x: refactoringDays) {
        total += x;
    }
    int count = 0;
    int right = 0;
    int sz = schedule.size();
    int req_refactoringDays_so_far = 0;
    while(right < sz && count < m) {
        auto cm = schedule[right];
        if(cm == 0) {
            right += 1;
            continue;
        } else {
            // check if it is possible to release cm on this day.
            // it is possible to release an item today.
            int days_for_curr_module = right - count - req_refactoringDays_so_far;
            if(days_for_curr_module < refactoringDays[cm - 1]) {
                // it is not possible to refactor all the modules.
                // go ahead without releasing cm today.
                right += 1;
                continue;
            }
        }

        if(release_day[cm] == -1) {
            req_refactoringDays_so_far += refactoringDays[cm - 1];
            count += 1;
        }
        release_day[cm] = right;
        if(count == m) {
            //  to ensure that right points to last release day.
            return right + 1;
            // break;
        }
        right += 1;
    }
    return -1;
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<int> refDays(m, 0);
    vector<int> schedule(n, 0);
    for(int i=0;i<n;i++) {
        cin>>schedule[i];
    }
    for(int i=0;i<m;i++) {
        cin>>refDays[i];
    }
    cout<<solve(schedule, refDays) <<endl;
}

// case 1
// 7 2
// 0 0 1 0 2 2 2
// 2 2



// case 2
// 8 2
// 1 0 0 1 2 2 1 2
// 1 2


// case 3
// 10 3
// 2 1 3 2 2 2 2 2 3 1
// 2 2 2