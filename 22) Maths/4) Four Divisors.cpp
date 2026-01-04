/*
T.C = O(n*sqrt(m))
S.C = O(1)
*/
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            int num = nums[i];
            int count = 0;
            int sum = 0;
            for(int j=1;j*j<=num;j++){
               if(num % j == 0){
                 sum += j;
                 count++;
               }

               if(num / j != j && num % j == 0){
                 sum += (num / j);
                 count++;
               }
               if(count > 4) break;
            }

            if(count == 4) ans += sum;
        }

        return ans;
    }
};
