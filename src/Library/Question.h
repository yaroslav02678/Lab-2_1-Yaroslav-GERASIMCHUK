#ifndef QUESTION_H
#define QUESTION_H

#include "User.h"
#include <map>
#include <fstream>

class Question {
private:
    string author;
    string questionText;
    map<int, string> answers;
    ofstream question;
    bool isQuestionOpen;
public:
    Question(const string authorName, const string& questionText, bool newISQuestionOpen);
    void addAnswer(int id, string answer, bool isQuestionOpen);
    void displayQuestion() const;
    void displayAnswers() const;
    void setQuestionText(const string& newQuestionText);
};

#endif