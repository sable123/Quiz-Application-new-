#include<fstream>
#include<string>
#include<cstring>
#include<iostream>
#include"QUIZ.h"
#include"../conio2.h"
#include<vector>
#include<ctime>
using namespace std;
void User::setUserDetails(string user_id,string user_name,string pwd){
  strcpy(this->userid,user_id.c_str());
  strcpy(this->username,user_name.c_str());
  strcpy(this->pwd,pwd.c_str());
  }

void Admin::create_admin(string userid,string password,string username){
  fstream fobj("Admin.bin",ios::binary|ios::in);
  if(fobj.fail()){
    fobj.open("Admin.bin",ios::binary|ios::out);
    Admin adminUser;
    adminUser.setUserDetails(userid,username,password);
    fobj.write((char*)&adminUser,sizeof(Admin));
    cout<<"File created!";
  }
  else
    cout<<"File already present";
  fobj.close();
}

int User::input()
{
 clrscr();
 gotoxy(1,1);
 textcolor(LIGHTGREEN);
 for(int i=1;i<=80;i++)
    cout<<"*";
 gotoxy(1,3);
 for(int i=1;i<=80;i++)
    cout<<"*";
 gotoxy(58,4);
 textcolor(WHITE);
 cout<<"Press 0 to exit/go back";
 gotoxy(32,2);
 textcolor(LIGHTRED);
 cout<<"QUIZ APPLICATION";
 gotoxy(1,8);
 textcolor(YELLOW);
 for(int i=1;i<=80;i++)
    cout<<"*";
 gotoxy(28,11);
 cout<<"Enter userid:";
 textcolor(WHITE);
 cin.getline(userid,20);
 if(strcmp(userid,"0")==0)
    return 0;
 char ch;
 int i=0;
 textcolor(YELLOW);
 gotoxy(28,12);
 cout<<"Enter password:";

 while(true){
    ch=getch();
    if(ch==13)
        break;
if(ch==8){
        if(i==0)
            continue;
        cout<<"\b \b";
        i--;
        continue;
    }
    cout<<ch;
    delay(200);
    cout<<"\b*";
    pwd[i]=ch;
    i++;
 }
 pwd[i]='\0';
 if(strcmp(pwd,"0")==0)
    return 0;
 return 1;
}

int User::checkUserExist(string usertype)
{
 if(strcmp(userid,"")==0||strcmp(pwd,"")==0)
 {
   gotoxy(28,20);
   textcolor(LIGHTRED);
   cout<<"BOTH THE FIELDS ARE MANDATARY";
   getch();
   return 0;
 }
 ifstream fin;
 User *uptr;
 if(usertype=="admin")
 {
  fin.open("Admin.bin",ios::in|ios::binary);
  uptr=new Admin;
 }
 else if(usertype=="student")
 {
  fin.open("Student.bin",ios::in|ios::binary);
  uptr=new Student;
 }
 else{
    gotoxy(28,18);
    textcolor(LIGHTRED);
    cout<<"WRONG USERTYPE PASSED!";
    getch();
    return 0;
 }
 bool useridfound=0,pwdfound=0;
 while(1){
    fin.read((char*)uptr,sizeof(*uptr));
    if(fin.eof())
        break;
    if(strcmp(userid,uptr->userid)==0){
        if(strcmp(pwd,uptr->pwd)==0)
        {
         useridfound=pwdfound=1;
         break;
        }
        useridfound=1;
    }
 }
 bool result=0;
 if(useridfound==0)
 {
  gotoxy(28,18);
  textcolor(LIGHTRED);
  cout<<"No such user exists!";
  getch();
 }
 else if(pwdfound==0){
  gotoxy(28,18);
  textcolor(LIGHTRED);
  cout<<"Invalid password!";
  getch();
 }
 else
 {
  result=1;
  strcpy(username,uptr->username);
 }
 fin.close();
 return result;
}

