NAME = philo
HEADR = ./includes/philo.h
CC = cc
CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=thread

SRCS_DIR = srcs
OBJS_DIR = objs

SRCS =	ph_main.c \
		ph_utils.c \
		ph_arguments.c \
		ph_initalise.c \
		ph_routine.c \
		ph_act.c

SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS := $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)
	@echo Finished!

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo making philos...

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)/*.o
	@echo cleaning...

fclean: clean
	@rm -f $(NAME)
	@echo fucking cleaning...

re: fclean all

.PHONY: all clean fclean re
