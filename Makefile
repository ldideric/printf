# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ldideric <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 13:33:11 by ldideric       #+#    #+#                 #
#    Updated: 2020/01/09 11:13:30 by ldideric      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

PRINTF_PATH	= ./printf/
PRINTF_SRC	=	ft_printf.c \
				ft_printf_bonus.c \
				ft_flags.c \
				ft_itoa_base.c \
				ft_ultoa_base.c \
				printf_c.c \
				printf_s.c \
				printf_di.c \
				printf_p.c \
				printf_u.c \
				printf_x.c \
				printf_per.c
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
				ft_putnbr_fd.c \
				ft_putchar.c \
				ft_putstr.c
LIBFT_OBJ	= ${LIBFT_SRC:.c=.o}

FLAGS		= -Wall -Wextra -Werror

PRINTF_OP	= $(PRINTF_OBJ:%=$(PRINTF_PATH)%)
LIBFT_OP	= $(LIBFT_OBJ:%=$(LIBFT_PATH)%)

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


#random variables to do cool stuff with

FIRST	= "\"\x1b[38;5;205m|\x1b[38;5;219m%4d\x1b[38;5;205m|\n\""
REAL	= \x1b[38;5;205m|\x1b[38;5;219mREAL\x1b[38;5;205m|\x1b[38;5;219m
MINE	= \x1b[38;5;205m|\x1b[38;5;219mMINE\x1b[38;5;205m|\x1b[38;5;219m
STRING	= $(R)Your forgot %s! %s...
ARG		= \"input, dumbass\", \"Give input with STRING and ARG\"
X		= \x1b[38;5;
Z		= m
SUM		= 1


# all the actual rules

all: $(NAME)

$(NAME): $(PRINTF_OP) $(LIBFT_OP)
	@echo "$(PL)	Compiling files..."
	@echo "		Creating library...$(RES)"
	@ar rc $(NAME) $(PRINTF_OP) $(LIBFT_OP)
	@ranlib $(NAME)
	@echo "$(G)				Finished.$(RES)"

printf/%.o: printf/%.c
	@echo "$(X)$(SUM)$(Z)░░▒▓▓Compiling ~ $@\n"
	$(eval SUM=$(shell echo $$(($(SUM)%15+1))))
	@gcc -o $@ -c $< $(FLAGS) -I$(SRC_PATH:%=$(PRINTF_PATH)%)

libft/%.o: libft/%.c
	@echo "$(X)$(SUM)$(Z)░░▒▓▓Compiling ~ $@\n"
	$(eval SUM=$(shell echo $$(($(SUM)%15+1))))
	@gcc -o $@ -c $< $(FLAGS) -I$(SRC_PATH:%=$(LIBFT_PATH)%)

clean:
	@echo "$(V)Cleaning objects...$(RES)"
	@rm -f $(PRINTF_OP)
	@rm -f $(LIBFT_OP)

fclean: clean
	@echo "$(V)Cleaning $(NAME)...$(RES)"
	@rm -f $(NAME)

re: fclean all

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

prettycomp: header $(NAME) clean

norm:
	@echo "$(R)NORMINETTE$(RES)"
	@norminette printf libft Makefile
	@echo "$(R)NORMINETTE PLUS$(RES)"
	@python ~/norminette+/run.py printf libft Makefile

test: 
	@clear
	@echo "$(V)Creating a.out...\n$(RES)"
	@gcc $(PRINTF_OP) $(LIBFT_OP) main.c $(FLAGS) \
		-D REAL="\"$(REAL)$(STRING)\", $(ARG)" \
		-D MINE="\"$(MINE)$(STRING)\", $(ARG)" \
		-D FIRST=$(FIRST) -g
	@clear
	@echo "$(R)[>    ]"
	@sleep .2
	@clear
	@echo "$(R)[ >   ]"
	@sleep .2
	@clear
	@echo "$(O)[  >  ]"
	@sleep .2
	@clear
	@echo "$(O)[   > ]"
	@sleep .2
	@clear
	@echo "$(G)[    >]"
	@sleep .2
	@clear
	@echo "$(G)[DONE!]"
	@sleep .5
	@clear
	@echo "$(PL)Comparing output of $(P)\"$(STRING)\", $(ARG)"
	@echo "$(PI).---#|=============|#---.$(RES)"
	@./a.out
	@echo "$(PI)'---#|=============|#---'$(RES)"
#	@rm a.out
