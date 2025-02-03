#pragma once
#include<iostream>
#include<random>
#include<stack>
#include<unordered_set>

template<typename T>
struct ListNode
{
	T value;
	ListNode* next;
	ListNode(T input) : value(input),next(NULL) {};
};

struct randomListNode
{
	int label;
	randomListNode* next;
	randomListNode* random;
	randomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

using Inode = ListNode<int>;

Inode* create_list(int*, int);
int count_list(Inode*);
void link_list(Inode*, Inode*);
Inode* reverse_list(Inode*);
Inode* reverse_list_by_group(Inode* ,int);
randomListNode* create_random_list(int*, int);
void link_random_node(randomListNode*, int,std::mt19937&);
void print_random_list(randomListNode*);
randomListNode* copy_random_list(randomListNode*);
bool IsPalindromicList1(Inode*);
bool IsPalindromicList2(Inode*);
Inode* returnMidNode(Inode*);
Inode* createRingList(Inode*, int, std::mt19937&);
Inode* firstEntryNode1(Inode*, std::unordered_set<Inode*>&);


class Compare_list
{
public:
	bool operator()(const Inode* a, const Inode* b) const
	{
		return a->value > b->value;
	}
};