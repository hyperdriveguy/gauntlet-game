CC = g++

CFLAGS = -Wall
CFLAGS += -I./src/include

DEBUG = -ggdb -g

TARGET = game

SRCS = src/*.cpp

all: $(TARGET)

debug: $(TARGET)
	$(CC) $(CFLAGS) $(DEBUG) -o $(TARGET) $(SRCS)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	$(RM) $(TARGET)

depend: .depend

.depend: $(SRCS)
	$(CC) $(CFLAGS) -MM $^ > $@

include .depend
