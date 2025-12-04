#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* T.C -> O(n)
       S.C -> O(1) */
       
    int countCollisions(string directions) {
        long long n = directions.size();
        long long collisions = 0; // final collisions count -> our ans

        long long i = 0; // start
        long long j = n - 1; // end
        
        if(directions[i] == 'L') while(i < n && directions[i] == 'L') i++; // first L -> no collisions
        if(directions[j] == 'R') while(j >= 0 && directions[j] == 'R') j--; // last R -> no collisions

        while(i <= j){
            if(directions[i] == 'L' || directions[i] == 'R') collisions++; // if(directions[i] == 'L' or 'R') add +1
            i++;
        }

        return collisions;
    }

};

int main(){
    string s;
    cin >> s;
    Solution sol;
    cout << sol.countCollisions(s); 
    return 0;
}