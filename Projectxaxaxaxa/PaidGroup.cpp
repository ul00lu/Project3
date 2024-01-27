#include "PaidGroup.h"
#include <iostream>

PaidGroup::PaidGroup(const std::string& groupIndex, int departmentNumber, int duration, int contractNumber, double tuitionFee)
    : GroupDescriptor(groupIndex, departmentNumber, duration),
    contractNumber(contractNumber), tuitionFee(tuitionFee) {}

std::string PaidGroup::getFormOfStudy() const {
    return "Paid";
}

int PaidGroup::getStudentCount() const {
    return 0; // Placeholder, as it was not specified in the problem statement
}

void PaidGroup::setStudentCount(int count) {
    // Placeholder, as it was not specified in the problem statement
}

void PaidGroup::displayInfo() const {
    GroupDescriptor::displayInfo();
    std::cout << "Form of Study: " << getFormOfStudy() << std::endl;
    std::cout << "Contract Number: " << contractNumber << std::endl;
    std::cout << "Tuition Fee: $" << tuitionFee << std::endl;
}

// Implementing getters and setters for tuition fee and contract number

double PaidGroup::getTuitionFee() const {
    return tuitionFee;
}

void PaidGroup::setTuitionFee(double fee) {
    tuitionFee = fee;
}

int PaidGroup::getContractNumber() const {
    return contractNumber;
}

void PaidGroup::setContractNumber(int number) {
    contractNumber = number;
}
