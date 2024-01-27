#include "EveningGroup.h"
#include <iostream>

EveningGroup::EveningGroup(const std::string& groupIndex, int departmentNumber, int duration,
    const std::string& studentContingent, const std::string& graduateQualification)
    : GroupDescriptor(groupIndex, departmentNumber, duration),
    studentContingent(studentContingent), graduateQualification(graduateQualification) {}

std::string EveningGroup::getFormOfStudy() const {
    return "Evening";
}

int EveningGroup::getStudentCount() const {
    return 0; // Placeholder, as it was not specified in the problem statement
}

void EveningGroup::setStudentCount(int count) {
    // Placeholder, as it was not specified in the problem statement
}

void EveningGroup::displayInfo() const {
    GroupDescriptor::displayInfo();
    std::cout << "Form of Study: " << getFormOfStudy() << std::endl;
    std::cout << "Student Contingent: " << studentContingent << std::endl;
    std::cout << "Graduate Qualification: " << graduateQualification << std::endl;
}

// Implementing getters and setters for studentContingent and graduateQualification

std::string EveningGroup::getStudentContingent() const {
    return studentContingent;
}

void EveningGroup::setStudentContingent(const std::string& contingent) {
    studentContingent = contingent;
}

std::string EveningGroup::getGraduateQualification() const {
    return graduateQualification;
}

void EveningGroup::setGraduateQualification(const std::string& qualification) {
    graduateQualification = qualification;
}
