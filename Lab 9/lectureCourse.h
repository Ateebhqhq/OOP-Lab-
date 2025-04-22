#ifndef LECTURECOURSE_H
#define LECTURECOURSE_H

#include "Course.h"
#include <iostream>

class LectureCourse : public Course {
public:
    LectureCourse(string c, int cr) : Course(c, cr) {}
    void calculateGrade() override;
    void displayInfo() override;
};

#endif