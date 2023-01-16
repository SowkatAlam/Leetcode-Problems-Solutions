class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mp;
        int siz=numbers.size();
        for(int i=0;i<siz;i++){
            mp[numbers[i]]=i+1;
        }
        vector<int>ans;
        for(int i=0;i<siz;i++){
            if(mp[target-numbers[i]]>=1){
                
                ans.push_back(i+1);
                ans.push_back(mp[target-numbers[i]]);
                return ans;
            }
        }
        return ans;
    }
};