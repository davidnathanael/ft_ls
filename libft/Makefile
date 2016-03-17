# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddela-cr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:43:54 by ddela-cr          #+#    #+#              #
#    Updated: 2016/01/27 14:38:36 by ddela-cr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

OBJS_PATH = objs/

SRCS		=	ft_bzero.c\
ft_memset.c\
ft_memcpy.c\
ft_memccpy.c\
ft_memmove.c\
ft_memchr.c\
ft_memcmp.c\
ft_strlen.c\
ft_wstrlen.c\
ft_wcharlen.c\
ft_strdup.c\
ft_wstrdup.c\
ft_strcpy.c\
ft_strncpy.c\
ft_strcat.c\
ft_strncat.c\
ft_strlcat.c\
ft_strchr.c\
ft_strnchr.c\
ft_strrchr.c\
ft_strstr.c\
ft_strreplace.c\
ft_strnstr.c\
ft_strcmp.c\
ft_strncmp.c\
ft_atoi.c\
ft_ultoi.c\
ft_isalpha.c\
ft_isdigit.c\
ft_isalnum.c\
ft_isascii.c\
ft_isprint.c\
ft_toupper.c\
ft_tolower.c\
ft_memalloc.c\
ft_memdel.c\
ft_strnew.c\
ft_strdel.c\
ft_strclr.c\
ft_striter.c\
ft_striteri.c\
ft_strmap.c\
ft_strmapi.c\
ft_strequ.c\
ft_strnequ.c\
ft_strsub.c\
ft_wstrsub.c\
ft_strjoin.c\
ft_wstrjoin.c\
ft_strtrim.c\
ft_strsplit.c\
ft_itoa.c\
ft_lltoa.c\
ft_itoa_base.c\
ft_putchar.c\
ft_putwchar.c\
ft_putstr.c\
ft_putwstr.c\
ft_putendl.c\
ft_putnbr.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_lstnew.c\
ft_lstdelone.c\
ft_lstdel.c\
ft_lstadd.c\
ft_lstiter.c\
ft_lstmap.c\
ft_swap.c\
ft_strupcase.c\
ft_strlowcase.c\
ft_isspace.c\
ft_strcapitalize.c\

FLAGS	= -Wall -Wextra -Werror

INC		= -I ../includes

OBJS = $(SRCS:.c=.o)

.SILENT:

all: $(NAME)
	echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NAME):
	printf "\r\033[38;5;11m⌛  MAKE   $(NAMEBASE) please wait ...\033[0m\033[K"
	gcc -c $(SRCS) $(FLAGS) $(INC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	mkdir $(OBJS_PATH)
	mv $(OBJS) $(OBJS_PATH)
	echo -en "\r\033[38;5;22m☑️  MAKE   $(NAMEBASE)\033[0m\033[K"
	echo "\r\033[38;5;184m👥  GROUP MEMBER(S):\033[0m\033[K"
	echo "\r\033[38;5;15m`cat auteur | sed s/^/\ \ \ \ /g`\033[0m\033[K"

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) please wait ...\033[0m\033[K"
	rm -rf $(OBJS_PATH)
	printf "\r\033[38;5;11m☑️  CLEAN  $(NAMEBASE) is done\033[0m\033[K"

fclean: clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) please wait ...\033[0m\033[K"
	rm -f $(NAME)
	printf "\r\033[38;5;11m☑️  FCLEAN  $(NAMEBASE) is done\033[0m\033[K"

re: fclean all

.PHONY: all clean fclean re
