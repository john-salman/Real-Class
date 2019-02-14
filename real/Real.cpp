/***********************************************************************************
Author: John Salman
Assignment: CS460 Homework 4
Date: 10/31/18
File: Real.cpp
Description: Implementation of Real class methods and private functions.

 ***********************************************************************************/

#include "Real.h"
#include <sstream>
#include <iomanip>

// Default Constructor
Real::Real ()
{
	sign = '+';
	magnitude = 1;
	precision = 0;
	whole = new unsigned char [1];
	whole[0] = 0;
	fraction = NULL;
}

// Default Destructor
Real::~Real ()
{
	delete [] whole;
	delete [] fraction;
}

// Real Constructor
Real::Real (const Real & R)
{
	sign = R.sign;
	magnitude = R.magnitude;
	precision = R.precision;
	whole = new unsigned char [magnitude];
	for (int i = 0; i < magnitude; i++)
		whole[i] = R.whole[i];
	if (precision > 0)
	{
		fraction = new unsigned char [precision];
		for (int i = 0; i < precision; i++)
			fraction[i] = R.fraction[i];
	}
	else
		fraction = NULL;
}

// String Constructor
Real::Real (const string & S)
{
  
	string T = S;
	bool no_whole = false;
	if (T[0] == '-' || T[0] == '+')
	{
		sign = T[0];
		T.erase (0, 1);
	}
	else
		sign = '+';
	while (T[0] == '0' && T.length() > 1)
		T.erase (0, 1);
	size_t dp = T.find('.');
	if (dp == 0)
	{
		magnitude = 1;
		whole = new unsigned char [1];
		whole[0] = 0;
		no_whole = true;
	}
	else
	{
		if (dp > T.length())
			dp = T.length();
		magnitude = dp;
		whole = new unsigned char [magnitude];
		for (int i = 0, j = magnitude-1; i < dp; i++, j--)
			whole[j] = T[i] - '0';
	}
	if (dp < T.length()-1)
	  {
	    int	j = T.length() - 1;
            while(T[j] == '0' && T.length() > 0){
	      T.erase(j--,1);
            }
	    if(T != ".") {
	        precision = T.length() - dp - 1;
		fraction = new unsigned char [precision];
		for (int i = 0; i < precision; i++)
		{
			dp++;
			fraction[i] = T[dp] - '0';
		}
	    } else {
	      precision = 0;
	      fraction = NULL;
	      if (no_whole){
		sign =	'+';
	      }
	    }
	}
	else
	{
		precision = 0;
		fraction = NULL;
		if (no_whole){
		  sign = '+';
		}
	}
}

// Double Constructor
// Description: Utilizes the string constructor to instantiate an object from
// a passed double
Real::Real (const double & D) {
  string string_double = to_string(D);
  bool no_whole = false;
  if (string_double[0] == '-' || string_double[0] == '+')
    {
      sign = string_double[0];
      string_double.erase (0, 1);
    }
  else
    sign = '+';

  while (string_double[0] == '0' && string_double.length() > 1)
    string_double.erase (0, 1);
  size_t dp = string_double.find('.');
  if (dp == 0)
    {
      magnitude = 1;
      whole = new unsigned char [1];
      whole[0] = 0;
      no_whole = true;
    }
  else
    {
      if (dp > string_double.length())
	dp = string_double.length();
      magnitude = dp;
      whole = new unsigned char [magnitude];
      for (int i = 0, j = magnitude-1; i < dp; i++, j--){
	whole[j] = string_double[i] - '0';
      }
      
    }
  if (dp < string_double.length()-1)
    {
      int j = string_double.length() - 1;
      while(string_double[j] == '0' && string_double.length() > 0){
	string_double.erase(j--,1);
      }
      if(string_double != ".") {
	precision = string_double.length() - dp - 1;
	fraction = new unsigned char [precision];
	for (int i = 0; i < precision; i++)
	  {
	    dp++;
	    fraction[i] = string_double[dp] - '0';
                }
      } else {
	precision = 0;
	fraction = NULL;
	if (no_whole){
	  sign = '+';
	}
      }
    }
  else
    {
      precision = 0;
      fraction = NULL;
      if (no_whole){
	sign = '+';
      }
    }
}

// Assignment operator
Real & Real::operator = (const Real & R)
{
	if (this == & R)
		return * this;
	delete [] whole;
	delete [] fraction;
	sign = R.sign;
	magnitude = R.magnitude;
	precision = R.precision;
	whole = new unsigned char [magnitude];
	for (int i = 0; i < magnitude; i++)
			whole[i] = R.whole[i];
	if (precision > 0)
	{
		fraction = new unsigned char [precision];
		for (int i = 0; i < precision; i++)
			fraction[i] = R.fraction[i];
	}
	else
		fraction = NULL;
	return * this;
}

