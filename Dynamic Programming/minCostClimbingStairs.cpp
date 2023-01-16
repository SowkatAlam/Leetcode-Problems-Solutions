class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int>dp(cost.size()+2,0);
        int siz=cost.size();
        dp[siz]=0;
        dp[siz+1]=0;
        
        for(int i=siz-1;i>=0;i--){
            dp[i]=min(dp[i+1]+cost[i],dp[i+2]+cost[i]);
        }
        
        return min(dp[0],dp[1]);
    }
};