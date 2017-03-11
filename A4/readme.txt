###############################################################################
###############################################################################
###########  Name: Benjamin McConville                              ###########
###########  Date 11-24-2014    File:Assignment 4   Course:CIS2520  ###########
###############################################################################
###############################################################################
###############################################################################

How to compile:
	-type make while inside the folder
How to run:
	-then type ./main to execute the program on linux
	-then type ./main.exe to execute the program on windows cygwin
	-The file you want to use in the program should be placed in the same directory
	as the main.c file
	
##########################################################################################
Files included:
	main.c		test.dat	readme.txt		makefile

##########################################################################################
main.c
	This program takes a file and reads the strings of characters organizing it into an AVL 
	tree. It then has a menu that allows the user to change values and delete them. Also
	the program can display the tree with every node above a give frequency.

Sample Outputs:

-Menu
********************
AVL tree paradigm
********************
1. Initialization
2. Find
3. Insert
4. Remove
5. Check Height and Size
6. Find all(above a given frequency)
7. Exit

All based on the test.dat file

option 1)
	Input the file name you want to initialize as an AVL tree:
	test.dat

option 2)
	Input the key name you want to search for:
	wrn79
	The key is: wrn79 and it's frequency is: 1
	
option 3)
	Input the key name you want to add to the tree:
	wrn123

option 4)
	Input the key name you want to be removed in tree:
	wrn123

option 5)
	The height of the tree is: 7

option 6)
	Input a positive integer frequency count for the tree:
	3
	flr117
	flr1854
	flr1857
	flr2511
	flr2910
	flr390
	flr548
	flr934
	wrn104
	wrn69


	
##########################################################################################
