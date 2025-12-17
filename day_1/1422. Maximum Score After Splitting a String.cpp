class Solution
{
public:
     int maxScore(string s)
     {

          int ans = 0;
          int n = s.size();
          int zero = 0;
          for (int i = 0; i < n - 1; i++)
          {
               if (s[i] == '0')
                    zero++;
               int one = 0;
               for (int j = i + 1; j < n; j++)
               {
                    if (s[j] == '1')
                    {
                         one++;
                    }
               }

               ans = max(ans, one + zero);
          }
          return ans;
     }
};
#include <bits/stdc++.h> 

 

int minpath(int i , int j,vector<vector<int>>& arr, int n,vector<vector<int>>& dp)
{

     if (i == n - 1)
     {

          return arr[n - 1][j];
     }

     if (dp[i][j] != -1)
          return dp[i][j];

     int down = arr[i][j] + minpath(i + 1, j, arr, n, dp);

     int diagonal = arr[i][j] + minpath(i + 1, j + 1, arr, n, dp);

     return dp[i][j] = min(down, diagonal);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{

     // Write your code here.

     vector<vector<int>> dp(n, vector<int>(n, -1));

     return minpath(0, 0, triangle, n, dp);
}