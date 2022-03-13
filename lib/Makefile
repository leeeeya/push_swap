
NAME = libft.a

SRC = ft_bzero.c \
	  ft_calloc.c \
	  ft_memcpy.c \
	  ft_memset.c \
	  ft_strchr.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strlen.c \
	  ft_strrchr.c \
	  ft_memmove.c \
	  ft_memcmp.c \
	  ft_substr.c \
	  ft_memchr.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_strlcpy.c \
	  ft_strlcat.c \
	  ft_strnstr.c \
	  ft_itoa.c \
	  ft_split.c \

SRC_B = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \

FLAGS = -Wall -Wextra -Werror
OBJ = $(patsubst %.c,%.o,$(SRC))
OBJ_B = $(patsubst %.c,%.o,$(SRC_B))
HEADER = libft.h

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $?

$(OBJ) :%.o : %.c
	gcc $(FLAGS) -c $< -o $@

bonus : $(OBJ) $(OBJ_B) $(HEADER)
	ar rcs $(NAME) $?

$(OBJ_B) :%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(OBJ_B)

fclean : clean
	rm -f $(NAME)

re :  fclean all

.PHONY : all clean fclean re bonus






