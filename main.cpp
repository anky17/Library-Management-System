//*******************************************************
//---------------LIBRARY MANAGEMENT SYSTEM--------------
//*******************************************************
// © 2024 Ankit Diyal. All rights reserved.
// Trademark ™ 2024 Ankit Diyal.

#include <bits/stdc++.h>
#include <conio.h>

#include <fstream>
#include <iostream>
using namespace std;
#define el "\n"

// Function prototypes
int res_book(int,
             int);  // To check whether any book a given book no. exists or not
bool res_student(
    int);  // To check whether the admission no. already exists or not

/*Class of books*/
class book {
  // Class members
 protected:
  int bno, quant;  // book no
  char bname[50];  // book name
  char aname[50];  // book author's name
  char pname[50];  // publication name
 public:
  // Member functions
  void createb();        // To enter data in data members of class book
  void showb();          // To display the details of books
  void showlist();       // To display book details in list form
  void assignbno(int x)  // bno assigned on the basis of no of objects in file
  {
    bno = 100;
    bno += x - 1;
  start1:
    bno += 1;
    if (res_book(bno, 0)) goto start1;
  }
  void set_q()  // Decreases the quantity of books by 1
  {
    quant -= 1;
  }
  int quantity()  // Returns the current quantity of books
  {
    return quant;
  }
  void reset_q()  // Increases the quantity of books by 1
  {
    quant += 1;
  }
  int retbno()  // Returns book number
  {
    return bno;
  }
};
void book::createb()  // To enter data in data members of class book
{
  int i;
  cout << "\n\t\tEnter the details:-\n";
  cout << "\n\t\tEnter Book's Name: ";
  char n[50];
  cin.getline(n, 50);
  cin.getline(bname, 50);
  for (i = 0; bname[i] != '\0'; i++) {
    if (bname[i] >= 'a' && bname[i] <= 'z') bname[i] -= 32;
  }
  cout << "\n\t\tEnter Author's Name: ";
  cin.getline(aname, 50);
  cout << "\n\t\tEnter Publication Name: ";
  cin.getline(pname, 50);
  cout << "\n\t\tEnter Book's quantity: ";
  cin >> quant;
}

void book::showb()  // To display the details of books
{
  cout << "\n\t\tBook No.: " << bno << el;
  cout << "\n\t\tBook Name: " << bname << el;
  cout << "\n\t\tBook's Author Name: " << aname << el;
  cout << "\n\t\tBook's Publication: " << pname << el;
  cout << "\n\t\tBook's Quantity: " << quant << el;
}

void book::showlist()  // To display book details in list form
{
  cout << "\n\t" << left << setw(15) << bno << setw(35) << bname << setw(30)
       << aname << setw(5) << quant;
}

/*Class of Students*/
class student {
  // Class members
 protected:
  char name[25];  // Student name
  int bno;        // Book no. of book issued
  int token;      // To verify book issued or not
 public:
  // Member functions
  void creates();       // To enter values to all data members of class student
  void shows();         // Show details of Students
  void showlist();      // To display Student details in list form
  void settoken(int x)  // To set token and assign bno a book no
  {
    bno = x;
    token = 1;
  }
  void resettoken()  // To reset token
  {
    bno = 0;
    token = 0;
  }
  int retbno() { return bno; }
  int admno;  // Admission No
};

void student::creates()  // To enter values to all data members of class student
{
  int i;
plane:
  system("CLS");
  cout << "\n\t\tEnter the details:-\n";
  cout << "\n\t\tEnter student's Admission no: ";
  cin >> admno;
  if (res_student(admno)) {
    cout << "\n\t\tRecord already exist with this admission no.";
    cout << "\n\t\tEnter a different admission no.\n";
    system("PAUSE");
    goto plane;
  }
  cout << "\n\t\tEnter student's Name: ";
  char n[50];
  cin.getline(n, 50);
  cin.getline(name, 25);
  for (i = 0; name[i] != '\0'; i++) {
    if (name[i] >= 'a' && name[i] <= 'z') name[i] -= 32;
  }
  bno = 0;
  token = 0;
}

void student::shows()  // Show details of Students
{
  cout << "\n\t\tStudent's Admission No.: " << admno << el;
  cout << "\n\t\tStudent's Name: " << name << el;
  if (token == 1) {
    cout << "\n\t\tBook Issued (Book no): " << bno;
  }
}

void student::showlist()  // To display Student details in list form
{
  cout << left << "\n\t" << admno << "\t\t\t" << setw(30) << name << "\t\t"
       << bno;
}

