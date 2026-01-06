/* Better Approach :: DFS 
T.C = O(n^2);
S.C = O(n);
*/
class Solution {
public:

    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }

    int nthRoot(TreeNode* root, int curr, int level){

        if(root == NULL) return 0;
        if(curr == level) return root->val;

        return nthRoot(root->left,curr + 1,level) + nthRoot(root->right,curr + 1,level);
    }

    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;
        int n = levels(root);

        int maxi = INT_MIN;
        int smallest_level = INT_MAX;
       
        for(int i=1;i<=n;i++){
            int sum = nthRoot(root,1,i);
            if(sum > maxi){
                maxi = sum;
                smallest_level = i;
            }
        }

        return smallest_level;
    }
};

//************************************************************************************************BFS**************************************************************************************************************//

/* Optimal Approach :: BFS 
T.C = O(n);
S.C = O(n);
*/
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int ansLevel = 1;
        int maxSum = INT_MIN;

        while(!q.empty()) {
            int sz = q.size();
            int sum = 0;

            while(sz--) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(sum > maxSum) {
                maxSum = sum;
                ansLevel = level;
            }

            level++;
        }

        return ansLevel;
    }
};