string User::getName(){
return username;
}
void Admin::addQuestion()
{
  Question quesobj;
  quesobj.add();
  clrscr();
}

void Question::add()
{
 fstream fobj("Question.bin",ios::app|ios::binary|ios::in);
 if(!fobj)
 {
   gotoxy(32,18);
   textcolor(LIGHTRED);
   cout<<"Sorry! File cannot be opened!";
   getch();
   return;
 }
 fobj.seekg(0,ios::end);
 if(fobj.tellg()==0)
    quesid=1;
 else
 {
  fobj.seekg(-1*sizeof(*this),ios::end);
  fobj.read((char*)this,sizeof(*this));
  cout<<"Last Question Id is"<<quesid;
  quesid++;
  fobj.seekg(0,ios::end);
 }
 cout<<endl<<"New Question Id is: "<<quesid;
 getch();
 char uchoice;
 fobj.seekg(0,ios::end);
 do
 {
    clrscr();
    textcolor(WHITE);
    gotoxy(58,4);
    cout<<"Press 0 to Exit/Go Back";
    textcolor(LIGHTGREEN);
    gotoxy(1,1);
    for(int i=1;i<=80;i++)
        cout<<"*";
    gotoxy(1,3);
    for(int i=1;i<=80;i++)
        cout<<"*";
    gotoxy(32,2);
    textcolor(LIGHTGREEN);
    cout<<"QUIZ APP";
    textcolor(WHITE);
    gotoxy(25,5);
    cout<<"***** ADD QUESTION DETAILS *****";
    gotoxy(1,8);
    textcolor(YELLOW);
    string str;
    cout<<"Enter question:";
    cin.ignore();
    textcolor(WHITE);
    getline(cin,str,'*');
    if(strcmp(str.c_str(),"0")==0)
    {
      gotoxy(1,24);
      textcolor(LIGHTGREEN);
     cout<<"Closing add question"<<endl;
      getch();
      fobj.close();
      return;
    }
    strncpy(ques,str.c_str(),499);
    textcolor(LIGHTGREEN);

    cout<<endl<<"Carries Marks:";
    textcolor(YELLOW);
    cin>>tot_marks;
    textcolor(LIGHTGREEN);
    cout<<endl<<"OPTIONS"<<endl<<endl;
    textcolor(YELLOW);
    cout<<"(a)";
    cin.ignore();
    textcolor(WHITE);
    getline(cin,str);
    strncpy(op1,str.c_str(),99);
    textcolor(YELLOW);
    cout<<"(b)";
    textcolor(WHITE);
    getline(cin,str);
    strncpy(op2,str.c_str(),99);
    textcolor(YELLOW);
    cout<<"(c)";
    textcolor(WHITE);
    getline(cin,str);
    strncpy(op3,str.c_str(),99);
    textcolor(YELLOW);
    cout<<"(d)";
    textcolor(WHITE);
    getline(cin,str);
    strncpy(op4,str.c_str(),99);
    bool valid;
    do
    {
      gotoxy(1,19);
      textcolor(YELLOW);
      cout<<endl<<"Enter correct ans(a/b/c/d):\b";
      textcolor(WHITE);
      cin>>ans;
      if(ans>='a' && ans<='d')
        valid=true;
      else
      {
        gotoxy(24,22);
        textcolor(LIGHTRED);
        cout<<"Invalid choice.Please try again";
        getch();
        valid=false;
      }
    }while(valid==false);
    fobj.write((char*)this,sizeof(*this));
    quesid++;gotoxy(24,22);
    printf("\t\t\t\t\t\t\t");
    gotoxy(34,22);
    textcolor(LIGHTGREEN);
    cout<<"QUESTION ADDED SUCCESSFULY!";
    getch();
    gotoxy(1,24);
    textcolor(LIGHTMAGENTA);
    cout<<endl<<"Do you want to add more questions (Y/N):";
    textcolor(WHITE);
    cin>>uchoice;

 }while(uchoice=='y'|| uchoice=='Y');
 fobj.close();
}
void Admin::viewQuestion()
{
  Question quesobj;
  quesobj.viewQuestion();
  clrscr();
}

