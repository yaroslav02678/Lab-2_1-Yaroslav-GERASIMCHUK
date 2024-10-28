#ifndef COMPUTER_ENGINEERING_STUDENT_H
#define COMPUTER_ENGINEERING_STUDENT_H

#include "User.h"

class ComputerEngineeringStudent : public User {
private:
    string course;
    string Uni;
    string position;
    fstream baseOfUsers;
    bool writeToFile;

public:
    ComputerEngineeringStudent(string newName, string newPassword,
    string newCourse, string newUni, string newPosition, bool newWriteToFile);

    void aboutAuthor() override;

    string getCourse();
    string getUni();
    string getPosition();
};

#endif 
