#include <iostream>
#include <stdlib.h>
#include <cstdlib.h>

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
    again:

    Student stud[10];

    int size;

    int num;

    char user_input;

    cout << "\t\t---------------------------" << endl;
    cout << "\t\t|      1. Add Student      |" << endl;
    cout << "\t\t|      2. Display Student  |" << endl;
    cout << "\t\t|      3. Exit             |" << endl;
    cout << "\t\t---------------------------" << endl;
    cout << endl;
    cout << "\t Enter your choice :-> ";

    system("CLS");

    cin >> user_input;

    switch(user_input)
    {
        case '1':
            cout << "\n\n\t\t_______________________________" << endl;
            cout << "\t\t  |        Add Student Record         |" << endl;
            cout << "\t\t_______________________________" << endl;

            cout << "\t\t Enter the number of Students: ";

            cin >> num;

            for (int i = 0; i < num; i++)
            {
                stud[i] = add(stud[i]);
            }

            goto again;

            break;
        case '2':
            size = num;

            display(stud, size);

            cout << "\t\t Press any key to continue... ";
            goto again;

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
    int itrate = 0;

    cout << "\t\tEnter Student name: ";

    cin >> s.name;

    cout << "\t\tEnter Age: ";

    cin >> s.age;

    for (int i = 0; i < 3; i++)
    {
        cout << "\t\tEnter Grade " << i+1 << " :";

        cin >> s.grade[i];
    }

    return s;
}

void display(Student s[], int size)
{
    cout <<"\t\t-----------------------------" << endl;
    cout <<"\t\t|   Show Student Record     |" << endl;
    cout <<"\t\t-----------------------------" << endl;
    cout << "\n\n";

    for (int i = 0; i < size; i++)
    {
        cout << "________________________________" << endl;
        cout << "        Record " << i+1 << endl;
        cout << "________________________________" << endl;
        cout << "\n";
        cout << "Student name: " << s[i].name << endl;
        cout << "Student Age: " << s[i].age << endl;

        for (int j = 0; j < 3; j++)
        {
            cout << "Grade " << i+1 << ": "<< s[i].grade[j] << endl;
        }
    }



}