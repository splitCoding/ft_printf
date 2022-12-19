# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghyep <sanghyep@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 19:00:14 by sanghyep          #+#    #+#              #
#    Updated: 2022/12/20 01:04:41 by sanghyep         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC			=	cc

FLAGS 		= -Wall -Wextra -Werror

NAME		=	libftprintf.a

UTILPATH	=	util

PARSERPATH	=	parser

SRCS		=	ft_printf.c\
				arg_diuc%s.c\
				arg_diuc%s_util.c\
				arg_pxX.c\
				arg_pxX_util.c
# $(UTILPATH)/ft_itoa.c\
# $(UTILPATH)/ft_strchr.c\
# $(UTILPATH)/ft_strdup.c\
# $(UTILPATH)/ft_unsigned_itoa.c\
# $(PARSERPATH)/get_hex_num_lower.c\
# $(PARSERPATH)/get_hex_num_upper.c\
# $(PARSERPATH)/get_hex_pointer.c\
# $(PARSERPATH)/get_int_char_str.c\
# $(PARSERPATH)/hex_parser.c

OBJS		= $(SRCS:%.c=%.o)

HEADER		=	ft_printf.h

.c.o 		:
			$(CC) $(FLAGS) -c $< -o $@  -I $(HEADER)
			
all			: $(NAME)

$(NAME)		: $(OBJS)
			ar rc $(NAME) $(OBJS)

clean 		:
			rm -f $(OBJS)

fclean		:	clean
			rm -f $(NAME)
			
re			:	fclean all