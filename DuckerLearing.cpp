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
	int arr[] = {1,2,3,4};
	int n = sizeof(arr) / sizeof(int);
	
	FullArrangement fullarrangement(arr, n);
	fullarrangement.printItself1();
	cout << endl;

	return 0;
	
}