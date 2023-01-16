class Solution {
public:
    
    bool isValid(string s) {
        
        stack<char>ans;
        bool isValid=true;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='(' || s[i]=='[' ||s[i]=='{'){
                ans.push(s[i]);
            }
            else{
                if(ans.size()==0){
                        return false;
                    }
                if(s[i]==')' && ans.top()!='('){
                    return false;
                }
                else if(s[i]==']' && ans.top()!='[')
                {
                    return false;
                }
                else if(s[i]=='}' && ans.top()!='{'){
                    return false;
                }
                else{
                    
                    ans.pop();
                }
            }
        }
        if(ans.size()==0){
            return true;
        }
        return false;
    }
};