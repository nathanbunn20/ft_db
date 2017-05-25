NAME	=	ft_db
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRC		=	sources/main.c sources/commandhandles.c sources/errorhandle.c \
			sources/dbcalls.c sources/filehandles.c sources/dbhandles.c \
			sources/create_db.c sources/awesomecommands.c \
			sources/dbdelete.c sources/dbselect.c sources/dbupdate.c
OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) libft/libft.a
	$(CC) $(CFLAGS) -I includes/ -L libft/ -lft -o $(NAME) $(SRC)

libft/libft.a:
	make -C libft/

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

lclean: fclean
	make -C ./libft fclean

re: fclean all
