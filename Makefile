NAME = Asxpm
CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -g3
RM = rm -f
SRC_DIR = srcs
SRC_NAMES = main.cpp picture.cpp tty.cpp
SRCS = $(SRC_NAMES:%=$(SRC_DIR)/%)
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJS)
	@echo "$(MAGENTA)🧹 Cleaning objects...$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)🗑️ Cleaning objects and executable...$(RESET)"

re: fclean clean all