#include <iostream>
#include <myconio_mac.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

class Book
{
    int book_id;
    string b_name;
    string a_name;

public:
    void create_book()
    {
        cout << "New BOOK" << endl;
        cout << "Enter book ID : ";
        cin >> book_id;
        cout << "Enter Book Name : ";
        getline(cin, b_name);
        cout << "Enter Author Name: ";
        getline(cin, a_name);
    }

    void showBook()
    {
        cout << "Book Id : " << book_id << endl;
        cout << "Book Name : " << b_name << endl;
        cout << "Author Name : " << a_name << endl;
    }

    void modifyBook()
    {
        cout << "Book ID :" << book_id << endl;
        cout << "Modify Name : ";
        getline(cin, b_name);
        cout << "Modify Author's Name : ";
        getline(cin, a_name);
    }
    int return_BookID()
    {
        return book_id;
    }

    void report()
    {
        // video 6.
    }

    string return_B_Name()
    {
        return b_name;
    }
};

class Student
{
    int admin_no;
    string Name;
    char stdbno[6];
    int book_holding;

public:
    void create_std()
    {
        clrscr();
        cout << "New Student" << endl;
        cout << "Enter admin no : ";
        cin >> admin_no;
        cout << "Enter  Name : ";
        getline(cin, Name);

        book_holding = 0;
        stdbno[0] = '\0';
        cout << "Profile Created." << endl;
    }

    void showStudent()
    {
        cout << "Admin no.: " << admin_no << endl;
        cout << "Name : " << Name << endl;
        cout << "Book Taken : " << book_holding << endl;
        if (book_holding == 1)
        {
            cout << "Book no." << stdbno;
        }
    }

    void modifyStudent()
    {
        cout << "Enter the admin no." << admin_no << endl;
        cout << "Modify student name:";
        getline(cin, Name);
    }

    int return_adminNo()
    {
        return admin_no;
    }

    char *return_studentBookno()
    {
        return stdbno;
    }

    int return_book_holding()
    {
        return book_holding;
    }

    void add_book_holding()
    {
        book_holding = 1;
    }

    void reset_book_holding()
    {
        book_holding = 0;
    }

    void getStudentBOOKno(char t[])
    {
        strcpy(stdbno, t);
    }

    void report(char t[])
    {
        // video 7
        // cout<<admin_no<<
    }
};

fstream fp, fp1;

Book bk;
Student st;

void writeBook()
{
    char ch = 'y';
    fp.open("book.dat", ios::out | ios::app);
    do
    {
        clrscr();
        bk.create_book();
        fp.write((char *)&bk, sizeof(Book));
        cout << "\n Add more. (y/n)?" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fp.close();
}

void writeStudent()
{
    char ch = 'y';
    fp.open("Student.dat", ios::out | ios::app);
    do
    {
        clrscr();
        st.create_std();
        fp.write((char *)&st, sizeof(Student));
        cout << "\n Add more. (y/n)?" << endl;
        cin >> ch;
    } while (ch == 'y' || ch != 'Y');
    fp.close();
}

void displayspb(int bookID)
{
    cout << "\nBook Details :" << endl;
    bool flag = 0;
    fp.open("book.dat", ios::in);
    while (fp.read((char *)&bk, sizeof(Book)))
    {
        if (bk.return_BookID() == bookID)
        {

            bk.showBook();
            flag = 1;
        }
    }
    fp.close();
    if (!flag)
    {
        cout << "Book Doesn't Exist." << endl;
    }
}

void displayspStd(int admin_no)
{
    cout << "Student Details :" << endl;
    bool flag = 0;
    fp.open("student.dat", ios::in);
    while (fp.read((char *)&st, sizeof(Student)))
    {
        if (st.return_adminNo() == admin_no)
        {

            st.showStudent();
            flag = 1;
        }
    }
    fp.close();
    if (!flag)
    {
        cout << "Student Doesn't Exist." << endl;
    }
}

void modifyBook()
{
    int book_id;
    bool found = false;
    clrscr();
    cout << "\nModify Book Record." << endl;
    cout << "Enter the Book no. :";
    cin >> book_id;
    fp.open("book.dat", ios::in || ios::out);
    while (fp.read((char *)&bk, sizeof(Book)))
    {
        if (book_id == bk.return_BookID())
        {
            bk.showBook();
            cout << "Enter the New detials" << endl;
            bk.modifyBook();
            int pos = -1 * sizeof(bk);
            fp.seekp(pos, ios::cur);
            fp.write((char *)&bk, sizeof(Book));
            cout << "\nRecord Updated" << endl;
            found = true;
        }
    }
    fp.close();
    if (!found)
    {
        cout << "No Book found" << endl;
    }
    getchar();
}

void start()
{
    clrscr();
    gotoxy(35, 11);
    cout << "LIB";
    gotoxy(35, 14);
    cout << "MAG";
    gotoxy(35, 17);
    cout << "SYS";
    getch();
}

int main();

void adminMenu()
{

    clrscr();
    int ch2;
    cout << "\n\tAdmin Menu" << endl;
    cout << "\n\t1.Create Student Record." << endl;
    cout << "\n\t2.Display All Students." << endl;
    cout << "\n\t3.Display 1 Student." << endl;
    cout << "\n\t4.Modify Student." << endl;
    cout << "\n\t5.Delete Student." << endl;
    cout << "\n\t6.Create Book." << endl;
    cout << "\n\t7.Display All Books." << endl;
    cout << "\n\t8.Display 1 Book." << endl;
    cout << "\n\t9.Modify Book" << endl;
    cout << "\n\t10.Delete Book" << endl;
    cout << "\n\t11.Back to Main." << endl;
    cout << "Option : ";
    cin >> ch2;
    int stdID;
    int BookID;
    switch (ch2)
    {
    case 1:
        // writeStudent();
        break;
    case 2:
        // displayALLStudent() ;
        break;
    case 3:
        clrscr();
        cout << "Enter Admissoin no of student : ";
        cin >> stdID;
        // display1Student();
        break;
    case 4:
        clrscr();
        // modifystudent();
        break;
    case 5:
        // deleteStudent();
        break;
    case 6:
        // writeBook();
        break;
    case 7:
        // displayALLBooks() ;
        break;
    case 8:
        clrscr();
        cout << "Enter Book Id : ";
        cin >> BookID;
        // display1Book();
        break;
    case 9:
        clrscr();
        // modifyBook();
        break;
    case 10:
        // deleteBook();
        break;
    case 11:
        main();
        break;
    default:
        break;
    }
    adminMenu();
}

int main()
{
    char ch;
    start();
    do
    {
        clrscr();
        cout << "\n\tMain Menu" << endl;
        cout << "\t1.Book Issue" << endl;
        cout << "\t2.Book Deposit" << endl;
        cout << "\t3.Admin Menu" << endl;
        cout << "\t4.Exit" << endl;
        cout << "Option : ";
        ch = getchar();
        switch (ch)
        {
        case '1':
            // bookissue();
            break;

        case '2':
            // bookdeposit();
            break;

        case '3':
            adminMenu();
            break;

        case '4':
            exit(0);
            break;

        default:
            break;
        }

    } while (ch != '4');
    return 0;
}