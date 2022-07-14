#include <iostream>
#include <stdlib.h>

using namespace std;

/**
 * add - function to add the student attribute
 * display - to display student attribute
 * Return - 0;
 *
 */

struct Student
{
    char name[50];
    int age;
    float grade [3];
};

Student add(Student s);
void display(Student s[], int size);

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
    cout << "\t\t|      3. Exit             |" << endl;
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
            cout << "\t\t|        Add Student Record    " << endl;
            cout << "\t\t-------------------------------" << endl;

            cout << "\t\t Enter the number of Students: ";

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

    cin.get(s.name, 50);

    again:

    cout << "\t\tEnter Age: ";

    cin >> s.age;

   if (s.age > 50 || s.age < 18)
    {
        cout << "\t\t Please Enter the correct age!" << endl;
        cout << "Press any key to retry... ";
        char user_input;
        cin >> user_input;
        goto again;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "\t\tEnter Grade " << i+1 << " :";

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
        cout << "\t\t\t" << s[i].name << "\t\t" << s[i].age << "       ";
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