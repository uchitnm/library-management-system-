// #include <iostream>
// #include <myconio_mac.h>
// #include <stdlib.h>
// #include <string.h>
// #include <fstream>
// using namespace std;

// class Book
// {
//     int book_id;
//     string b_name;
//     string a_name;

// public:
//     void create_book()
//     {
//         cout << "New BOOK" << endl;
//         cout << "Enter book ID : ";
//         cin >> book_id;
//         cout << "Enter Book Name : ";
//         getline(cin, b_name);
//         cout << "Enter Author Name: ";
//         getline(cin, a_name);
//     }

//     void showBook()
//     {
//         cout << "Book Id : " << book_id << endl;
//         cout << "Book Name : " << b_name << endl;
//         cout << "Author Name : " << a_name << endl;
//     }

//     void modifyBook()
//     {
//         cout << "Book ID :" << book_id << endl;
//         cout << "Modify Name : ";
//         getline(cin, b_name);
//         cout << "Modify Author's Name : ";
//         getline(cin, a_name);
//     }
//     int return_BookID()
//     {
//         return book_id;
//     }

//     void report()
//     {
//         // video 6.
//         cout << book_id << " | " << b_name << " | " << a_name << " | " << endl;
//     }

//     string return_B_Name()
//     {
//         return b_name;
//     }
// };

// class Student
// {
//     int admin_no;
//     string Name;
//     int stdbno;
//     int book_holding;

// public:
//     void create_std()
//     {
//         clrscr();
//         cout << "New Student" << endl;
//         cout << "Enter admin no : ";
//         cin >> admin_no;
//         cout << "Enter  Name : ";
//         cin >> Name ;
//         book_holding = 0;
//         stdbno = 0;
//         cout << "Profile Created." << endl;
//     }

//     void showStudent()
//     {
//         cout << "Admin no.: " << admin_no << endl;
//         cout << "Name : " << Name << endl;
//         cout << "Book Taken : " << book_holding << endl;
//         if (book_holding == 1)
//         {
//             cout << "Book no." << stdbno;
//         }
//     }

//     void modifyStudent()
//     {
//         cout << "Enter the admin no." << admin_no << endl;
//         cout << "Modify student name:";
//         getline(cin, Name);
//     }

//     int return_adminNo()
//     {
//         return admin_no;
//     }

//     int return_studentBookno()
//     {
//         return stdbno;
//     }

//     int return_book_holding()
//     {
//         return book_holding;
//     }

//     void add_book_holding()
//     {
//         book_holding = 1;
//     }

//     void reset_book_holding()
//     {
//         book_holding = 0;
//     }

//     void getStudentBOOKno(int t)
//     {
//         stdbno = t;
//     }

//     void report()
//     {
//         // video 7
//         cout << admin_no << " | " << Name << " | " << book_holding << " | " << endl;
//     }
// };

// fstream fp, fp1;

// Book bk;
// Student st;

// void writeBook()
// {
//     char ch = 'y';
//     fp.open("book.dat", ios::out | ios::app);
//     do
//     {
//         clrscr();
//         bk.create_book();
//         fp.write((char *)&bk, sizeof(Book));
//         cout << "\n Add more. (y/n)?" << endl;
//         cin >> ch;
//     } while (ch == 'y' || ch == 'Y');
//     fp.close();
// }

// void writeStudent()
// {
//     char ch;
//     fp.open("Student.dat", ios::app | ios::out);
//     do
//     {
//         clrscr();
//         st.create_std();
//         fp.write((char *)&st, sizeof(Student));
//         cout << "\n Add more. (y/n)?" << endl;
//         ch = getch();

//     } while (ch == 'y' || ch != 'Y');
//     fp.close();
// }

// void displayspb(int bookID)
// {
//     cout << "\nBook Details :" << endl;
//     bool flag = 0;
//     fp.open("book.dat", ios::in);
//     while (fp.read((char *)&bk, sizeof(Book)))
//     {
//         if (bk.return_BookID() == bookID)
//         {

