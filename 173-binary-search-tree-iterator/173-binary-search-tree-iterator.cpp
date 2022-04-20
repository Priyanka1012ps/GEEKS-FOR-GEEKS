/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        func(st,root);
    }
    void func(stack<TreeNode*>&st,TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    int next() {
        TreeNode* tp=st.top();
        st.pop();
        func(st,tp->right);
        return tp->val;
    }
    
    bool hasNext() {
        return (st.size()!=0);
    }
};
