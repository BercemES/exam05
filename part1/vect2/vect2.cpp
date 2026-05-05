#include "vect2.hpp"

vect2::vect2(): x(0), y(0) {}
vect2::vect2(const int num1, const int num2): x(num1), y(num2) {}
vect2::vect2(const vect2& other): x(other.x), y(other.y) {}
vect2& vect2::operator=(const vect2& other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return (*this);
}

vect2::~vect2() {}

bool vect2::operator==(const vect2& other)const
{
	if (this->x == other.x && this->y == other.y)
		return (true);
	return (false);
}
bool vect2::operator!=(const vect2& other)const
{
	if (this->x == other.x && this->y == other.y)
		return (false);
	return (true);
}

vect2 vect2::operator+(const vect2& num)const
{
	return vect2(this->x + num.x, this->y + num.y);
}

vect2 vect2::operator-(const vect2& num)const
{
	return vect2(this->x - num.x, this->y - num.y);
}

vect2 vect2::operator+(const int num)const
{
	return vect2(this->x + num, this->y + num);
}
vect2 vect2::operator-(const int num)const
{
	return vect2(this->x - num, this->y - num);
}
vect2 vect2::operator*(const int num)const
{
	return vect2(this->x * num, this->y * num);
}

vect2 vect2::operator-()
{
	return (*this * -1);
}

vect2& vect2::operator++()
{
	this->x++;
	this->y++;
	return (*this);
}
vect2 vect2::operator++(int)
{
	vect2 temp = *this;
	this->x++;
	this->y++;
	return (temp);
}
vect2& vect2::operator--()
{
	this->x--;
	this->y--;
	return (*this);
}
vect2 vect2::operator--(int)
{
	vect2 temp = *this;
	this->x--;
	this->y--;
	return (temp);
}

vect2& vect2::operator+=(const vect2& num)
{
	*this = *this + num;
	return (*this);
}
vect2& vect2::operator-=(const vect2& num)
{
	*this = *this - num;
	return (*this);
}
vect2& vect2::operator*=(const int num)
{
	*this = *this * num;
	return (*this);
}

int& vect2::operator[](const int index)
{
	if (index == 0)
		return (this->x);
	return (this->y);
}
const int& vect2::operator[](const int index)const
{
	if (index == 0)
		return (this->x);
	return (this->y);
}

std::ostream& operator<<(std::ostream& os, const vect2& v)
{
	os << "{" << v[0] << ", " << v[1] << "}";
	return (os);
}

vect2 operator*(int num, const vect2& v)
{
	return (v * num);
}

