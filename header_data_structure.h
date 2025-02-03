#pragma once
#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<random>
#include<queue>
#include<stack>

class setAll
{
private:
	int time;
	int setValue;
	int setTime;
	std::unordered_map<int, std::pair<int, int>> setMap;
public:
	setAll();
	void insert(int,int);
	void set_all(int);
	int find(int);
};

class LRU
{
private:
	struct node
	{
		int key;
		int value;
		node* last;
		node* next;
		node(int x, int y) : key(x), value(y), last(nullptr), next(nullptr) {};
	};

	node* head;
	node* tail;
	int size;
	int num;
	void moveToHead(node*);
public:
	LRU(int x);
	~LRU();
	int find(int);
	void insert(int x, int y);
	void printItself();
};

class Hashset //增删和随机返回一个值都是O(1).
{
private:
	std::unordered_map<int, int> map;
	int tail;
	std::vector<int> vec;
public:
	Hashset();
	void insert(int);
	void erase(int);
	int getRandom(std::mt19937& gen);
	void printItself();
};

class Hashset2//允许有重复值, 但是随机返回一个值的时间复杂度为O(n).
{
	private:
		std::unordered_map<int, std::unordered_set<int>> map;
		std::vector<int> vec;
		int size;
	public:
		Hashset2();
		void insert(int);
		void erase(int);
		int getRandom(std::mt19937& gen);
		void printItself();
};

class MidNumber
{
private:
	std::priority_queue<int, std::vector<int>, std::greater<int>> right;
	std::priority_queue<int, std::vector<int>, std::less<int>> left;
	void balance();
public:
	MidNumber();
	void insert(int);
	double getMidNumber();
	void printItself();
};

class MaxFrequentStack
{
private:
	std::unordered_map<int, int> frequency;
	std::unordered_map<int, std::list<int>> stack;
	int maxfreq;

public:
	MaxFrequentStack():maxfreq(0){}
	void push(int x);
	int getMax();
};

class FreqString
{
private:
	class Bucket
	{
	public:
		int freq;
		std::stack<std::string> bucket;
		Bucket* last;
		Bucket* next;
		Bucket(int freq, std::string str) : freq(freq)
		{
			bucket.push(str);
		}
	};

	Bucket* Llimit;
	Bucket* Rlimit;

	std::unordered_map<std::string, Bucket*> map;
	void insert(Bucket* bucket1,Bucket* bucket2);
	void remove(Bucket* bucket);
public:
	FreqString() {};
	void inc(std::string str);
	void dec(std::string str);
	std::string getMaxfreq();
	std::string getMinfreq();
};