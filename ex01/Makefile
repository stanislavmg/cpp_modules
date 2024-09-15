NAME =		PhoneBook
CC =		c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98
SRC =		PhoneBook.cpp Contact.cpp
OBJ =		$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)
