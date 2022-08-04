#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

/**
 * add - function to add the student attribute
 * display - to display student attribute
 * Return - 0;
 *
 */
struct Personalinfo
{
    char name[50];
    int age;
};

struct Student
{
    Personalinfo info;
    float grade [3];
};


Student add(Student s);
void display(Student s[], int size);
void search(Student s[], int size);

int main()
{


    Student stud[10];

    int size = 0;

    int num;

    menu:
    char user_input;

    cout << "\t\t---------------------------" << endl;
    cout << "\t\t|      1. Add Student      |" << endl;
    cout << "\t\t|      2. Display Student  |" << endl;
    cout << "\t\t|      3. Search           |" << endl;
    cout << "\t\t|      4. Exit             |" << endl;
    cout << "\t\t---------------------------" << endl;
    cout << endl;
    cout << "\t Enter your choice :-> ";

  //  system("cls");

    cin >> user_input;

    switch(user_input)
    {
        case '1':
            cout << "\n\n";
            cout << "\t\t-------------------------------" << endl;
            cout << "\t\t|        Add Student Record    |" << endl;
            cout << "\t\t-------------------------------" << endl;

            cout << "\t\t Enter the number of students you want to add: ";

            cin >> num;

            for (int i = size; i < (num + size); i++)
            {
                stud[i] = add(stud[i]);
            }

            size += num;

            goto menu;

            break;
        case '2':
            size = num;

            display(stud, size);

            cout << "\t\t Press any key to continue... ";
            goto menu;

            break;
        case '3':
            search(stud, size);
            goto menu;
            break;
        case '4':
            exit(0);
            break;
        default:
            cout << "\n Please Enter the correct Input...";
            cout << "\n Press any key to continu";

    }

}


Student add(Student s)
{
    cin.ignore();

    cout << "\t\t Enter Student name: ";

    cin.get(s.info.name, 50);

    again:

    cout << "\t\t Enter Age: ";

    cin >> s.info.age;

   if (s.info.age > 50 || s.info.age < 18)
    {
        cout << "\t\t Please Enter the correct age!" << endl;
        cout << "\t\t Press any key to retry... ";
        string user_input;
        cin >> user_input;
        goto again;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "\t\t Enter Grade " << i+1 << " :";

        cin >> s.grade[i];
    }
    cout << endl;

    return s;
}

void display(Student s[], int size)
{
    cout <<"\t\t-----------------------------" << endl;
    cout <<"\t\t|   Show Student Record     |" << endl;
    cout <<"\t\t-----------------------------" << endl;
    cout << "\n\n";

    cout << "\t\t+----------------------------------------------------------+" << endl;
     cout << "\t\t\tStudent Name | Age  |  Grade 1  | Grade 2 | Grade 3 |" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "\t\t\t" << s[i].info.name << "\t\t" << s[i].info.age << "       ";
        for (int j = 0; j < 3; j++)
        {
            cout << s[i].grade[j];
            cout << "       ";
        }
        cout << endl;
    }
    cout << "\t\t+----------------------------------------------------------+" << endl;
    cout << endl;
    cout << endl;



}

void search(Student s[], int size)
{
    searchagain:
    string user_input;
    char namessearch[50];
    cout <<"\t\t-----------------------------" << endl;
    cout <<"\t\t|   Search Student Name     |" << endl;
    cout <<"\t\t-----------------------------" << endl;
    cout << "\n\n";
    cout << "Enter Student Name: ";
    cin.ignore();
    cin.get(namessearch, 50);
   // int j = 0;
    cout << "\t\tResult: " << endl;
    cout << endl;
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (strncasecmp(namessearch, s[i].info.name, strlen(namessearch)) == 0)
        {
            k++;
            cout << "\t\t+----------------------------------------------------------+" << endl;
            cout << "\t\t\tStudent Name | Age  |  Grade 1  | Grade 2 | Grade 3 |" << endl;
            cout << "\t\t\t" << s[i].info.name << "\t\t" << s[i].info.age << "       ";
            for (int j = 0; j < 3; j++)
           {
            cout << s[i].grade[j];
            cout << "       ";
           }
            cout << endl;
            cout << "\t\t+----------------------------------------------------------+" << endl;
        }
    }

    if (k == 0)
    {
        cout << "\t\t Not found" << endl;
    }
    cout << endl;
    cout << "\t\t Press 1 to countinue searching. any other key to exit... ";
    cin >> user_input;
    if (user_input == "1")
    {
        goto searchagain;
    }
    cout << endl;




}