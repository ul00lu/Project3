// GroupDescriptor.cpp
#include "GroupDescriptor.h"
#include <iostream>

GroupDescriptor::GroupDescriptor(const std::string& groupIndex, int departmentNumber, int duration)
    : groupIndex(groupIndex), departmentNumber(departmentNumber), duration(duration) {}

const std::string& GroupDescriptor::getGroupIndex() const {
    return groupIndex;
}

int GroupDescriptor::getDepartmentNumber() const {
    return departmentNumber;
}

int GroupDescriptor::getDuration() const {
    return duration;
}

void GroupDescriptor::displayInfo() const {
    std::cout << "Group Index: " << groupIndex << std::endl;
    std::cout << "Department Number: " << departmentNumber << std::endl;
    std::cout << "Duration: " << duration << " years" << std::endl;
}
