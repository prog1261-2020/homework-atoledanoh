#pragma once
#include <list>
#include <mutex>

class WorkQueue
{
public:
	WorkQueue();
	void push(int n);
	int pop();
	int size();

private:
	std::list<int>jobs;
	std::mutex mtx;
};