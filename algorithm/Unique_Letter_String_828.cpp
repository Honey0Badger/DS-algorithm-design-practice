/* Notes: Try optimize the solution to 1 pass */

class Solution {
public:
    int uniqueLetterString(string S) {
        int ns=S.length();
        long ans=0;
        for (int i=0; i<26; ++i) {
            char c = 'A'+i;
            int pre=-1, curr=-1, next=-1;
            for (int j=0; j<ns; ++j) {
                if (S[j] != c) continue;
                if (curr < 0) curr = j; 
                else {
                    if (next < 0) next = j;
                    else {
                        pre = curr;
                        curr = next;
                        next = j;        
                    }
                    ans += (curr-pre)*(next-curr);
                    ans %= MOD;
                }
            }
            if (next >= 0) ans += (next-curr)*(ns-next);
            else if (curr >= 0) ans += (curr-pre)*(ns-curr);
            ans %= MOD;    
        }
        return ans;
    }
private:
    const static int MOD = 1000000007;
};