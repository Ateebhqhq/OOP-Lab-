#ifndef LABCOURSE_H
#define LABCOURSE_H

#include "Course.h"
#include <iostream>

class LabCourse : public Course {
public:
    LabCourse(string c, int cr) : Course(c, cr) {}
    void calculateGrade() override;
    void displayInfo() override;
};

#endif