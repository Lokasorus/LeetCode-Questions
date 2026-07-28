class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        map<int, int> mpp;
        int cnt = 0;
        for(int i = 0; i<row.size(); i++){
            mpp[row[i]] = i;
        }
        for(int i = 0; i<row.size(); i+=2){
            if(row[i]%2 == 0){
                if(mpp[row[i] + 1] != i+1){
                    int temp = mpp[row[i] + 1];
                    mpp[row[i] + 1] = mpp[row[i+1]];
                    mpp[row[i+1]] = temp;
                    swap(row[mpp[row[i] + 1]], row[mpp[row[i+1]]]);
                    cnt++;
        
                }
            }else{
                if(mpp[row[i] - 1] != i+1){
                    int temp = mpp[row[i] - 1];
                    mpp[row[i] - 1] = mpp[row[i+1]];
                    mpp[row[i+1]] = temp;
                    swap(row[mpp[row[i] - 1]], row[mpp[row[i+1]]]);

                    cnt++;
        
                }

            }
        }
        return cnt;
    }
};