// Function prototypes for file operations
void write_book();
void write_student();
void list_student();
void list_book();
void search_student(int x);
void search_book(int x);
void modify_book(int x);
void modify_student(int x);
void delete_student(int x);
void delete_book(int x);

// Function prototypes for administrative tasks
void admin_menu();
bool passwords();

// Function prototypes for book operations
void book_issue();
void book_deposit();

// Main function
int main() {
  // Displaying introductory message
  cout << "\n\n\t\t\t*******************************************";
  cout << "\n\t\t\t------------------------------------------";
  cout << "\n\t\t\t\tLIBRARY MANAGEMENT SYSTEM";
  cout << "\n\t\t\t------------------------------------------";
  cout << "\n\t\t\t*******************************************";

  // Checking password
  bool a = passwords();
  if (!a) {
    for (int i = 0; i < 2; i++) {
      cout << "\nWrong password";
      cout << "\nYou have " << 2 - i << " attempts left";
      if (passwords()) goto last;
      if (i == 1) {
        cout << "\n\n\n\t\t\t All attempts failed........";
        cout << "\n\n\t\t\t Sorry, but you can't login";
        exit(0);
      }
    }
  }
last:
  cout << "\n\n";

start:
  cout << "\t\n*********LOGIN SUCCESSFUL*********\n";
  system("PAUSE");
  system("CLS");
  int opt;
  cout << "\n\n\t\t\t------------------------------------------";
  cout << "\n\t\t\t\tLIBRARY MANAGEMENT SYSTEM";
  cout << "\n\t\t\t------------------------------------------";
  cout << "\n\n\t\t\tWhat do you want to do?";
  cout << "\n\t\t\t1.\tBOOK ISSUE";
  cout << "\n\t\t\t2.\tBOOK DEPOSIT";
  cout << "\n\t\t\t3.\tADMINISTRATOR MENU";
  cout << "\n\t\t\t4.\tExit";
  cout << "\n\n Choose your option: ";
  cin >> opt;
  if (opt == 1) {
    system("CLS");
    book_issue();
    goto start;
  } else if (opt == 2) {
    system("CLS");
    book_deposit();
    goto start;
  } else if (opt == 3) {
    admin_menu();
    goto start;
  } else if (opt == 4)
    exit(0);
  else {
    cout << "\n\t\tEnter correct option";
    goto start;
  }

  return 0;
}

//*******************************************************
//---------------IMPLEMENTATION--------------------------
//*******************************************************

// Function to create book record
void write_book() {
  book bk;
  ofstream outf("book1.bin", ios::app | ios::binary);
  outf.seekp(0, ios::end);
  int x = outf.tellp() / sizeof(book);
  bk.assignbno(x);
  bk.createb();
  bk.showb();
  outf.write(reinterpret_cast<char *>(&bk), sizeof(book));
  cout << "\n\t\tRecord added successfully";
  outf.close();
}

// Function to create student record
void write_student() {
  student st;
  ofstream outf("student.bin", ios::app | ios::binary);
  outf.seekp(0, ios::end);
  st.creates();
  st.shows();
  outf.write(reinterpret_cast<char *>(&st), sizeof(student));
  cout << "\n\t\tRecord added successfully";
  outf.close();
}

// Function to display list of students
void list_student() {
  system("CLS");
  student st;
  ifstream intf("student.bin", ios::in | ios::binary);
  intf.seekg(0, ios::beg);
  if (!intf)
    cout << "\n\t\tFile not found";
  else {
    cout << "\n\t*****Students Details*****\n\n";
    cout << "\n\tAdmission No: \t\tName: \t\t\t\t\tBook Issued: ";
    while (intf.read(reinterpret_cast<char *>(&st), sizeof(student)))
      st.showlist();
  }
  intf.close();
}

// Function to display list of books
void list_book() {
  book bk;
  ifstream intf("book1.bin", ios::in | ios::binary);
  intf.seekg(0, ios::beg);
  if (!intf)
    cout << "\n\t\tFile not found";
  else {
    cout << "\n\t*****Books Details*****\n\n";
    cout << left << setw(15) << "\tBook No:" << setw(25)
         << "  Name:" << setw(20) << setw(15) << "\t\t Author's Name:"
         << "\t\t\tQuantity:" << endl;

    while (intf.read(reinterpret_cast<char *>(&bk), sizeof(book))){
    	if (bk.quantity() > 0)
    	bk.showlist();
	}
      
  }
  intf.close();
}

