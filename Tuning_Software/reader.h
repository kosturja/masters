/* 	Fill reading header */
/* 	This struct holds information pertaining
	to a specific file, for use with the database
	including the number of column, length of each column
	filename(database name)
*/
typedef struct file_info
{
	/* 	Contains the file name */
	char *filename;
	/* 	Contains the soon to be table name */
	char *tablename;
	/* 	Contains the number columns in the file */
	int number_columns;
	/* 	Contains the length of each column */
	int column_length;
	/* 	A pointer to the next file info,this allows
		us to keep a linked-list of the file info 
	*/
	struct file_info *next;

}file_info;

/* 	Function takes in a file_info struct
	and an file name, and returns a file_info struct
	filled out with information 
*/

file_info* readfile(char *filename);

char* extract_table_name(char* filename);
int calc_column_length(FILE *fp);
int calc_number_columns(FILE *fp);