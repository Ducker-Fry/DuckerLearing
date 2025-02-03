#pragma once
#include<unordered_set>
#include<string>
#include<iostream>

class Subsequence
{
private:
	std::unordered_set<std::string> set;
	std::string str;
	int len;
	std::vector<std::string> subseq;
	void recursion(std::string&,int);
	void recursion2(std::string&, int);
public:
	Subsequence(std::string);
	void printItself();
	bool test();
};