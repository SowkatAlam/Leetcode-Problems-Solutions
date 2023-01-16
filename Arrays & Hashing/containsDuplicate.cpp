class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int>mp;
        int siz=nums.size();
        
        for(int i=0;i<siz;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>=2){
                return true;
            }
        }
        return false;
    }
};