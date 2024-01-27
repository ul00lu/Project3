#include "GroupTable.h"
#include <iostream>
#include <algorithm>
#include <typeinfo>
#include "DaytimeGroup.h"
#include "EveningGroup.h"
#include "PaidGroup.h"

void GroupTable::addGroup(std::shared_ptr<GroupDescriptor> group) {
    groups.push_back(group);
}

void GroupTable::deleteGroup(const std::string& groupIndex) {
    auto it = std::remove_if(groups.begin(), groups.end(),
        [&groupIndex](const std::shared_ptr<GroupDescriptor>& group) {
            return group->getGroupIndex() == groupIndex;
        });

    if (it != groups.end()) {
        groups.erase(it, groups.end());
    }
}

std::shared_ptr<GroupDescriptor> GroupTable::findGroup(const std::string& groupIndex) const {
    for (const auto& group : groups) {
        if (group->getGroupIndex() == groupIndex) {
            return group;
        }
    }
    return nullptr;
}

void GroupTable::displayAllGroups() const {
    for (const auto& group : groups) {
        group->displayInfo();
        std::cout << std::endl;
    }
}

void GroupTable::displayGroupsByDepartment(int departmentNumber) const {
    for (const auto& group : groups) {
        if (group->getDepartmentNumber() == departmentNumber) {
            group->displayInfo();
            std::cout << std::endl;
        }
    }
}

double GroupTable::calculateTotalIncome(double budgetStudentIncome) const {
    double totalIncome = 0.0;
    for (const auto& group : groups) {
        // Implement income calculation logic here
        // Example:
        // if (dynamic_cast<DaytimeGroup*>(group.get()) != nullptr) {
        //     totalIncome += budgetStudentIncome;
        // }
        // if (auto paidGroup = dynamic_cast<PaidGroup*>(group.get())) {
        //     totalIncome += paidGroup->getTuitionFee();
        // }
    }
    return totalIncome;
}
