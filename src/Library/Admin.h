#ifndef ADMIN_H
#define ADMIN_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Question.h"

class Admin {
public:
    Admin(vector<Question>& qs);
    void removeQuestion(int index);
    void editQuestion(int index, const std::string& newQuestionText);
    void clearAllQuestions();
    void run();

private:
    vector<Question>& questions;
    void saveQuestionsToFile();
    void loadQuestionsFromFile();
};

#endif
