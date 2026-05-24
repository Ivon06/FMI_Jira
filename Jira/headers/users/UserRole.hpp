#pragma once

#include <string>
#include <stdexcept>


enum class UserRole {
    Student,
    TeachingAssistant,
    Lecturer,
    Administrator
};

inline UserRole stringToRole(const std::string& roleStr) {
    if (roleStr == "Student") return UserRole::Student;
    if (roleStr == "TeachingAssistant") return UserRole::TeachingAssistant;
    if (roleStr == "Lecturer") return UserRole::Lecturer;
    if (roleStr == "Administrator") return UserRole::Administrator;
    throw std::invalid_argument("Unknown user role: " + roleStr);
}

inline std::string roleToString(UserRole role) {
    switch (role) {
    case UserRole::Student: return "Student";
    case UserRole::TeachingAssistant: return "TeachingAssistant";
    case UserRole::Lecturer: return "Lecturer";
    case UserRole::Administrator: return "Administrator";
    }
    return "Unknown";
}