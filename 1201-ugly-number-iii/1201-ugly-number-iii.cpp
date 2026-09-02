class Solution {
public:
    int nthUglyNumber(int n, int A, int B, int C) {
        long long a = (long long)A;
        long long b = (long long)B;
        long long c = (long long)C;
        long long ab = (a*b)/(__gcd(a, b));
        long long bc = (b*c)/(__gcd(b, c));
        long long ac = (a*c)/(__gcd(a, c));
        long long abc = (a*bc)/(__gcd(a, bc));
        long long l = 1;
        long long r = 2*(int)1e9;

        while(l<r){
            long long mid = l + (r-l)/2;
            long long k  = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc;
            if(k<n){
                l = mid+1;
            }else{
                r = mid;
            }

        }
        return r;
        
    }
};