//             bk.showBook();
//             flag = 1;
//         }
//     }
//     fp.close();
//     if (!flag)
//     {
//         cout << "Book Doesn't Exist." << endl;
//     }
// }

// void displayspStd(int admin_no)
// {
//     cout << "Student Details :" << endl;
//     bool flag = 0;
//     fp.open("student.dat", ios::in);
//     while (fp.read((char *)&st, sizeof(Student)))
//     {
//         if (st.return_adminNo() == admin_no)
//         {

//             st.showStudent();
//             flag = 1;
//         }
//     }
//     fp.close();
//     if (!flag)
//     {
//         cout << "Student Doesn't Exist." << endl;
//     }
// }

// void modifyBook()
// {
//     int book_id;
//     bool found = false;
//     clrscr();
//     cout << "\nModify Book Record." << endl;
//     cout << "Enter the Book no. :";
//     cin >> book_id;
//     fp.open("book.dat", ios::in | ios::out);
//     while (fp.read((char *)&bk, sizeof(Book)))
//     {
//         if (book_id == bk.return_BookID())
//         {
//             bk.showBook();
//             cout << "Enter the New detials" << endl;
//             bk.modifyBook();
//             int pos = -1 * (int)sizeof(bk);
//             fp.seekp(pos, ios::cur);
//             fp.write((char *)&bk, sizeof(Book));
//             cout << "\nRecord Updated" << endl;
//             found = true;
//         }
//     }
//     fp.close();
//     if (!found)
//     {
//         cout << "No Book found" << endl;
//     }
//     getchar();
// }

// void modifyStudent()
// {
//     int admin_no;
//     bool found = false;
//     clrscr();
//     cout << "\nModify Student Record." << endl;
//     cout << "Enter the Admin no. :";
//     cin >> admin_no;
//     fp.open("Student.dat", ios::in | ios::out);
//     while (fp.read((char *)&st, sizeof(Student)))
//     {
//         if (admin_no == st.return_adminNo())
//         {
//             st.showStudent();
//             cout << "Enter the New detials" << endl;
//             st.modifyStudent();
//             int pos = -1 * (int)sizeof(st);
//             fp.seekp(pos, ios::cur);
//             fp.write((char *)&st, sizeof(Student));
//             cout << "\nRecord Updated" << endl;
//             found = true;
//         }
//     }
//     fp.close();
//     if (!found)
//     {
//         cout << "No Student found" << endl;
//     }
//     getchar();
// }

// void deleteStudent()
// {

//     int admin_no;
//     bool flag = false;
//     clrscr();
//     cout << "\n\tDelete Student." << endl;
//     cout << "Enter thr Admin no." << endl;
//     cin >> admin_no;
//     fp.open("Student.dat", ios::in | ios::out);
//     fstream fp2;
//     fp2.open("temp.dat", ios::out);
//     fp.seekg(0, ios::beg);
//     while (fp.read((char *)&st, sizeof(Student)))
//     {
//         if (admin_no != st.return_adminNo())
//         {
//             fp2.write((char *)&st, sizeof(Student));
//         }
//         else
//         {

//             flag = true;
//         }
//     }
//     fp2.close();
//     fp.close();
//     remove("student.dat");
//     rename("temp.dat", "student.dat");
//     if (flag)
//     {
//         cout << "Record deleted" << endl;
//     }
//     else
//     {
//         cout << "Record not found." << endl;
//     }

//     getchar();
// }

// void deleteBook()
// {

//     int Book_ID;
//     bool flag = false;
//     clrscr();
//     cout << "\n\tDelete BOOK." << endl;
//     cout << "Enter thr Book ID." << endl;
//     cin >> Book_ID;
//     fp.open("Book.dat", ios::in | ios::out);
//     fstream fp2;
//     fp2.open("temp.dat", ios::out);
//     fp.seekg(0, ios::beg);
//     while (fp.read((char *)&bk, sizeof(Book)))
//     {
//         if (Book_ID != bk.return_BookID())
//         {
//             fp2.write((char *)&bk, sizeof(Book));
//         }
//         else
//         {

