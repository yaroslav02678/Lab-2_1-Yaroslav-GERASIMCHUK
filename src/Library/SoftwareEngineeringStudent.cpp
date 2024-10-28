#include "SoftwareEngineeringStudent.h"

// Constructor
SoftwareEngineeringStudent::SoftwareEngineeringStudent(string newName, string newPassword,
    string newCourse, string newUni, string newPosition, bool newWriteToFile)
    : User(newName, newPassword), course(newCourse), Uni(newUni), position(newPosition), writeToFile(newWriteToFile)  {
    if (newName.empty() || newPassword.empty() || newCourse.empty() || newUni.empty() || newPosition.empty()) {
        throw invalid_argument("Arguments cannot be empty");
    }
    if(newWriteToFile == false){
        return;
    }
    if (writeToFile) {
        try {
            baseOfUsers.open("baseOfUsers.txt", ios::out | ios::app);
            if (!baseOfUsers) {
                throw runtime_error("Unable to open file");
            }
            baseOfUsers << left << setw(20) << newName   
                        << setw(20) << newPassword 
                        << setw(30) << newPosition 
                        << setw(5) << newCourse 
                        << setw(10) << newUni << endl;
            baseOfUsers.close();
        } 
        catch (const exception &e) {
            cerr << "Exception: " << e.what() << endl;
        }
    }
}

// Display information about the author
void SoftwareEngineeringStudent::aboutAuthor() {
    cout << "Name: " << getName() << endl
         << "Specialization: " << getPosition() << endl
         << "Course: " << getCourse() << endl
         << "University: " << getUni() << endl;     
}

// Getters
string SoftwareEngineeringStudent::getCourse() {
    return course;
}

// Getters
string SoftwareEngineeringStudent::getUni() {
    return Uni;
}

// Getters
string SoftwareEngineeringStudent::getPosition() {
    return position;
}   