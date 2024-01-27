#ifndef PAID_GROUP_H
#define PAID_GROUP_H

#include "GroupDescriptor.h"
#include <string>

class PaidGroup : public GroupDescriptor {
public:
    PaidGroup(const std::string& groupIndex, int departmentNumber, int duration, int contractNumber, double tuitionFee);

    std::string getFormOfStudy() const override;
    int getStudentCount() const override;
    void setStudentCount(int count) override;
    void displayInfo() const override;

    // New methods to get and set tuition fee and contract number
    double getTuitionFee() const;
    void setTuitionFee(double fee);
    int getContractNumber() const;
    void setContractNumber(int number);

private:
    int contractNumber;
    double tuitionFee;
};

#endif
