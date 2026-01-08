/*
T.C = O(n * m);
S.C = O(n * m); + Recursion Stack 
*/
class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& dp){
        if(i == nums1.size() || j == nums2.size()) return -1e9;

        if(dp[i][j] != -1) return dp[i][j];

        int take = (nums1[i] * nums2[j]) + max(0,solve(nums1,nums2,i+1,j+1,dp));
        int skip1 = solve(nums1,nums2,i+1,j,dp);
        int skip2 = solve(nums1,nums2,i,j+1,dp);

        return dp[i][j] = max({take,skip1,skip2});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),-1));
        return solve(nums1,nums2,0,0,dp);
    }
};

/*********************************************************************BOTTOM-UP***************************************************************************************/
/*
T.C = O(n * m);
S.C = O(n * m);
*/
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int INF = -1e9;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1e9));

        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = m - 1 ; j >= 0 ; j--){
                int take = (nums1[i] * nums2[j]) + max(0,dp[i+1][j+1]);
                int skip1 = dp[i+1][j];
                int skip2 = dp[i][j+1];

                dp[i][j] = max({take,skip1,skip2});
            }
        }

        return dp[0][0];
    }
};