void Question::viewQuestion()
{
    ifstream fin("Question.bin",ios::in|ios::binary);
    if(!fin)
    {
      gotoxy(1,10);
      textcolor(LIGHTRED);
      cout<<"No questions have been added yet!";
      getch();
      return;
    }
    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {
      gotoxy(1,10);
      textcolor(LIGHTRED);
      cout<<"No questions present in the file!";
      getch();
      return;
    }
    clrscr();
    fin.seekg(0);
    while(1)
    {

      textcolor(LIGHTGREEN);
      gotoxy(1,1);
      for(int i=1;i<=80;i++)
        cout<<"*";
      gotoxy(1,3);
      for(int i=1;i<=80;i++)
        cout<<"*";
      gotoxy(32,2);
      textcolor(LIGHTRED);
      cout<<"QUIZ APP";
      textcolor(WHITE);
      gotoxy(25,5);
      cout<<"***** SHOW QUESTION DETAILS *****";
      gotoxy(1,7);
      textcolor(LIGHTGREEN);
      for(int i=1;i<=80;i++)
        cout<<"*";


      fin.read((char*)this,sizeof(*this));
      if(fin.eof()){
        cout<<endl;
        textcolor(LIGHTRED);
        gotoxy(35,10);
        cout<<"NO MORE QUESTIONS PRESENT!";
        getch();

        break;
      }
      else{
        show();
        getch();
        clrscr();
      }
    }
    fin.close();

}
void Question::show()
{
  cout<<endl;
  textcolor(YELLOW);
  cout<<"Q."<<quesid<<" ";
  cout<<ques<<endl;
  cout<<"carries Marks: "<<tot_marks<<endl;
  cout<<"a."<<op1<<endl;
  cout<<"b."<<op2<<endl;
  cout<<"c."<<op3<<endl;
  cout<<"d."<<op4<<endl;
  textcolor(LIGHTGREEN);
  cout<<endl<<"correct option: "<<ans;

}

void Admin::removeQuestion()
{
  Question quesobj;
  quesobj.Remove();
  clrscr();
}

void Question::Remove()
{
  clrscr();
    textcolor(WHITE);
    gotoxy(58,4);
    cout<<"Press 0 to Exit/Go Back";
    textcolor(LIGHTGREEN);
    gotoxy(1,1);
    for(int i=1;i<=80;i++)
        cout<<"*";
    gotoxy(1,3);
    for(int i=1;i<=80;i++)
        cout<<"*";
    gotoxy(32,2);
    textcolor(LIGHTGREEN);
    cout<<"QUIZ APP";
    textcolor(WHITE);
    gotoxy(25,5);
    cout<<"***** REMOVE QUESTION DETAILS *****";
    ifstream fin("Question.bin",ios::in|ios::binary);
    if(!fin)
    {
      gotoxy(35,10);
      textcolor(LIGHTRED);
      cout<<"Sorry! File cannot be opened!";
      getch();
      return;
    }
    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {
      gotoxy(35,10);
      textcolor(LIGHTRED);
      cout<<"No questions available for deletion!";
      getch();
      fin.close();
      return;
    }
    getch();
    gotoxy(1,8);
    textcolor(YELLOW);
    cout<<"Enter Question ID:";
    bool found=false,valid;
    int id;
    ofstream fout("temp.bin",ios::out|ios::binary);
    if(!fout)
    {
      gotoxy(35,10);
      textcolor(LIGHTRED);
      cout<<"Sorry! removal not possible!";
      getch();
      fin.close();
      return;
    }
    fin.seekg(0);

    do
    {
      valid=true;
      cin>>id;
      if(id==0)
      {
        fin.close();
        fout.close();
        remove("temp.bin");
        return;
      }
      if(id<0)
      {
        valid=false;
        gotoxy(1,24);
        textcolor(LIGHTRED);
        cout<<"\t\t\t\t\t\t\t\t\t\t\rInvalid Question ID";
        getch();
        gotoxy(19,8);
        cout<<"\t\t\t\t\t\t\t\t\t";
        gotoxy(19,8);
        textcolor(WHITE);

      }
      else
      {
        while(true)
        {
          fin.read((char*)this,sizeof(*this));
          if(fin.eof())
            break;
          if(this->quesid==id)
          {
            found=true;
            continue;
          }
          else
          {
            fout.write((char*)this,sizeof(*this));
          }
        }
        fout.close();
        fin.close();
        if(found)
        {
          textcolor(WHITE);
          gotoxy(1,24);
          cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\rQuestion Removed Successfully!";
          getch();
          remove("Question.bin");
          rename("temp.bin","Question.bin");
        }
        else
        {
          textcolor(LIGHTRED);
          gotoxy(1,24);
          cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\rQuestion Id not fount!";
          getch();
          remove("temp.bin");
          getch();
        }
      }

    }while(valid==false);
}

