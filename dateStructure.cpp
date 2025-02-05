#include"header_data_structure.h"


setAll::setAll() : time(0), setTime(0), setValue(-1) {};

void setAll::insert(int key,int value)
{
	time = time < setTime ? setTime : time;
	setMap[key] = { value,++time };
}

void setAll::set_all(int value)
{
	setValue = value;
	setTime = time + 1;
}

int setAll::find(int key)
{
	int result;
	result = setMap[key].second < setTime ? setValue : setMap[key].first;
	return result;
}


//class LRU
LRU::LRU(int x) : head(NULL), tail(NULL), size(x),num(0) {};
LRU::~LRU()
{
	node* current = head;
	while (current)
	{
		node* next = current->next;
		delete current;
		current = next;
	}
}

int LRU::find(int x)
{
	node* current = head;
	while (current)
	{
		if (current->key == x)
		{
			moveToHead(current);
			return current->value;
		}
		else current = current->next;
	}

	return 404;
}

void LRU::moveToHead(node* p)
{
	if (p == tail)
	{
		node* temp = tail->last;
		temp->next = NULL;
		tail = temp;
	}
	else
	{
		node* lastnode = p->last;
		node* nextnode = p->next;
		lastnode->next = nextnode;
		nextnode->last = lastnode;
	}

	p->last = NULL;
	p->next = head;
	head->last = p;
	head = p;
}


void LRU::insert(int key, int value)
{
	if (num + 1 > size)
	{
		tail = tail->last;
		delete tail->next;
		tail->next = NULL;
		num--;
	}

	if (head)
	{
		head->last = new node(key, value);
		node* temp = head;
		head = head->last;
		head->next = temp;
	}
	else head = tail = new node(key, value);

	num++;
}

void LRU::printItself()
{
	node* current = head;
	while (current)
	{
		std::cout << current->value << " ";
		current = current->next;
	}

	std::cout << std::endl;
}


Hashset::Hashset() : tail(0) {};
void Hashset::insert(int value)
{
	if (map.find(value) != map.end())
	{
		std::cout << "already added" << std::endl;
	}
	else
	{
		map[value] = tail++;
		vec.push_back(value);
	}
}

void Hashset::erase(int value)
{
	if (map.find(value) == map.end())
	{
		std::cout << "not found" << std::endl;
		return;
	}
	else
	{
		int index = map[value];
		int last = vec.back();
		vec[index] = last;
		map[last] = index;
		vec.pop_back();
		map.erase(value);
	}
}

int Hashset::getRandom(std::mt19937& gen)
{
	int len = vec.size();
	std::uniform_int_distribution<int> dis(0, len - 1);
	int index = dis(gen);
	return vec[index];
}

void Hashset::printItself()
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}

	std::cout << std::endl;
}


//class HashTable
Hashset2::Hashset2() : size(0) {};
void Hashset2::insert(int value)
{
	map[value].insert(size++);
	vec.push_back(value);
}

void Hashset2::erase(int value)
{
	if (map.find(value) == map.end())
	{
		std::cout << "not found" << std::endl;
		return;
	}
	else
	{
		int last = vec.back();
		if (value == last)
		{
			map[last].erase(size - 1);
			size--;
			vec.pop_back();
		}
		else
		{
			
			int index = *map.find(value)->second.begin();
			vec[index] = last;
			vec.pop_back();
			size--;
			map[last].insert(index);
			map[value].erase(index);
		}
	}
}

int Hashset2::getRandom(std::mt19937& gen)
{
	int len = vec.size();
	std::uniform_int_distribution<int> dis(0, len - 1);
	int index = dis(gen);
	return vec[index];
}

void Hashset2::printItself()
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}

	std::cout << std::endl;
}

//class MidNumber
MidNumber::MidNumber() {};
void MidNumber::insert(int value)
{
	if (left.empty()||value < left.top())
	{
		left.push(value);
	}
	else
	{
		right.push(value);
	}

	balance();
}

void MidNumber::balance()
{
	if (std::abs((int)left.size() - (int)right.size()) > 1)
	{
		if (left.size() > right.size())
		{
			right.push(left.top());
			left.pop();
		}
		else
		{
			left.push(right.top());
			right.pop();
		}
	}
}
		
	
double MidNumber::getMidNumber()
{
	if (left.size() == right.size())
	{
		return (left.top() + right.top()) / 2.0;
	}
	else
	{
		if (left.size() > right.size())
		{
			return left.top();
		}
		else
		{
			return right.top();
		}
	}

}

