CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = libft2/libft.a

SRC_DIR_ALGO = algo
SRC_DIR_CMD_OPS = cmd_ops

SRC_ALGO = $(SRC_DIR_ALGO)/error.c \
           $(SRC_DIR_ALGO)/init_stack.c \
           $(SRC_DIR_ALGO)/main.c \
           $(SRC_DIR_ALGO)/mv_a_mv_b.c \
           $(SRC_DIR_ALGO)/ops_to_init_A.c \
           $(SRC_DIR_ALGO)/ops_to_init_B.c \
           $(SRC_DIR_ALGO)/turk.c \
           $(SRC_DIR_ALGO)/utils_stack.c

SRC_CMD_OPS = $(SRC_DIR_CMD_OPS)/cmd_ops.c \
              $(SRC_DIR_CMD_OPS)/cmd_ops1.c \
              $(SRC_DIR_CMD_OPS)/ifThree.c

OBJ_ALGO = $(SRC_ALGO:.c=.o)
OBJ_CMD_OPS = $(SRC_CMD_OPS:.c=.o)

TARGET = push_swap

all: $(TARGET)

%.o: $(SRC_DIR_ALGO)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: $(SRC_DIR_CMD_OPS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ_ALGO) $(OBJ_CMD_OPS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBS):
	$(MAKE) -C libft2

clean:
	rm -rf *.o $(TARGET)
	rm -rf $(SRC_DIR_ALGO)/*.o
	rm -rf $(SRC_DIR_CMD_OPS)/*.o

fclean: clean
	$(MAKE) -C libft2 fclean
	rm -rf $(TARGET)

re: fclean all