//             flag = true;
//         }
//     }
//     fp2.close();
//     fp.close();
//     remove("book.dat");
//     rename("temp.dat", "book.dat");
//     if (flag)
//     {
//         cout << "Record deleted" << endl;
//     }
//     else
//     {
//         cout << "Record not found." << endl;
//     }

//     getchar();
// }

// void DispAllStd()
// {
//     clrscr();
//     fp.open("student.dat", ios::in);
//     if (!fp)
//     {
//         cout << "File not Open" << endl;
//         getchar();
//         return;
//     }
//     cout << "\n\n\tStudent list" << endl;
//     cout << "=======" << endl;
//     cout << "Admin no | "
//          << " Name | "
//          << " | Book no. | " << endl;
//     while (fp.read((char *)&st, sizeof(Student)))
//     {
//         st.report();
//     }
//     fp.close();
//     getchar();
// }

// void DispAllBook()
// {
//     clrscr();
//     fp.open("book.dat", ios::in);
//     if (!fp)
//     {
//         cout << "File not Open" << endl;
//         getchar();
//         return;
//     }
//     cout << "\n\nBooks list" << endl;
//     cout << "=======" << endl;
//     cout << "Book ID | "
//          << " Name | "
//          << " | Author | " << endl;
//     while (fp.read((char *)&bk, sizeof(Book)))
//     {
//         bk.report();
//     }
//     fp.close();
//     getchar();
// }

// void bookissue()
// {

//     int student_adminNo;
//     int BookID;

//     bool found = false, flag = false;

//     clrscr();
//     cout << "\tBook Issue:-" << endl;
//     cout << "Enter Student admin no.:";
//     cin >> student_adminNo;
//     fp.open("student.dat", ios::in | ios ::out);
//     fp1.open("book.dat", ios::in | ios ::out);
//     while (fp.read((char *)&st, sizeof(Student)) && !found)
//     {
//         if (st.return_adminNo() == student_adminNo)
//         {
//             found = true;
//             if (st.return_book_holding() == 0)
//             {
//                 cout << "Enter the Book ID: " << endl;
//                 cin >> BookID;
//                 while (fp1.read((char *)&bk, sizeof(Book)) && !flag)
//                 {
//                     if (bk.return_BookID() == BookID)
//                     {
//                         flag = true;
//                         st.add_book_holding();
//                         st.getStudentBOOKno(bk.return_BookID());
//                         int pos = -1 * (int)sizeof(st);
//                         fp.seekg(pos, ios::cur);
//                         fp.write((char *)&st, sizeof(Student));
//                         cout << "Book issued." << endl;
//                         // Fine message.
//                     }
//                 }
//                 if (flag == 0)
//                 {
//                     cout << "Book doesn't Exist." << endl;
//                 }
//                 else
//                 {
//                     cout << "Return the previous Book" << endl;
//                 }
//             }
//         }
//     }
//     if (found == 0)
//     {
//         cout << "No Student Found" << endl;
//     }
//     getchar();
//     fp.close();
//     fp1.close();
// }

// void bookDeposit()
// {

//     int student_adminNo;
//     int BookID;

//     bool found = false, flag = false;

//     clrscr();
//     cout << "\tBook Deposit :- " << endl;
//     cout << "Enter Student admin no.:";
//     cin >> student_adminNo;
//     fp.open("student.dat", ios::in | ios ::out);
//     fp1.open("book.dat", ios::in | ios ::out);
//     while (fp.read((char *)&st, sizeof(Student)) && !found)
//     {
//         if (st.return_adminNo() == student_adminNo)
//         {
//             found = true;
//             if (st.return_book_holding() == 1)
//             {
//                 cout << "Enter the Book ID: " << endl;
//                 cin >> BookID;
//                 while (fp1.read((char *)&bk, sizeof(Book)) && !flag)
//                 {
//                     if (bk.return_BookID() == st.return_studentBookno())
//                     {
//                         flag = true;
//                         bk.showBook();

