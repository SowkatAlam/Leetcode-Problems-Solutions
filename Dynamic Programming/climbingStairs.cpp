class Solution {
public:
    int dp[50];
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return runDp(1, n);
    }
    int runDp(int c, int n){
        if(c>=n){
            return 1;
        }
       else if(dp[c]!=-1)return dp[c];
        else{
             dp[c]=runDp(c+1, n) + runDp(c+2, n);
            return dp[c];
        }
    }
};