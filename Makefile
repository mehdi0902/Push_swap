CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = libft2/libft.a

SRC_DIR_ALGO = algo
SRC_DIR_CMD_OPS = cmd_ops
SRC_DIR_CHECKER_BONUS = checker_bonus

MAIN_PUSH_SWAP = $(SRC_DIR_ALGO)/main.c
MAIN_CHECKER = $(SRC_DIR_CHECKER_BONUS)/main_checker.c

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

SRC_CHECKER_BONUS = $(SRC_DIR_CHECKER_BONUS)/checker.c \
					$(SRC_DIR_CHECKER_BONUS)/checker_error.c \
              		$(SRC_DIR_CHECKER_BONUS)/checker_utils.c\
					$(SRC_DIR_CHECKER_BONUS)/get_next_line_utils.c\
					$(SRC_DIR_CHECKER_BONUS)/get_next_line.c
					
SRC_CHECKER_BONUS += $(SRC_CMD_OPS)

				
OBJ_ALGO = $(SRC_ALGO:.c=.o)
OBJ_CMD_OPS = $(SRC_CMD_OPS:.c=.o)
OBJ_CHECKER_BONUS = $(SRC_CHECKER_BONUS:.c=.o)

TARGET = push_swap
TARGET_CHECKER = checker

all: $(TARGET) $(TARGET_CHECKER)

$(MAIN_PUSH_SWAP:.c=.o): $(MAIN_PUSH_SWAP)
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_CHECKER:.c=.o): $(MAIN_CHECKER)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ_ALGO) $(OBJ_CMD_OPS) $(MAIN_PUSH_SWAP:.c=.o) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET_CHECKER): $(OBJ_CHECKER_BONUS) $(MAIN_CHECKER:.c=.o) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: $(SRC_DIR_ALGO)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: $(SRC_DIR_CMD_OPS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ_ALGO) $(OBJ_CMD_OPS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET_CHECKER): $(OBJ_CHECKER_BONUS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBS): 
	$(MAKE) -C libft2

clean:
	rm -rf *.o $(TARGET) $(TARGET_CHECKER)
	rm -rf $(SRC_DIR_ALGO)/*.o
	rm -rf $(SRC_DIR_CMD_OPS)/*.o
	rm -rf $(SRC_DIR_CHECKER_BONUS)/*.o

fclean: clean
	$(MAKE) -C libft2 fclean
	rm -rf $(TARGET) $(TARGET_CHECKER)

sanitize: CFLAGS += -g3 -fsanitize=address
sanitize: all

re: fclean all
