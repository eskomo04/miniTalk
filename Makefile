CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# Directories
#SRC_DIR = .
LIBFT_DIR = ./libft

# Mandatory Files
#SERVER_SRC = $(SRC_DIR) /server.c
SERVER_SRC = ./server.c
#CLIENT_SRC = $(SRC_DIR)/client.c
CLIENT_SRC = ./client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

# Bonus Files
#SERVER_BONUS_SRC = $(SRC_DIR)/server_bonus.c
SERVER_BONUS_SRC = ./server_bonus.c
#CLIENT_BONUS_SRC = $(SRC_DIR)/client_bonus.c
CLIENT_BONUS_SRC = ./client_bonus.c

SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)

# Executable Names
NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

# Default rule
all: $(NAME_SERVER) $(NAME_CLIENT)

# Server build
#	-C //go to ./libft and run 'make'. -L//Find libery .a. -lft link the Function from libery
$(NAME_SERVER): $(SERVER_OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -L$(LIBFT_DIR) -lft -o $(NAME_SERVER)

# Client build
$(NAME_CLIENT): $(CLIENT_OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -L$(LIBFT_DIR) -lft -o $(NAME_CLIENT)

# Bonus Server build
$(NAME_SERVER_BONUS): $(SERVER_BONUS_OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) -L$(LIBFT_DIR) -lft -o $(NAME_SERVER_BONUS)

# Bonus Client build
$(NAME_CLIENT_BONUS): $(CLIENT_BONUS_OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) -L$(LIBFT_DIR) -lft -o $(NAME_CLIENT_BONUS)

# Bonus rule
bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

# Clean object files
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)

# Clean all (objects + binaries)
#	-f//Force
fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
