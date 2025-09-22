# Executable
NAME		= bricks

# Compiler and flags
CC		= c++
CPPFLAGS	= -Wall -Wextra -std=c++11
#CPPFLAGS	+= -Werror
CPPFLAGS	+= -g -fsanitize=address

# Sources files
SRC		= ./src/main.cpp \
			./src/strechBond.cpp \
			./src/patterns.cpp \
			./src/printFunctions.cpp \

# Object Directory
OBJDIR		= obj

# Header files
HEADERDIR	= ./header

# Objects files
OBJ		= $(addprefix $(OBJDIR)/, $(notdir $(SRC:.cpp=.o)))

# Colors
BOLD		= \033[1m
ITALIC		= \033[3m
UNDER 		= \033[4m
GREEN		= \033[32;1m
CORAL		= \033[38;2;255;127;80m
RESET		= \033[0m

# Targets
all: $(NAME)
	
$(NAME):$(OBJ) 
		$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)
		@echo "$(CORAL) $(UNDER) $(BOLD) $(ITALIC) ✨Compiling Done✨   $(RESET)"

$(OBJDIR)/%.o: ./src/%.cpp
		@mkdir -p $(OBJDIR)
		$(CC) $(CPPFLAGS) -I $(HEADERDIR) -c $< -o $@

# Clean
clean:
		@rm -rf $(OBJDIR)
		@echo "$(GREEN) $(ITALIC) ✅ Cleaned object files ✅$(RESET)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(GREEN) $(ITALIC)  ✅ Removed executable ✅$(RESET)"

re:		fclean all

.PHONY: all clean fclean re
