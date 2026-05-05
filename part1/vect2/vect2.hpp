#ifndef VECT2_HPP
# define VECT2_HPP

# include <iostream> 

class vect2
{
	private:
		int x;
		int y;
	public:
		vect2();
		vect2(const int num1, const int num2);
		vect2(const vect2& other);
		vect2& operator=(const vect2& other);
		~vect2();

		bool operator==(const vect2& other)const;
		bool operator!=(const vect2& other)const;

		vect2 operator+(const vect2& num)const;
		vect2 operator-(const vect2& num)const;

		vect2 operator+(const int num)const;
		vect2 operator-(const int num)const;
		vect2 operator*(const int num)const;
		
		vect2 operator-();

		vect2& operator++();
		vect2 operator++(int);
		vect2& operator--();
		vect2 operator--(int);

		vect2& operator+=(const vect2& num);
		vect2& operator-=(const vect2& num);

		vect2& operator*=(const int num);

		int& operator[](const int index);
		const int& operator[](const int index)const;
};

std::ostream& operator<<(std::ostream& os, const vect2& v);

vect2 operator*(int num, const vect2& v);

#endif