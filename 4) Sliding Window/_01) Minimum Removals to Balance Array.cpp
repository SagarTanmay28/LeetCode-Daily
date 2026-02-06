/*
T.C = O(nlogn);
S.C = O(1);
*/
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int max_len = 0;

        sort(nums.begin(),nums.end());
        
        int i = 0;
        int j = 0;
        // Sliding Window 
        while(j < n){
            while(nums[j] > (long long)k * nums[i]) i++;
            max_len = max(max_len,j-i+1);

            j++;
        }

        return (n - max_len);
    }
};
