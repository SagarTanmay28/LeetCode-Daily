/*
T.C = O(n^2);
S.C = O(1);
*/
class Solution {
public:
    int minPairSum(vector<int>& nums){
        int n = nums.size();

        int sum = INT_MAX;
        int idx = -1;

        for(int i=0;i<n-1;i++){
            if(nums[i] + nums[i+1] < sum){
                sum = nums[i] + nums[i+1];
                idx = i;
            }
        }

        return idx;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;

        while(!is_sorted(nums.begin(),nums.end())){
            int i = minPairSum(nums);

            nums[i] = nums[i] + nums[i+1];

            nums.erase(nums.begin() + i + 1);

            operations++;
        }

        return operations;
    }
};
