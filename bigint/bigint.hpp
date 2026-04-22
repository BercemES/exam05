#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <iostream>
# include <sstream>
# include <algorithm>
# include <cstdlib>

class bigint
{
	private:
		std::string str;
	public:
		bigint();
		bigint(int num);
		bigint(const bigint &src);
		bigint& operator=(const bigint& other);

		std::string getStr() const;

		bigint& operator+=(const bigint& other);
		bigint operator+(const bigint& other) const;

		bigint operator++();
		bigint operator++(int);

		bigint operator<<(const unsigned int n) const;
		bigint operator>>(const unsigned int n) const;
		bigint& operator<<=(const unsigned int n);
		bigint& operator>>=(const unsigned int n);

		bigint operator<<(const bigint &other) const;
		bigint operator>>(const bigint &other) const;
		bigint& operator<<=(const bigint &other);
		bigint& operator>>=(const bigint &other);

		bool operator<(const bigint &other) const;
		bool operator>(const bigint &other) const;
		bool operator<=(const bigint &other);
		bool operator>=(const bigint &other);

		bool operator==(const bigint &other) const;
		bool operator!=(const bigint &other) const;
};

std::ostream& operator<<(std::ostream& output, const bigint& obj);


#endif