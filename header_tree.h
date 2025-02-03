#pragma once
#include<iostream>
#include<vector>

struct Node
{
	int value;
	Node* left;
	Node* right;
	Node(int input) : value(input), left(NULL), right(NULL) {};
};

//����
Node* create_SBT(int*, int);
void midOrderTraverse(Node*);
bool Is_SBT(Node* root);
Node* trimBST(Node*, int, int);


//��
class SearchBinaryTree
{
private:
    Node* root;
    Node* insert(Node* node, int value);
    void midOrderTraverse(Node* root);
public:
    SearchBinaryTree();
    void insert(int value);
    void midOrderTraverse();
    Node* returnroot();
};


class BSTMaxTheft
{
private:
    int yes;
    int no;
    //���x�����ı���������֮��
    //yes������͵����ͷ�ڵ���������
    //no�����ǲ�͵����ͷ�ڵ���������

    void recursion1(Node* root);
    std::pair<int, int> recursion2(Node* root);
public:
    int maxStealedValue(Node* root);
    int maxStealedValue2(Node* root);

};