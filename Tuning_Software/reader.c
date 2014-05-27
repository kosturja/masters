/* Fill reading Implementation */
#include <reader.h>
#include <stdio.h>
#include <stdlib.h>


file_info*  readfile(char *filename)
{
	int fp;
	char *mode = "r";
	fp = open(filename,mode);
	printf("About to open the file:%d\n",fp);
	if (fp == NULL)
	{
		printf("Error opening file %s\n",filename);
		return 0;
	}
	else
	{
		printf("Successfully opened the file %s\n",filename);
	}
	file_info *temp;
	temp = malloc(sizeof(file_info));
	temp->filename = filename;
	temp->tablename = extract_table_name(filename);
	temp->number_columns = calc_number_columns(fp);
	temp->column_length = calc_column_length(fp);
	return temp;
}
/*	Calculates the number of columns in the file */
int calc_number_columns(int fp)
{
	char *buffer = malloc(sizeof(char) * 20);
	fgets(buffer,20,fp);
	printf("Read this from file%s\n",buffer);
	return 10;
}
/*	Calculates the number of rows in each column */
int calc_column_length( int fp)
{
	return 15;
}

char* extract_table_name(char *filename)
{
	return "Test";
}