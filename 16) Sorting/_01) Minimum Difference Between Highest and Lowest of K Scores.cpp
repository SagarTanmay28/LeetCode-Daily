/*
T.C = O(nlogn)
S.C = O(logn)
*/
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return 0;

        sort(nums.begin(), nums.end());

        int mini = INT_MAX;

        for (int i = 0; i + k - 1 < n; i++) {
            mini = min(mini, nums[i + k - 1] - nums[i]);
        }

        return mini;
    }
};
