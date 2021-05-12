#include "function.h"

int main(int argc, char const* argv[])
{
	//profile info
	Profile customers[100] = {0}; // the input file may not exceed 100 customer profiles
	int num_read = 0;
	
	//static data
	double num_total_salary = 0;
	double num_avg_salary = 0;
	double num_high_salary = 0;
	double num_low_salary = 0;

	char* my_ptr = "CptS 121";
	printf("%c", *(my_ptr++));

	
	//open files
	FILE* infile = open_file("customers.txt", "r");
	FILE* outfile = open_file("charges.txt", "w");
	
	//init profile
	num_read = initProfileStruct(customers, infile);

	//quick sort user profile
	QSortProfile(customers, num_read);

	//get high and low salary
	num_high_salary = customers[0].charges;
	num_low_salary = customers[0].charges;
	num_total_salary = customers[0].charges;
	
	for (size_t i = 1; i < num_read; i++)
	{
		num_total_salary += customers[i].charges;
		if (num_high_salary < customers[i].charges)
		{
			num_high_salary = customers[i].charges;
		}
		if (num_low_salary > customers[i].charges)
		{
			num_low_salary = customers[i].charges;
		}
	}
	num_avg_salary = num_total_salary / num_read;

	//print the result
	fprintf(stdout, "Total: $ %.2lf\n", num_total_salary);
	fprintf(stdout, "Average: $ %.2lf\n", num_avg_salary);
	fprintf(stdout, "Max: $ %.2lf\n", num_high_salary);
	fprintf(stdout, "Min: $ %.2lf\n", num_low_salary);

	//write to files
	fprintf(outfile, "Total: $ %.2lf\n", num_total_salary);
	fprintf(outfile, "Average: $ %.2lf\n", num_avg_salary);
	fprintf(outfile, "Max: $ %.2lf\n", num_high_salary);
	fprintf(outfile, "Min: $ %.2lf\n", num_low_salary);
	
	//close files
	fclose(infile);
	fclose(outfile);
	
	return 0;
}
