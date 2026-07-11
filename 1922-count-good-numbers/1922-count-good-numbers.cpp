class Solution {
public:
long long MOD = 1e9+7;
long long binaryExp(long long x, long long n){
    if(n == 0) return 1;
    long long half = binaryExp(x, n/2);
    long long val = (half*half)%MOD;
    if(n%2 == 1) val = (x*val)%MOD;
    return val;
}
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        return (binaryExp(5, even)*binaryExp(4, odd))%MOD;

        
    }
};