#include "QuizQuestionInterface.hpp"

#include <string>
#include <vector>

class ReverseDigits : public QuizQuestionInterface
{
public:
  ReverseDigits();

  void DisplayTestDescription() override;
  bool SetDataSet(std::string aDataSet) override;
  void RunTest() override;

private:
  std::vector<int> mTestValues;

  int Reverse(int x);
};