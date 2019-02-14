#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Real
{
	public:
		Real ();
		~Real ();
		Real (const Real & R);
		Real (const string & S);
		Real (const double & D);
		Real & operator = (const Real & R);
		void additionTest (const Real & R) const;
		Real operator + (const Real & R) const;
		Real operator * (const Real & R) const;
		Real operator - (const Real & R) const;
		Real operator += (const Real & R);
		Real operator *= (const Real & R);
		Real operator	-= (const Real & R);
		bool operator == (const Real & R) const;
		bool operator != (const Real & R) const;
		bool operator > (const Real & R) const;
		bool operator >= (const Real & R) const;
		bool operator < (const Real & R) const;
		bool operator <= (const Real & R) const;
		friend istream & operator >> (istream & ins, Real & R);
		friend ostream & operator << (ostream & outs, const Real & R);
		
 private:
		char sign;
		size_t magnitude;
		size_t precision;
		unsigned char * whole;
		unsigned char *  fraction;

		
		int add_whole_diff(const Real &left, const Real &right, int _carry);
		int add_whole_same(const Real &left, const Real &right, int _carry);
		int add_frac(const Real &left, const Real &right);
		  
		Real multiply (const Real &self, const Real &other) const;
		void flatten(const Real & R);
		void unflatten(int _total_precision);
		void normalize(Real &left, Real &right) const;
		Real multiply_single_elements(const Real & R) const;
		void split(Real &a, Real &b);
		void add_leading_zeros(int x);
		void add_trailing_zeros(int x);

		void sub_whole_same(const Real &left, const Real &right, int _detract);
		void sub_whole_diff(const Real &left, const Real &right, int _detract);
		int sub_frac(const Real &left, const Real &right, int _detract);

		bool remove_trailing_zeros();
		bool remove_leading_zeros();
};
		

