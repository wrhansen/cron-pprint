/*
 * This module was derived from http://rosettacode.org/wiki/Read_a_file_line_by_line#C
 */
#ifndef LINEREADER_H_
#define LINEREADER_H_

#include <stdlib.h>	/* exit, malloc, realloc, free */
#include <stdio.h>	/* fopen, fgetc, fputs, fwrite */

/* line_reader -- data structure that handles reading a file line-by-line.*/
struct line_reader {
	FILE *file;
	char *buffer;
	size_t size;
};

/*
 * Initialize a line reader with the given FILE pointer
 */
void line_reader_init(struct line_reader *lr, FILE *f);

/*
 * Read a line from line_reader and return return it. 
 */
char *read_next_line(struct line_reader *lr, size_t *len);

/*
 * Free memory of a line_reader data structure
 */
void free_line_reader(struct line_reader *lr);

#endif