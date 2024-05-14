/*
 * @description 二叉树的非递归（迭代）遍历 前序、中序、后续
 * @date   2024/5/14 10:40
 * @author zhc
 */
#include <iostream>
#include <stack>

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

/**
 * 前序遍历
 * @param root 根节点
 */
void pre_order(TreeNode* root)
{
    if(root)
    {
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty())
        {
            root = stack.top();
            stack.pop();
            cout << root->val << " ";
            if(root->right)
            {
                stack.push(root->right);
            }
            if(root->left)
            {
                stack.push(root->left);
            }
        }
    }
    cout << endl;
}

/**
 * 中序遍历
 * @param root 根节点
 */
void in_order(TreeNode* root)
{
    if(root)
    {
        stack<TreeNode*> stack;
        while(!stack.empty() || root)
        {
            if(root)
            {
                stack.push(root);
                root = root->left;
            } else
            {
                root = stack.top();
                stack.pop();
                cout << root->val << " ";
                root = root->right;
            }
        }
    }
    cout << endl;
}

/**
 * 中 右 左（另一种先序）
 * 左 右 中 刚好相反
 * 后序遍历(两个栈)
 * @param root 根节点
 */
void post_order_double_stack(TreeNode* root)
{
    if(root)
    {
        stack<TreeNode*> st;
        stack<TreeNode*> collect;
        st.push(root);
        while(!st.empty())
        {
            root = st.top();
            st.pop();
            collect.push(root);
            if(root->left)
            {
                st.push(root->left);
            }
            if(root->right)
            {
                st.push(root->right);
            }
        }

        while(!collect.empty())
        {
            cout << collect.top()->val;
            collect.pop();
            cout << " ";
        }

        cout << endl;
    }
}

/**
 * 后序遍历 一个栈实现
 * @param root 根节点
 */
void post_order_one_stack(TreeNode* root)
{
    if(root)
    {
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty())
        {
            TreeNode* cur = stack.top();
            if(cur->left && root != cur->left && root != cur->right)
            {
                stack.push(cur->left);
            } else if(cur->right && root != cur->right)
            {
                stack.push(cur->right);
            } else
            {
                // 左子树、右子树都处理完毕，该处理根节点了
                cout << cur->val << " ";
                root = stack.top();
                stack.pop();
            }
        }
    }
    cout << endl;
}


int main()
{
    TreeNode root(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.left->left = new TreeNode(4);
    root.left->right = new TreeNode(5);
    root.right->left = new TreeNode(6);
    root.right->right = new TreeNode(7);
    pre_order(&root);

    in_order(&root);

    post_order_double_stack(&root);

    post_order_one_stack(&root);
    return 0;
}
