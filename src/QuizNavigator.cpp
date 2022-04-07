#include "QuizNavigator.hpp"
#include "ReverseDigits.hpp"

#include <iostream>
#include <sstream>

QuizNavigator::QuizNavigator()
{
  mQuestionList.push_back(new ReverseDigits());
}

void QuizNavigator::PrintQuestions()
{
  std::cout << "/nCoding Quiz Test Bed\n";
  std::cout << "Test Id:\tDescription:\n";

  int i{0};

  for (auto &question : mQuestionList)
  {
    i++;
    std::cout << i << ")\t";
    question->DisplayTestDescription();
    std::cout << "\n\n";
  }
}

void QuizNavigator::RunQuiz()
{
  PrintQuestions();
  while (!mExitProg)
  {
    std::string inputString{""};
    std::cin >> inputString;
    HandleCommand(inputString);
  }
}

bool QuizNavigator::HandleCommand(std::string &aCommandInput)
{
  int testId{0};
  std::istringstream is(aCommandInput);
  std::string part;
  bool firstInputRead{false};

  while (std::getline(is, part, ' '))
  {
    if (!part.compare("exit"))
    {
      mExitProg = true;
    }
    else if (!firstInputRead)
    {
      firstInputRead = true;
      char *p;
      testId = strtol(part.c_str(), &p, 10);
      if (0 == testId || testId > mQuestionList.size())
      {
        PrintHelp();
      }
    }
    else
    {
      if (testId == 0 || testId > mQuestionList.size() || !mQuestionList[testId - 1]->SetDataSet(part))
      {
        PrintHelp();
      }
    }
  }

  if (testId != 0 && testId <= mQuestionList.size())
  {
    mQuestionList[testId - 1]->RunTest();
  }

  return true;
}

void QuizNavigator::PrintHelp()
{
  std::cout << "HELP\n\n";
}
