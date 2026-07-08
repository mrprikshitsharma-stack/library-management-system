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
- Calculate Fines
- Generate Reports

---

## Student (Future Version)

The student will be able to:

- Search Books
- View Book Availability
- View Borrowed Books
- View Outstanding Fine

---

# 4. Core Features

## Book Management

- Add Book
- Delete Book
- Update Book
- Search Book
- View All Books

## Member Management

- Register Member
- Delete Member
- Search Member
- View Members

## Transaction Management

- Issue Book
- Return Book
- Store Borrowing History

## Fine Management

- Automatic Fine Calculation
- Outstanding Fine Per Member
- Fine History Per Transaction

## Reports

- Total Books
- Total Members
- Available Books
- Issued Books
- Outstanding Fines

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
- Fine Payment System
- Dashboard
- Charts & Statistics
- Web Version
- Mobile Application

---

# 9. Design Decisions

- Library owns all Books, Members, and Transactions.
- Book stores only book-related information.
- Member stores current outstanding fine.
- Transaction stores fine generated for each borrowing event.
- Business logic will be handled by the Library class.

---