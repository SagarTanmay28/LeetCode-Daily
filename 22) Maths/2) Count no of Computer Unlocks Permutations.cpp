/*
T.C = O(n);
S.C = O(1);
*/
class Solution {
public:
    static const long long MOD = 1e9+7;

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        long long result = 1;

        for(int i = 1; i < n ; i++){ // O(n)
           if(complexity[i] <= complexity[0])  return 0;
           result = (result * i) % MOD;
        }

        return result;
    }
};
