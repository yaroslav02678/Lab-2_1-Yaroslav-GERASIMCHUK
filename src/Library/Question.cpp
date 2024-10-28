#include "Question.h"

// Constructor
Question::Question(const string authorName, const string& questionText, bool newIsQuestionOpen ) : author(authorName), questionText(questionText){
    question.open("QuestionsAndAnswers.txt", ios::app);
    if(newIsQuestionOpen == false) {
        return;
    }
    if (!question.is_open()) cerr << "Failed to open log file." << endl;
    else{
        try {
            question << "Author: " << authorName << endl;
            question << "Question created: " << questionText <<  endl;
        } 
        catch (const ofstream::failure& e) {
            cerr << "Exception writing to log file: " << e.what() << endl;
        }
    }
    question.close();
}

// Add answer to the question
void Question::addAnswer(int id, string answer, bool isQuestionOpen) {
    if (!isQuestionOpen) {
        answers[id] = answer;
        return;
    }
    answers[id] = answer;
    if (question.is_open()) {
        try {
            question << "Added answer: " << id << " - " << answer << endl;
        } 
        catch (const ofstream::failure& e) {
            cerr << "Exception writing to log file: " << e.what() << endl;
        }
    }
}

// Display question
void Question::displayQuestion() const {
    try {
        cout << "Question: " << questionText << endl;
    } 
    catch (const exception& e) {
        cerr << "Error displaying question: " << e.what() << endl;
    } 
    catch (...) {
        cerr << "Unknown error occurred while displaying question." << endl;
    }
}

// Display answers
void Question::displayAnswers() const {
    try {
        if (answers.empty()) {
            cout << "No answers available for this question." << endl;
            return;
        }
        for (const auto& answer : answers) {
            cout << answer.first << ": " << answer.second << endl;
        }
    }
    catch (const exception& e) {
        cerr << "Error displaying answers: " << e.what() << endl;
    } 
    catch (...) {
        cerr << "Unknown error occurred while displaying answers." << endl;
    }
}

// Set question text
void Question::setQuestionText(const string& newQuestionText) {
    questionText = newQuestionText;
}