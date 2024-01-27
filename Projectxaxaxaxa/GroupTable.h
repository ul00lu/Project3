#ifndef GROUP_TABLE_H
#define GROUP_TABLE_H

#include <vector>
#include <memory>
#include <string>
#include "GroupDescriptor.h"

class GroupTable {
public:
    void addGroup(std::shared_ptr<GroupDescriptor> group);
    void deleteGroup(const std::string& groupIndex);
    std::shared_ptr<GroupDescriptor> findGroup(const std::string& groupIndex) const;
    void displayAllGroups() const;

    // New methods to display groups from a specific department and calculate total income
    void displayGroupsByDepartment(int departmentNumber) const;
    double calculateTotalIncome(double budgetStudentIncome) const;

private:
    std::vector<std::shared_ptr<GroupDescriptor>> groups;
};

#endif
