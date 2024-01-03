#include <iostream>
#include <math.h>
#include <string>
using namespace std;


int main(int argc, char *argv[]) { 
  string digits[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  string tenths[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
  string powers[11] = {"hundred", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion", "octillion"};
  
  string number;
  cin >> number; 
  int length = number.length();
  for (int i = 0; i < number.length(); i++) {
    if (number[i] != 0){
      if (length - i > 2){
        cout << digits[number[i] - '0' - 1] << " " << powers[length - i - 3] << " ";
      } else if (length - i == 2){
        cout << tenths[number[i] - '0'] << " ";
      } else {
        cout << digits[number[i] - '0' - 1] << " ";
      }
    }
  }

  return 0;
}
