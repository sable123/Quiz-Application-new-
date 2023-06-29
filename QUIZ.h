#ifndef QUIZ_H_INCLUDED
#define QUIZ_H_INCLUDED

#include<string>

using namespace std;

class User{
    protected:
    char userid[20],pwd[20],username[50];
    public:
    void setUserDetails(string,string,string);
    string getName(string);
    string getName();
    string getUserID();
    int checkUserExist(string);
    void show();
    int input();
    };

class Student:public User{
    public:
    void add();
    void Remove();
    void showStudentDetails();
    void quiz();
    void viewPerformance();
    };

class Admin:public User{
public:
    static void create_admin(string,string,string);
    void addStudent();
    void removeStudent();
    void viewStudent();
    void addQuestion();
    void removeQuestion();
    void viewQuestion();
    };

class Question{
private:
    int quesid,tot_marks;
    char ques[500],op1[100],op2[100],op3[100],op4[100],ans;

public:
    void add();
    void Remove();
    void setQuestionDetails(int,char*,char*,char*,char*,char*,char);
    void show();
    void viewQuestion();
    void startQuiz(char*);
    int ques_count();
    };

class StudentPerformance{
private:
    char studid[10];
    int marks;
    int tot_marks;
public:
    void setMarksDetails(string,int,int);
    void saveMarksDetails();
    void viewDetails(string);
    void show();
    };

#endif // QUIZ_H_INCLUDED






