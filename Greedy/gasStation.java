class Solution {
    
    public int canCompleteCircuit(int[] gas, int[] cost) {
        
        int siz=gas.length;
        
        for(int i=0;i<siz;i++){
            
            int totalGas=0;
            int gasStationVisit=0;
            int sn=i;
            
            while(gasStationVisit<siz){
                totalGas+=(gas[sn%siz]-cost[sn%siz]);
                
                if(totalGas<0){
                    i=sn;
                    break;
                }
                sn++;
                gasStationVisit++;
            }
            if(totalGas>=0 && gasStationVisit==siz)return i;
            
        }
        return -1;
    }
    
}