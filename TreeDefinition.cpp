#include"header_tree.h"

Node* create_SBT(int* arr, int len) 
{
    // 空数组处理
    if (len == 0) return nullptr;

    // 创建根节点
    Node* root = new Node(arr[0]);

    for (int i = 1; i < len; i++) 
    {
        Node* current = root;
        Node* prev = nullptr;
        int value = arr[i];

        // 找到插入位置
        while (current) 
        {
            prev = current;
            if (value < current->value) 
            {
                current = current->left;
            }
            else if (value > current->value) 
            {
                current = current->right;
            }
            else 
            {
                // 跳过重复值
                break;
            }
        }

        // 插入节点
        if (!current) 
        {
            if (value < prev->value) 
            {
                prev->left = new Node(value);
            }
            else 
            {
                prev->right = new Node(value);
            }
        }
    }

    return root;
}

void midOrderTraverse(Node* root)
{
	if (!root)return;
	midOrderTraverse(root->left);
	std::cout << root->value << " ";
	midOrderTraverse(root->right);
}


SearchBinaryTree::SearchBinaryTree() : root(nullptr) {}


Node* SearchBinaryTree::insert(Node* node, int value)
{
    if (node == nullptr) return new Node(value);

    if (value < node->value) node->left = insert(node->left, value);
    else if (value > node->value) node->right = insert(node->right, value);
    else return node;
    return node;
}


void SearchBinaryTree::midOrderTraverse(Node* root)
{
    if (root == nullptr) return;
    midOrderTraverse(root->left);
    std::cout << root->value << " ";
    midOrderTraverse(root->right);
}


void SearchBinaryTree::insert(int value)
{
    root = insert(root, value);
}


void SearchBinaryTree::midOrderTraverse()
{
    midOrderTraverse(root);
    std::cout << std::endl;
}


Node* SearchBinaryTree::returnroot()
{
    return root;
}

bool Is_SBT(Node* root)
{
    std::vector<Node*> stack;
    Node* cur = root;
    Node* pre = NULL;

    while (cur||!stack.empty())
    {
        if (cur)
        {
            stack.push_back(cur);
            cur = cur->left;
        }
        else
        {
            cur = stack.back();
            stack.pop_back();
            if (pre && pre->value >= cur->value) return false;
            pre = cur;
            cur = cur->right;
        }

    }

    return true;
}

Node* trimBST(Node* root, int low, int high)
{
    if (root == NULL) return NULL;

    if (root->value < low)
    {
        return trimBST(root->right, low, high);
    }
    else if (root->value > high)
    {
        return trimBST(root->left, low, high);
    }
    else
    {
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }

}

int BSTMaxTheft::maxStealedValue(Node* root)
{
    recursion1(root);
    return std::max(yes, no);
}

void BSTMaxTheft::recursion1(Node* root)
{
    int leftYes, rightYes;
    int leftNo, rightNo;

    if (root == NULL)
    {
        yes = no = 0;
        return;
    }

    recursion1(root->left);
    //此时更新了成员变量yes和no
    leftYes = yes;
    leftNo = no;

    recursion1(root->right);
    rightYes = yes;
    rightNo = no;

    yes = root->value + leftNo + rightNo;
    no = std::max(leftYes, leftNo) + std::max(rightYes, rightNo);
}

int BSTMaxTheft::maxStealedValue2(Node* root)
{
    std::pair<int, int> ans = recursion2(root);
    return std::max(ans.first, ans.second);
}

std::pair<int, int> BSTMaxTheft::recursion2(Node* root)
{
    if (root == NULL)
    {
        return { 0,0 };
    }

    std::pair<int, int> left = recursion2(root->left);
    std::pair<int, int> right = recursion2(root->right);

    int yes = root->value + left.second + right.second;
    int no = std::max(left.first, left.second) + std::max(right.first, right.second);

    return { yes,no };
}

