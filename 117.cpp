/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        vector<TreeLinkNode*> v;
        v.push_back(root);
        int head = 0;
        int tail = 1;
        while(head != tail)
        {
            TreeLinkNode* last = v[head];
            for(int i = head; i < tail;i++)
            {
                TreeLinkNode* cur = v[i];
                if(i != head)
                {
                    last->next = cur;
                    last = cur;
                }
                if(cur->left)
                {
                    v.push_back(cur->left);
                }
                if(cur->right)
                {
                    v.push_back(cur->right);
                }
            }
            head = tail;
            tail = v.size();
        }
    }
};