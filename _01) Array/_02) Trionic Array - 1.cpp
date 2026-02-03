/*
T.C = O(n);
S.C = O(1);
*/
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        int p = -1;
        int q = -1;

        for(int i=1;i<n-1;i++){
            if(nums[i] > nums[i-1]) p = i;
            else break;  
        }
        if(p == -1) return false;

        for(int i=p+1;i<n-1;i++){
            if(nums[i] < nums[i-1]) q = i;
            else break;
        }
        if(q == -1) return false;
        if(q <= p) return false;

        for(int i=q+1;i<n;i++){
            if(nums[i] <= nums[i-1]) return false;
        }

        return true;
    }
};
