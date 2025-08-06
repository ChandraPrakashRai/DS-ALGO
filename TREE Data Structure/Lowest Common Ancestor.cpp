// +++++++++ LEETCODE 236 +++++++


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // agar root hi exist n kre to
        if(root==NULL) return NULL;

        // agar p and q dono mil gye 
        if(root==p || root==q )
        {
            return root;
        }


        // left subtree me check kr lenge ki kya p , q exist kr rha hi aya nhi 
        TreeNode* leftN = lowestCommonAncestor(root->left , p , q);
        TreeNode* rightN = lowestCommonAncestor(root->right , p , q);

        // agar leftN aur rightN dono mil jaye
        if(leftN!=NULL && rightN!=NULL)
        {
            return root;
        }
        if(leftN!=NULL)
        return leftN;

       
        return rightN;
        
    }
};