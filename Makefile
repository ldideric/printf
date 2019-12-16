# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ldideric <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 13:33:11 by ldideric       #+#    #+#                 #
#    Updated: 2019/12/12 16:47:32 by ldideric      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

PRINTF_PATH	= ./printf/
PRINTF_SRC	=	ft_printf.c \
				ft_printf_bonus.c \
				ft_flags.c \
				ft_itoa_base.c \
				printf_c.c \
				printf_s.c \
				printf_di.c \
				printf_p.c \
				printf_u.c \
				printf_x.c
PRINTF_OBJ	= $(PRINTF_SRC:.c=.o)

LIBFT_PATH	= ./libft/
LIBFT_SRC	=	ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c
LIBFT_OBJ	= ${LIBFT_SRC:.c=.o}

BONUS_PATH	= ./libft_bonus/
BONUS_SRC	=	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c
BONUS_OBJ	= $(BONUS_SRC:.c=.o)

FLAGS		= -Wall -Wextra -Werror
OBJ_PATH	= OBJ/
SRC_PATH	= SRC/

PRINTF_OP	= $(PRINTF_OBJ:%=$(OBJ_PATH:%=$(PRINTF_PATH)%)%)
LIBFT_OP	= $(LIBFT_OBJ:%=$(OBJ_PATH:%=$(LIBFT_PATH)%)%)
BONUS_OP	= $(BONUS_OBJ:%=$(OBJ_PATH:%=$(BONUS_PATH)%)%)

#COLOR CODES
#red
R	= \x1b[38;5;196m
#orange
O	= \x1b[38;5;208m
#yellow
Y	= \x1b[38;5;3m
#green
G	= \x1b[38;5;83m
#blue
B	= \x1b[38;5;21m
#purple
P	= \x1b[38;5;129m
#pink
PI	= \x1b[38;5;205m
#light pink
PL	= \x1b[38;5;219m
#grey
GR	= \x1b[38;5;244m
#dark grey
V	= \x1b[38;5;239m
#reset to white
RES	= \x1b[0m

REAL	= \x1b[38;5;205m|\x1b[38;5;219mREAL\x1b[38;5;205m|\x1b[38;5;219m
MINE	= \x1b[38;5;205m|\x1b[38;5;219mMINE\x1b[38;5;205m|\x1b[38;5;219m
STRING	= $(R)Your forgot %s! %s...
ARG		= \"input, dumbass\", \"Give input with STRING and ARG\"
X		= \x1b[38;5;
Z		= m
SUM		= 1

all: $(NAME)

$(NAME): $(PRINTF_OP) $(LIBFT_OP)
	@echo "$(PL)	Compiling files..."
	@echo "		Creating library...$(RES)"
	@ar rc $(NAME) $(PRINTF_OP) $(LIBFT_OP)
	@ranlib $(NAME)
	@echo "$(G)				Finished.$(RES)"

printf/OBJ/%.o: printf/SRC/%.c
	@echo "$(X)$(SUM)$(Z)░░▒▓▓Compiling ~ $@\n"
	$(eval SUM=$(shell echo $$(($(SUM)%15+1))))
	@gcc -o $@ -c $< $(FLAGS) -I$(SRC_PATH:%=$(PRINTF_PATH)%)

libft/OBJ/%.o: libft/SRC/%.c
	@echo "$(X)$(SUM)$(Z)░░▒▓▓Compiling ~ $@\n"
	$(eval SUM=$(shell echo $$(($(SUM)%15+1))))
	@gcc -o $@ -c $< $(FLAGS) -I$(SRC_PATH:%=$(LIBFT_PATH)%)

libft_bonus/OBJ/%.o: libft_bonus/SRC/%.c
	@echo "$(X)$(SUM)$(Z)░░▒▓▓Compiling ~ $@\n"
	$(eval SUM=$(shell echo $$(($(SUM)%15+1))))
	@gcc -o $@ -c $< $(FLAGS) -I$(SRC_PATH:%=$(BONUS_PATH)%)

clean: clean_bonus
	@echo "$(V)Cleaning objects...$(RES)"
	@rm -f $(PRINTF_OP)
	@rm -f $(LIBFT_OP)

fclean: clean
	@echo "$(V)Cleaning $(NAME)...$(RES)"
	@rm -f $(NAME)

clean_bonus:
	@echo "$(V)Cleaning bonus objects...$(RES)"
	@rm -f $(BONUS_OP)

re: fclean all

bonus: bonush $(BONUS_OP) $(LIBFT_OP)
	@echo "$(PL)   Adding bonus to library...$(RES)"
	@ar rc $(NAME) $(BONUS_OP) $(LIBFT_OP)
	@ranlib $(NAME)
	@echo "$(G)			Finished."

header:
	@echo "$(PI)  _____  _____  _____ _   _ _______ ______ "
	@echo " |💗 __ \|  __ \|_   _| \ | |__ 🌺 __|  ____|"
	@echo " | |__) | |__) | | | |  \| |  | |  | |__   "
	@echo " |  ___/|  _ 💕/  | | | .   |  | |  |  __|  "
	@echo " | |    | | \ \ _| |_| |\🌷 |  | |  | |     "
	@echo " |_| 🌸  |_|  \_\_____|_| \_|  |_|  |_| 💓   "
	@echo " _________________________________________ "
	@echo "                               $(V)-ldideric🦄  "
	@echo ""

bonush:
	@echo "$(PI)    ____  ____  _   ____  _______"
	@echo "   / __ )/ __ \/ | / / / / / ___/"
	@echo "  / __  / / / /  |/ / / / /\__ \ "
	@echo " / /_/ / /_/ / /|  / /_/ /___/ / "
	@echo "/_____/\____/_/ |_/\____//____/  "
	@echo "_________________________________"
	@echo "                      $(V)-ldideric🦄 "
	@echo ""

prettycomp: header $(NAME) bonus clean

norm:
	@echo "$(R)NORMINETTE$(RES)"
	@norminette printf libft libft_bonus Makefile
	@echo "$(R)NORMINETTE+$(RES)"
	@python ~/norminette+/run.py printf libft libft_bonus Makefile

test:
	@echo "$(V)Creating a.out...\n$(RES)"
	@gcc $(PRINTF_SRC:%=$(SRC_PATH:%=$(PRINTF_PATH)%)%) \
		$(LIBFT_SRC:%=$(SRC_PATH:%=$(LIBFT_PATH)%)%) \
		$(BONUS_SRC:%=$(SRC_PATH:%=$(BONUS_PATH)%)%) \
		printf/SRC/main.c -g $(FLAGS) -D REAL="\"$(REAL)$(STRING)\", $(ARG)" \
		-D MINE="\"$(MINE)$(STRING)\", $(ARG)" -D \
		FIRST="\"\x1b[38;5;205m|\x1b[38;5;219m%d\x1b[38;5;205m|\n\""
	@echo "$(PL)Comparing output:"
	@echo "$(PI).---#|=============|#---.$(RES)"
	@./a.out
	@echo "$(PI)'---#|=============|#---'$(RES)"
#	@rm a.out