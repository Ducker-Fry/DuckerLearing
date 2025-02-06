#include<iostream>
#include"header_list.h"
#include"header_tree.h"
#include"header_data_structure.h"
#include"header_solution.h"
#include"classical_recursion.h"

using namespace std;
random_device rd;
mt19937 gen(rd());
std::unordered_set<Inode*> set;

int main()
{
	int arr[] = { 2,2,4,4,6,6};
	int n = sizeof(arr) / sizeof(int);
	ArraySet arrayset(arr, n);
	arrayset.printItself1();
	cout << endl;

	arrayset.printItself2();
	return 0;
	
}