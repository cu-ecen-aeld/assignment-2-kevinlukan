CC = gcc
CFLAGS = -Wall
LDFLAGS = 
OBJFILES = writer.o
TARGET = writer

ifdef CROSS_COMPILE
	CC = $(CROSS_COMPILE)gcc
endif

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJFILES) $(TARGET)

.PHONY: all clean