/*****************************************************************************************
Function: + operator
Params: A Real object representing the other
Returns: The sum of this plus other
Description: Applies the standard approach to addition of real number if the signs are
             equal, otherwise a call to the subtraction operator is made and the value
             from that is returned.
Helpers: add_whole_same(), add_whole_diff(), add_frac()
******************************************************************************************/
Real Real::operator + (const Real & R) const
{
  Real sum;
  if (*this == sum && R == sum) {
    return sum;
  } else if (*this == sum) {
    return R;
  } else if (R == sum) {
    return *this;
  }
  
  if ((sign == '+' && R.sign == '+')  || (sign == '-' &&  R.sign == '-')) { // these behave the same, just gotta remember the sign 

    int carry = 0; // put this out here to put in a wider scope
    if (R.precision == 0 && precision > 0) { // the other has no fraction
      sum.precision = precision;
      sum.fraction = new unsigned char [sum.precision];
      for (int i = precision - 1; i >=0; i--) {
	sum.fraction[i] = fraction[i];
      }
    } else if (precision == 0 && R.precision > 0) { // self has no fraction
      sum.precision = R.precision;
      sum.fraction = new unsigned char [sum.precision];
      for (int i = R.precision - 1; i >=0; i--) {
        sum.fraction[i] = R.fraction[i];
      }

    } else if (precision == 0 && R.precision == 0) { // they both lack a fraction
      // space intentionally blank, we have nothing to do here
    } else {

      carry = sum.add_frac(*this, R);

    }
    if ((R.magnitude == 1 && R.whole[0] == 0) && (magnitude > 1 || whole[0] != 0) && carry == 0) { // the other has no magnitude, and there is no overflow from carry
      sum.magnitude = magnitude;
      delete [] sum.whole;
      sum.whole = new unsigned char [sum.magnitude];
      for (int i = 0; i < magnitude; i++) {
	sum.whole[i] = whole[i];
      }
    } else if ((magnitude == 0 && whole[0] == 0) && (R.magnitude > 1 || R.whole[0] != 1) && carry == 0) { // self has no magnitude and there is no overflow
      sum.magnitude = R.magnitude;
      delete [] sum.whole;
      sum.whole = new unsigned char [sum.magnitude];
      for (int i = 0; i < R.magnitude; i++) {
        sum.whole[i] = R.whole[i];
      }
    } else if (magnitude == 1 && R.magnitude == 1 && whole[0] == 0 && R.whole[0] == 0 && carry == 0) {
      // space intentionally blank
    } else {

      int difference = magnitude - R.magnitude;
      if (difference == 0) { // whole arrays are equal size

	sum.whole = new unsigned char [magnitude];
	carry = sum.add_whole_same(*this, R, carry);

      } else if (difference > 0) { // self-whole array is bigger
	sum.whole = new unsigned char [magnitude];
	carry = sum.add_whole_diff(*this, R, carry);//self=left, other=right

      } else { // other is bigger

	sum.whole = new unsigned char [R.magnitude];
	carry = sum.add_whole_diff(R, *this, carry); // just flip the parameters so other=left, self=right

      }
      if (carry == 1) { // if the carry isn't empty
	unsigned char * temp = new unsigned char [sum.magnitude + 1];
	for (int i = 0; i < sum.magnitude; i++) {
	  temp[i] = sum.whole[i];
	}
	delete [] sum.whole;
	temp[sum.magnitude++] = 1;
	sum.whole = temp;
      }
    }
    sum.sign = sign;
    sum.remove_trailing_zeros();
    return sum;
  } else if (sign == '+') { // a + (-b) == a - b 
    // here I take advantage of addition laws to reduce the number of cases
    // I have to account for
    Real positive = R;
    positive.sign = '+';
    return *this - positive;

  } else { // -a + b == b - a 
    // same as above, take advantage of equivalence
    Real positive = *this;
    positive.sign = '+';
    return R - positive; // will return negative if "a" is bigger
   }
}

/*******************************************
 ADDITION HELPERS
*******************************************/