// Function to search for a specific student
void search_student(int x) {
  student st;
  int cnt = 0;
  ifstream intf("student.bin", ios::in | ios::binary);
  intf.seekg(0, ios::beg);
  if (!intf)
    cout << "\n\t\tFile not found";
  else {
    while (intf.read(reinterpret_cast<char *>(&st), sizeof(student))) {
      if (st.admno == x) {
        cnt++;
        cout << "\n\t\tFILE FOUND!!!!";
        st.shows();
        break;
      }
    }
    if (cnt == 0) cout << "\n\t\tNo such record exists";
  }
  intf.close();
}

/*To search for a specific book*/
void search_book(int x) {
  book bk;
  int cnt = 0;
  ifstream intf("book1.bin", ios::in | ios::binary);
  intf.seekg(0, ios::beg);
  if (!intf)
    cout << "\n\t\tFile not found";
  else {
    while (intf.read(reinterpret_cast<char *>(&bk), sizeof(book))) {
      if (bk.retbno() == x) {
        cnt++;
        cout << "\n\t\tFILE FOUND!!!!";
        bk.showb();
        break;
      }
    }
    if (cnt == 0) cout << "\n\t\tNo such record exists";
  }
  intf.close();
}

// Function to modify book records
void modify_book(int x) {
  book bk;
  int cnt = 0;
  fstream intf("book1.bin", ios::in | ios::out | ios::ate | ios::binary);
  intf.seekg(0, ios::beg);
  if (!intf)
    cout << "\n\t\tFile not found";
  else {
    while (intf.read(reinterpret_cast<char *>(&bk), sizeof(book))) {
      if (bk.retbno() == x) {
        cnt++;
        bk.createb();
        bk.showb();
        intf.seekp(static_cast<int>(intf.tellp()) -
                   static_cast<int>(sizeof(book)));

        intf.write(reinterpret_cast<char *>(&bk), sizeof(book));
        cout << "\n\t\tRecord Updated";
        break;
      }
    }
    if (cnt == 0) cout << "\n\t\tNo such record exists";
  }
  intf.close();
}

// Function to modify student records
void modify_student(int x) {
  student st;
  int cnt = 0;
  fstream intf("student.bin", ios::in | ios::out | ios::ate | ios::binary);
  intf.seekg(0, ios::beg);
  if (!intf)
    cout << "\n\t\tFile not found";
  else {
    while (intf.read(reinterpret_cast<char *>(&st), sizeof(student))) {
      if (st.admno == x) {
        cnt++;
        st.creates();
        st.shows();
        intf.seekp(static_cast<int>(intf.tellp()) -
                   static_cast<int>(sizeof(student)));

        intf.write(reinterpret_cast<char *>(&st), sizeof(student));
        cout << "\n\t\tRecord Updated";
        break;
      }
    }
    if (cnt == 0) cout << "\n\t\tNo such record exists";
  }
  intf.close();
}

// Function to delete a specific student record
void delete_student(int x) {
  student st;
  int cnt = 0;
  ifstream intf("student.bin", ios::in | ios::binary);
  intf.seekg(0, ios::beg);
  if (!intf)
    cout << "\n\t\tFile not found";
  else {
    ofstream outf("temp.bin", ios::app | ios::binary);
    while (intf.read(reinterpret_cast<char *>(&st), sizeof(student))) {
      if (st.admno == x)
        cnt++;
      else
        outf.write(reinterpret_cast<char *>(&st), sizeof(student));
    }
    intf.close();
    outf.close();
    if (cnt == 0) {
      remove("temp.bin");
      cout << "\n\t\tNo such record exists";
    } else {
      remove("student.bin");
      rename("temp.bin", "student.bin");
      cout << "\n\t\tRecord deleted successfully";
    }
  }
}

// Function to delete a specific book record
void delete_book(int x) {
  book bk;
  int cnt = 0;
  ifstream intf("book1.bin", ios::in | ios::binary);
  intf.seekg(0, ios::beg);
  if (!intf)
    cout << "\n\t\tFile not found";
  else {
    ofstream outf("temp1.bin", ios::app | ios::binary);
    while (intf.read(reinterpret_cast<char *>(&bk), sizeof(book))) {
      if (bk.retbno() == x){
	  
        cnt++;
    }
      else
        outf.write(reinterpret_cast<char *>(&bk), sizeof(book));
    }
    intf.close();
    outf.close();
    if (cnt == 0) {
      remove("temp1.bin");
      cout << "\n\t\tNo such record exists";
    } else {
      remove("book1.bin");
      rename("temp1.bin", "book1.bin");
      cout << "\n\t\tRecord deleted successfully";
    }
  }
}