void MidNumber::printItself()
{
	std::cout << left.size() << " " << right.size() << std::endl;
	while (!left.empty())
	{
		std::cout << left.top() << " ";
		left.pop();
	}
	std::cout << " " << std::endl;
	while (!right.empty())
	{
		std::cout << right.top() << " ";
		right.pop();
	}
	std::cout << std::endl;
}



//MaxFrequentStack
void MaxFrequentStack::push(int x)
{
	int freq;
	if (frequency.find(x) == frequency.end())
	{
		freq = 1;
	}
	else freq = frequency[x] + 1;

	frequency[x] = freq;
	maxfreq = maxfreq > freq ? maxfreq : freq;

	if (stack.find(freq) == stack.end())
	{
		std::list<int> list;
		list.push_back(x);
		stack[freq] = list;
	}
	else
	{
		stack[freq].push_back(x);
	}
}


int MaxFrequentStack::getMax()
{
	int max = stack[maxfreq].back();
	stack[maxfreq].pop_back();

	if (stack[maxfreq].empty())
	{
		stack.erase(maxfreq);
		maxfreq--;
	}

	return max;
}



//class FreqString 

void FreqString::insert(Bucket* bucket1, Bucket* bucket2)
{
	// 在 bucket1 后面插入一个桶 bucket2
	Bucket* temp = bucket1->next;
	bucket1->next = bucket2;
	bucket2->next = temp;
	if (temp != nullptr)
	{
		temp->last = bucket2;
	}
	bucket2->last = bucket1;
}

void FreqString::remove(Bucket* bucket)
{
	if (bucket == Llimit || bucket == Rlimit)
	{
		return; // 不删除边界哨兵节点
	}
	Bucket* left = bucket->last;
	Bucket* right = bucket->next;
	left->next = right;
	right->last = left;
	delete bucket;
}

FreqString::FreqString()
{
	Llimit = new Bucket(0, "");
	Rlimit = new Bucket(std::numeric_limits<int>::max(), "");
	Llimit->next = Rlimit;
	Rlimit->last = Llimit;
}

FreqString::~FreqString()
{
	Bucket* current = Llimit->next;
	while (current != Rlimit)
	{
		Bucket* next = current->next;
		delete current;
		current = next;
	}
	delete Llimit;
	delete Rlimit;
}

void FreqString::inc(const std::string& str)
{
	if (map.find(str) == map.end())
	{
		Bucket* temp = Llimit->next;
		if (temp->freq != 1)
		{
			insert(Llimit, new Bucket(1, str));
			map[str] = Llimit->next;
		}
		else
		{
			temp->bucket.insert(str);
			map[str] = temp;
		}
	}
	else
	{
		Bucket* temp = map[str];
		Bucket* nextBucket = temp->next;
		if (nextBucket == Rlimit || nextBucket->freq != temp->freq + 1)
		{
			insert(temp, new Bucket(temp->freq + 1, str));
			map[str] = temp->next;
		}
		else
		{
			nextBucket->bucket.insert(str);
			map[str] = nextBucket;
		}
		temp->bucket.erase(str);
		if (temp->bucket.empty())
		{
			remove(temp);
		}
	}
}

void FreqString::dec(const std::string& str)
{
	if (map.find(str) == map.end())
	{
		return; // 如果字符串不存在，直接返回
	}

	Bucket* temp = map[str];
	if (temp->freq == 1)
	{
		map.erase(str);
		temp->bucket.erase(str);
		if (temp->bucket.empty())
		{
			remove(temp);
		}
	}
	else
	{
		Bucket* prevBucket = temp->last;
		if (prevBucket == Llimit || prevBucket->freq != temp->freq - 1)
		{
			insert(prevBucket, new Bucket(temp->freq - 1, str));
			map[str] = prevBucket->next;
		}
		else
		{
			prevBucket->bucket.insert(str);
			map[str] = prevBucket;
		}
		temp->bucket.erase(str);
		if (temp->bucket.empty())
		{
			remove(temp);
		}
	}
}

std::string FreqString::getMaxfreq()
{
	Bucket* temp = Rlimit->last;
	if (temp == Llimit)
	{
		std::cout << "error, the container is empty \n";
		return "";
	}
	std::string ans = *temp->bucket.begin();
	return ans;
}

std::string FreqString::getMinfreq()
{
	Bucket* temp = Llimit->next;
	if (temp == Rlimit)
	{
		std::cout << "error, the container is empty \n";
		return "";
	}
	std::string ans = *temp->bucket.begin();
	return ans;
}