/*****************************************************************************************    
 Function: add_whole_diff()
 Params: 2 Real object representing operands, and the current value of the carry
 Returns: the new value of the carry
 Description: Is called to sum the whole arrays of two real numbers if they are of
              differing size. Takes in to account the carry from the summing of the
              fraction arrays.
******************************************************************************************/
int Real::add_whole_diff(const Real &left, const Real &right, int _carry) {
  int i = 0;
  int j = 0;
  int carry = _carry;
  int current = 0;
  for (; j < right.magnitude; i++, j++) {
    current = (left.whole[i]) + (right.whole[j]);
    if ((current + carry) > 9) {
      current -= 10;
      whole[i] = (unsigned char)(current + carry); // this will never exceed 9, as the max value we can see is 18 (9 + 9)                                                                  
      carry = 1;
    } else {
      whole[i] = (unsigned char)(current + carry);
      carry = 0;
    }
    
  }
  for(; i < left.magnitude; i++) {
    current = left.whole[i] + carry;
    if ((current) > 9) {
      current -= 10;
      whole[i] = (unsigned char)current;
      carry = 1;
    } else {
      whole[i] = (unsigned char)current;
      carry = 0;
    }
  }
  magnitude = left.magnitude;
  return carry;
}

/*****************************************************************************************
Function: add_whole_same()
Params: Two real objects representing operands and an integer representing the carry
Returns: the new value of the carry
Description: This function sums the whole arrays of two Real objects and returns the 
             value of the carry in case the last index overflows.
******************************************************************************************/
int Real::add_whole_same(const Real &left, const Real &right, int _carry) {
  int carry = _carry;
  int current = 0;
  for (int i = 0; i < left.magnitude; i++) {
    current = (left.whole[i]) + (right.whole[i]);
    if ((current + carry) > 9) {
      current -= 10;
      whole[i] = (unsigned char)(current + carry); // this will never exceed 9, as the max value we can see is 18 (9 + 9)                                                                    
      carry = 1;
    } else {
      whole[i] = (unsigned char)(current + carry);
      carry = 0;
    }
    
  }
  magnitude = left.magnitude;
  return carry;
}

/*****************************************************************************************
 Function: add_frac()
 Params: two real objects representing operands 
 Returns: The value of the carry                                                                                                                                                                        
 Description: This funtion sums the fraction arrays of two Real objects and returns the 
              carry regardless of it being 0 or 1.
******************************************************************************************/
int Real::add_frac(const Real &left, const Real &right) {
  int max_precision;
  int min_precision;
  int carry = 0;
  if (left.precision > right.precision) { // we need to remember which is smaller
    max_precision = left.precision;
    min_precision = right.precision;
  } else {
    max_precision = right.precision;
    min_precision = left.precision;
  }
  
  fraction = new unsigned char [max_precision];
  precision = max_precision;
  int difference = left.precision - right.precision;
  if (difference > 0) { // self-fraction array is bigger
    int x = precision - difference;
    for (int i = left.precision - 1; i >= x; i--) {
      fraction[i] = left.fraction[i];
    }
  } else if (difference < 0) { // other-fraction array is bigger
    int x = precision + difference;
    for (int i = right.precision - 1; i >= x; i--) {
      fraction[i] = right.fraction[i];
    }
  }
  int current = 0;
  for (int i = min_precision - 1; i >= 0; i--) {
    current = (left.fraction[i]) + (right.fraction[i]);
    if ((current + carry) > 9) {
      current -= 10;
      fraction[i] = (unsigned char)(current + carry); // this will never exceed 9, as the max value we can see is 18 (9 + 9)
      carry = 1;
    } else {
      fraction[i] = (unsigned char)(current + carry);
      carry = 0;
    }
  }
  return carry;
}

/*******************************************
 END OF ADDITION HELPERS
*******************************************/

/*****************************************************************************************        
Function: * operator                                                                              
Params: A Real object representing the other                                                      
Returns: The product of this * other                                                               
Description: I attempted to implement the Karatsuba Algorithm to improve the effieciency
             of multiplication. Currently not working, induces an error in the default 
             constructor that I was unable to get around.
Helpers: multiply(), flatten(), unflatten()
******************************************************************************************/
Real Real::operator * (const Real & R) const {
  Real result;
  if (*this == result || R == result) { // Are we looking at a multiply against zero?
    return result; // any number times zero is zero
  }

  Real self;
  Real other;
  
  self.flatten(*this); // essentially removes the decimal point which will need to be reconfigured after
  other.flatten(R);
  result = multiply(self, other); // call to main helper
  int total_precision = precision + R.precision;
  if (total_precision > result.magnitude) {
    result.add_leading_zeros((total_precision-result.magnitude) + 1);
    //    total_precision--;
  }
  result.unflatten(total_precision);
  result.remove_trailing_zeros();
  result.remove_leading_zeros();
  if(sign != R.sign){ // sign by default is positive, only change if an operand is negative
    result.sign = '-';
  }
  
  return result;
}

