#pragma once
#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_set>
#include<set>

class ArraySet
{
public:
	ArraySet(int* arr,int size);
	~ArraySet();
	void printItself1();
	void printItself2();

private:
	std::vector<int> arr;
	std::vector<std::vector<int>> ans;
	std::vector<int> path;
	std::vector<std::vector<int>> combination;
	std::set<std::vector<int>> set;
	void recursion1(int,std::vector<int>&);
	void recursion2(int index, std::vector<int> path);
};

