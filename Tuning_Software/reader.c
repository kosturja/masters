/* Fill reading Implementation */
#include <reader.h>
#include <stdio.h>
#include <stdlib.h>

file_info*  readfile(char *filename)
{
	FILE *fp;
	char *mode = "r";
	fp = open(filename,mode);
	if (fp == NULL)
	{
		printf("Error opening file %s\n",filename);
		return 0;
	}
	file_info *temp;
	temp = malloc(sizeof(file_info));
	temp->filename = filename;
	temp->tablename = "Test";
	temp->number_columns = calc_number_columns(fp);
	temp->column_length = calc_column_length(fp);
	return temp;
}
/*	Calculates the number of columns in the file */
int calc_number_columns(FILE *fp)
{
	return 10;
}
/*	Calculates the number of rows in each column */
int calc_column_length(FILE *fp)
{
	return 15;
}