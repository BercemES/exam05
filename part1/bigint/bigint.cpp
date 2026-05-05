#include "bigint.hpp"

bigint::bigint(): str("0") {}

bigint::bigint(int num)
{
	std::stringstream intstr;
	intstr << num;
	this->str = intstr.str();
}
bigint::bigint(const bigint &other): str(other.str) {}
bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
		this->str = other.str;
	return (*this);
}

std::string bigint::getStr() const
{
	return (this->str);
}

bigint& bigint::operator+=(const bigint& other)
{
	std::string	result;
	std::string	strX = this->str;
	std::string	strY = other.str;
	int			lenX = strX.size() - 1;
	int			lenY = strY.size() - 1;
	int			carry = 0;
	int			sum = 0;

	while (lenX >= 0 || lenY >= 0 || carry > 0)
	{
		sum = carry;
		if (lenX >= 0){
			sum += strX[lenX] - '0';
			lenX--;
		}
		if(lenY >= 0){
			sum += strY[lenY] - '0';
			lenY--;
		}
		carry = sum / 10;
		result.push_back((sum % 10) + '0');
	}
	std::reverse(result.begin(), result.end());
	this->str = result;
	return (*this);
}

bigint bigint::operator+(const bigint& other) const
{
	bigint	res;

	res = *this;
	res += other;
	return (res);
}

bigint bigint::operator++()
{
	*this += bigint(1);
	return (*this); 
}

bigint bigint::operator++(int)
{
	bigint temp;

	temp = *this;
	*this += bigint(1);
	return (temp);
}

bigint bigint::operator<<(const unsigned int n) const
{
	bigint	res(*this);

	res <<= n;
	return (res);
}

bigint bigint::operator>>(const unsigned int n) const
{
	bigint	res(*this);
	res >>= n;
	return (res);
}

bigint& bigint::operator<<=(const unsigned int n)
{
	if (this->str == "0")
		return (*this);
	
	for (size_t i = 0; i < n; i++)
	{
		this->str.push_back('0');
	}
	return (*this);
}

bigint& bigint::operator>>=(const unsigned int n)
{
	int	lenStr;

	lenStr = this->str.size();
	if (n >= lenStr)
		this->str = "0";
	else
	{
		for (size_t i = 0; i < n; i++)
			this->str.pop_back();
	}
	return (*this);
}

bigint bigint::operator<<(const bigint &other) const
{
	int 	n;
	bigint	res(*this);

	n = atoi(other.str.c_str());
	res <<= n;
	return (res);
}

bigint bigint::operator>>(const bigint &other) const
{
	int 	n;
	bigint	res(*this);

	n = atoi(other.str.c_str());
	res >>= n;
	return (res);
}

bigint& bigint::operator<<=(const bigint &other)
{
	int 	n;

	n = atoi(other.str.c_str());
	*this <<= n;
	return (*this);
}

bigint& bigint::operator>>=(const bigint &other)
{
	int 	n;

	n = atoi(other.str.c_str());
	*this >>= n;
	return (*this);
}

bool bigint::operator<(const bigint &other) const
{
	if (this->str.size() != other.str.size())
		return (this->str.size() < other.str.size());
	return this->str < other.str;
}

bool bigint::operator>(const bigint &other) const
{
	if (this->str.size() != other.str.size())
		return (this->str.size() > other.str.size());
	return this->str > other.str;
}

bool bigint::operator<=(const bigint &other)
{
	return (!(*this > other));
}

bool bigint::operator>=(const bigint &other)
{
	return (!(*this < other));
}

bool bigint::operator==(const bigint &other) const
{
	return (this->str == other.str);
}

bool bigint::operator!=(const bigint &other) const
{
	return (this->str != other.str);
}


std::ostream& operator<<(std::ostream& output, const bigint& obj)
{
	output << obj.getStr();
	return (output);
}
