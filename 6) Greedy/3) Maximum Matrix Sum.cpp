/*
T.C = O(n * m);
S.C = O(1);
*/
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long n = matrix.size();
        long long m = matrix[0].size();

        long long mini = LLONG_MAX;
        long long sum = 0;
        long long neg = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mini = min(mini,abs((long long)matrix[i][j]));
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0) neg++;
            }
        }

        return (neg % 2 == 0) ? sum : sum - 2 * mini;
    }
};
