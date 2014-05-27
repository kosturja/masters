/* The main compilation file */ 
/* This fill contains the main method to be compile */
/* Includes the database and reader files */
#include <Database.c>
#include <reader.c>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("\n");
	#ifdef DEBUG
	printf("Debugging has been enabled!\nThis means we will have some extra print statements\n");
	#endif
	/* Pointers for the Database */
	Database* data_head;
	Database* data_tail;
	Database* data_current;
	/* Pointers for the File linked list */
	file_info* file_head;
	file_info* file_tail;
	file_info* file_current;

	file_head = readfile("test2.txt");
	printf("File info:\nFilename:%s\nTablename:%s\nColumns:%d\nLength:%d\n"
		,file_head->filename,file_head->tablename,file_head->number_columns,file_head->column_length);


	/* Init the database, and the first table */
	data_head = create_DB("Test_DB");
	table* test;
	test = create_table("March 10th");
	data_head->table = test;

	/* Creating test data */
	double *test_Data = malloc(sizeof(double)*10);
	int i = 0;
	for (i  ; i < 10 ; i++)
	{
		test_Data[i] = 12;
	}
	/* End of Data creation */
	/* Make sure the table was created successfully */
	if ( test )
	{
		printf("First Table successfully created!\n");
		printf("Table name is:%s\n",test->table_name);
	}
	/* Table created successfully */
	/* Init the column, with a name, and size */
	test->entry = init_column("AFR", 10);
	if ( test->entry )
	{
		printf("Entry created successfully!\n");
		
	}
	/* Fill the column with our test data */
	Fill_column(test->entry,test_Data);
	/* Print the column after we have filled it */
	print_column(test->entry);
	/* Create the second column of data */
	test->entry->next = init_column("Knock",10);
	if( test->next)
	{
		printf("Second Entry Created!\n");
	}
	/* Fill and print the second column */
	Fill_column(test->entry->next,test_Data);
	print_column(test->entry->next);
	



	return 0;
}