void Admin::addStudent()
{
  Student studobj;
  studobj.add();
  clrscr();
}

void Student::add()
{

  char uchoice;
  int id;
  char stuid[10];
  string str;
  fstream fobj("Student.bin",ios::app|ios::in|ios::binary);
  fobj.seekg(0,ios::end);
  if(fobj.tellg()==0)
    id=1;
  else{
    fobj.seekg(-1L*sizeof(*this),ios::cur);
    fobj.read((char*)this,sizeof(*this));
    cout << "this->userid: " << this->userid <<endl;
    getch();
    char*pos=strchr(userid,'-');
    if(pos!=NULL)
    {
      id=atoi(pos+1);
      id++;
    }
    fobj.seekg(0,ios::end);
  }
  cout<<"Next id is:"<<id;
  getch();
  fobj.seekg(0,ios::end);
  do
  {
    clrscr();
    textcolor(WHITE);
    gotoxy(58,4);
    cout<<"Press 0 to Exit/Go Back";
    textcolor(LIGHTGREEN);
    gotoxy(1,1);
    for(int i=1;i<=80;i++)
        cout<<"~";
    gotoxy(1,3);
    for(int i=1;i<=80;i++)
        cout<<"~";
    gotoxy(32,2);
    textcolor(LIGHTRED);
    cout<<"QUIZ APP";
    textcolor(WHITE);
    gotoxy(25,5);
    cout<<"***** ADD STUDENT DETAILS *****";
    gotoxy(1,8);
    textcolor(YELLOW);
    cout<<"Enter Student Name:";
    cin.ignore();
    textcolor(WHITE);
    getline(cin,str);
    strncpy(username,str.c_str(),19);
    if(strcmp(username,"0")==0)
    {
      gotoxy(1,24);
      textcolor(LIGHTRED);
      cout<<"Cancelling Add Student...."<<endl;
      getch();
      fobj.close();
      return;
    }
    textcolor(YELLOW);
    cout<<"Enter Student Password:";
    textcolor(WHITE);
    getline(cin,str);
    strncpy(pwd,str.c_str(),19);
    if(strcmp(pwd,"0")==0)
    {
      gotoxy(1,24);
      textcolor(LIGHTRED);
      cout<<"Cancelling Add Student...."<<endl;
      getch();
      fobj.close();
      return;
    }
    sprintf(stuid,"STU-%d",id);
    strcpy(userid,stuid);
    fobj.write((char*)this,sizeof(*this));
    gotoxy(30,15);
    textcolor(LIGHTGREEN);
    cout<<"STUDENT ADDED SUCCESSFULLY!";
    cout<<endl<<"STUDENT ID IS:"<<userid;
    getch();
    gotoxy(1,20);
    textcolor(MAGENTA);
    cout<<"Do you want to add more student(Y/N)?";
    cin>>uchoice;
    id++;
  }while(uchoice=='Y'||uchoice=='y');
  fobj.close();
}

