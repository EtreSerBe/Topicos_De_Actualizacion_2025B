#pragma once

#include "SentinelLinkedList.h"

template <typename T>
class LQueue
{
public:
	void PushBack(T value)
	{
		data.PushBack(value);
	}


private:
	SentinelLinkedList<T> data;

};

