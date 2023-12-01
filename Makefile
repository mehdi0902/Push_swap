CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = libft2/libft.a

SRC_DIR_ALGO = algo
SRC_DIR_CMD_OPS = cmd_ops

SRC_ALGO = $(wildcard $(SRC_DIR_ALGO)/*.c)
SRC_CMD_OPS = $(wildcard $(SRC_DIR_CMD_OPS)/*.c)

OBJ_ALGO = $(patsubst $(SRC_DIR_ALGO)/%.c, %.o, $(SRC_ALGO))
OBJ_CMD_OPS = $(patsubst $(SRC_DIR_CMD_OPS)/%.c, %.o, $(SRC_CMD_OPS))

TARGET = push_swap

all: $(TARGET)

%.o: $(SRC_DIR_ALGO)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: $(SRC_DIR_CMD_OPS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ_ALGO) $(OBJ_CMD_OPS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

clean:
	rm -rf *.o $(TARGET)

fclean: clean
	rm -rf libft.a

re: fclean all