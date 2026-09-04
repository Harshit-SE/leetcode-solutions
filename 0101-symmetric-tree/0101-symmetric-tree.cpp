class Solution {
public:
    bool isSymmetricHelper(TreeNode* node1, TreeNode* node2) {
        if (node1 == NULL && node2 == NULL) {
            return true;
        }
        if (node1 == NULL || node2 == NULL) {
            return false;
        }
        if (node1->val != node2->val) {
            return false;
        }
        return isSymmetricHelper(node1->left, node2->right) &&
               isSymmetricHelper(node1->right, node2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;

        return isSymmetricHelper(root->left, root->right);
    }
};