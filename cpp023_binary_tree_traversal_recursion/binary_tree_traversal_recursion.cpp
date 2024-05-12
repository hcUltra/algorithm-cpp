/*
 * @description 
 * @date   2024/5/12 19:25
 * @author zhc
 */
#include <iostream>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v)
    {
    }
};

void pre_order(TreeNode* head)
{
    if(head == nullptr)
    {
        return;
    }
    cout << head->val << " ";
    pre_order(head->left);
    pre_order(head->right);
}

void middle_order(TreeNode* head)
{
    if(head == nullptr)
    {
        return;
    }
    middle_order(head->left);
    cout << head->val << " ";
    middle_order(head->right);
}

void post_order(TreeNode* head)
{
    if(head == nullptr)
    {
        return;
    }
    post_order(head->left);
    post_order(head->right);
    cout << head->val << " ";
}

int main()
{
    TreeNode head(1);
    head.left = new TreeNode(2);
    head.right = new TreeNode(3);
    head.left->left = new TreeNode(4);
    head.left->right = new TreeNode(5);
    head.right->left = new TreeNode(6);
    head.right->right = new TreeNode(7);

    cout << "先序遍历递归版" << endl;
    pre_order(&head);
    cout << endl;

    cout << "中序遍历递归版" << endl;
    middle_order(&head);

    cout << endl;
    cout << "后序遍历递归版" << endl;
    post_order(&head);

    return 0;
}
