###############################################################################
###########
####################################################################
######################
#######
######  Name: Benjamin McConville                              ################
####
##
####
#######  Date 09-22-2014    File:Assignment 1   Course:CIS2520  ###############



#####
##########################################################################
################
###############################################################
###########################
####################################################
######################################
How to run:
	-type make while inside the folder
	-then type ./A1 to execute the program on linux
	-then type ./A1.exe to execute the program on windows cygwin

####################################################
######################################
Files included:
	main.c		carbon.c	ackerman.c	newton.c	makefile

####################################################
######################################
Running main.c :
	This program calls the three other programs and gives the user a selection to 
choose one of the three or quit. It will continue to loop through the menu untill the user
presses (q) terminate the loop.

Sample output:
Input either (c)Carbon, (a)Ackerman, (n)Newton to run the function or
(q)to quit

####################################################
######################################
carbon.c:
	When typing (c) in the main menu it will bring you to the carbon_main function
which will call the carbon function that will out put all possible outputs of the letters
c,a,r,b,o,n without any letters repeating and there still remaining 6 characters. Then it 
will bring the user back to the main menu.

Sample output of first 8:
carbon
carbno
carobn
caronb
carnob
carnbo
cabron
cabrno

####################################################
######################################
ackermann.c:
	When typing (a) in the main menu it will bring you to the ackermann_main function.
This function will promt the user to input the m and n values consisting in the function.
After that it will call the function ackermann which will go through so recursion to get 
to the answer. Which will pass back to the ackermann_main and output the answer. Then it 
will bring the user back to the main menu.


Sample output:
Input the m value for the Ackermann function
2
input the n value for the Ackermann function
2
A(2,2)=7


Testing of ackermann:
A(m,n) Cases:

While n>0 and m>=4 the program would segmant fault meaning the value would be too big
While n=12 and m=3 the A(3,12)=32765 which is 2 below the cealing of a short int
But when n>12 and m=3 the program would segemant fault meaning the value would be too big
 
####################################################
######################################
newton.c:
	When typing (n) in the main menu it will bring you to the newton_main function.
This function will prompt teh user to input the number they want to be square rooted
The function will then calculate an estimated value by first calling the function newton
which will recursively find the soultion the output the answer. Then after that the function
will calculate the same answer but with a while loop and not recursion. It will then display
that answer and bring the user back to the main menu.

Sample output:
Input a real number to be square rooted:
53
Recursive output: 7.280110
Non-recursive method: 7.280110

The difference in time for both of these processes is milliseconds if there is any. They both
execute instantaneously.
####################################################
######################################

