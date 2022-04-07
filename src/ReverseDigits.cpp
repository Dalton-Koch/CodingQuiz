#include "ReverseDigits.hpp"

#include <iostream>
#include <sstream>
#include <math.h>

// https://leetcode.com/problems/reverse-integer/

ReverseDigits::ReverseDigits()
{
  mTestValues.push_back(123);
  mTestValues.push_back(321);
}

void ReverseDigits::DisplayTestDescription()
{
  std::cout << "\tGiven a signed 32-bit integer x, return x with its digits reversed.";
  std::cout << "If reversing x causes the value to go outside the signed 32 - bit integer range[-231, 231 - 1], then return 0.\n";
}

bool ReverseDigits::SetDataSet(std::string aDataSet)
{
  std::istringstream is(aDataSet);
  std::string part;

  while (std::getline(is, part, ','))
  {
    char *p;
    int testId = strtol(part.c_str(), &p, 10);
    if (0 == testId)
    {
      return false;
    }
    else
    {
      mTestValues.push_back(testId);
    }
  }
  return true;
}

void ReverseDigits::RunTest()
{
  for (auto &value : mTestValues)
  {
    int result = Reverse(value);
    std::cout << "Input: " + std::to_string(value) + "\tOutput: " + std::to_string(result) + "\tTest Finished!\n\n";
  }
}

int ReverseDigits::Reverse(int x)
{
  int sign = (x > 0) ? 1 : -1;
  std::string numberString = std::to_string(abs(x));
  int numberOfDidgits = numberString.length();
  long storedValue{abs(x)};
  unsigned long newValue{0};
  int j{0};

  for (int i = numberOfDidgits - 1; i >= 0; i--)
  {
    unsigned long reversedDidgit = storedValue / pow(10.0, static_cast<float>(i));
    storedValue = storedValue % static_cast<unsigned long>(pow(10.0, static_cast<float>(i)));
    newValue += reversedDidgit * pow(10.0, j);
    j++;
  }
  if (newValue >= static_cast<unsigned long>(std::numeric_limits<int>::max()))
  {
    return 0;
  }
  return static_cast<int>(newValue) * sign;
}