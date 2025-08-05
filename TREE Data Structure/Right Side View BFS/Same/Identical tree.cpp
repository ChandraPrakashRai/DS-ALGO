Har tree ka:

Inorder traversal (LNR)

Preorder traversal (NLR)
store karo in a vector (including NULL nodes also!)

Dono trees ke inorder aur preorder vectors ko compare karo
→ agar dono match ho, then trees are same.

📘 Code Breakdown (Short Notes):

void Inorder(TreeNode* root, vector<int>& v)
Left → Node → Right

If root is NULL, push 100000 (to handle structure/null nodes too)

void preorder(TreeNode* root, vector<int>& v)
Node → Left → Right

Again, NULL nodes are marked with 100000


bool isSameTree(TreeNode* p, TreeNode* q)
Create 4 vectors:
inp = inorder of p
inq = inorder of q
prp = preorder of p
prq = preorder of q

Compare both:

if (inp == inq && prp == prq)
    return true;
🧠 Why 100000?
Because if structure is different but values are same, normal traversal may still match.
E.g., this tree:


    1
   /
  2
and


    1
     \
      2
Both will give same inorder (2 1) if NULLs aren't tracked.

Using a placeholder like 100000 makes structure part of traversal too ✅

_______****** CODE*******________


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
class Solution {
public:
    void Inorder(TreeNode* root  , vector<int>& v)
    {
        if(root!=NULL) 
        {
        Inorder(root->left , v);
        v.push_back(root->val);
        Inorder(root->right , v);
        }
        else
        {
            v.push_back(100000);
        }
    }
    void preorder(TreeNode* root  , vector<int>& v)
    {
        if(root!=NULL) 
        {
        v.push_back(root->val);
        preorder(root->left , v);
        preorder(root->right , v);
        }
        else
        {
            v.push_back(100000);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> inp , inq ,prp , prq;

        Inorder(p , inp);
        Inorder(q , inq);
        preorder(p , prp);
        preorder(q , prq);

        if(inp==inq && prp==prq  )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};