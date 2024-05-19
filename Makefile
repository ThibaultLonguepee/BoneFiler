##
## EPITECH PROJECT, 2024
## Bonefiler
## File description:
## Makefile
##

NAME	:= bonefiler

SRC	:=	src/main.cpp \
		src/Fire.cpp \
		src/File.cpp \
		src/FileLister.cpp \
		src/FileManager.cpp \
		src/Renderer.cpp \
		src/AnimatedSprite.cpp

OBJ	:=	$(SRC:.cpp=.o)

CC	:=	g++

CXXFLAGS	+=	-Wall -Wextra -Werror -Wpedantic
CXXFLAGS	+=	-lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS 	+=	-I./src/

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

tests_run: all

run: all

init: install-hooks install-mango

install-hooks:
	@cp .githooks/commit-msg .git/hooks/commit-msg
	@chmod +x .git/hooks/commit-msg
	@echo "Hooks installed."

install-mango:
	@chmod +x ./init/install-mango.sh
	@./init/install-mango.sh

.PHONY: all clean fclean re
.SILENT: run