/*******************************************
 MULTIPLICATION HELPERS
*******************************************/

/*****************************************************************************************        
Function: multiply()                                                                              
Params: A Real object representing the first operand, another representing the second                                                      
Returns: The product of this * other                                                               
Description: Main helper for * operator, this is where the bulk of the computation occurs
             Works by recursively splitting the object until they can be multiplied as
             single elements. 
Helpers: split(), multiply_single_elements(), normalize(), add_leading_zeros(),
         add_trailing_zeros(), remove_leading_zeros()
******************************************************************************************/
Real Real::multiply(const Real &_self, const Real &_other) const {
  // !!!WARNING!!! MULTIPLY WILL MODIFY VALUES !!!WARNING!!!
  Real result;
  Real self (_self);
  Real other (_other);
  
  self.remove_leading_zeros();
  other.remove_leading_zeros();
  if((self.magnitude == 1 && self.whole[0] == 0) || (other.magnitude == 1 && other.whole[0] == 0)){
    return result; // any number by 0 is 0
  }
  else if (self.magnitude == 1 && other.magnitude == 1) { // base case, we dont need to split further
    result =  self.multiply_single_elements(other);
    return result;
  }
  normalize(self,other); // make sure they are same size and padded accordingly

  // Necessary variables
  Real self_left;
  Real self_right;
  Real other_left;
  Real other_right;
 
  // This is where the split occurs, works accurately
  self.split(self_left, self_right);
  other.split(other_left, other_right);

  Real c_1;
  Real c_2;
  Real c_2_left;
  Real c_2_right;
  Real c_3;

  c_2_left = self_left + self_right;
  c_2_right = other_left + other_right;
  
  // Recursive call to self
  c_1 = multiply(self_left, other_left);
  c_3 = multiply(self_right, other_right);

  
  Real c_2_a = multiply(c_2_left, c_2_right);
  Real c_2_b = c_1 + c_3;
  c_2 = c_2_a - c_2_b;

  c_1.add_trailing_zeros(self.magnitude);
  c_2.add_trailing_zeros(self.magnitude/2);

  // These lines represents: final = c_1^(n) + c_2^(n/2) + c_3
  Real result_a = c_1 + c_2;
  result = result_a + c_3;

  result.remove_leading_zeros();
  return result;
}


/***************************************************************************************** 
Function: remove_leading_zeros()
Params: none
Returns: boolean value                                                                                                                                                                       
Description: This function removes all zeros at the start of the whole array. If the array
             is already empty or is made empty by the function, then the funtion returns
             true, false otherwise.
NOTE: IS ALSO A HELPER OF SUBTRACTION
******************************************************************************************/
bool Real::remove_leading_zeros() {
  if (magnitude == 1 && whole[0] == 0){
    return true;
  } else if (magnitude == 1) {
    return false;
  }
  if (whole[magnitude - 1] == 0) { // check for leading zeroes                                                     
    int zero_count = 1;
    int i = magnitude - 2;
    while(whole[i] == 0 && i >= 0) {
      zero_count++;
      i--;
    }
    if ((magnitude - zero_count) == 0){
      delete [] whole;
      magnitude = 1;
      whole = new unsigned char [magnitude];
      whole[0] = 0;
      return true;
    } else {
      int new_magnitude = magnitude - zero_count;
      unsigned char * temp = new unsigned char [new_magnitude]; // instantiate a new array equal to the number of non-zero numbers
      for (int j = new_magnitude - 1; j >= 0; j--) {
        temp[j] = whole[j];
      }

      delete [] whole;
      whole = temp;
      magnitude = new_magnitude;
    }
    return false;
  }
  return false;
}


/*****************************************************************************************                                                                
Function: flatten()        
Params: A Real object            
Returns: none                                                                                                                                                                      
Description: This function essentially returns the entire number, but held in only the
             the whole array, thereby removing the decimal point.
******************************************************************************************/
void Real::flatten(const Real & R) {
  int new_magnitude = R.magnitude + R.precision;
  delete [] whole;
  whole = new unsigned char[new_magnitude];
  magnitude = new_magnitude;
  int k = 0;
  if (R.precision > 0) {
    for (int i = R.precision - 1; i >= 0; i--) {
      whole[k] = R.fraction[i];
      k++;
    }
  }
  if (R.magnitude > 0) {
    for (int j = 0; j < R.magnitude; j++) {
      whole[k] = R.whole[j];
      k++;
    }
  }
  return;
}

