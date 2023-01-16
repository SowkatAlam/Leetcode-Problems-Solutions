class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int siz=nums.size();
        
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans_temp;
        set<vector<int>>ans;
        
        for(int i=0;i<siz;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int low=i+1;
            int high=siz-1;
            while(low<high){
                if(nums[low]+nums[high]+nums[i]==0){
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    //ans.push_back(temp);
                    //ans.insert(temp);
                    ans_temp.push_back(temp);
                    while(low<high && nums[low]==nums[low+1]){
                        low++;
                    }
                    while(low<high && nums[high]==nums[high-1]){
                        high--;
                    }
                    low=low+1;
                    high--;
                }
                else if(nums[low]+nums[high]+nums[i]>0){
                    high--;
                }else if(nums[low]+nums[high]+nums[i]<0){
                    low++;
                }
            }
        }
        /*
        for(set<vector<int>>::iterator it=ans.begin();it!=ans.end();it++){
            ans_temp.push_back(*it);
        }
        */
        return ans_temp;
    }
    
    /*
    vector<vector<int>> threeSum(vector<int>& nums) {
        int siz=nums.size();
        sort(nums.begin(),nums.end());
        
        set<vector<int>>ans;
        unordered_map<int,int>mp;
        vector<vector<int>> ans_temp;
        
        for(int i=0;i<siz;i++){
            mp[nums[i]]=i;
        }
        
        for(int i=0;i<siz;i++){
            for(int j=i+1;j<siz;j++){
                if(mp.count(-(nums[i]+nums[j]))>=1 && mp[-(nums[i]+nums[j])]>i && mp[-(nums[i]+nums[j])]>j && i-1>=0 && nums[i]!=nums[i-1]){
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(-(nums[i]+nums[j]));
                    ans_temp.push_back(temp);
                    
                    
                    if(ans.find(temp)==ans.end()){
                        ans.insert(temp);
                        ans_temp.push_back(temp);
                    }
                    
                    
                }
            }
        }
        
        for(set<vector<int>>::iterator it=ans.begin();it!=ans.end();it++){
            ans_temp.push_back(*it);
        }
        
        return ans_temp;
    }
    */
};