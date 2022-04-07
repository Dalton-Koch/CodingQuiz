#include <string>

#ifndef QuizQuestionInterface_h
#define QuizQuestionInterface_h

class QuizQuestionInterface
{
public:
  QuizQuestionInterface(){};
  virtual void DisplayTestDescription() = 0;
  virtual bool SetDataSet(std::string aDataSet) = 0;
  virtual void RunTest() = 0;

private:
  bool mUseDefauoltDataSet{true};
};

#endif