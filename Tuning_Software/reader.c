/* Fill reading Implementation */
#include <reader.h>
#include <stdio.h>
#include <stdlib.h>


file_info*  readfile(char *filename)
{
	FILE *fp;
	char *mode = "r";
	fp = open(filename,mode);
	printf("About to open the file\n");
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
int calc_number_columns(FILE *fp)
{
	int count;
	char c;

    count = 0;
    for( ;; )
    {
        c = fgetc( fp );
        if( c == EOF || c == '\n' )
            break;
        ++count;
    }

    if( count == 0)
    {
    	return -1;
    }

    return count;
}
/*	Calculates the number of rows in each column */
int calc_column_length(FILE *fp)
{
	return 15;
}

char* extract_table_name(char *filename)
{
	return "Test";
}