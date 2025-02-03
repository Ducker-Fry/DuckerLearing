#include"header_list.h"

Inode* create_list(int* arr, int len)
{
	Inode* head = new Inode(arr[0]);
	Inode* current = head;
	for (int i = 1; i < len; i++)
	{
		current->next = new Inode(arr[i]);
		current = current->next;
	}
	return head;
}


int count_list(Inode* head)
{
	int count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return count;
}

void link_list(Inode* head1, Inode* head2)
{
	Inode* current = head1;
	while (current->next)
	{
		current = current->next;
	}
	current->next = head2;
}

Inode* reverse_list(Inode* head)
{
	Inode* pre = NULL;
	Inode* next = NULL;
	Inode* current = head;
	while (current)
	{
		next = current->next;
		current->next = pre;
		pre = current;
		current = next;
	}
	return pre;
}

Inode* reverse_list_by_group(Inode* head, int k)
{
	Inode* pre = NULL;
	Inode* next = NULL;
	Inode* current = head;
	int count = 0;
	while (current && count < k)
	{
		next = current->next;
		current->next = pre;
		pre = current;
		current = next;
		count++;
	}
	if (next)
	{
		head->next = reverse_list_by_group(next, k);
	}
	return pre;
}


randomListNode* create_random_list(int* arr, int len)
{
	randomListNode* head = new randomListNode(arr[0]);
	randomListNode* current = head;
	for (int i = 1; i < len; i++)
	{
		current->next = new randomListNode(arr[i]);
		current->random = NULL;
		current = current->next;
	}
	return head;
}

void link_random_node(randomListNode* head, int len,std::mt19937& gen)
{
	randomListNode* current = head;
	while (current)
	{
		int index = std::uniform_int_distribution<int>(0, len - 1)(gen);
		randomListNode* temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		current->random = temp;
		current = current->next;
	}
}

void print_random_list(randomListNode* head)
{
	while (head)
	{
		std::cout << head->label << " ";
		std::cout << head->random->label << " ";
		head = head->next;
	}
	std::cout << std::endl;	
}

randomListNode* copy_random_list(randomListNode* head)
{
	randomListNode* result = head;
	randomListNode* current = head->next;
	randomListNode* temp = result;
	while (current)
	{
		temp->next = new randomListNode(current->label);
		temp->next->random = new randomListNode(current->random->label);
		temp = temp->next;
		current = current->next;
	}

	return result;
}

bool IsPalindromicList1(Inode* head)
{
	std::stack<Inode*> stack;
	Inode* current = head;
	while (current)
	{
		stack.push(current);
		current = current->next;
	}

	while (head)
	{
		if (head->value != stack.top()->value) return false;
		head = head->next;
		stack.pop();
	}

	return true;
}

Inode* returnMidNode(Inode* head)
{
	Inode* fast, * slow;
	fast = slow = head;

	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

bool IsPalindromicList2(Inode* head)
{
	Inode* temp = returnMidNode(head);
	temp = reverse_list(temp);

	while (head && temp)
	{
		if (head->value != temp->value) return false;
		head = head->next;
		temp = temp->next;
	}

	return true;
}

Inode* createRingList(Inode* head, int len, std::mt19937& gen)
{
	std::uniform_int_distribution<int>dis(0,len - 1);
	int randomIndex = dis(gen);

	Inode* temp, * tail;
	temp = head;
	tail = NULL;
	while (temp)
	{
		tail = temp;
		temp = temp->next;
	}
	std::cout << "randomIndex :"<< randomIndex << std::endl;
	std::cout << "tail : " << tail->value << std::endl;
	temp = head;
	for (int i = 0; i < randomIndex; i++)
	{
		temp = temp->next;
	}

	tail->next = temp;
	std::cout << temp->value << std::endl;

	return head;
}

Inode* firstEntryNode1(Inode* head,std::unordered_set<Inode*>& set)
{
	Inode* current = head;

	while (set.find(current) == set.end())
	{
		set.insert(current);
		current = current->next;
	}

	return current;
}