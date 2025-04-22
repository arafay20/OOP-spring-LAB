
#include <iostream>
#include "LectureCourse.h"
#include "LabCourse.h"

int main() {
    LectureCourse lec("CS101", 3);
    LabCourse lab("CS102L", 1);

    Course*c1=&lec;
    c1->displayInfo();
    c1->calculateGrade();
    c1 =&lab;
    c1->displayInfo();
    c1->calculateGrade();
	}
