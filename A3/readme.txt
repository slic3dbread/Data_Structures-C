###############################################################################
###############################################################################
###########  Name: Benjamin McConville                              ###########
###########  Date 11-03-2014    File:Assignment 3   Course:CIS2520  ###########
###############################################################################
###############################################################################
###############################################################################

How to run:
	-type make while inside the folder
	For question 1:
	-Make sure to put brackets around the arithmetic expression and all of that in quotes
	-then type ./q1 "(Put Arithmetic expression here)" to execute the program on linux
	-then type ./q1.exe "(Put Arithmetic expression here)" to execute the program on windows cygwin
	For question 2:
	-just make sure the file is called f1.dat before calling it
	-then type ./q2 to execute the program on linux
	-then type ./q2.exe to execute the program on windows cygwin

##########################################################################################
Files included:
	q1.c		q2.c		f1.dat		readme.txt		makefile

##########################################################################################
q1.c
	This program takes the arithmetic expression of the command line and puts it in a
binary expression tree using a linked list. It will then display the tree in preorder,
postorder and inorder. It will also update values of variables in the tree and calculate
the arithmetic expression itself.

User Input:  ./a.exe "(((2*x2)+(3*4))/3)"

Sample Outputs:

-Menu
********************
Arithmetic Expression
********************
1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. calculate
7. Exit




-Display list
        /3
/
                        /4
                /*
                        \3
        \+
                        /x2
                \*
                        \2



-Update
Input the variable name you want to change:
x2
Input the value you want to give it:
3.2



##########################################################################################
q2.c
	This program calls the f1.dat file and tokenizes for every space and newline making
a 20 X 10 array. The array will be down heaped and the re-displayed 

Sample output for the sample file in f1.dat:
25 12 17 82 52 53  5  3 68 64
16 14 27 99 29 99 79 45 59 19
50  9  6 44 59 87 32 36 36 46
12  0 68 68 49 68 74 32  9 30
81 30 16 65 40 39 44 49 32 60
25 41 11 88 15 39 88 69 31 49
44 27 68 96 70 98 85 13 25 47
 2 60 76 23 14 81 82  0 38  4
43 27 20 59  4 84 10 42 43  2
41 82 53 40 29 84 24 61 87 20
99 37 50 93 57  6 29 91 92 39
80 14 42 21  9 69  5 30 20 91
 3 37 97 53 36 54 69 68 38 43
83 82 43 11 21  4  8 97 93 14
51 90 37 86 42 44 48 64 41  1
96 89 75  0 63 24 54 20 20 24
88 56 59 88 39 30 44 59 49 72
49 17 44 32 33 54 60 33 51 87
 9 83 22 90 74 56 64 75 67 55
41 62 82 46 69 42 74 68 79 28


##########################################################################################
f1.dat
	A file containing two digit numbers in the format of 20 rows X 10 columns 

Sample file:
25 12 17 82 52 53 05 03 68 64
43 27 20 59 04 84 10 42 43 02 
80 14 42 21 09 69 05 30 20 91 
96 89 75 00 63 24 54 20 20 24 
41 62 82 46 69 42 74 68 79 28 
50 09 06 44 59 87 32 36 36 46 
83 82 43 11 21 04 08 97 93 14 
02 60 76 23 14 81 82 00 38 04 
09 83 22 90 74 56 64 75 67 55 
41 82 53 40 29 84 24 61 87 20 
99 37 50 93 57 06 29 91 92 39 
25 41 11 88 15 39 88 69 31 49 
03 37 97 53 36 54 69 68 38 43 
44 27 68 96 70 98 85 13 25 47 
51 90 37 86 42 44 48 64 41 01 
16 14 27 99 29 99 79 45 59 19 
88 56 59 88 39 30 44 59 49 72 
49 17 44 32 33 54 60 33 51 87 
12 00 68 68 49 68 74 32 09 30 
81 30 16 65 40 39 44 49 32 60 

	
	
##########################################################################################