/*****************************************************************************************                                                                
Function: unflatten()        
Params: an integer representing the combined precision of the original operands 
Returns: none                                                                                                                                                                       
Description: This function serves to reformat the Real object that is returned from the
             multiply() function.
Helpers:                                                                                                                                                                             
******************************************************************************************/
void Real::unflatten(int _total_precision) {
  precision = _total_precision;
  fraction = new unsigned char [precision];
  int new_magnitude = magnitude - precision;
  unsigned char * temp = new unsigned char[new_magnitude];
  int i = 0;
  for(int k = precision - 1; k >= 0; k--,i++) {
    fraction[i] = whole[k];
  }
  int j = 0;
  for (int h = precision; h < magnitude; j++, h++) {
    temp[j] = whole[h];
  }
  delete [] whole;
  whole = temp;
  magnitude = new_magnitude;
  return;
}

/*****************************************************************************************                                                                
Function: normalize()        
Params: two Real objects representing operands            
Returns: none
Description: This function ensures the two objects are of the same size, and that that
             size is a multiple of two. It accomplishes this by padding the two numbers
             with zeros until this is accomplished.
Helpers: add_leading_zeros()
******************************************************************************************/
void Real::normalize(Real &left, Real &right) const{
  int difference = left.magnitude - right.magnitude;
  if (difference == 0) {
    if(left.magnitude == 1) {
      return;
    }
    if (left.magnitude % 2 != 0) {
      left.add_leading_zeros(1);
      right.add_leading_zeros(1);
    }
  } else if (difference > 0) {
    right.add_leading_zeros(difference);
  } else {
    left.add_leading_zeros(-(difference));
  }

  if (left.magnitude % 2 != 0) {
      left.add_leading_zeros(1);
      right.add_leading_zeros(1);
  }
  return;

}

/***************************************************************************************** 
Function: multiply_single_elements()
Params: a real object representing the right operand (left is the self).            
Returns: a real object representing the product
Description: This function works as the name implies, it multiplies two singleton values
             and returns the product.
******************************************************************************************/
Real Real::multiply_single_elements(const Real & R) const{
  int x = whole[0]; int y = R.whole[0];
  Real mult;
  int current = whole[0] * R.whole[0];

  if (current > 9) { // largest we can see is 81                                                                   
    delete [] mult.whole;
    mult.magnitude = 2;
    mult.whole = new unsigned char[2];
    mult.whole[1] = (unsigned char)(current / 10);
    mult.whole[0] = (unsigned char)(current % 10);
  } else {
    mult.whole[0] = (unsigned char)current;
  }
  return mult;
}

/***************************************************************************************** 
Function: split()        
Params: two real objects            
Returns: none                                                                                                                                                                       
Description: splits the original into a leftside, contained in "a", and a rightside,                                                                                                                                   to be contained in "b".
******************************************************************************************/
void Real::split(Real &a, Real &b) {
  if (magnitude > 2) {
    a.magnitude = b.magnitude = (magnitude/2);
    delete [] a.whole;
    delete [] b.whole;
    a.whole = new unsigned char [a.magnitude];
    b.whole = new unsigned char [b.magnitude];
    for (int i = 0; i < b.magnitude; i++) {
      b.whole[i] = whole[i];
    }
    int j = 0;
    for (int k = a.magnitude; k < magnitude; k++){
      a.whole[j] = whole[k];
      j++;
    }
  } else { // bulk of this might be unneccessary
    delete [] a.whole;
    delete [] b.whole;
    a.magnitude = b.magnitude = 1;
    a.whole = new unsigned char [a.magnitude];
    b.whole = new unsigned char [b.magnitude];
    b.whole[0] = whole[0];
    a.whole[0] = whole[1];
  }
  return;
}

/*****************************************************************************************                                                                
Function: add_leading_zeros()        
Params: an integer representing the number of zeros to be added 
Returns: none                                                                                                                                                                       
Description: Adds the desired number of zeros to the start of the whole number.
******************************************************************************************/
void Real::add_leading_zeros(int x) {
  int new_magnitude = magnitude + x;
  unsigned char *temp = new unsigned char[new_magnitude];
  for (int i = new_magnitude - 1; i > magnitude - 1; i--) {
    temp[i] = (unsigned char)0;
  }
  for (int i = magnitude - 1; i >= 0; i--) {
    temp[i] = whole[i];
  }
  delete [] whole;
  magnitude = new_magnitude;
  whole = temp;
  return;
}

