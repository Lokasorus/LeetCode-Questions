class Solution {
public:
int fact(int n){
    if(n == 0) return 1;
    
    return n* fact(n-1);
}
// int find(vector<int> &arr, int k, int x){
//     int sum = 0;
//     for(int i = 0; i<arr.size(); i++){
//         if(arr[i]!= 0){
//             sum += x;
//             if(sum>k){
//                 return i;
//                 break;

//             }
//         }
//     }
//     return -1;
// }
    string getPermutation(int n, int k) {
    //     vector<int> ans;
    //     for(int i = 1; i<=n; i++){|
    //         ans.push_back(i);
    //     }
    //     if(k == 1) return n;

    //     int num = k;
    //     int f = n-1;
    //     int x = fact(f);
    //     string a ="";
    //     while(num>0){
    //         int ind = find(arr, k, x);
    //         a += ans[ind];
    //         ans[ind] = 0;
    //         num -=x;
    //         f--;
    //         x = fact(f);
            
    //     }

     map<int,int> mp;
     for(int i=1;i<=n;i++){
        mp[i]++;
     }
     string s="";
     int num=k;
     while(num){
        for(int i=n;i>=1;i--){
            int fac=fact(i-1);
            if(i==1)fac=0;
            for(int j=1;j<=9;j++){
                if(mp[j]==1){
                    if(num<=fac){
                        s+=to_string(j);
                        mp[j]--;
                        break;
                    }
                    else num-=fac;
                }
            }
        }
        break;
     }
     for(int i = 1; i<=9; i++){
        if(mp[i] == 1) s+=to_string(i);
     }
     return s;
     }
   
};