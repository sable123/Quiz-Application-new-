#include <iostream>
#include"QUIZ.h"
#include"../conio2.h"
using namespace std;

int main()
{
    int c,choice,type;
    textcolor(LIGHTGREEN);
    for(int i=1;i<=80;i++)
        cout<<"*";
    textcolor(LIGHTRED);
    gotoxy(32,2);
    cout<<"QUIZ APPLICATION";
    gotoxy(1,3);
    textcolor(LIGHTGREEN);
    for(int i=1;i<=80;i++)
        cout<<"*";
    gotoxy(20,10);
    textcolor(YELLOW);
    cout<<"WELCOME TO TECH TEST-QUIZ APPLICATION";
    gotoxy(20,14);
    textcolor(LIGHTGREEN);
    cout<<"TEST YOUR SKILLS! IMPROVE YOUR KNOWLEDGE!";
    textcolor(WHITE);
    gotoxy(1,20);
    cout<<"Press any key to continue"<<endl;
    getch();
    Admin::create_admin("uadmin","abc","Sachin");

    do{
        clrscr();
        textcolor(LIGHTGREEN);
        for(int i=1;i<=80;i++)
            cout<<"*";
        textcolor(LIGHTRED);
        gotoxy(32,2);
        cout<<"QUIZ APPLICATION";
        gotoxy(1,3);
        textcolor(LIGHTGREEN);
        for(int i=1;i<=80;i++)
            cout<<"*";
        gotoxy(58,4);
        textcolor(WHITE);
        cout<<"Press 0 to Exit/Go Back";
        gotoxy(1,8);
        textcolor(YELLOW);
        for(int i=1;i<=80;i++)
            cout<<"*";
        gotoxy(32,10);
        cout<<"1. ADMIN";
        gotoxy(32,12);
        cout<<"2. STUDENT";
        gotoxy(32,14);
        textcolor(WHITE);
        cout<<"Select your role:";
        cin>>type;
        if(type==0)
            break;
        cin.ignore();

        if(type==1){

            do{
                Admin adminObj;
                c=adminObj.input();
                if(c==0){
                    gotoxy(30,14);
                    textcolor(LIGHTRED);
                    cout<<"Login Cancelled";
                    gotoxy(1,20);
                    textcolor(WHITE);
                    cout<<"Press any key to continue";
                    getch();
                    break;
                }
                c=adminObj.checkUserExist("admin");
                if(c==1){
                    gotoxy(28,28);
                    textcolor(LIGHTGREEN);
                    cout<<"Login Accepted!";
                    gotoxy(28,20);
                    cout<<"Welcome! "<<adminObj.getName();
                    gotoxy(28,22);
                    textcolor(WHITE);
                    cout<<"Press any key to continue";
                    getch();
                   while(1){
        clrscr();
        textcolor(LIGHTGREEN);
        for(int i=1;i<=80;i++)
            cout<<"*";
        gotoxy(1,3);
        for(int i=1;i<=80;i++)
            cout<<"*";
        textcolor(LIGHTRED);
        gotoxy(32,2);
        cout<<"QUIZ APPLICATION";
        textcolor(LIGHTGREEN);
        gotoxy(35,6);
        cout<<"ADMIN MENU"<<endl;
        textcolor(YELLOW);
        for(int i=1;i<=80;i++)
            cout<<"*";
        gotoxy(32,8);
        cout<<"1.Add Question";
        gotoxy(32,9);
        cout<<"2.Add Student";
        gotoxy(32,10);
        cout<<"3.Show Questions";
        gotoxy(32,11);
        cout<<"4.Show Students";
        gotoxy(32,12);
        cout<<"5.Remove Question";
        gotoxy(32,13);
        cout<<"6.Remove Student";
        gotoxy(32,14);
        cout<<"7.Exit";
        gotoxy(32,16);
        cout<<"Enter choice:";
        textcolor(WHITE);
        cin>>choice;
 Admin adminObj;
        switch(choice)
        {
     case 1:
        clrscr();
        adminObj.addQuestion();
        break;

     case 2:
        clrscr();
        adminObj.addStudent();
        break;

     case 3:
        clrscr();
        adminObj.viewQuestion();
        break;

     case 4:
        clrscr();
        adminObj.viewStudent();
        break;

     case 5:
        clrscr();
        adminObj.removeQuestion();
        break;//exit from the switch

     case 6:
        clrscr();
        adminObj.removeStudent();
        break;//exit from the switch

     case 7:
        clrscr();
        break;//exit from the switch

     default:
        textcolor(LIGHTRED);
        gotoxy(32,18);
        cout<<"Wrong choice.Try again";
        getch();
        }//switch close
        if(choice==7)
            break;
     }
                    //code for handling Admin Option
                }//if close
            }while(c==0);


        }
        else if(type==2){
                Student studobj;
          do{
                c=studobj.input();
                if(c==0){
                    gotoxy(30,14);
                    textcolor(LIGHTRED);
                    cout<<"Login Cancelled";
                    gotoxy(1,20);
                    textcolor(WHITE);
                    cout<<"Press any key to continue";
                    getch();
                    break;
                }
                c=studobj.checkUserExist("student");
                studobj.getName();
          }while(c==0);
                if(c==1){
                    gotoxy(28,28);
                    textcolor(LIGHTGREEN);
                    cout<<"Login Accepted!";
                    gotoxy(28,20);
                    cout<<"Welcome! "<<studobj.getName();
                    gotoxy(28,22);
                    textcolor(WHITE);
                    cout<<"Press any key to continue";
                    getch();
                   ///////////////////////////////////
                   while(1){
                   clrscr();
                   textcolor(LIGHTGREEN);
                   for(int i=1;i<=80;i++)
                   cout<<"*";
                   gotoxy(1,3);
                   for(int i=1;i<=80;i++)
                   cout<<"*";
                   textcolor(LIGHTRED);
                   gotoxy(32,2);
                   cout<<"QUIZ APPLICATION";
                   textcolor(LIGHTGREEN);
                   gotoxy(35,6);
                   cout<<"STUDENT MENU"<<endl;
                   textcolor(YELLOW);
                   for(int i=1;i<=80;i++)
                   cout<<"*";
                   gotoxy(32,8);
                   cout<<"1.Start Quiz";
                   gotoxy(32,9);
                   cout<<"2.view Performance";
                   gotoxy(32,10);
                   cout<<"3.Exit";
                   gotoxy(32,11);
                   cout<<"Enter choice:";
                   //gotoxy(32,11);
                   textcolor(WHITE);
                   cin>>choice;

          switch(choice){
      case 1:
        clrscr();
        studobj.quiz();
        break;
      case 2:
        clrscr();
        studobj.viewPerformance();
        break;
      case 3:
        clrscr();
        break;
      default:
          //textcolor(LIGHTRED);
          //gotoxy(32,18);
        cout<<"Invalid choice entered.Try again"<<endl;
          //getch();
          }
         if(choice==3)break;
                }//if close
                c=0;
            }
        }

        else{
            textcolor(LIGHTRED);
            gotoxy(30,14);
            cout<<"\t\t\t\t\t\t\t\t\t";
            gotoxy(30,14);
            cout<<"Invalid User Type";
            getch();
            textcolor(WHITE);
            clrscr();
        }
    }while((type!=1||type!=2));



    return 0;
}