/*****************************************************************************************                                                                
Function: add_trailing_zeros()       
Params: an integer representing the number of zeros to be added
Returns: none                                                                                                                                                                       
Description: Adds the desired number of zeros to the end of the whole number.
******************************************************************************************/
void Real::add_trailing_zeros(int x) {
  int new_magnitude = x + magnitude;
  unsigned char * temp = new unsigned char[new_magnitude];
  int k = new_magnitude - 1;
  for(int i = magnitude - 1; i >= 0; i--, k--) {
    temp[k] = whole[i];
  }
  for(int i = 0; i < x; i++) {
    temp[i] = (unsigned char)0;
  }
  delete [] whole;
  magnitude = new_magnitude;
  whole = temp;
  return;
}

/*******************************************
 END OF MULTIPLICATION HELPERS
*******************************************/

/*****************************************************************************************        
Function: - operator                                                                              
Params: A Real object representing the other                                                      
Returns: The result of this - other                                                               
Description: Applies the standard approach to subtraction of real numbers if the signs are            
             equal and the first operand is bigger or equal, otherwise a call to the 
             addition operator is made and the value from that is returned. If the second
             operand is larger a recursive call is made and the sign is switched after
             computation.
Helpers: remove_trailing_zeros(), remove_leading_zeros(), sub_frac(), sub_whole_same()
         sub_whole_diff()
******************************************************************************************/
Real Real::operator - (const Real & R) const {

  Real result;
  if (*this == result && R == result) {
    return result;
  } else if (R == result) {
    return *this;
  }
  
  if ((sign == '+' && R.sign == '+')){
    if (*this >= R) { // Is the first operand bigger?
      int detract = 0;
      int current = 0;

      if (R.precision == 0) {
	result.precision = precision;
	result.fraction = new unsigned char [result.precision];
	for (int i = precision - 1; i >= 0; i--) {
	  result.fraction[i] = fraction[i];
	}
      } else if (R.precision == 0 && precision == 0) {
	result.fraction = NULL;
	result.precision = 0;
      } else {
	int difference = precision - R.precision;
	if (difference == 0) { // fraction arrays are the same size
	  result.fraction = new unsigned char [precision];
	  result.precision = precision;
	  detract = result.sub_frac(*this, R, detract);
	
	} else if (difference > 0) { // self-fraction array is bigger
	  result.fraction = new unsigned char [precision];
	  result.precision = precision;
	  for (int i = precision - 1; i > (precision - difference) - 1; i--) { // note the conditionals, we're going back to front
	    result.fraction[i] = fraction[i];
	  }
	  detract = result.sub_frac(*this, R, detract);
	} else { // other-fraction array is bigger
	  result.fraction = new unsigned char [R.precision];
	  result.precision = R.precision;
	  int x = R.precision + difference;
	  for (int i = R.precision - 1; i >= x; i--) {
	    current = (10 - detract) - R.fraction[i]; // even if the zeroes aren't really there, we still have to pretend
	    result.fraction[i] = (unsigned char)current;
	    detract = 1; // so in the first round this is zero
	  }
	  if(precision != 0) {
	    detract = result.sub_frac(*this, R, detract);
	  }
	}
      }	
      if (R.magnitude == 1 && R.whole[0] == 0) { // other has no whole number
	delete [] result.whole;
	result.magnitude = magnitude;
	result.whole = new unsigned char[result.magnitude];
	for (int i = 0; i < magnitude; i++) {
	  if (detract == 1){
	    current = whole[i] - 1;
	    if (current < 0) {
	      current += 10;
	      result.whole[i] = (unsigned char)current;
	    } else {
	      result.whole[i] = (unsigned char)current;
	      detract = 0;
	    }
	  } else {
	    result.whole[i] = whole[i];
	  }
	}
      } else { // note we never have to check if self has no whole number, as the first operand is always bigger
	current = 0;
	int difference = magnitude - R.magnitude;
	delete [] result.whole;
	result.whole = new unsigned char [magnitude];
	result.magnitude = magnitude;
	
	if (difference == 0) { // equal size
	  
	  result.sub_whole_same(*this, R, detract);
	  
	} else if (difference > 0) { // self-whole array is bigger
	  
	  result.sub_whole_diff(*this, R, detract);
	  
	}

      }
    
      bool no_fraction = result.remove_trailing_zeros();
      bool no_whole = result.remove_leading_zeros();
      if (no_fraction && no_whole){ // calling the truncate function, so that it can shortcut if the fraction isn't empty
	Real null_real;
	return null_real; // return an empty number
	
      }
      return result;
      } else { // (a - b) == -(b - a)
    
      // Another instance where I take advantage of arithmetic laws
      
      result = R - *this; // should only ever execute a recursive call once
      Real null_real;
      if (result != null_real) {
	result.sign = (result.sign == '+') ? '-' : '+'; // we simply need to negate whatever sign came out      
      }
      return result;
    }

    }else if (R.sign == '-') { // call to addition, a - (-b) == a + b
      Real positive = R;
      positive.sign = '+';
      return *this + positive;

    } else { // call to addition; -a - b == -a + -b
      Real negative = R;
      negative.sign = '-';
      return *this + negative;
    }
}

