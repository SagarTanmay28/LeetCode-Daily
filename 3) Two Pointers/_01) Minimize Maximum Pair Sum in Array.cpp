/*
T.C = O(n*logn);
S.C = O(logn); -> Quick Sort 
*/
class Solution {
public:
    int minPairSum(vector<int>& nums) {

        int n = nums.size();
        int maxi = INT_MIN;

        sort(nums.begin(),nums.end());

        int i = 0;
        int j = n - 1;

        while(i < j){
            int sum = nums[i] + nums[j];
            if(sum > maxi) maxi = sum;

            i++;
            j--;
        }

        return maxi;
    }
};
