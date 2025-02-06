#include"classical_recursion.h"

ArraySet::ArraySet(int* input,int size)
{
	arr.assign(input, input + size);
	std::sort(arr.begin(), arr.end());
}

ArraySet::~ArraySet()
{
}

void ArraySet::recursion1(int index,std::vector<int>& path)
{
	if (index == arr.size())
	{
		set.insert(path);
	}
	else
	{
		//加上这个数字的情况
		path.push_back(arr[index]);
		recursion1(index + 1, path);
		//场景复原
		path.pop_back();
		recursion1(index + 1, path);
	}
}

void ArraySet::recursion2(int i, std::vector<int> path)
{
	//当i索引走到数组尽头时，说明 path 已经记录完了一种组合，这时候将这种组合添加进答案中。
	//
	if (i == arr.size()) ans.push_back(path);
	//如果没有到末尾，要计算出下一组的开头索引
	else
	{
		int j = i + 1;
		while (j < arr.size() && arr[i] == arr[j])
		{
			j++;
		}

		//下组数字x，加入0个。
		recursion2(j, path);
		//接下来是要1到j - i个
		for (; i < j; i++)
		{
			path.push_back(arr[i]);
			recursion2(j, path);
		}
	}
}

void ArraySet::printItself1()
{
	recursion1(0, path);
	for (const auto it : set)
	{
		for (int i : it)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
}

void ArraySet::printItself2()
{
	recursion2(0, path);

	for (const auto it : ans)
	{
		for (int i : it)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
}



//class FullArrangement

FullArrangement::FullArrangement(int* input, int size)
{
	this->size = size;
	temp.resize(size);
	std::fill(temp.begin(), temp.end(), 0);
	arr.assign(input, input + size);
	mark = new int[size];
	std::fill(mark, mark + size, 1);
}

FullArrangement::~FullArrangement()
{

}

void FullArrangement::recursion1(int index, int* mark)
{
	//index1 用来访问原数组里的数字，而index2是加入答案的索引。
	if (index == size)
	{
		ans.push_back(temp);
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (mark[i])
			{
				temp[i] = arr[index];
				mark[i] = 0;
				recursion1(index + 1, mark);
				mark[i] = 1;
			}
		}
	}
}

void FullArrangement::printItself1()
{
	recursion1(0, mark);
	for (const auto it : ans)
	{
		for (const int i : it)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
}