void Admin::viewStudent()
{
  Student studobj;
  studobj.showStudentDetails();
  clrscr();
}

void Student::showStudentDetails()
{
  clrscr();
  ifstream fin("Student.bin",ios::in|ios::binary);
    if(!fin)
    {
      gotoxy(10,1);
      textcolor(LIGHTRED);
      cout<<"No students have been added yet!";
      getch();
      return;
    }
    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {
      gotoxy(10,1);
      textcolor(LIGHTRED);
      cout<<"No students present in the file!";
      getch();
      return;
    }
    clrscr();
    fin.seekg(0);
    while(1)
    {

      textcolor(LIGHTGREEN);
      gotoxy(1,1);
      for(int i=1;i<=80;i++)
        cout<<"*";
      gotoxy(1,3);
      for(int i=1;i<=80;i++)
        cout<<"*";
      gotoxy(32,2);
      textcolor(LIGHTRED);
      cout<<"QUIZ APP";
      textcolor(WHITE);
      gotoxy(25,5);
      cout<<"***** SHOW STUDENT DETAILS *****";
      gotoxy(1,7);
      textcolor(LIGHTGREEN);
      for(int i=1;i<=80;i++)
        cout<<"*";


      fin.read((char*)this,sizeof(*this));
      if(fin.eof()){
        cout<<endl;
        textcolor(LIGHTRED);
        gotoxy(35,10);
        cout<<"NO MORE STUDENTS PRESENT!";
        getch();

        break;
      }
      else{
        show();
        getch();
        clrscr();
      }
    }
    fin.close();

}

void User::show()
{
  cout<<endl;
  textcolor(YELLOW);
  cout<<"UserId is:";
  textcolor(LIGHTGREEN);
  cout<<userid<<endl;
  textcolor(YELLOW);
  cout<<"User name is:";
  textcolor(LIGHTGREEN);
  cout<<username<<endl;
  textcolor(YELLOW);
  cout<<"Password is:";
  textcolor(LIGHTGREEN);
  cout<<pwd<<endl;
}

void Admin::removeStudent()
{
  Student studobj;
  studobj.Remove();
}


void Student::Remove()
{
  clrscr();
    textcolor(WHITE);
    gotoxy(58,4);
    cout<<"Press 0 to Exit/Go Back";
    textcolor(LIGHTGREEN);
    gotoxy(1,1);
    for(int i=1;i<=80;i++)
        cout<<"*";
    gotoxy(1,3);
    for(int i=1;i<=80;i++)
        cout<<"*";
    gotoxy(32,2);
    textcolor(LIGHTGREEN);
    cout<<"QUIZ APP";
    textcolor(WHITE);
    gotoxy(25,5);
    cout<<"***** REMOVE STUDENT DETAILS *****";
    ifstream fin("Student.bin",ios::in|ios::binary);
    if(!fin)
    {
      gotoxy(35,10);
      textcolor(LIGHTRED);
      cout<<"Sorry! File cannot be opened!";
      getch();
      return;
    }
    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {
      gotoxy(35,10);
      textcolor(LIGHTRED);
      cout<<"No Student available for deletion!";
      getch();
      fin.close();
      return;
    }
    getch();
    gotoxy(1,8);
    textcolor(YELLOW);
    cout<<"Enter Student ID:";
    bool found=false,valid;
    int id;
    char stuid[10];
    ofstream fout("temp.bin",ios::out|ios::binary);
    if(!fout)
    {
      gotoxy(35,10);
      textcolor(LIGHTRED);
      cout<<"Sorry! removal not possible!";
      getch();
      fin.close();
      return;
    }
    fin.seekg(0);

    do
    {
      valid=true;
      cin>>id;
      sprintf(stuid,"STU-%d",id);

      if(id==0)
      {
        fin.close();
        fout.close();
        remove("temp.bin");
        return;
      }
      if(id<0)
      {
        valid=false;
        gotoxy(1,24);
        textcolor(LIGHTRED);
        cout<<"\t\t\t\t\t\t\t\t\t\t\rInvalid Student ID";
        getch();
        gotoxy(19,8);
        cout<<"\t\t\t\t\t\t\t\t\t";
        gotoxy(19,8);
        textcolor(WHITE);

      }


      else
      {
        while(true)
        {
          fin.read((char*)this,sizeof(*this));
          if(fin.eof())
            break;
          int res=strcmp(this->userid,stuid);
          if(res==0)
          {
            found=true;
            continue;
          }
          else
          {
            fout.write((char*)this,sizeof(*this));
          }
        }
        fout.close();
        fin.close();
        if(found)
        {
          textcolor(WHITE);
          gotoxy(1,24);
          cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\rStudent Removed Successfully!";
          getch();
          remove("Student.bin");
          rename("temp.bin","Student.bin");
        }
        else
        {
          textcolor(LIGHTRED);
          gotoxy(1,24);
          cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\rStudent Id not fount!";
          getch();
          remove("temp.bin");
          getch();
        }
      }

    }while(valid==false);
}
/////////////////////////////
bool ispresent(vector<int>&,int);
void Student::quiz()
{
 Question quesobj;
 quesobj.startQuiz(userid);
}

