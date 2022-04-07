#include "QuizQuestionInterface.hpp"

#include <string>
#include <vector>

#ifndef QUIZNAVIGATOR_H
#define QUIZNAVIGATOR_H

class QuizNavigator
{
public:
  QuizNavigator();

  void RunQuiz();

private:
  bool HandleCommand(std::string &aCommandInput);
  void PrintQuestions();
  void PrintHelp();

  std::vector<QuizQuestionInterface *> mQuestionList;
  bool mExitProg{false};
};

#endif