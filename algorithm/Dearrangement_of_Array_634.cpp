class Solution {
public:
    int findDerangement(int n) {
        if (n <= 1) return 0;
        if ( n== 2) return 1;
        long s0=0, s1=1, s2;
        for (int i=3; i<=n; ++i) {
            s2 = ((i-1)*(s1+s0)) % MOD;
            s0 = s1;
            s1 = s2;
        }
        return s2;
    }
private:
    const static int MOD=1000000007;
};