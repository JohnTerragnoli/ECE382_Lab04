ECE382_Lab04
============



#Prelab

##Data Types

| Size    | Signed/Unsigned | Type           | Min Value      | Max Value |
|---------|-----------------|----------------|----------------|-----------|
| 8 bit   | Unsigned        | unsigned char,bool, _Bool               |0                |    255       |
| 8 bit   | Signed          |     signed char          |       -128         |      127     |
| 16 bit  | Unsigned        | Unsigned Short |      0          |      65 535       |
| 16 bit  | Signed          | short, signed short                |-32 768                |   32 767        |
| 32 bit  | Unsigned        |    unsigned long            |          0      |    4 294 967 295       |
| 32 bit  | Signed          |  long, signed long              | -2,147,483,648 |    2 147 483 647       |
| 64 bit  | Unsigned        |        unsigned long long        |         0       |    18 446 744 073 709 551 615       |
| 64 bit  | Signed  | long long, signed long long | -9 223 372 036 854 775 808  | 9 223 372 036 854 775 807 |


##Code Definitions

| Type   | Meaning               | C typedef Declaration        |
|--------|-----------------------|------------------------------|
| int8   | unsigned 8 bit value  | typedef unsigned char int8  |
| sint8  | signed 8 bit value    |  typedef signed char sint8   |
| int16  | unsigned 16 bit value | typedef unsigned short int16 |
| sint16 | signed 16 bit value   | typedef signed short sint16 |
| int32  | unsigned 32 bit value | typedef unsigned long int32   |
| sint32 | signed 32 bit value   |  typedef signed long sint32  |
| int64  | unsigned 64 bit value |  typedef unsigned long long int64   |
| sint64 | signed 64 bit value |  typedef signed long long sint64  |


##Calling/Returning Convention

| Iteration | a | b | c | d | e |
|-----------|---|---|---|---|---|
| 1st       | 1  |2   |  3 | 4  | 1  |
| 2nd       | 10  | 9  |  8 |  7 |  10 |
| 3rd       |  16 |  15 |  14 | 13  | 16  |
| 4th       |  22 |  21 |   20|  19 | 22  |
| 5th       |  28 |  27 |  26 | 25  | 28  |

##Registers and Parameters

| Parameter                     | Value Sought |
|-------------------------------|--------------|
| Starting Address of Function  |  0xC0BA     |
| Ending Address of Function    |  0xC0C6    |
| Register holding w            |   R12           |
| Register holding x            |   R13           |
| Register holding y            |   R14           |
| Register holding z            |   R15           |
| Register holding return value |   R12           |

##Cross Language Build Constructs

1. What is the role of the extern directive in a .c file? Hint: check out the external variable Wikipedia page.
"An external variable is a variable defined outside any function block. On the other hand, a local (automatic) variable is a variable defined inside a function block" (Wiki page).  


2. What is the role of the .global directive in an .asm file (used in lines 28-32)? Hint: reference section 2.6.2 in the MSP 430 Assembly Language Tools v4.3 User's Guide. 
