Program: Database.c Database.h reader.h reader.c
	gcc -o Program main.c -g -I. 
Database: Database.c Database.h
	gcc -o Database Database.c -g -I.
debug:	Database.c Database.h
	gcc -o Database Database.c -g -I. -DDEBUG
clean: 
	rm -rf Database
	rm -rf Program
	
