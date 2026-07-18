class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int i = 0;
        int j = plants.size()-1;
        int capa = capacityA;
        int capb = capacityB;
        int cnt = 0;
        while(i<j){
            
            if(capa<plants[i]){
                cnt++;
                capa = capacityA;
            }
            capa -= plants[i];
            i++;
            if(capb<plants[j]){
                cnt++;
                capb = capacityB;

            }
            capb -= plants[j];
            j--;
            
        }
        if(i == j){
            if(max(capa, capb)<plants[i]){
                cnt++;
            }
            
        }
        return cnt;
        
    }
};