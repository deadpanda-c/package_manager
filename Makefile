CXX	=	g++

SRC	=	$(shell find . -name "*.cpp")

OBJ	=	$(SRC:.cpp=.o)

NAME	=	kekpm

all:	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) -lcurl -g3

clean:
	find . -name "*.o" -delete -o -name "*.swp" -delete

fclean:	clean
	rm -rf $(NAME)

re:	fclean	all
