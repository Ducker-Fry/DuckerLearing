#include"header_solution.h"

Subsequence::Subsequence(std::string str) :str(str) { len = str.length(); };
void Subsequence::recursion(std::string& input, int index)
{
	if (index >= len) return;
	std::string temp = input;
	recursion(temp, index + 1);
	if (set.find(temp) == set.end())
	{
		set.insert(temp);
		subseq.push_back(temp);
	}

	input += str[index];
	recursion(input, index + 1);
	if (set.find(input) == set.end())
	{
		set.insert(input);
		subseq.push_back(input);
	}
}


void Subsequence::recursion2(std::string& input, int index)
{
	if (index >= len) return;

	input += str[index];
	recursion2(input, index + 1);
	if (set.find(input) == set.end())
	{
		set.insert(input);
		subseq.push_back(input);
	}

	input.pop_back();
	//ª÷∏¥œ÷≥°
	recursion2(input, index + 1);
	if (set.find(input) == set.end())
	{
		set.insert(input);
		subseq.push_back(input);
	}
}

void Subsequence::printItself()
{
	std::string emptystring;
	recursion(emptystring, 0);
	for (std::string it : subseq)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;
}

bool Subsequence::test()
{
	std::unordered_set<std::string> copyset;
	std::string empty;
	recursion(empty, 0);
	copyset = set;
	set.clear();
	empty.clear();

	recursion2(empty, 0);
	for (const auto it : set)
	{
		if (copyset.find(it) == copyset.end()) return false;
	}
	return true;
}