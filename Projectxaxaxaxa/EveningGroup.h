#ifndef EVENING_GROUP_H
#define EVENING_GROUP_H

#include "GroupDescriptor.h"
#include <string>

class EveningGroup : public GroupDescriptor {
public:
    EveningGroup(const std::string& groupIndex, int departmentNumber, int duration,
        const std::string& studentContingent, const std::string& graduateQualification);

    std::string getFormOfStudy() const override;
    int getStudentCount() const override;
    void setStudentCount(int count) override;
    void displayInfo() const override;

    // New methods to get and set student contingent and graduate qualification
    std::string getStudentContingent() const;
    void setStudentContingent(const std::string& contingent);

    std::string getGraduateQualification() const;
    void setGraduateQualification(const std::string& qualification);

private:
    std::string studentContingent;
    std::string graduateQualification;
};

#endif