void Question::startQuiz(char* id)
{
 ifstream fin("Question.bin",ios::in|ios::binary);
 if(fin.fail())
 {
  gotoxy(28,20);
  textcolor(LIGHTRED);
  cout<<"No Question Have Been Added Yet!";
  getch();
  return;
 }
 vector<Question>vecQues;

 while(1)
 {
  fin.read((char*)this,sizeof(*this));
  if(fin.eof())
    break;
  vecQues.push_back(*this);
 }
 fin.close();
 vector<int>vecRand;
 srand((unsigned int)time(NULL));
 int randno;
 while(1)
 {
  randno=rand()%vecQues.size();
  if(ispresent(vecRand,randno)==true)
    continue;
  vecRand.push_back(randno);
  if(vecRand.size()==vecQues.size())
    break;

 }
 int count=0;
 User userObj;
 int local_marks=0;
 int local_tot_marks=0;
 string name=userObj.getName(id);
 for(unsigned int i=0;i<vecQues.size();i++)
 {
    int index=vecRand.at(i);
    *this=vecQues.at(index);
    clrscr();
    gotoxy(37,2);
    textcolor(LIGHTRED);
    cout<<"QUIZ APP";
    textcolor(YELLOW);
    gotoxy(1,4);
    for(int j=1;j<=80;j++)
        cout<<"*";
    textcolor(WHITE);
    gotoxy(50,5);
    cout<<name;
    gotoxy(10,5);
    cout<<"TOTAL QUESTION:"<<vecQues.size()<<endl;
    gotoxy(1,6);
    textcolor(YELLOW);
    for(int j=1;j<=80;j++)
        cout<<"*";

    textcolor(GREEN);
    gotoxy(1,8);
    count++;
    cout<<count<<")";
    gotoxy(4,8);
    cout<<this->ques<<endl<<endl;
    textcolor(LIGHTGRAY);
    cout<<"a."<<this->op1<<endl<<endl;
    cout<<"b."<<this->op2<<endl<<endl;
    cout<<"c."<<this->op3<<endl<<endl;
    cout<<"d."<<this->op4<<endl<<endl;

    bool valid;
    char uans;
    do
    {
     textcolor(YELLOW);
     cout<<"Enter your option(a/b/c/d): \b";
     cin>>uans;
     if(uans>='a' && uans<='d')
        valid=true;
     else
     {
        valid=false;
        gotoxy(24,22);
        textcolor(LIGHTRED);
        cout<<"Invalid option entered.Try again";
        getch();
        gotoxy(24,22);
        cout<<"\t\t\t\t\t\t\t\t\t";
        gotoxy(1,18);
     }
    }while(valid==false);
    local_tot_marks+=this->tot_marks;
    if(uans==this->ans)
        local_marks+=this->tot_marks;
 }
 clrscr();
 gotoxy(37,2);
 textcolor(LIGHTRED);
 cout<<"QUIZ APP";
 textcolor(YELLOW);
 gotoxy(1,4);
 for(int i=1;i<=80;i++)
    cout<<"*";
 gotoxy(32,10);
 textcolor(LIGHTRED);
 cout<<"** TEST FINISHED **";
 gotoxy(22,12);
 cout<<"PRESS ANY KEY TO GO BACK TO MAIN MENU";
 getch();
 StudentPerformance sp;
 sp.setMarksDetails(id,local_marks,local_tot_marks);
}

