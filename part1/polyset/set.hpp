#ifndef SET_HPP
# define SET_HPP

#include "searchable_bag.hpp"


class set
{
	private:
		searchable_bag& bag;
	public:
		set(searchable_bag& s_bag);
		set(const set& other) = delete;
		set& operator=(const set& other) = delete;
		~set();

		searchable_bag& get_bag()const;
		bool has(int value) const;
		void insert(int value);
		void insert(const int *arr, int size);
		void print() const;
		void clear();
};

#endif
