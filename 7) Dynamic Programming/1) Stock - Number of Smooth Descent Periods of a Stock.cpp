/*
T.C = O(n)
S.C = O(1)
*/
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long n = prices.size();
        long long count = 0;

        long long ones = 0;
        for(int i=0;i<n - 1;i++){ //  O(n)
            if(prices[i] - prices[i+1] == 1){
                ones++;
            }
            else{
                long long x = ones + 1;
                count += (x) * (x + 1) / 2;
                ones = 0;
            }
        }
        
        // Handle the last descent segment (if it exists)
        long long x = ones + 1;
        count += (x) * (x + 1) / 2;

        return count;
    }
};


// Leetcode Solution 

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long res = 1;  // total number of smooth descending periods,
                            // initial value is dp[0]
        int prev = 1;  // total number of smooth descending periods ending with
                       // the previous element, initial value is dp[0]
        // traverse the array starting from 1, and update prev and the total res
        // according to the recurrence relation
        for (int i = 1; i < n; ++i) {
            if (prices[i] == prices[i - 1] - 1) {
                ++prev;
            } else {
                prev = 1;
            }
            res += prev;
        }
        return res;
    }
};
