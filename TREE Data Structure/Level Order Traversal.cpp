class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};
📌 GitHub Comment Line (for Save):

// ✅ Level Order Traversal using Queue (returns vector<vector<int>>)
📘 Input Example:
markdown
Copy
Edit
        1
       / \
      2   3
         / \
        4   5
🟢 Output:

[
  [1],
  [2, 3],
  [4, 5]
]