/*
T.C = O(n);
S.C = O(1);
*/
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        
        int left_b = 0;
        int right_a = 0;

        int count = n;

        for(int i=0;i<n;i++){
            if(s[i] == 'a') right_a++;
        }

        for(int i=0;i<n;i++){
            if(s[i] == 'b'){
                count = min(count,left_b + right_a);
                left_b++;
            }
            else{
                right_a--;
                count = min(count,left_b + right_a);
            }
        }

        return count;
    }
};

/*
T.C = O(n);
S.C = O(n);
*/
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int count = 0;

        stack<char> st;

        for(int i=0;i<n;i++){
            if(!st.empty() && s[i] == 'a' && st.top() == 'b'){
                st.pop();
                count++;
            }
            else st.push(s[i]);
        }

        return count;
    }
};


/*
T.C = O(n);
S.C = O(2n); -> ek variable countb = 0 leke and only a ka vector rakhke bhi kar sakte hai O(n) mei 
*/
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        
        vector<int> left_b(n,0);
        vector<int> right_a(n,0);

        int countb = 0;
        for(int i=0;i<n;i++){
            left_b[i] = countb;
            if(s[i] == 'b') countb++;
        }

        int counta = 0;
        for(int i=n-1;i>=0;i--){
            right_a[i] = counta;
            if(s[i] == 'a') counta++;
        }

        int count = n;
        for(int i=0;i<n;i++){
            count = min(count,left_b[i] + right_a[i]);
        }

        return count;
    }
};
