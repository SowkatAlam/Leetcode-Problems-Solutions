class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int siz=nums.size();
        map<int,int>mp;
        
        vector<int>ans;
        
        for(int i=0;i<siz;i++){
            mp[nums[i]]=i;
        }
        
        for(int i=0;i<siz;i++){
            int rest=target-nums[i];
            auto it=mp.find(rest);
            
            if(it!=mp.end() && target!=nums[i]*2){
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                return ans;
            }
            else if(it!=mp.end() && target==nums[i]*2){
                for(auto j=0;j<siz;j++){
                    if(i!=j && nums[i]==nums[j]){
                        ans.push_back(i);
                        ans.push_back(j);
                        return ans;
                    }
                }
            }
            
        }
        return ans;
    }
};