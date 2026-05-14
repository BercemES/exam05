#include "set.hpp"


set::set(searchable_bag& bag): sBag(bag) {}
set::~set() {}

bool set::has(int value) const
{
	return(sBag.has(value));
}
void set::insert (int value)
{
	if (!sBag.has(value))
		sBag.insert(value);
}
void set::insert (int *arr, int size)
{
	for (int i = 0; i < size; i++)
		this->insert(arr[i]);
}
void set::print() const
{
	sBag.print();
}
void set::clear()
{
	sBag.clear();
}
searchable_bag& set::get_bag()const
{
	return (this->sBag);
}