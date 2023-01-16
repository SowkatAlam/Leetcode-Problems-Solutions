class Solution {
public:
    
    long long int getResult(long long int top1, long long int top2, string token){
        if(token=="+")return top1+top2;
        else if(token=="-") return top2-top1;
        else if(token=="*") return top2*top1;
        else if(token=="/") return top2/top1;
        return 0;
    }
    long long int stringToInt(string temp){
        return stoi(temp);
    }
    int evalRPN(vector<string>& tokens) {
        
        stack<long long int>s;
        
        s.push(stringToInt(tokens[0]));
    
        int siz=tokens.size();
        
        for(int i=1;i<siz;i++){
            if(tokens[i]=="+"|| tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                long long int top1=s.top();
                s.pop();
                long long int top2=s.top();
                s.pop();
                s.push(getResult(top1,top2,tokens[i]));
            }
            else{
                s.push(stringToInt(tokens[i]));
            }
        }
        
        if(!s.empty())return s.top();
        return 0;
    }
};