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
		newEntry->column_data = malloc(sizeof(double) * num_data);
	}
	newEntry->column_data[num_data] = -255;
	return newEntry;
}
// Prints the specific column passed into the function
void print_column(table_entry *temp)
{
	printf("Column Name:%s\n",temp->column_name);
	int i = 0;
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
void Fill_column(table_entry *column)
{
	// Function stub for filling data
	// into the columns of a table.
}
int main()
{
	printf("Test print\n");
	table* test;
	test = create_table("March 10th");
	if ( test )
	{
		printf("First Table successfully created!\n");
		printf("Table name is:%s\n",test->table_name);
	}
	test->entry = init_column("AFR", 10);
	if ( test->entry )
	{
		printf("Entry created successfully!\n");
		
	}
	printf("Filling the first column\n");

	print_column(test->entry);
	

	

	return 0;
}
