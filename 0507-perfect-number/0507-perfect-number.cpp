class Solution {
public:
    bool checkPerfectNumber(int num) {
        int cnt = 0;
        if(num == 1) return false;
        for(int i = 1; i<=sqrt(num); i++){
            if(num%i == 0){
                int first = i;
                int second = num/i;
                if(first!=second && i!= 1){
                    cnt = cnt + first+ second;
                    
                }else{
                    cnt+= first;
                }
            }
        }
        return cnt == num;
        
    }
};