# C -- Random Integer Generator by John Wolf, v 0.0.1

## Table of Contents
1. Overview
2. How to use
	1. Argument-based
	2. UI-based
3. Troubleshooting
***
# Overview
This program creates n random integers between lower bound i and upper bound k
The output is saved to its current directory in a file named 'output.txt'

# How to use
There are two executable files included in this repository:

1. Argument-based executable
This program accepts between 1 and 3 arguments. The syntax and results are as follows
	1. 1 integer argument: ./main.exe count
		* The program will generate count random integers between the minimum and maximum integer values for C
		* ie. if count = 10, 10 random integers will be generated
	2. 2 integer arguments: ./main.exe upper count
		* The program will generate count random integers between the minimum integer value for C and upper
		* ie. if upper = 1000 and count = 10, 10 random integers will be generated between the minimum integer and 100
	3. 3 integer arguments: ./main.exe lower upper count
		* The program will generate count random integers between the lower and upper bounds
		* ie. if lower = 0, upper = 100, and count = 10, the program will generate 10 random integers between 0 and 100
2. UI-based executable
This program will use user input instead of command line arguments to generate random integers
	* It is important to note that the program currently requires input for all values. There are plans to allow it to accept null inputs and use the maximum and minimum values of integers for the upper and lower bounds respectively
	* The UI is straight forward and will guide you through the process

# Troubleshooting
* The values are negative when the max and min integer values are selected
	* This is a problem I'm trying to iron out. It heavily favors negative values with this setting
* I don't like that I can't choose the output file!
	* This is currently a priority in development along with allowing the UI-based program to choose min and max integer values. This is still in development and will be finished soon
* This program has been done a million times
	* Well now it has been done a million and one times
* What is the point of this program?
	* I wanted a quick way to generate a large number of integers quickly. Python is a bit slow since it is an interpreted language and C++ files can be pretty bloated for simple programs like this
	* I also like making programs like this in languages that I'm learning, so I made one for C
* Can this be sped up with the use of threads?
	* Yes, but threads in C are finicky. I have a C/C++ thread header that could be used but that would change this program from a C program compiled with gcc to a C program interpreted as C++ compiled with g++
	* So the program would either have to change to be g++ compatible or it would have to sacrifice cross-platform usage to use threads in C. There are currently no plans to use either of these routes.
