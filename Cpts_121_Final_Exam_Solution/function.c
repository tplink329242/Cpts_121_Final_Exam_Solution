#include "function.h"

FILE* open_file(char* filename, char* fileaccess)
{
	FILE* infile = NULL;
	infile = fopen(filename, fileaccess);
	if (infile == NULL)
	{
		perror("Error: ");
		return NULL;
	}

	printf("\nOpening success");
	return infile;
}

double read_double(FILE* infile)
{
	double credits = 0;
	fscanf(infile, "%lf", &credits);
	return credits;
}

char read_char(FILE* infile)
{
	char credits = '\0';
	fscanf(infile, "%c", &credits);
	return credits;
}

int fnc_CompareDecrease(const void* a, const void* b)
{
	const Profile* aa = a;
	const Profile* bb = b;
	return -(strcmp(aa->name, bb->name));
}

int initProfileStruct(Profile customers[100], FILE* infile)
{
	int i = 0;
	while (!feof(infile))
	{
		//get name
		//read_string(infile, payroll[i].name);
		fscanf(infile, " %[^\n]%*c", customers[i].name);

		//get title
		customers[i].plan = read_char(infile);

		//get Hours worked
		customers[i].talk_minutes = read_double(infile);

		//get Rate per hour
		customers[i].data_MB = read_double(infile);

		//calc the charge
		customers[i].charges = calc_the_sum_charges(customers[i]);

		i++;
	}
	return i;
}

double calc_the_sum_charges(Profile customers)
{
	double sum = 0;
	double sum_talk = 0;
	double sum_data = 0;
	
	if (customers.plan == 'A')
	{
		sum = 60;
		
		// calc talk sum
		if (customers.talk_minutes > 1000)
		{
			sum_talk = (customers.talk_minutes - 1000) * 0.5 + 35;
		}
		else
		{
			sum_talk = 35;
		}

		//calc talk data
		if (customers.data_MB > 10000)
		{
			sum_data = (customers.data_MB - 10000) * 0.25 + 25;
		}
		else
		{
			sum_data = 25;
		}
	}
	if (customers.plan == 'B')
	{
		sum = 85;
		
		// calc talk sum
		if (customers.talk_minutes > 2000)
		{
			sum_talk = (customers.talk_minutes - 2000) * 0.4 + 55;
		}
		else
		{
			sum_talk = 55;
		}

		//calc talk data
		if (customers.data_MB > 20000)
		{
			sum_data = (customers.data_MB - 20000) * 0.15 + 30;
		}
		else
		{
			sum_data = 30;
		}
	}

	//calc sum
	sum = sum_data + sum_talk;
	return sum;
}

void QSortProfile(Profile customers[100], int numbers)
{
	qsort(customers->name, numbers, sizeof(Profile), fnc_CompareDecrease);
}
