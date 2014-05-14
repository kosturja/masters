#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/param.h>
#include <unistd.h>
#include <Database.h>

/* This is the implementation of my database, for a Tuning Software. */
Database* create_DB(char *Databasename)
{
	Database* newDatabase = malloc(sizeof(Database));
	if (NULL != newDatabase)
	{
		newDatabase->Database_name = Databasename;
		newDatabase->table = NULL;
	}
}


table* create_table(char * tablename)
{
	table* newtable = malloc(sizeof(table));
	if (NULL != newtable)
	{
		newtable->table_name = tablename;
		newtable->entry = NULL;
		newtable->next = NULL;
	}
	return newtable;
	
}
// Creates a new column, allocating the name and size of the accompaning array
// of data.
table_entry* init_column(char * name, int num_data)
{
	table_entry* newEntry = malloc(sizeof(table_entry));
	if( NULL != newEntry)
	{
		newEntry->column_name = name;
		newEntry->column_data = malloc(sizeof(double) * (num_data + 1));
	}
	newEntry->column_data[0] = num_data;
	/* Debugging print statements */
	#ifdef DEBUG
	printf("\n Init_column\tSize of array:%.1f\n",newEntry->column_data[0]);
	#endif
	/* end debugging stuff */
	newEntry->column_data[num_data+1] = -255;
	return newEntry;
}
// Prints the specific column passed into the function
void print_column(table_entry *temp)
{
	printf("Printing %s \n",temp->column_name);
	int i = 1;
	double temp_value = 0;
	temp_value = temp->column_data[i];
	while(temp_value != -255)
	{
		printf("Data: %.2f\n",temp_value);
		i++;
		temp_value = temp->column_data[i];
	}
	
	
}
// Prints the entire table passed into the function.
void print_table(table *temp)
{
	printf("First Column in the table:\n");
	print_column(temp->entry);
	temp = temp->next;
	printf("Second Column in the table:\n");
	print_column(temp->entry);
}
void Fill_column(table_entry *column,double *data)
{
	printf("Filling the column %s \n",column->column_name);
	int i = 1;
	int length = column->column_data[0];
	
	for (i ; i < length + 1 ; i++)
	{
		#ifdef DEBUG
		printf("\nFill Column \t Length:%d \t Data[%d]:%f",length,i,data[i]);
		#endif
		column->column_data[i] = data[i-1];
	}
	printf("\n");
	// Function stub for filling data
	// into the columns of a table.
}

