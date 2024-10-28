#ifndef SOFTWARE_ENGINEERING_STUDENT_H
#define SOFTWARE_ENGINEERING_STUDENT_H

#include "User.h"

class SoftwareEngineeringStudent : public User{
    string course;
    string Uni;
    string position;
    fstream baseOfUsers;
    bool writeToFile;

public:
    SoftwareEngineeringStudent(string newName, string newPassword,
    string newCourse, string newUni, string newPosition, bool newWriteToFile);

    void aboutAuthor() override;

    string getCourse();
    string getUni();
    string getPosition();
};

#endif