# Library Management System - Software Design Document

---

# 1. Project Overview

The Library Management System is a console-based software application developed using C++. It is designed to help librarians efficiently manage books, members, book issuing, returns, fines, and library records.

The project follows Object-Oriented Programming (OOP) principles and is being developed in multiple phases. The initial version will be a console application, with future plans to convert it into a desktop application using Qt and later integrate an SQLite database.

---

# 2. Project Objective

The objective of this project is to build a real-world software application that demonstrates:

- Object-Oriented Programming
- File Handling
- STL (Standard Template Library)
- Software Design Principles
- Git & GitHub Workflow

This project is intended to simulate how an actual library management software works.

---

# 3. Users

## Librarian (Version 1)

The librarian can:

- Add Books
- Delete Books
- Update Book Information
- Search Books
- Register Members
- Remove Members
- Search Members
- Issue Books
- Return Books
- Manage Fine Payments
- Generate Reports

---

## Student (Future Version)

The student will be able to:

- Search Books
- View Book Availability
- View Borrowed Books
- View Total Fine

---

# 4. Core Features

## Book Management

- Add Book
- Remove Book
- Update Book
- Search Book
- View All Books

## Member Management

- Register Member
- Remove Member
- Search Member
- View Members
- Update Member

## Transaction Management

- Issue Book
- Return Book
- Store Borrowing History

## Fine Management

- Automatic Fine Calculation
- Total Fine Per Member
- Fine History Per Transaction
- Fine Payment

## Reports

- Total Books
- Total Members
- Available Books
- Issued Books
- Total Fines

## File Storage

- Save Data
- Load Data

---

# 5. Core Classes

The project will initially contain four major classes.

## Book

Stores all information related to books.

## Member

Stores all information related to library members.

## Transaction

Stores every borrowing and returning record.

## Library

Acts as the central controller of the entire system.

---

# 6. Software Architecture

Library
│
├── Book
│
├── Member
│
└── Transaction

The Library class manages all Books, Members, and Transactions.

---

# 7. Development Roadmap

Phase 1
- Console Application

Phase 2
- Complete Library Logic

Phase 3
- File Handling

Phase 4
- Fine Management

Phase 5
- Reports

Phase 6
- Qt Desktop GUI

Phase 7
- SQLite Database

---

# 8. Future Enhancements

- Login System
- Book Reservation
- QR Code Support
- Email Notifications
- Dashboard
- Charts & Statistics
- Web Version
- Mobile Application

---

# 9. Design Decisions

- Library owns all Books, Members, and Transactions.
- Book stores only book-related information.
- Member stores current total unpaid fine.
- Transaction stores fine generated for each borrowing event.
- Business logic will be handled by the Library class.

---

# 10. Book Class Design

## Responsibility

The Book class stores all information related to a single book in the library. It does not handle issuing, returning, searching, or fine calculation. Those responsibilities belong to the Library and Transaction classes.

### Attributes

- Book ID
- Title
- Author
- Category
- Publisher
- ISBN
- Publication Year
- Total Copies
- Available Copies

### Member Functions

- Constructor
- displayBook()
- updateBook()
- isAvailable()

### Design Decisions

- Total Copies remains constant unless the librarian adds or removes copies.
- Available Copies changes whenever a book is issued or returned.
- The Book class does not know which member borrowed it.
- Borrowing information is stored in the Transaction class.

---

# 11. Member Class Design

## Responsibility

The Member class stores all information related to a library member. It maintains the member's personal details, borrowing status, and total unpaid fine. It does not issue books, return books, or calculate fines. Those responsibilities belong to the Library class.

### Attributes

- Member ID
- Roll Number
- Name
- Department
- Phone Number
- Email
- Borrowed Book Count
- Total Fine

### Member Functions

- Constructor
- displayMember()
- updateMember()
- hasFine()

### Design Decisions

