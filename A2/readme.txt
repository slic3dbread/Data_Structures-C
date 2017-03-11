###############################################################################
###############################################################################
###########  Name: Benjamin McConville                              ###########
###########  Date 10-15-2014    File:Assignment 1   Course:CIS2520  ###########
###############################################################################
###############################################################################
###############################################################################

How to run:
	-type make while inside the folder
	for question 1:
	-then type ./q1 to execute the program on linux
	-then type ./q1.exe to execute the program on windows cygwin
	for question 2:
	-then type ./q2 to execute the program on linux
	-then type ./q2.exe to execute the program on windows cygwin
	-On the command line after type the variables to be calculated

##########################################################################################
Files included:
	q1.c		q2.c	data.txt	makefile

##########################################################################################
q1.c :
	This program consists of 3 link lists. One for available cars, one for rented and one 
for repair. It prompts the users for options and uses its functions to execute these
options like moving one value in a link list to another. This is done using some of the 
functions in q1.c .

Sample output for menu:
********************************************************************
Welcome to the car rental company choose from the following choices:
********************************************************************
1. add a new car to the List-for-rent list
2. add a returned car to the List-for-rent list
3. add a returned car to the List list
4. transfer a car from the List list to the List-for-rent list
5. rent the first List car
6. print all the lists
7. quit



##########################################################################################
q2.c:

	This program c takes the argument of the command line and calculates it. It isn't in a
normal order. So the program must reorganize the numbers and operators to calculate it
properly.
	
Sample Input:
./q1 234*+45++	

Sample output:
23.00


Testing of q2.c:
Going through different cases testing if every character works as well as testing of the
amount of numbers that can be put on the command line.

##########################################################################################
data.txt :

	This is the storage file for the data of the link lists. It is read from to generate 
all three link lists in q1.c .
