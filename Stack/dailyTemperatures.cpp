class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>adj[101];
        vector<int> ans;
        
        int siz=temperatures.size();
        
        for(int i=0;i<siz;i++){
            adj[temperatures[i]].push_back(i);
        }
        
        /*
        for(int i=0;i<siz;i++){
            for(int j=0;j<adj[temperatures[i]].size();j++){
                cout<<adj[temperatures[i]][j]<<"  ";
            }
            cout<<endl;
        }
        */
        
        for(int i=0;i<siz;i++){
            int item=temperatures[i];
            
            int max_min_idx=100004;
            for(int j=item+1;j<=100;j++){
                if(adj[j].size()>0){
                    
                    /*
                    for(int k=0;k<adj[j].size();k++){
                        cout<<adj[j][k]<<"  ";
                    }
                    
                    cout<<endl;
                    */
                    int idx=lower_bound(adj[j].begin(), adj[j].end(), i+1)-adj[j].begin();
                    if(idx<adj[j].size()){
                        max_min_idx=min(max_min_idx, adj[j][idx]);
                    }
                    
                  //  cout<<idx<<endl;
                }
                
            }
            
            if(max_min_idx==100004){
              ans.push_back(0);  
            }
            else{
                ans.push_back(max_min_idx-i);
            }
            
        }
        return ans;
    }
};