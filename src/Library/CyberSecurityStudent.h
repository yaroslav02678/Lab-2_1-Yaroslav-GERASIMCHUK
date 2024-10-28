#ifndef CYBER_SECURITY_STUDENT_H
#define CYBER_SECURITY_STUDENT_H

#include "User.h"

class CyberSecurityStudent : public User {
private:
    string course;
    string Uni;
    string position;
    fstream baseOfUsers;
    bool writeToFile;

public:
    CyberSecurityStudent(string newName, string newPassword,
    string newCourse, string newUni, string newPosition, bool newWriteToFile);

    void aboutAuthor() override;

    string getCourse();
    string getUni();
    string getPosition();
};

#endif 
