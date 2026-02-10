
// Brute Force 
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            int evenCount = 0;
            int oddCount = 0;
            unordered_set<int> st;

            for(int j=i;j<n;j++){
                if(st.find(nums[j]) == st.end()){
                    if(nums[j] % 2 == 0) evenCount++;
                    else oddCount++;
                    st.insert(nums[j]);
                }

                if(oddCount == evenCount) ans = max(ans,j-i+1);
            }
        }

        return ans;
    }
};