// Function to display administrator menu
void admin_menu() {
fine:
  system("PAUSE");
  system("CLS");
  int opt;
  cout << "\n\n\n\t\t\t******ADMINISTRATOR MENU******";
  cout << "\n\n\t1.\tCREATE STUDENT RECORD";
  cout << "\n\n\t2.\tDISPLAY ALL STUDENTS RECORD";
  cout << "\n\n\t3.\tDISPLAY SPECIFIC STUDENT RECORD ";
  cout << "\n\n\t4.\tMODIFY STUDENT RECORD";
  cout << "\n\n\t5.\tDELETE STUDENT RECORD";
  cout << "\n\n\t6.\tCREATE BOOK ";
  cout << "\n\n\t7.\tDISPLAY ALL BOOKS ";
  cout << "\n\n\t8.\tDISPLAY SPECIFIC BOOK ";
  cout << "\n\n\t9.\tMODIFY BOOK ";
  cout << "\n\n\t10.\tDELETE BOOK ";
  cout << "\n\n\t11.\tBACK TO MAIN MENU";
  cout << "\n\n\tPlease Enter Your Choice: ";
  cin >> opt;
  if (opt == 1) {
    system("CLS");
    write_student();
    cout << el;
    goto fine;
  } else if (opt == 2) {
    system("CLS");
    list_student();
    cout << el;
    goto fine;
  } else if (opt == 3) {
    system("CLS");
    int ad;
    cout << "\n\n\n\t\tEnter the admission number of the student: ";
    cin >> ad;
    search_student(ad);
    cout << el;
    goto fine;
  } else if (opt == 4) {
    system("CLS");
    int ad;
    cout << "\n\n\n\t\tEnter the admission number of the student: ";
    cin >> ad;
    modify_student(ad);
    cout << el;
    goto fine;
  } else if (opt == 5) {
    system("CLS");
    int ad;
    cout << "\n\n\n\t\tEnter the admission number of the student: ";
    cin >> ad;
    delete_student(ad);
    cout << el;
    goto fine;
  } else if (opt == 6) {
    system("CLS");
    write_book();
    cout << el;
    goto fine;
  } else if (opt == 7) {
    system("CLS");
    list_book();
    cout << el;
    goto fine;
  } else if (opt == 8) {
    system("CLS");
    int ad;
    cout << "\n\n\n\t\tEnter the book number of the book: ";
    cin >> ad;
    search_book(ad);
    cout << el;
    goto fine;
  } else if (opt == 9) {
    system("CLS");
    int ad;
    cout << "\n\n\n\t\tEnter the book number of the book: ";
    cin >> ad;
    modify_book(ad);
    cout << el;
    goto fine;
  } else if (opt == 10) {
    system("CLS");
    int ad;
    cout << "\n\n\n\t\tEnter the book number of the book: ";
    cin >> ad;
    delete_book(ad);
    cout << el;
    goto fine;
  } else if (opt == 11)
    return;
  else {
    cout << "\n\t\tEnter correct option";
    cout << el;
    goto fine;
  }
}

// Function to check passwords
bool passwords() {
  int i = 0;
  char ch, st[21], ch1[21] = {"ankit"};
  cout << "\n\n\t\tEnter Password : ";
  while (1) {
    ch = getch();
    if (ch == 13) {
      st[i] = '\0';
      break;
    }
    // This condition is used when you have entered wrong character as password
    else if (ch == 8 && i > 0)  // ASCII=8 is for backspace to move cursor one
                                // position back
    {
      i--;
      cout << "\b \b";
    } else {
      cout << "*";
      st[i] = ch;
      i++;
    }
  }
  for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++)
    ;  // this semi-colon is used to denote that there is nothing inside the
       // loop body the loop gets terminated after the terminating condition

  if (st[i] == '\0' && ch1[i] == '\0')
    return 1;
  else
    return 0;
}

