CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I./include
TARGET = turt
SRCS = turt.c utils.c
OBJS = $(SRCS:.c=.o)
DEPS = turt.h

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)