CC = gcc
CFLAGS = -Ihead
SRCS = main.c func/ingredientes.c func/pizza.c
OBJS = $(SRCS:.c=.o)
TARGET = meu_programa

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
