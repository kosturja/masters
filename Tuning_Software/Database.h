/* Database header file */


typedef struct table_entry
{
	char *column_name;
	double *column_data;
}table_entry;

typedef struct table{
	char *table_name;
	table_entry *entry;
	table_entry *next;
	
}table;

table* create_table(char * tablename);
table_entry* init_column(char * name, int num_data);
void print_column(table_entry *temp);
void print_table(table *temp);
void Fill_column(table_entry *column,double *data);
