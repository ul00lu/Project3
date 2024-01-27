#include "GroupTable.h"
#include "DaytimeGroup.h"
#include "EveningGroup.h"
#include "PaidGroup.h"
#include <iostream>
#include <memory>
#include <limits>

template <class T>
T getNum(T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max()) {
    T a;
    while (true) {
        std::cin >> a;
        if (std::cin.eof())
            throw std::runtime_error("Failed to read number: EOF");
        else if (std::cin.bad())
            throw std::runtime_error("Failed to read number");
        else if (std::cin.fail() || a < min || a > max) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again: ";
        }
        else
            return a;
    }
}

int main() {
    GroupTable groupTable;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Group" << std::endl;
        std::cout << "2. Delete Group" << std::endl;
        std::cout << "3. Find Group" << std::endl;
        std::cout << "4. Display All Groups" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice = getNum<int>(1, 5);

        switch (choice) {
        case 1: {
            std::cout << "Enter Group Type (1 - Daytime, 2 - Evening, 3 - Paid): ";
            int groupType = getNum<int>(1, 3);

            std::string groupIndex;
            int departmentNumber;
            int duration;

            std::cout << "Enter Group Index: ";
            std::cin >> groupIndex;
            std::cout << "Enter Department Number: ";
            departmentNumber = getNum<int>();
            std::cout << "Enter Duration (in years): ";
            duration = getNum<int>();

            if (groupType == 1) {
                std::string specialization;
                double scholarship;
                int scholarshipStudents;

                std::cout << "Enter Specialization: ";
                std::cin >> specialization;
                std::cout << "Enter Scholarship: ";
                scholarship = getNum<double>();
                std::cout << "Enter Scholarship Students: ";
                scholarshipStudents = getNum<int>();

                std::shared_ptr<GroupDescriptor> group = std::make_shared<DaytimeGroup>(
                    groupIndex, departmentNumber, duration, specialization, scholarship, scholarshipStudents);
                groupTable.addGroup(group);
            }
            else if (groupType == 2) {
                std::string studentContingent;
                std::string graduateQualification;

                std::cout << "Enter Student Contingent: ";
                std::cin >> studentContingent;
                std::cout << "Enter Graduate Qualification: ";
                std::cin >> graduateQualification;

                std::shared_ptr<GroupDescriptor> group = std::make_shared<EveningGroup>(
                    groupIndex, departmentNumber, duration, studentContingent, graduateQualification);
                groupTable.addGroup(group);
            }
            else if (groupType == 3) {
                int contractNumber;
                double tuitionFee;

                std::cout << "Enter Contract Number: ";
                contractNumber = getNum<int>();
                std::cout << "Enter Tuition Fee: ";
                tuitionFee = getNum<double>();

                std::shared_ptr<GroupDescriptor> group = std::make_shared<PaidGroup>(
                    groupIndex, departmentNumber, duration, contractNumber, tuitionFee);
                groupTable.addGroup(group);
            }
            break;
        }
        case 2: {
            std::string groupIndex;
            std::cout << "Enter Group Index to Delete: ";
            std::cin >> groupIndex;
            groupTable.deleteGroup(groupIndex);
            break;
        }
        case 3: {
            std::string groupIndex;
            std::cout << "Enter Group Index to Find: ";
            std::cin >> groupIndex;
            std::shared_ptr<GroupDescriptor> foundGroup = groupTable.findGroup(groupIndex);
            if (foundGroup) {
                foundGroup->displayInfo();
            }
            else {
                std::cout << "Group not found." << std::endl;
            }
            break;
        }
        case 4: {
            std::cout << "All Groups:" << std::endl;
            groupTable.displayAllGroups();
            break;
        }
        case 5:
            return 0;
        }
    }

    return 0;
}