- Every member has a unique Member ID.
- Every student also has a unique College Roll Number.
- Total Fine stores the total unpaid fine of the member.
- Individual fine records are stored in the Transaction class.
- Borrowed Book Count stores the number of books currently borrowed.
- Complete borrowing history is maintained by the Transaction class.

---

# 12. Library Policies

The Library class defines the rules that apply to every member and transaction.

## Initial Policies

- Maximum Books Per Member = 5
- Loan Duration = 15 Days
- Fine Per Day = ₹10
- Maximum Borrowing Fine Limit = ₹100

These values are configurable and can be modified in future versions without changing the rest of the software.

## Borrowing Rules

- A member cannot borrow more than 5 books at the same time.
- A book can only be issued if at least one copy is available.
- A member with pending fine can still be searched, but future borrowing restrictions may be added in later versions.
- Members with Total Fine greater than ₹100 cannot borrow new books until the fine is reduced below the limit.

---

# 13. Fine Payment Workflow

The librarian can collect fine payments from members.

## Workflow

- Enter Member ID
- Verify Member Exists
- Display Current Total Fine
- Enter Amount Paid
- Update Member's Total Fine
- Save Updated Data
- Display Payment Successful

## Rules

- Payment amount cannot exceed the member's Total Fine.
- If Total Fine becomes ₹0, the member can borrow books again.
- Every payment updates the member record immediately.

---

# 14. Main Menu Design

The application starts by displaying the main menu. From here, the librarian can access all major features of the system.

## Main Menu

========================================

      LIBRARY MANAGEMENT SYSTEM

========================================

1. Book Management

2. Member Management

3. Transaction Management

4. Reports

5. Exit

========================================

## Book Management

- Add Book
- Remove Book
- Update Book
- Search Book
- View All Books
- Back

## Member Management

- Register Member
- Remove Member
- Update Member
- Search Member
- View All Members
- Back

## Transaction Management

- Issue Book
- Return Book
- Pay Fine
- View Transaction History
- Back

## Reports

- View All Books
- View Available Books
- View Issued Books
- View All Members
- Members with Pending Fine
- Overdue Books
- Back

---

# 15. Transaction Class Design

## Responsibility

The Transaction class stores information about one complete borrowing transaction. It records book issue, return, due dates, fine generated, and transaction status. It does not perform borrowing logic or fine calculation.

### Attributes

- Transaction ID
- Member ID
- Book ID
- Issue Date
- Due Date
- Return Date
- Days Late
- Fine Generated
- Status (Issued / Returned)

### Member Functions

- Constructor
- displayTransaction()
- markReturned()

### Design Decisions

- One transaction represents one borrowing cycle.
- Every borrowing creates a new transaction.
- Fine Generated stores the fine for only that transaction.
- Status prevents duplicate returns.
- Borrowing and fine calculation are controlled by the Library class.

---

# 16. Library Class Design

## Responsibility

The Library class is the central controller of the application. It manages all books, members, transactions, library policies, reports, and file handling.

### Attributes

#### Collections

- Books
- Members
- Transactions

#### Library Policies

- Maximum Books Per Member
- Loan Duration
- Fine Per Day
- Maximum Borrowing Fine Limit

### Member Functions

#### Book Management

- addBook()
- removeBook()
- updateBook()
- searchBook()
- viewAllBooks()

#### Member Management

- registerMember()
- removeMember()
- updateMember()
- searchMember()
- viewAllMembers()

#### Transaction Management

- issueBook()
- returnBook()
- payFine()
- viewTransactionHistory()

#### Reports

- viewAvailableBooks()
- viewIssuedBooks()
- viewMembersWithPendingFine()
- viewOverdueBooks()

#### File Handling

- loadData()
- saveData()

### Design Decisions

- The Library class controls all business logic.
- Every operation is validated before execution.
- Books, Members, and Transactions do not directly modify each other.
- All file operations are handled by the Library class.