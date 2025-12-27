#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp(502, vector<int>(502, -1));

int TopDown(int a, int b) {
  if (a > b) {
    // HOW IS THIS IMPORTANT ?
    /**
        This small condition is reducing the time complexity by huge
        margins.
        This is because 10x6 can be cut horizontally to 2x6 and 8x6
        This is because 10x6 can be cut vertically to 10x2 --> 6x2 + 4x2 and
       10x4

        In the above cases, you can see that 6x2 is subproblem of 10x2
        and 2x6 is the subproblem of 10x6.
        Both, 6x2 and 2x6 are two same subproblems.
        If we don't swap these two then there is double calculation.
        So, the below condition is very important optimization.
    */
    return TopDown(b, a);
  }
  if (a == b) {
    // no cuts required
    return 0;
  }
  //   if(a == 1) {
  //     return b - 1;
  //   }else if(b == 1) {
  //     return a - 1;
  //   }
  if (dp[a][b] != -1) {
    return dp[a][b];
  }
  int ans = a * b;
  for (int i = 1; i < a; i++) {
    auto x = TopDown(i, b);
    auto y = TopDown(a - i, b);
    auto t = x + y + 1;
    ans = min(t, ans);
  }
  for (int i = 1; i < b; i++) {
    auto x = TopDown(a, i);
    auto y = TopDown(a, b - i);
    auto t = x + y + 1;
    ans = min(t, ans);
  }
  dp[a][b] = ans;
  return ans;
}

long long BottomUp(int w, int h) {
  for (int i = 0; i <= w; i++) {
    for (int j = 0; j <= h; j++) {
      if (i == j) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = 1e9;
        for (int k = 1; k < i; k++) {
          dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
        }
        for (int k = 1; k < j; k++) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
        }
      }
    }
  }
  return dp[w][h];
}

int main() {
  int a, b;

  cin >> a >> b;

  // auto start = std::chrono::high_resolution_clock::now();
  auto ans = TopDown(a, b);
  cout << ans << endl;
  // auto ans = BottomUp(a,b);
  // auto end = std::chrono::high_resolution_clock::now();

  // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end -
  // start); cout<<ans<<" time: "<<duration.count()<<endl;
  return 0;
}