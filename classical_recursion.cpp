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
		//����������ֵ����
		path.push_back(arr[index]);
		recursion1(index + 1, path);
		//������ԭ
		path.pop_back();
		recursion1(index + 1, path);
	}
}

void ArraySet::recursion2(int i, std::vector<int> path)
{
	//��i�����ߵ����龡ͷʱ��˵�� path �Ѿ���¼����һ����ϣ���ʱ�����������ӽ����С�
	//
	if (i == arr.size()) ans.push_back(path);
	//���û�е�ĩβ��Ҫ�������һ��Ŀ�ͷ����
	else
	{
		int j = i + 1;
		while (j < arr.size() && arr[i] == arr[j])
		{
			j++;
		}

		//��������x������0����
		recursion2(j, path);
		//��������Ҫ1��j - i��
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
	//index1 ��������ԭ����������֣���index2�Ǽ���𰸵�������
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