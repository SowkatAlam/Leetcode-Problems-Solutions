class Solution {
private:
    bool check_palin(string ss){
        int i=0;
        int j=ss.size()-1;
        while(i<j){
            if(ss[i]!=ss[j])return false;
            i++;
            j--;
        }
        return true;
    }
public:
    
    bool isPalindrome(string s) {
        string ss="";
        
        for(auto i=0;i<s.size();i++){
            if( (s[i]>=48 && s[i]<=57) || (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) ){
                
                if((s[i]>=65 && s[i]<=90)){
                    ss+=s[i]+32;
                }
                else{
                    ss+=s[i];
                }
                
            }
        }
        //cout<<ss;
        return check_palin(ss);
    }
};