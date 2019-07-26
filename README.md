# Vending_Machine_System
C++ project simulating a Vending machine
Final Project of the System Software Architecture of the IIT Chicago 2019.

Goal : Simulate the behaviour of a vending machine in a clean C++ project, Using 3 patterns :
- Abstract Factory Pattern
- Strategy Pattern
- State Pattern

## Documentation

Here is the final class diagram :
<img src=https://imgur.com/YJ9zGnl.png/>

The Class diagram is available in pdf. (class_diagram.pdf)

Alongside the following files :
- "Final_Report.pdf" details for the role and implementation of every classes.
- "State_diagram.pdf" the state diagram
- "Seq_1.pdf" sequence diagrams for a first scenario
- "Seq_2.pdf" sequence diagrams for a second scenario

## Implementation

The code is in C++, and has been tested and run on the IDE "CLion" (from JetBrains).

In the “Globals.hpp” file I included two #define possibilities :
- #define DEBUG_MODE that will print mor text (Call and actions between classes)
- #define TEST_MODE that will execute the scenarios in describe in the test/ folder rather than main code.
By default these two defines are commented.

I generated 3 .exe :
- SSA_VM.exe : execute the main code
- SSA_VM_DEBUG.exe : execute the code with #define DEBUG_MODE (more intermediate print messages)
- SSA_VM_TEST.exe will execute the code with #define TEST_MODE (scenarios)
