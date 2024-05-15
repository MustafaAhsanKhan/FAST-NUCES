#pragma once
#include <iostream>
#include "pch.h"
using namespace std;

string helper_reverse_string(string s, int index, string s_final)
{
    if (index == s.length())
    {
        return s_final;
    }
    else
    {
        s_final = helper_reverse_string(s, index + 1, s_final);

        s_final = s_final + s[index];
        return s_final;
    }
}

string helper_reverse_word(string s, int index, string s_final)
{
    if (index == s.length())
    {
        return s_final;
    }
    else
    {
        if (s[index] == ' ')
        {
            s_final = helper_reverse_string(s, index - 1, s_final);

        }
        s_final = helper_reverse_string(s, index + 1, s_final);
        s_final = s_final + s[index];
        return s_final;
    }
}

string reverse_string(string s)
{
    string s_final = "";
    return helper_reverse_string(s, 0, s_final);
    //return helper_reverse_word(s, 0, s_final);
}

struct Complex
{
    int real;
    int imaginary;

    Complex addComplex(Complex c1, Complex& c2)
    {
        c1.real = c1.real + c2.real;
        c1.imaginary = c1.imaginary + c2.imaginary;
        return c1;
    }
};

struct Student
{
    string Name;
    string roll_no;
    int age;

    string* getNames(Student* std)
    {
        int exact_18 = 0;

        for (int i = 0; i < 5; ++i)
        {
            if (std[i].age == 18)
            {
                exact_18++;
            }
        }

        string* names = new string[exact_18];
        int index = 0;
        for (int i = 0; i < 5; ++i)
        {
            if (std[i].age == 18)
            {
                names[index] = std[i].Name;
                ++index;
            }
        }

        return names;
    }

    Student* getEvenRollno(Student* std)
    {
        int evens = 0;

        for (int i = 0; i < 5; ++i)
        {
            if (int(std[i].roll_no[7]) % 2 == 0)
            {
                evens++;
            }
        }

        Student* s = new Student[evens];

        int index = 0;
        for (int i = 0; i < 5; ++i)
        {
            if (int(std[i].roll_no[7]) % 2 == 0)
            {
                s[index] = std[i];
                ++index;
            }
        }

        return s;
    }
};

struct CustomTime
{
    int hours;
    int mins;
    int secs;

    int timeToSecs(CustomTime t1)
    {
        int totaltime = 0;

        totaltime = (t1.hours * 60 * 60) + (t1.mins * 60) + t1.secs;

        return totaltime;
    }

    int AddTimes(CustomTime t1, CustomTime t2)
    {
        return timeToSecs(t1) + timeToSecs(t2);
    }
};

struct CourseRegistration
{
    string courseCode;
    string courseTitle;
    int CreditHours;
    char Section;
};

struct SemesterRegistration
{
    string semesterCode;
    CourseRegistration* course_reg = new CourseRegistration[5];

    int GetCreditHoursCount(SemesterRegistration s)
    {
        int total_credit_hours = 0;

        for (int i = 0; i < 5; ++i)
        {
            total_credit_hours = total_credit_hours + s.course_reg[i].CreditHours;
        }

        return total_credit_hours;
    }

    bool FindCourseInSemesterRegistration(SemesterRegistration s, string courseCode)
    {
        for (int i = 0; i < 5; ++i)
        {
            if (s.course_reg[i].courseCode == courseCode)
            {
                return true;
            }
        }

        return false;
    }
};

