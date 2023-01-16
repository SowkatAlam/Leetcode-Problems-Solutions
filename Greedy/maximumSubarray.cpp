class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int siz=nums.size();
        int temp_ans=nums[0];
        
        for(auto i=1;i<siz;i++){
            temp_ans=temp_ans+nums[i];
            
            if(temp_ans<nums[i]){
                temp_ans=nums[i];
            }
            ans=max(ans,temp_ans);
        }
        return ans;
    }
};