/*******************************************
  SUBTRACTION HELPERS 
 *******************************************/

/*****************************************************************************************                                                                
Function: sub_whole_same()        
Params: two Real objects and the current value of detract
Returns: none                                                                                                                                                                       
Description: Finds the difference of two whole arrays of the same size.
******************************************************************************************/
void Real::sub_whole_same(const Real &left, const Real &right, int _detract) {
  int detract = _detract;
  int current = 0;
  for (int i = 0; i < left.magnitude; i++) {
    if (left.whole[i] < right.whole[i] || (detract == 1 && left.whole[i] == right.whole[i])) {
      current = ((left.whole[i] - detract) + 10) - right.whole[i];
      whole[i] = (unsigned char) current;
      detract = 1;
    } else {
      current = (left.whole[i] - detract) - right.whole[i];
      whole[i] = (unsigned char)current;
      detract = 0;
    }
  }
}

/*****************************************************************************************                                                                
Function: sub_whole_diff()       
Params: two Real objects and the current value of detract
Returns: none                                                                                                                                                                       
Description: Find the difference of two whole arrays of differing size, with the larger 
             being the "left" object.
******************************************************************************************/
void Real::sub_whole_diff(const Real &left, const Real &right, int _detract) {
  int detract = _detract;
  int current = 0;
  int i = 0;
  for (; i < right.magnitude; i++) {
    if (left.whole[i] < right.whole[i] || (detract == 1 && left.whole[i] == right.whole[i])) {
      current = ((left.whole[i] - detract) + 10) - right.whole[i];
      whole[i] = (unsigned char) current;
      detract = 1;
    } else {
      current = (left.whole[i] - detract) - right.whole[i];
      whole[i] = (unsigned char)current;
      detract = 0;
    }
    
  }
  int lead_check = left.whole[i] - detract;
  if (lead_check == 0 && i == (left.magnitude - 1)) {
    whole[i] = (unsigned char)lead_check;
  } else {
    for (; i < left.magnitude; i++) {
      current = left.whole[i] - detract;
      if (current < 0) {
	current += 10;
	whole[i] = (unsigned char)current;
      } else {
	whole[i] = (unsigned char) current;
	detract = 0;
      }
    }
  }
  return;
}

/*****************************************************************************************                                                                
Function: sub_frac()        
Params: two real objects representing operands and the current value of detract
Returns: the new value of detract
Description: Calculates the difference of the fraction arrays and returns the new value of
             detract.
******************************************************************************************/
int Real::sub_frac(const Real &left, const Real &right, int _detract){
  int detract = _detract;
  int current = 0;
  int loop_precision = (left.precision > right.precision) ? right.precision - 1 : left.precision - 1;
  for (int i = loop_precision; i >= 0; i--) {
    if (left.fraction[i] < right.fraction[i] || (detract == 1 && left.fraction[i] == right.fraction[i])) {
      current = ((left.fraction[i] - detract) + 10) - right.fraction[i];
      fraction[i] = (unsigned char)current;
      detract = 1;
    } else {
      current = (left.fraction[i] - detract) - right.fraction[i];
      fraction[i] = (unsigned char)current;
      detract = 0;
    }
  }
  return detract;
}

/*****************************************************************************************                                                                                                                Function:remove_trailing_zeros()
Params: none
Returns: boolean value
Description: This function removes all zero values at the end of the fraction array. If
             the fraction array is already empty is made empty then the function
             returns true, false otherwise
******************************************************************************************/
bool Real::remove_trailing_zeros() {
  if (fraction != NULL) {
    int i = precision - 1;
    int trail_count = 0;
    while (fraction[i] == 0 && i >= 0) {
      trail_count++;
      i--;
    }
    if (trail_count == precision) {
      delete [] fraction;
      precision = 0;
      fraction = NULL;
      return true; // if there is nothing in the fraction                                                                                                                                                  
    } else if (trail_count > 0){
      int fixed_precision = precision - trail_count;
      unsigned char * fixed_fraction = new unsigned char [fixed_precision];
      for (int j = 0; j < fixed_precision; j++) {
        fixed_fraction[j] = fraction[j];
      }
      delete [] fraction;
      precision = fixed_precision;
      fraction = fixed_fraction;
    }
    return false;
  }
  return true; // there is nothing here                                                                                                                                                                    
}


