#include<iostream>
#include"header_list.h"
#include"header_tree.h"
#include"header_data_structure.h"
#include"header_solution.h"

using namespace std;
random_device rd;
mt19937 gen(rd());
std::unordered_set<Inode*> set;

int main()
{
	int arr[] = { 1,1,1,3,3,2,5 };
	//result is 1,3,1,5,2,3,1
	int n = sizeof(arr) / sizeof(arr[0]);

	MaxFrequentStack maxFreqStack;
	for (int i = 0; i < n; i++)
	{
		maxFreqStack.push(arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		cout << maxFreqStack.getMax() << " ";
	}

	return 0;
}