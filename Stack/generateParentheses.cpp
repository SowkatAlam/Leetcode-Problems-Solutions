class Solution {
public:
    
    unordered_set<string> str_list;
    
    void f(int n, string temp, int left_char, int right_char){
        
        if(temp.size()==n*2){
            str_list.insert(temp);
            return ;
        }
        //cout<<temp<<endl;
        
        if(left_char<n){
            f(n, temp+'(',left_char+1, right_char);
        }
        if(right_char<left_char){
            f(n, temp+')', left_char, right_char+1);
        }
        
        
        return ;
    }
    
    bool check_if_valid(string s){
        int siz=s.size();
        stack<char>st;
        
        //s.push_back(s[0]);
        
        
        for(int i=0;i<siz;i++){
            if(s[i]=='('){
                st.push('(');
            }
            else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }else{
                    return false;
                    
                }
            }
            
        }
        
        
        if(st.empty())return true;
        
        return false;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        f(n,"",0,0);
        
       // cout<<str_list.size();
        
        for(auto const &i : str_list){
            //cout<<i<<endl;
            ans.push_back(i);
            /*
            if(check_if_valid(i)){
                ans.push_back(i);
            }
            */
        }
       //cout<<ans.size();
        
        return ans;
    }
};