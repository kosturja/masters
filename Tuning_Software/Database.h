/* Database header file */

typedef struct Database
{
	char *Database_name;
	struct table *table;
}Database;


typedef struct table_entry
{
	/* Name of the Column */
	char *column_name;
	/* An array of data that the column contains */
	double *column_data;
	/* A pointer to the next column of data */
	struct table_entry *next;
}table_entry;


typedef struct table
{
	/* Name of the table */
	char *table_name;
	/* A pointer to the first column of the table */
	table_entry *entry;
	/* A pointer to the next table in the database */
	struct table *next;
	
}table;


table* create_table(char * tablename);
table_entry* init_column(char * name, int num_data);
void print_column(table_entry *temp);
void print_table(table *temp);
void Fill_column(table_entry *column,double *data);
