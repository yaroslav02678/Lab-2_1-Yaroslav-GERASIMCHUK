#include "library/SoftwareEngineeringStudent.h"
#include "library/ComputerEngineeringStudent.h"
#include "library/CyberSecurityStudent.h"
#include "library/Question.h"
#include "library/Admin.h"

vector<SoftwareEngineeringStudent> softwareStudents;
vector<ComputerEngineeringStudent> computerStudents;
vector<CyberSecurityStudent> cyberStudents;
vector<Question> questions;
map<int, string> answers;

string line;

// Function to write users from file
void writeUsers() {
    ifstream baseOfUsers("baseOfUsers.txt");
    string newName, newPassword, newCourse, newUni, newPosition;

    while (getline(baseOfUsers, line)) {
        stringstream ss(line);
        ss >> newName >> newPassword >> newPosition >> newCourse >> newUni;

        if (newPosition == "SoftwareEngineeringStudent") softwareStudents.emplace_back(newName, newPassword, newCourse, newUni, newPosition, false);
        else if (newPosition == "ComputerEngineeringStudent") computerStudents.emplace_back(newName, newPassword, newCourse, newUni, newPosition, false);
        else if (newPosition == "CyberSecurityStudent") cyberStudents.emplace_back(newName, newPassword, newCourse, newUni, newPosition, false);
    }
}

// Function to write questions from file
void writeQuestions() {
    ifstream questionAndAnswers("QuestionsAndAnswers.txt");
    if (!questionAndAnswers.is_open()) {
        cerr << "Failed to open QuestionsAndAnswers.txt" << endl;
        return;
    }

    string authorName, questionText, line, ignore, answerText;
    int id;

    while (getline(questionAndAnswers, line)) {
        if (line.find("Author: ") == 0) {
            authorName = line.substr(8);
        }
        
        if (line.find("Question created: ") == 0) {
            questionText = line.substr(18);
            questions.emplace_back(authorName, questionText, false);
        }

        if (line.find("Added answer: ") == 0) {
            stringstream ss(line);
            ss >> ignore >> ignore >> id >> answerText;
            questions.back().addAnswer(id, answerText, false);
        }
    }
}

// Function to check if user exists
bool check(const string& name, const string& password) {
    for (const auto& student : softwareStudents) 
        if (student.getName() == name && student.getPassword() == password) return true;
    for (const auto& student : computerStudents) 
        if (student.getName() == name && student.getPassword() == password) return true;
    for (const auto& student : cyberStudents)
        if (student.getName() == name && student.getPassword() == password) return true;
    
    cout << "Invalid name or password. Please try again." << endl;
    return false;
}

// Main function
int main() {
    writeUsers();
    writeQuestions();

    int choice = 0;

    while(choice != 3) {
        cout << "1. Log in" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        if(choice == 1) {
            cout << "Enter your name: : ";
            cin.ignore(); string newName; cin >> newName; int choice;
            cout << "Enter your password: "; string newPassword; cin >> newPassword;
            if (newName == "Admin" && newPassword == "Admin") {
                Admin admin(questions);
                admin.run();
            }
            else
            if(check(newName, newPassword)) {
                int newChoice = 0;
                while(newChoice != 4) {
                    cout << "1. Ask a question" << endl;
                    cout << "2. Answer a question" << endl;
                    cout << "3. View answers to my question" << endl;
                    cout << "4. Log out" << endl;
                    cout << "Enter your choice (1-4): ";
                    cin >> newChoice;

                    if (newChoice == 1) {
                        string questionText;
                        cout << "Enter your question: "; cin.ignore(); getline(cin, questionText);
                        questions.emplace_back(newName, questionText, true);
                    } 
                    else if(newChoice == 2) {
                        if (questions.empty()) {
                            cout << "No questions available for answering." << endl;
                            continue;
                        }
                        for (size_t i = 0; i < questions.size(); ++i) {
                            cout << i + 1 << ". ";
                            questions[i].displayQuestion();
                        }
                        cout << "Choose the question number you want to answer: "; cin >> choice;
                        cout << "Enter id of your answer: "; int id; cin >> id;
                        cout << "Enter your answer: "; string answer; cin.ignore(); getline(cin, answer);
                        questions[choice - 1].addAnswer(id, answer, true);
                    } 
                    else if(newChoice == 3) {
                        cout << "Your questions and answers:" << endl;
                        for (const auto& question : questions) {
                            question.displayQuestion();
                            question.displayAnswers();
                        }
                    }
                }
            }
        } 
        else if (choice == 2) {
            string newName, newPosition, newUni, newPassword;
            int newCourse;

            cout << "What is your specialization:" << endl
                 << "1. Software Engineering" << endl
                 << "2. Computer Engineering" << endl
                 << "3. Cyber Security" << endl;
            cin >> choice;

            if (choice == 1) newPosition = "SoftwareEngineeringStudent";
            else if (choice == 2) newPosition = "ComputerEngineeringStudent";
            else if (choice == 3) newPosition = "CyberSecurityStudent";
            else {
                cout << "Invalid choice. Please try again." << endl;
                break;;
            }

            cout << "Enter your name: "; cin.ignore(); getline(cin, newName);
            cout << "Enter your course: "; cin >> newCourse;
            cout << "Enter your university: "; cin.ignore(); getline(cin, newUni);
            cout << "Enter your password: "; getline(cin, newPassword);

            if(choice == 1) {
                softwareStudents.emplace_back(newName, newPassword, to_string(newCourse), newUni, newPosition, true);
            } 
            else if(choice == 2) {
                computerStudents.emplace_back(newName, newPassword, to_string(newCourse), newUni, newPosition, true);
            } 
            else if(choice == 3) {
                cyberStudents.emplace_back(newName, newPassword, to_string(newCourse), newUni, newPosition, true);
            }
        }
    }
}
