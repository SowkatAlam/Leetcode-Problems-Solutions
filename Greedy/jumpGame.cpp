class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        
        vector<int>dpt(nums.size()+1,false);
        dpt[nums.size()-1]=true;
        
        int siz=nums.size();
        
        for(int i=nums.size()-2;i>=0;i--){
            
            int diff=min(nums[i],abs(siz-i));
            
            for(int j=diff;j>=0;j--){
                if(dpt[i+j]==true){
                    dpt[i]=true;
                    break;
                }
            }
        }
        return dpt[0];
    }
};