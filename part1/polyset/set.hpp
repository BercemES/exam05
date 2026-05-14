#pragma once

#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag& sBag;
	public:
		set() = delete;
		set(const set &) = delete;
		set &operator=(const set &other) = delete;
		set(searchable_bag& bag);
		~set();

		bool has(int) const;
		void insert (int);
		void insert (int *, int);
		void print() const;
		void clear();
		searchable_bag& get_bag()const;
};
