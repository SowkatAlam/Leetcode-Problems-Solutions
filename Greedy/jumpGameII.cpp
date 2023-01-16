class Solution {
public:
    
    int jump(vector<int>& nums) {
        
        int siz=nums.size()-1;
        
        int currentLadder=0;
        int maxLadder=nums[0];
        int jump=0;
        
        for(int i=0;i<siz;i++){
            maxLadder=max(maxLadder,i+nums[i]);
            if(currentLadder==i){
                jump++;
                currentLadder=maxLadder;
            }
        }
        
        return jump;
    }
};