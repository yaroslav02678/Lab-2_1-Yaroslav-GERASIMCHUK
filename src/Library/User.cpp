#include "User.h"

// Constructor
User::User(string& newName, string& newPassword) : name(newName), password(newPassword) {}

// Getters
string User::getName() const { return name; }

// Getters
string User::getPassword() const { return password; }