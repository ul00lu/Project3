// GroupDescriptor.h
#ifndef GROUP_DESCRIPTOR_H
#define GROUP_DESCRIPTOR_H

#include <string>

class GroupDescriptor {
public:
    GroupDescriptor(const std::string& groupIndex, int departmentNumber, int duration);
    virtual ~GroupDescriptor() = default;

    const std::string& getGroupIndex() const;
    int getDepartmentNumber() const;
    int getDuration() const;

    virtual std::string getFormOfStudy() const = 0;
    virtual int getStudentCount() const = 0;
    virtual void setStudentCount(int count) = 0;

    virtual void displayInfo() const;

private:
    std::string groupIndex;
    int departmentNumber;
    int duration;
};

#endif
