#include "Admin.h"

Admin::Admin(vector<Question>& qs) : questions(qs) {}

// delete question by index
void Admin::removeQuestion(int index) {
    if (index >= 0 && index < questions.size()) {
        questions.erase(questions.begin() + index);
        cout << "Question removed successfully." << endl;
    } 
    else {
        cout << "Invalid question index." << endl;
    }
}

// edit question by index
void Admin::editQuestion(int index, const std::string& newQuestionText) {
    if (index >= 0 && index < questions.size()) {
        questions[index].setQuestionText(newQuestionText);
        cout << "Question edited successfully." << endl;
    } 
    else {
        cout << "Invalid question index." << endl;
    }
}

// clear all questions
void Admin::clearAllQuestions() {
    questions.clear();
    cout << "All questions cleared successfully." << endl;
}
 
// run admin panel
void Admin::run() {
    int option;
    do {
        cout << "\nAdmin Panel:\n";
        cout << "1. Remove question\n";
        cout << "2. Edit question\n";
        cout << "3. Clear all questions\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        if (option == 1) {
            cout << "Enter question index to remove: ";
            int index;
            cin >> index;
            removeQuestion(index - 1); 
        } 
        else if (option == 2) {
            cout << "Enter question index to edit: ";
            int index;
            cin >> index;
            cout << "Enter new question text: ";
            cin.ignore(); 
            string newQuestionText;
            getline(cin, newQuestionText);
            editQuestion(index - 1, newQuestionText);
        } 
        else if (option == 3) {
            clearAllQuestions();
        }
    } while (option != 4);
}
