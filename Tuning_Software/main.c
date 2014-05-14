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
	Database* head;
	Database* tail;
	Database* current;
	head = create_DB("Test_DB");
	table* test;
	test = create_table("March 10th");
	head->table = test;

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