# Hospital Patient Queue System

A console-based hospital patient queue management system built with C++.

## Features

* Add new patients
* Organize patients by specialization
* Give priority to urgent patients
* Display patients in each specialization
* Call the next patient
* Check whether a specialization's queue is empty or full
* Input validation through a menu system

## Concepts Used

* C++
* Functions
* 2D arrays
* Strings
* Loops and conditional statements
* Queue management
* Priority handling
* Data manipulation
* Menu-driven programming

## How It Works

The system manages patients across different medical specializations.

Each specialization has its own queue with a limited capacity. Regular patients are added to the end of the queue, while urgent patients are placed at the front.

When a doctor is ready for the next patient, the first patient in the selected specialization's queue is called and removed.

## Future Improvements

* Rebuild the system using Object-Oriented Programming
* Use dedicated queue data structures
* Add patient IDs
* Add more robust input validation
* Add file handling to save patient data
