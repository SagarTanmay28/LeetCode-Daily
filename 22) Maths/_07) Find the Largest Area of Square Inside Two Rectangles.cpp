/*
T.C = O(n^2);
S.C = O(1);
*/
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& left, vector<vector<int>>& right) {
        long long n = left.size();
        long long max_area = 0;

        for(int i=0;i<n;i++){
            long long x1 = left[i][0];
            long long x2 = right[i][0];
            long long y1 = left[i][1];
            long long y2 = right[i][1];



            for(int j=i+1 ; j<n ; j++){
                long long x1_cor = left[j][0];
                long long x2_cor = right[j][0];
                long long y1_cor = left[j][1];
                long long y2_cor = right[j][1];

                long long x1_common = max(x1, x1_cor);
                long long x2_common = min(x2, x2_cor);
                long long y1_common = max(y1, y1_cor);
                long long y2_common = min(y2, y2_cor);


                long long side = 0;
                long long area = 0;
                long long length = 0;
                long long width = 0;

                if(x2_common > x1_common && y2_common > y1_common){
                    length = x2_common - x1_common;
                    width = y2_common - y1_common;
                    side = min(length,width);
                    area = side * side;
                    max_area = max(max_area,area);
                }
            }  
        }

        return max_area;

    }
};
