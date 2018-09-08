class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int na=A.size(), cnt=0;
        vector<unordered_map<int,int>> hashmap(na);
        for (int i=0; i<na; ++i) {
            for (int j=0; j<i; ++j) {
                int d=A[i]-A[j];
                if (hashmap[j].count(d) == 0) ++hashmap[i][d];
                else {
                    hashmap[i][d] += hashmap[j][d]+1; 
                    cnt += hashmap[j][d];
                }
            }
        }
        return cnt;
    }
};