bool ispresent(vector<int>&v,int value)
{
 for(unsigned int i=0;i < v.size();i++)
 {
     if(v.at(i)==value)
        return true;
 }
 return false;
}

string User::getName(string id)
{
 ifstream fin("Student.bin",ios::in|ios::binary);
 while(1)
 {
   fin.read((char*)this,sizeof(User));
   if(fin.eof())
   {
       cout<<"No match of record found";
       break;
   }
   int result=strcmp(this->getUserID().c_str(),id.c_str());
   if(result==0)
   {
    fin.close();
    return this->username;
   }
 }
 fin.close();
 return NULL;
}

string User::getUserID()
{
 string USERID;
 USERID=userid;
 return USERID;
}

void StudentPerformance::setMarksDetails(string id,int marks,int tot_marks)
{
 strcpy(studid,id.c_str());
 this->marks=marks;
 this->tot_marks=tot_marks;
 saveMarksDetails();
}

void StudentPerformance::saveMarksDetails()
{
 ofstream fout("Performance.bin",ios::app|ios::binary);
 if(!fout)
 {
  gotoxy(1,26);
  textcolor(LIGHTRED);
  cout<<"Error in creating/opening file";
  getch();
  return;
 }

 fout.write((char*)this,sizeof(*this));
 fout.close();
}

void Student::viewPerformance(){
StudentPerformance studp;
studp.viewDetails(userid);
}

void StudentPerformance::viewDetails(string str){
ifstream fin("Performance.bin",ios::in|ios::binary);
if(fin.fail()){
    gotoxy(28,20);
    textcolor(LIGHTRED);
    cout<<"No Student have been appear in test yet!";
    getch();
    return;
}
while(1){
fin.read((char*)this,sizeof(*this));
if(fin.eof()){
    gotoxy(26,19);
    textcolor(LIGHTRED);
    cout<<"NO MORE RECORDS"<<endl;
    break;
}
int result=strcmp(this->studid,str.c_str());
if(result==0){
clrscr();
gotoxy(37,2);
textcolor(LIGHTRED);
cout<<"QUIZ APP";
textcolor(LIGHTGREEN);
gotoxy(1,3);
for(int i=0;i<80;i++)
    cout<<"*";
textcolor(YELLOW);
gotoxy(26,8);
cout<<"***** VIEW REPORT CARD *****";
gotoxy(1,9);
for(int i=0;i<80;i++)
cout<<"-";
gotoxy(1,13);
cout<<"Name:"<<str;
textcolor(LIGHTGREEN);
gotoxy(1,15);
cout<<"S.NO.";
gotoxy(26,15);
cout<<"MARKS OBTAINED";
gotoxy(75,15);
cout<<"TOTAL MARKS";
gotoxy(1,18);
for(int i=0;i<80;i++)
    cout<<"-";
gotoxy(1,16);
cout<<studid<<".";
gotoxy(1,16);
cout<<"    \b\b\b\b";
gotoxy(26,16);
cout<<marks;
gotoxy(75,16);
cout<<tot_marks;
getch();

}}
getch();
return;
}

