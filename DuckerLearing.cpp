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
	FreqString fs;
	vector<string> v;
	v = {"hello", "world", "this", "is", "a", "test", "hello",
		"world","this","is","test","hello",
		"world","this","is","test"};

	for (auto s : v)
	{
		fs.inc(s);
	}
	

	cout << fs.getMaxfreq() << endl;
	cout << fs.getMinfreq() << endl;

	return 0;
}