//                         st.reset_book_holding();
//                         int pos = -1 * (int)sizeof(st);
//                         fp.seekg(pos, ios::cur);
//                         fp.write((char *)&st, sizeof(Student));
//                         cout << "Book Deposited." << endl;
//                     }
//                 }
//                 if (flag == 0)
//                 {
//                     cout << "Book doesn't Exist." << endl;
//                 }
//                 else
//                 {
//                     cout << "No book Issued." << endl;
//                 }
//             }
//         }
//     }
//     if (found == 0)
//     {
//         cout << "No Student Found" << endl;
//     }
//     getchar();
//     fp.close();
//     fp1.close();
// }

// void start()
// {
//     clrscr();
//     gotoxy(35, 11);
//     cout << "LIB";
//     gotoxy(35, 14);
//     cout << "MAG";
//     gotoxy(35, 17);
//     cout << "SYS";
//     getch();
// }

// int main();

// void adminMenu()
// {

//     clrscr();
//     int ch2;
//     cout << "\n\tAdmin Menu" << endl;
//     cout << "\n\t1.Create Student Record." << endl;
//     cout << "\n\t2.Display All Students." << endl;
//     cout << "\n\t3.Display 1 Student." << endl;
//     cout << "\n\t4.Modify Student." << endl;
//     cout << "\n\t5.Delete Student." << endl;
//     cout << "\n\t6.Create Book." << endl;
//     cout << "\n\t7.Display All Books." << endl;
//     cout << "\n\t8.Display 1 Book." << endl;
//     cout << "\n\t9.Modify Book" << endl;
//     cout << "\n\t10.Delete Book" << endl;
//     cout << "\n\t11.Back to Main." << endl;
//     cout << "Option : ";
//     cin >> ch2;
//     int stdID;
//     int BookID;
//     switch (ch2)
//     {
//     case 1:
//         // writeStudent();
//         writeStudent();
//         break;
//     case 2:
//         // displayALLStudent() ;
//         DispAllStd();
//         break;
//     case 3:
//         clrscr();
//         cout << "Enter Admissoin no of student : ";
//         cin >> stdID;
//         // display1Student();
//         displayspStd(stdID);
//         break;
//     case 4:
//         clrscr();
//         // modifystudent();
//         modifyStudent();
//         break;
//     case 5:
//         // deleteStudent();
//         deleteStudent();
//         break;
//     case 6:
//         // writeBook();
//         writeBook();
//         break;
//     case 7:
//         // displayALLBooks() ;
//         DispAllBook();
//         break;
//     case 8:
//         clrscr();
//         cout << "Enter Book Id : ";
//         cin >> BookID;
//         // display1Book();
//         displayspb(BookID);
//         break;
//     case 9:
//         clrscr();
//         // modifyBook();
//         modifyBook();
//         break;
//     case 10:
//         // deleteBook();
//         deleteBook();
//         break;
//     case 11:
//         main();
//         break;
//     default:
//         break;
//     }
//     adminMenu();
// }

// int main()
// {
//     char ch;
//     start();
//     do
//     {
//         clrscr();
//         cout << "\n\tMain Menu" << endl;
//         cout << "\t1.Book Issue" << endl;
//         cout << "\t2.Book Deposit" << endl;
//         cout << "\t3.Admin Menu" << endl;
//         cout << "\t4.Exit" << endl;
//         cout << "Option : ";
//         ch = getchar();
//         switch (ch)
//         {
//         case '1':
//             // bookissue();
//             bookissue();
//             break;

//         case '2':
//             // bookdeposit();
//             bookDeposit();
//             break;

//         case '3':
//             adminMenu();
//             break;

//         case '4':
//             exit(0);
//             break;

//         default:
//             break;
//         }

//     } while (ch != '4');
//     return 0;
// }