/* TC -> O(n^2);
   SC -> O(1); */
class Solution {
public:
    int countTriples(int n) {

        int count = 0;

        for(int i=1;i<=n;i++){ // O(n)
            int a = i;
            for(int j=1;j<=n;j++){ // O(n)
                int b = j;
                double c1 = sqrt((a*a) + (b*b));
                int c2 = sqrt((a*a) + (b*b));

                if(c1 == c2 && c1 <= n) count++;
            }
        }

        return count;
        
    }
};
