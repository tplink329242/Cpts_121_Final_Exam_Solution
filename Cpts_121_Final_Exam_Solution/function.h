#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

	//std library	
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <time.h> 
#include <Windows.h>
#include <stdbool.h>
#include <string.h>

	typedef struct profile
	{
		char name[100];     // customer's name - last, first
		char plan;          // plan 'A' or 'B'
		int talk_minutes;   // number of minutes used for talking
		int data_MB;        // amount of data used in MB
		double charges;     // total charges for this customer ¨C you will compute!
		
	} Profile;

	//open a file
	FILE* open_file(char* filename, char* fileaccess);
	
	//read double
	double read_double(FILE* infile);

	//read char
	char read_char(FILE* infile);

	//compare func
	int fnc_CompareDecrease(const void* a, const void* b);
	
	//init struct
	int initProfileStruct(Profile customers[100], FILE* infile);

	/// <summary>
	/// calc the sum charges
	/// </summary>
	/// <param name="customers"></param>
	/// <returns></returns>
	double calc_the_sum_charges(Profile customers);

	//quick sort the profile
	void QSortProfile(Profile customers[100], int numbers);
	

#ifdef __cplusplus
}
#endif
#endif
