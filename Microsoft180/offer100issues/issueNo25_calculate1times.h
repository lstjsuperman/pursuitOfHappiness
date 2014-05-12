#ifndef __ISSUE_NO25__
#define __ISSUE_NO25__

namespace NO25 {

int NumberOf1(const char* strN);
int PowerBase10(unsigned int n);

/////////////////////////////////////////////////////////////////////////////
// Find the number of 1 in an integer with radix 10
// Input: n - an integer
// Output: the number of 1 in n with radix
/////////////////////////////////////////////////////////////////////////////
int NumberOf1BeforeBetween1AndN_Solution2(int n)
{
      if(n <= 0)
            return 0;

      // convert the integer into a string
      char strN[50];
      sprintf(strN, "%d", n);

      return NumberOf1(strN);
}


/////////////////////////////////////////////////////////////////////////////
// Find the number of 1 in an integer with radix 10
// Input: strN - a string, which represents an integer
// Output: the number of 1 in n with radix
/////////////////////////////////////////////////////////////////////////////
int NumberOf1(const char* strN)
{
      if(!strN || *strN < '0' || *strN > '9' || *strN == '\0')
            return 0;

      int firstDigit = *strN - '0';
      unsigned int length = static_cast<unsigned int>(strlen(strN));

      // the integer contains only one digit
      if(length == 1 && firstDigit == 0)
            return 0;

      if(length == 1 && firstDigit > 0)
            return 1;

      // suppose the integer is 21345
      // numFirstDigit is the number of 1 of 10000-19999 due to the first digit
      int numFirstDigit = 0;
      // numOtherDigits is the number of 1 01346-21345 due to all digits
      // except the first one
      int numOtherDigits = firstDigit * (length - 1) * PowerBase10(length - 2);
      // numRecursive is the number of 1 of integer 1345
      int numRecursive = NumberOf1(strN + 1);

      // if the first digit is greater than 1, suppose in integer 21345
      // number of 1 due to the first digit is 10^4. It's 10000-19999
      if(firstDigit > 1)
            numFirstDigit = PowerBase10(length - 1);

      // if the first digit equals to 1, suppose in integer 12345
      // number of 1 due to the first digit is 2346. It's 10000-12345
      else if(firstDigit == 1)
            numFirstDigit = atoi(strN + 1) + 1;

      return numFirstDigit + numOtherDigits + numRecursive;
}

/////////////////////////////////////////////////////////////////////////////
// Calculate 10^n
/////////////////////////////////////////////////////////////////////////////
int PowerBase10(unsigned int n)
{
      int result = 1;
      for(unsigned int i = 0; i < n; ++ i)
            result *= 10;

      return result;
}

void testNumberOfOne() {
    const char* tmpString= "12";
    int ret = NumberOf1(tmpString);
    std::cout << "Result of 1 is :" << ret << std::endl;
}
}

#endif // __ISSUE_NO25__
