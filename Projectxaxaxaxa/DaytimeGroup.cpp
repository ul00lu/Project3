#include "DaytimeGroup.h"
#include <iostream>

DaytimeGroup::DaytimeGroup(const std::string& groupIndex, int departmentNumber, int duration,
    const std::string& specialization, double scholarship, int scholarshipStudents)
    : GroupDescriptor(groupIndex, departmentNumber, duration),
    specialization(specialization), scholarship(scholarship), scholarshipStudents(scholarshipStudents) {}

std::string DaytimeGroup::getFormOfStudy() const {
    return "Daytime";
}

int DaytimeGroup::getStudentCount() const {
    return scholarshipStudents;
}

void DaytimeGroup::setStudentCount(int count) {
    scholarshipStudents = count;
}

void DaytimeGroup::displayInfo() const {
    GroupDescriptor::displayInfo();
    std::cout << "Form of Study: " << getFormOfStudy() << std::endl;
    std::cout << "Specialization: " << specialization << std::endl;
    std::cout << "Scholarship: $" << scholarship << std::endl;
    std::cout << "Scholarship Students: " << scholarshipStudents << std::endl;
}

// Implementing getters and setters for scholarship details

double DaytimeGroup::getScholarshipAmount() const {
    return scholarship;
}

void DaytimeGroup::setScholarshipAmount(double amount) {
    scholarship = amount;
}

int DaytimeGroup::getScholarshipStudents() const {
    return scholarshipStudents;
}

void DaytimeGroup::setScholarshipStudents(int count) {
    scholarshipStudents = count;
}
