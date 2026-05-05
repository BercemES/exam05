
#include "set.hpp"

set::set(searchable_bag& s_bag) : bag(s_bag) {}
set::~set() {}

searchable_bag& set::get_bag()const
{
	return(bag);
}

bool set::has(int value) const
{
	return (bag.has(value));
}

void set::insert (int value)
{
	if (!bag.has(value))
		bag.insert(value);
}

void set::insert (const int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!bag.has(arr[i]))
			bag.insert(arr[i]);
	}
}

void set::print() const
{
	bag.print();
}

void set::clear()
{
	bag.clear();
}