/*
T.C = O(k);
S.C = O(1);
*/
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long n = happiness.size();
        long long count = 0;

        sort(happiness.begin(),happiness.end(),greater<int>()); 

        for(int i=0;i<k;i++){
            long long val = happiness[i] - i;
            if(val <= 0) break;
            count += val;
        }

        return count;
    }
};