// Function to issue books
void book_issue() {
  int sn, bn;
	system("CLS");
	cout << "\n\n\t\t*****BOOK ISSUE******";
	cout << "\n\n\t\tEnter the student's admission number: ";
	cin >> sn;
	int cnt = 0;
	student st;
	fstream outf("student.bin", ios::in | ios::out | ios::ate | ios::binary);
	outf.seekg(0, ios::beg);
	if (!outf)
		cout << "\n\t\tFile not found\n";
	else
	{
		while (outf.read(reinterpret_cast<char *>(&st), sizeof(student)))
		{
			if (st.admno == sn)
			{
				cnt++;
				list_book();
				cout << "\n\n\t\tEnter the book number:";
				cin >> bn;
				cout << "\n";
				int flag = res_book(bn, 1); //The res_book() function is called with two arguments: bn (book number) and
											// 1 (a flag indicating a specific operation related to book status).
				if (flag == 1)
				{
					st.settoken(bn);
					outf.seekp(static_cast<int>(outf.tellp()) - static_cast<int>(sizeof(student)));
					outf.write(reinterpret_cast<char *>(&st), sizeof(student));
					cout << "\n\t\tBook Issued";
					cout << "\n\t\tNote: Write the current date in the record file";
					cout << "\n\t\t      Should be submitted within 10 days to avoid fine";
					cout << "\n\t\t      The fine is Rs. 2 for each day after 10 days period\n";
					break;
				}
				else if (flag == 2)
				{
					cout << "\n\t\tTHE BOOK IS OUT OF STOCK!!!";
					break;
				}
				else
				{
					cout << "\n\t\tNo such record exists\n";
					break;
				}
			}
		}
		if (cnt == 0)
			cout << "\n\t\tNo such record exists\n";
	}
	outf.close();
}

// Function to deposit books
void book_deposit() {
  int sn, bn;
  system("CLS");
  cout << "\n\n\t\t*****BOOK DEPOSIT******";
  cout << "\n\n\t\tEnter the student's admission number: ";
  cin >> sn;
  int cnt = 0;
  student st;
  fstream outf("student.bin", ios::in | ios::out | ios::ate | ios::binary);
  outf.seekg(0, ios::beg);
  if (!outf)
    cout << "\n\t\tFile not found\n";
  else {
    while (outf.read(reinterpret_cast<char *>(&st), sizeof(student))) {
      if (st.admno == sn) {
        cnt++;
        bn = st.retbno();
        bool flag = res_book(bn, 2);
        if (flag) {
          st.resettoken();
          outf.seekp(static_cast<int>(outf.tellp()) -
                     static_cast<int>(sizeof(student)));
          outf.write(reinterpret_cast<char *>(&st), sizeof(student));
          int days;
          cout << "\n\t\tBook deposited in number of days:";
          cin >> days;
          if (days > 10) {
            int fine = (days - 10) * 2;
            cout << "\n\n\t\tFine: " << fine << el;
          }
          cout << "\n\t\tBook Deposited Successfully\n";
          break;
        } else {
          cout << "\n\t\tNo such record exists\n";
          break;
        }
      }
    }
    if (cnt == 0) cout << "\n\t\tNo such record exists\n";
  }
  outf.close();
}

// To search whether a specific student record exists or not
bool res_student(int x) {
  student st;
  int cnt = 0, f = 0;
  ifstream intf("student.bin", ios::in | ios::binary);
  intf.seekg(0, ios::beg);
  if (!intf)
    f = 1;
  else {
    while (intf.read(reinterpret_cast<char *>(&st), sizeof(student))) {
      if (st.admno == x) {
        cnt++;
        break;
      }
    }
    if (cnt == 0) f = 1;
  }
  intf.close();
  if (f)
    return 0;
  else
    return 1;
}

/*To search a specific book and return true or false*/
int res_book(int x, int z) {
  book bk;
  int cnt = 0, f = 1;
  fstream intf("book1.bin", ios::in | ios::out | ios::ate | ios::binary);
  intf.seekg(0, ios::beg);
  if (!intf)
    f = 0;
  else {
    while (intf.read(reinterpret_cast<char *>(&bk), sizeof(book))) {
      if (bk.retbno() == x) {
        cnt++;  // Counting Book Occurrences: cnt is initialized to 0 and serves
                // as a counter to track how many times a book with the given
                // book number (x) appears in the file
        if (z == 1) {
          bk.showb();
          if (bk.quantity() > 0) {
            bk.set_q();
            intf.seekp(static_cast<int>(intf.tellp()) -
                       static_cast<int>(sizeof(book)));
            intf.write(reinterpret_cast<char *>(&bk), sizeof(book));
          } else
            f = 2;
        } else if (z == 2) {
          bk.showb();
          bk.reset_q();
          intf.seekp(static_cast<int>(intf.tellp()) -
                     static_cast<int>(sizeof(book)));
          intf.write(reinterpret_cast<char *>(&bk), sizeof(book));
        }
        break;
      }
    }
    if (cnt == 0) f = 0;
  }
  intf.close();
  return f;
}