/*******************************************
 END OF MULTIPLICATION HELPERS
*******************************************/

// += operator, calls addition operator
Real Real::operator += (const Real & R){
  *this = *this + R;
  return *this;
}

// *= operator, calls multiplication operator
Real Real::operator *= (const Real & R) {
  *this = *this * R;
  return *this;
}

Real Real::operator -= (const Real & R) {
  *this = *this - R;
  return *this;
}

/*****************************************************************************************        
Function: == operator                                                                              
Params: A Real object representing the other                                                      
Returns: the boolean value representing the equivalence of the objects
Description: Applies multiple tests to see if the passed values are equivalent, checking
             address, sign, size, and then the internal values.
******************************************************************************************/
bool Real::operator == (const Real & R) const {

  if (this == &R) { //are we looking at the same object?
    return true;
  }
  if (sign != R.sign){
    return false;
  } else if (magnitude != R.magnitude || precision != R.precision) {
    return false;
  } else {

    // utilizing memcmp for speed
    // NOTE: doesn't work for whole[] as the numbers are stored in reverse
    int fraction_comparison = memcmp(fraction, R.fraction, precision); // NOTE: comes out as int 0 if same (i.e. bool false) 
    if (fraction_comparison != 0) {
      return false;
    }
    
    for (int i = magnitude - 1; i >= 0; i--) {
      if (whole[i] != R.whole[i]) {
	return false;
      }
    }
  }
  return true;
}

// != operator, makes a negated call to equivalence operator
bool Real::operator != (const Real & R) const {
  return !(*this == R); // don't reinvent the wheel
}

/*****************************************************************************************        
Function: > operator                                                                              
Params: A Real object representing the other                                                      
Returns: The boolean value representing the result of the tests
Description: Applies multiple tests to see if the self is greater than other, checking
             the addresses, signs, sizes, and finally internal values.
******************************************************************************************/
bool Real::operator > (const Real & R) const {
  if (this == &R) { // are we looking at the same object?
    return false;
  }
  if (*this == R) { // are we looking at a copy?
    return false;
  }
  
  if (sign != R.sign) {
    if (sign == '+') {
      return true;
    } else {
      return false;
    }
  } else if (sign == '-') {
    Real pos_this (*this);
    Real pos_R (R);
    pos_this.sign = pos_R.sign = '+'; 
    return pos_this < pos_R;    
  }


  if (magnitude > R.magnitude) {
    return true;
  } else if (magnitude < R.magnitude) {
    return false;
  } else { // equal
    for (int i = magnitude - 1; i >= 0; i--) {
      if (whole[i] < R.whole[i]) {
	return false;
      } else if (whole[i] > R.whole[i]){
	return true;
      }
    }
  }

  if (precision > R.precision) {
    return true;
  } else if (precision < R.precision){
    return false;
  } else {
     for (int i = 0; i < ((precision >= R.precision) ? precision : R.precision); i++) {
    
       if (fraction[i] > R.fraction[i]) {
	 return true;
       } else if (fraction[i] < R.fraction[i]) {
	 return false;
       } // if we get past both of these conditionals then we know the indeces are equal
     }
  }
  // if this line is reached, then the two values are equal
  return false; // To reach this the equality operator must fail
}

// >= operator, makes call to equality and greater than operators
bool Real:: operator >= (const Real & R) const {

  if (*this == R){
    return true;
  }
  return *this > R;
}

// < operator, makes call to greater than operator with reversed operands
bool Real::operator < (const Real & R) const {
  return R > *this; // a < b == b > a
}

// <= operator, makes call to equality operator and less than operator
bool Real::operator <= (const Real & R) const {

  if (*this == R)
    return true;
  return *this < R;
}

// istream operator
istream & operator >> (istream & ins, Real & R) {
  string astring;
  ins >> astring;
  if (!ins.fail()){
    Real new_R (astring);
    R = new_R;
  }
  return ins;
}

ostream & operator << (ostream & outs, const Real & R)
{
	if (R.sign == '-')
		outs << R.sign;
	for (int i = R.magnitude-1; i >= 0; i--)
		outs << char ('0' + R.whole[i]);
	if (R.precision > 0)
		outs << '.';
	for (int i = 0; i < R.precision; i++)
		outs << char ('0' + R.fraction[i]);
	return outs;
}

