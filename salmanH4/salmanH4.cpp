#include <iostream>
#include "Real.h"

using namespace std;

int main() {
  Real double_1 (432.875);
  Real double_2 (0.87576473874);
  Real double_3 (57485839.2394348);
  Real double_4 (0.0);
  Real double_5 (34590);

  Real double_1_neg (-432.875);
  Real double_2_neg (-0.8757673874);
  Real double_3_neg (-57485839.2394348);
  Real double_4_neg (-0.0);
  Real double_5_neg (-34590);

  string TF [2] = {"false", "true"};
  
  cout << endl;
  cout << double_1 << " > " << double_1 << " = " << TF[double_1 > double_1] << endl;
  cout << double_1 << " > " << double_2 << " = " << TF[double_1 > double_2] << endl;
  cout << double_1 << " > " << double_3 << " = " << TF[double_1 > double_3] << endl;  
  cout << double_1 << " > " << double_4 << " = " << TF[double_1 > double_4] << endl;
  cout << double_1 << " > " << double_5 << " = " << TF[double_1 > double_5] << endl;
									   
  cout << double_1 << " > " << double_1_neg << " = " << TF[double_1 > double_1_neg] << endl;
  cout << double_1 << " > " << double_2_neg << " = " << TF[double_1 > double_2_neg] << endl;
  cout << double_1 << " > " << double_3_neg << " = " << TF[double_1 > double_3_neg] << endl;
  cout << double_1 << " > " << double_4_neg << " = " << TF[double_1 > double_4_neg] << endl;
  cout << double_1 << " > " << double_5_neg << " = " << TF[double_1 > double_5_neg] << endl;

  cout << endl;
  cout << double_2 << " > " << double_1 << " = " << TF[double_2 > double_1] << endl;
  cout << double_2 << " > " << double_2 << " = " << TF[double_2 > double_2] << endl;
  cout << double_2 << " > " << double_3 << " = " << TF[double_2 > double_3] << endl;
  cout << double_2 << " > " << double_4 << " = " << TF[double_2 > double_4] << endl;
  cout << double_2 << " > " << double_5 << " = " << TF[double_2 > double_5] << endl;

  cout << double_2 << " > " << double_1_neg << " = " << TF[double_2 > double_1_neg] << endl;
  cout << double_2 << " > " << double_2_neg << " = " << TF[double_2 > double_2_neg] << endl;
  cout << double_2 << " > " << double_3_neg << " = " << TF[double_2 > double_3_neg] << endl;
  cout << double_2 << " > " << double_4_neg << " = " << TF[double_2 > double_4_neg] << endl;
  cout << double_2 << " > " << double_5_neg << " = " << TF[double_2 > double_5_neg] << endl;

  cout << endl;
  cout << double_3 << " > " << double_1 << " = " << TF[double_3 > double_1] << endl;
  cout << double_3 << " > " << double_2 << " = " << TF[double_3 > double_2] << endl;
  cout << double_3 << " > " << double_3 << " = " << TF[double_3 > double_3] << endl;
  cout << double_3 << " > " << double_4 << " = " << TF[double_3 > double_4] << endl;
  cout << double_3 << " > " << double_5 << " = " << TF[double_3 > double_5] << endl;

  cout << double_3 << " > " << double_1_neg << " = " << TF[double_3 > double_1_neg] << endl;
  cout << double_3 << " > " << double_2_neg << " = " << TF[double_3 > double_2_neg] << endl;
  cout << double_3 << " > " << double_3_neg << " = " << TF[double_3 > double_3_neg] << endl;
  cout << double_3 << " > " << double_4_neg << " = " << TF[double_3 > double_4_neg] << endl;
  cout << double_3 << " > " << double_5_neg << " = " << TF[double_3 > double_5_neg] << endl;

  cout << endl;
  cout << double_4 << " > " << double_1 << " = " << TF[double_4 > double_1] << endl;
  cout << double_4 << " > " << double_2 << " = " << TF[double_4 > double_2] << endl;
  cout << double_4 << " > " << double_3 << " = " << TF[double_4 > double_3] << endl;
  cout << double_4 << " > " << double_4 << " = " << TF[double_4 > double_4] << endl;
  cout << double_4 << " > " << double_5 << " = " << TF[double_4 > double_5] << endl;

  cout << double_4 << " > " << double_1_neg << " = " << TF[double_4 > double_1_neg] << endl;
  cout << double_4 << " > " << double_2_neg << " = " << TF[double_4 > double_2_neg] << endl;
  cout << double_4 << " > " << double_3_neg << " = " << TF[double_4 > double_3_neg] << endl;
  cout << double_4 << " > " << double_4_neg << " = " << TF[double_4 > double_4_neg] << endl;
  cout << double_4 << " > " << double_5_neg << " = " << TF[double_4 > double_5_neg] << endl;

  cout << endl;
  cout << double_5 << " > " << double_1 << " = " << TF[double_5 > double_1] << endl;
  cout << double_5 << " > " << double_2 << " = " << TF[double_5 > double_2] << endl;
  cout << double_5 << " > " << double_3 << " = " << TF[double_5 > double_3] << endl;
  cout << double_5 << " > " << double_4 << " = " << TF[double_5 > double_4] << endl;
  cout << double_5 << " > " << double_5 << " = " << TF[double_5 > double_5] << endl;

  cout << double_5 << " > " << double_1_neg << " = " << TF[double_5 > double_1_neg] << endl;
  cout << double_5 << " > " << double_2_neg << " = " << TF[double_5 > double_2_neg] << endl;
  cout << double_5 << " > " << double_3_neg << " = " << TF[double_5 > double_3_neg] << endl;
  cout << double_5 << " > " << double_4_neg << " = " << TF[double_5 > double_4_neg] << endl;
  cout << double_5 << " > " << double_5_neg << " = " << TF[double_5 > double_5_neg] << endl;

  cout << endl;
  cout << double_1_neg << " > " << double_1 << " = " << TF[double_1_neg > double_1] << endl;
  cout << double_1_neg << " > " << double_2 << " = " << TF[double_1_neg > double_2] << endl;
  cout << double_1_neg << " > " << double_3 << " = " << TF[double_1_neg > double_3] << endl;
  cout << double_1_neg << " > " << double_4 << " = " << TF[double_1_neg > double_4] << endl;
  cout << double_1_neg << " > " << double_5 << " = " << TF[double_1_neg > double_5] << endl;

  cout << double_1_neg << " > " << double_1_neg << " = " << TF[double_1_neg > double_1_neg] << endl;
  cout << double_1_neg << " > " << double_2_neg << " = " << TF[double_1_neg > double_2_neg] << endl;
  cout << double_1_neg << " > " << double_3_neg << " = " << TF[double_1_neg > double_3_neg] << endl;
  cout << double_1_neg << " > " << double_4_neg << " = " << TF[double_1_neg > double_4_neg] << endl;
  cout << double_1_neg << " > " << double_5_neg << " = " << TF[double_1_neg > double_5_neg] << endl;

  cout << endl;
  cout << double_2_neg << " > " << double_1 << " = " << TF[double_2_neg > double_1] << endl;
  cout << double_2_neg << " > " << double_2 << " = " << TF[double_2_neg > double_2] << endl;
  cout << double_2_neg << " > " << double_3 << " = " << TF[double_2_neg > double_3] << endl;
  cout << double_2_neg << " > " << double_4 << " = " << TF[double_2_neg > double_4] << endl;
  cout << double_2_neg << " > " << double_5 << " = " << TF[double_2_neg > double_5] << endl;

  cout << double_2_neg << " > " << double_1_neg << " = " << TF[double_2_neg > double_1_neg] << endl;
  cout << double_2_neg << " > " << double_2_neg << " = " << TF[double_2_neg > double_2_neg] << endl;
  cout << double_2_neg << " > " << double_3_neg << " = " << TF[double_2_neg > double_3_neg] << endl;
  cout << double_2_neg << " > " << double_4_neg << " = " << TF[double_2_neg > double_4_neg] << endl;
  cout << double_2_neg << " > " << double_5_neg << " = " << TF[double_2_neg > double_5_neg] << endl;

  cout << endl;
  cout << double_3_neg << " > " << double_1 << " = " << TF[double_3_neg > double_1] << endl;
  cout << double_3_neg << " > " << double_2 << " = " << TF[double_3_neg > double_2] << endl;
  cout << double_3_neg << " > " << double_3 << " = " << TF[double_3_neg > double_3] << endl;
  cout << double_3_neg << " > " << double_4 << " = " << TF[double_3_neg > double_4] << endl;
  cout << double_3_neg << " > " << double_5 << " = " << TF[double_3_neg > double_5] << endl;

  cout << double_3_neg << " > " << double_1_neg << " = " << TF[double_3_neg > double_1_neg] << endl;
  cout << double_3_neg << " > " << double_2_neg << " = " << TF[double_3_neg > double_2_neg] << endl;
  cout << double_3_neg << " > " << double_3_neg << " = " << TF[double_3_neg > double_3_neg] << endl;
  cout << double_3_neg << " > " << double_4_neg << " = " << TF[double_3_neg > double_4_neg] << endl;
  cout << double_3_neg << " > " << double_5_neg << " = " << TF[double_3_neg > double_5_neg] << endl;

  cout << endl;
  cout << double_4_neg << " > " << double_1 << " = " << TF[double_4_neg > double_1] << endl;
  cout << double_4_neg << " > " << double_2 << " = " << TF[double_4_neg > double_2] << endl;
  cout << double_4_neg << " > " << double_3 << " = " << TF[double_4_neg > double_3] << endl;
  cout << double_4_neg << " > " << double_4 << " = " << TF[double_4_neg > double_4] << endl;
  cout << double_4_neg << " > " << double_5 << " = " << TF[double_4_neg > double_5] << endl;

  cout << double_4_neg << " > " << double_1_neg << " = " << TF[double_4_neg > double_1_neg] << endl;
  cout << double_4_neg << " > " << double_2_neg << " = " << TF[double_4_neg > double_2_neg] << endl;
  cout << double_4_neg << " > " << double_3_neg << " = " << TF[double_4_neg > double_3_neg] << endl;
  cout << double_4_neg << " > " << double_4_neg << " = " << TF[double_4_neg > double_4_neg] << endl;
  cout << double_4_neg << " > " << double_5_neg << " = " << TF[double_4_neg > double_5_neg] << endl;

  cout << endl;
  cout << double_5_neg << " > " << double_1 << " = " << TF[double_5_neg > double_1] << endl;
  cout << double_5_neg << " > " << double_2 << " = " << TF[double_5_neg > double_2] << endl;
  cout << double_5_neg << " > " << double_3 << " = " << TF[double_5_neg > double_3] << endl;
  cout << double_5_neg << " > " << double_4 << " = " << TF[double_5_neg > double_4] << endl;
  cout << double_5_neg << " > " << double_5 << " = " << TF[double_5_neg > double_5] << endl;

  cout << double_5_neg << " > " << double_1_neg << " = " << TF[double_5_neg > double_1_neg] << endl;
  cout << double_5_neg << " > " << double_2_neg << " = " << TF[double_5_neg > double_2_neg] << endl;
  cout << double_5_neg << " > " << double_3_neg << " = " << TF[double_5_neg > double_3_neg] << endl;
  cout << double_5_neg << " > " << double_4_neg << " = " << TF[double_5_neg > double_4_neg] << endl;
  cout << double_5_neg << " > " << double_5_neg << " = " << TF[double_5_neg > double_5_neg] << endl;
  return 0;
}
