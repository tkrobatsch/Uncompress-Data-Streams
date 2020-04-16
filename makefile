CC = gcc
CFLAGS = -g -Wall
OBJFILES = data_uncompress.o
TARGET = data_uncompress

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
