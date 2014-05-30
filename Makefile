CC = gcc
CFLAGS = -c -Wall
SOURCES = src/main.c src/linereader.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = bin/cron-pprint

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)