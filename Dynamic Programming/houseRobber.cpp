class Solution{
    public:
    int rob(vector<int>& nums){
        
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int pre_pre=nums[0];
        int pre=max(pre_pre,nums[1]);
        int current=nums[2];
        
        for(auto i=2;i<nums.size();i++){
            current= max(pre, pre_pre+nums[i]);
            pre_pre=pre;
            pre=current;
        }
        return current;
    }
};