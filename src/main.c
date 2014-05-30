/*
 *	Wesley Hansen
 *  date started: Mon 26 May 2014 03:47:21 AM EDT
 *	cron-pprint -- pretty print cron entries in human-readable form.
 *  cron-pprint can accept lines of text from stdin, or a filename from stdin
 *  an attempt to decode and print a cron tab line.
 */

#include <stdio.h>
#include <err.h>
#include "linereader.h"


int main(int argc, char *argv[])
{
	// Is filename given?
	if(argc != 2)
	{
		perror("No file specified, quitting.");
		return 1;
	}
	else
	{
		struct line_reader lr;
		FILE * file;
		size_t len;
		char *line;

		// Open filename given
		file = fopen(argv[1], "r");
		if(file == NULL)
		{
			perror(argv[1]);
			exit(1);
		}

		line_reader_init(&lr, file);
		while((line = read_next_line(&lr, &len)))
		{
			/* Do something to line here */
			// fputs("LINE: ", stdout);
			fwrite(line, len, 1, stdout);
		}
		if(!feof(file))
		{
			perror("next_line");
			exit(1);
		}
		free_line_reader(&lr);
		fwrite("\n", 1, 1, stdout);
		return 0;
	}
}
