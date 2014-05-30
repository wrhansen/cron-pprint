#include "linereader.h"

void line_reader_init(struct line_reader *lr, FILE *f)
{
	lr->file = f;
	lr->buffer = NULL;
	lr->size = 0; 
}

char *read_next_line(struct line_reader *lr, size_t *len)
{
	size_t new_size;
	int c;
	char *new_buffer;

	*len = 0;
	for(;;)
	{
		c = fgetc(lr->file);
		if(ferror(lr->file))
			return NULL;
		if(c == EOF)
		{
			if(*len == 0)
				return NULL;
			else
				return lr->buffer;
		}
		else
		{
			if(*len == lr->size)
			{
				/* Need a bigger buffer */
				new_size = lr->size + 4096;
				new_buffer = realloc(lr->buffer, new_size);
				if(new_buffer == NULL)
					return NULL;
				lr->buffer = new_buffer;
				lr->size = new_size;
			}
			lr->buffer[(*len)++] = c;
			if(c == '\n')
				return lr->buffer;
		}
	}
}

void free_line_reader(struct line_reader *lr)
{
	free(lr->buffer);
	lr->buffer = NULL;
	lr->size = 0;
}

