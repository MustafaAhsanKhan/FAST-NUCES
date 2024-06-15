#include<iostream>
#include "pch.h"
#include "../Lab01/Header.h"
using namespace std;
//question 1
TEST(Reverse, case1) {
    string s = "cat is running";
    ASSERT_EQ("running is cat", reverse_string(s));

}
TEST(Reverse, case2) {
    string s = "This is a car";
    ASSERT_EQ("car a is This", reverse_string(s));

}
//question 2
TEST(Complex, case1) {
    Complex c1 = { 5,3 };
    Complex c2 = { 4,2 };
    Complex c3;
    c3 = c1.addComplex(c1, c2);
    ASSERT_EQ(9, c3.real);
    ASSERT_EQ(5, c3.imaginary);
}
TEST(Complex, case2) {
    Complex c1 = { 2,7 };
    Complex c2 = { 10,6 };
    Complex c3;
    c3 = c1.addComplex(c1, c2);
    ASSERT_EQ(12, c3.real);
    ASSERT_EQ(13, c3.imaginary);
}
//question 3
TEST(Student, getNames) {
    Student s;
    Student* std = new Student[5];
    string name[5] = { "John","karen","Jenny","David","Smith" };
    string roll_no[5] = { "21i-1234","21i-1243","21i-1765","21i-1422","21i-1846" };
    int age[5] = { 18,17,20,18,21 };
    for (int i = 0; i < 5; i++) {
        std[i].Name = name[i];
        std[i].roll_no = roll_no[i];
        std[i].age = age[i];
    }
    string arr1[] = { "John","David" };
    string* arr2 = s.getNames(std);
    for (int i = 0; i < 2; i++) {
        ASSERT_EQ(arr1[i], arr2[i]);
    }

    int age1[5] = { 18,17,20,18,18 };
    for (int i = 0; i < 5; i++) {
        std[i].age = age1[i];
    }
    string arr3[] = { "John","David","Smith" };
    string* arr4 = s.getNames(std);
    for (int i = 0; i < 3; i++) {
        ASSERT_EQ(arr3[i], arr4[i]);
    }
}
TEST(Student, getEvenRollno) {
    Student s;
    Student* std = new Student[5];
    string name[5] = { "John","karen","Jenny","David","Smith" };
    string roll_no[5] = { "21i-1234","21i-1243","21i-1765","21i-1422","21i-1846" };
    int age[5] = { 18,17,20,18,21 };
    for (int i = 0; i < 5; i++) {
        std[i].Name = name[i];
        std[i].roll_no = roll_no[i];
        std[i].age = age[i];
    }
    //Student *std1=new Student[3];
    string name1[3] = { "John","David","Smith" };
    string roll_no1[3] = { "21i-1234","21i-1422","21i-1846" };
    int age1[3] = { 18,18,21 };
    Student* std1 = s.getEvenRollno(std);
    for (int i = 0; i < 3; i++) {
        ASSERT_EQ(std1[i].Name, name1[i]);
        ASSERT_EQ(std1[i].roll_no, roll_no1[i]);
        ASSERT_EQ(std1[i].age, age1[i]);
    }
}
//question 4
TEST(CustomTime, timeToSecs) {
    CustomTime t1 = { 2,0,0 };
    ASSERT_EQ(7200, t1.timeToSecs(t1));
    CustomTime t2 = { 2,40,30 };
    ASSERT_EQ(9630, t2.timeToSecs(t2));
}
TEST(CustomTime, AddTimes) {
    CustomTime t1 = { 2,0,0 };
    CustomTime t2 = { 2,40,30 };
    CustomTime t3;
    ASSERT_EQ(16830, t3.AddTimes(t1, t2));

    CustomTime t4 = { 1,1,6 };
    CustomTime t5 = { 1,1,6 };
    CustomTime t6;
    ASSERT_EQ(7332, t6.AddTimes(t4, t5));
}

//question 5
TEST(SemesterRegistration, GetCreditHoursCount) {
    SemesterRegistration sem_reg;
    sem_reg.semesterCode = "Spring 2023";
    string courseCode[] = { "CL1004","EL2003","CL1001","CL2002","EL2020" };
    string courseTitle[] = { "OOP","COAL","PF","CNET","DLD" };
    int CreditHour[] = { 1,3,3,4,1 };
    char Section[] = { 'A','B','C','D','E' };
    for (int i = 0; i < 5; i++) {
        sem_reg.course_reg[i].courseCode = courseCode[i];
        sem_reg.course_reg[i].courseTitle = courseTitle[i];
        sem_reg.course_reg[i].CreditHour = CreditHour[i];
        sem_reg.course_reg[i].Section = Section[i];
    }
    ASSERT_EQ(12, sem_reg.GetCreditHoursCount(sem_reg));
}

TEST(SemesterRegistration, FindCourseInSemesterRegistration) {
    SemesterRegistration sem_reg;
    sem_reg.semesterCode = "Spring 2023";
    string courseCode[] = { "CL1004","EL2003","CL1001","CL2002","EL2020" };
    string courseTitle[] = { "OOP","COAL","PF","CNET","DLD" };
    int CreditHour[] = { 1,3,3,4,1 };
    char Section[] = { 'A','B','C','D','E' };
    for (int i = 0; i < 5; i++) {
        sem_reg.course_reg[i].courseCode = courseCode[i];
        sem_reg.course_reg[i].courseTitle = courseTitle[i];
        sem_reg.course_reg[i].CreditHour = CreditHour[i];
        sem_reg.course_reg[i].Section = Section[i];
    }
    ASSERT_EQ(1, sem_reg.FindCourseInSemesterRegistration(sem_reg, "CL1001"));
    ASSERT_EQ(0, sem_reg.FindCourseInSemesterRegistration(sem_reg, "CL2004"));
}

