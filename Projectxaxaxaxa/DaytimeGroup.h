#ifndef DAYTIME_GROUP_H
#define DAYTIME_GROUP_H

#include "GroupDescriptor.h"
#include <string>

class DaytimeGroup : public GroupDescriptor {
public:
    DaytimeGroup(const std::string& groupIndex, int departmentNumber, int duration,        //конструктор индекс группы , номер профилирующей кафедры  срок обучения , специализация , размер стипендии  и количество студентов, получающих стипендию .
        const std::string& specialization, double scholarship, int scholarshipStudents);

    std::string getFormOfStudy() const override;
    int getStudentCount() const override;
    void setStudentCount(int count) override;
    void displayInfo() const override;

    // Add methods to get and set scholarship details
    double getScholarshipAmount() const;
    void setScholarshipAmount(double amount);
    int getScholarshipStudents() const;
    void setScholarshipStudents(int count);

private:
    std::string specialization;
    double scholarship;
    int scholarshipStudents;
};

#endif
