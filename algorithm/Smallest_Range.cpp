class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        vector<int> idx(k,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int curr_max=INT_MIN;
        for (int i=0; i<k; ++i) {
            curr_max = max(curr_max, nums[i][idx[i]]);
            pq.push({nums[i][idx[i]], i});
        }
        vector<int> ans({pq.top().first, curr_max});
        while (true) {
            int ind = pq.top().second;
            ++idx[ind];
            if (idx[ind] == nums[ind].size()) return ans;
            curr_max = max(curr_max, nums[ind][idx[ind]]);
            pq.pop();
            pq.push({nums[ind][idx[ind]], ind});
            if (curr_max-pq.top().first < ans[1]-ans[0]) {
                ans[0] = pq.top().first;
                ans[1] = curr_max;
            }
        }
        return ans;
    }
};