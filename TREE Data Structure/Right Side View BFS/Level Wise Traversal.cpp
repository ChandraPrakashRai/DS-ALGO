class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // If the tree is empty, return an empty list
        if (root == NULL)
            return {};

        queue<TreeNode*> que;   // Queue for level order traversal (BFS)
        vector<int> result;     // Stores the rightmost node of each level

        que.push(root);         // Start BFS with the root

        while (!que.empty()) {
            int n = que.size(); // Number of nodes at the current level
            TreeNode* node = NULL;

            // Traverse all nodes of the current level
            for (int i = 0; i < n; i++) {
                node = que.front();
                que.pop();

                // Add left and right children of current node to the queue
                if (node->left != NULL)
                    que.push(node->left);
                if (node->right != NULL)
                    que.push(node->right);
            }

            // The last node we visited at this level is the rightmost one
            result.push_back(node->val);
        }

        return result;
    }
};



//  Sample Input

//         1
//        / \
//       2   3
//        \   \
//         5   4
// Output: [1, 3, 4]

