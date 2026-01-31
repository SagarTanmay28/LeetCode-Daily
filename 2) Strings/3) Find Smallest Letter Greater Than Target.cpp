/*
T.C = O(n);
S.C = O(1);
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& nums, char target) {
        int n = nums.size();
        for(char ch : nums){
            if(ch > target) return ch;
        }
        return nums[0];
    }
};
