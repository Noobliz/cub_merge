NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_PATH) -I$(LIBFT_PATH)/includes -g #-Wconversion
LDFLAGS = -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lbsd -L$(LIBFT_PATH) -lft

LIBFT_PATH = ./libft
MLX_PATH = ./minilibx-linux
SRC_DIR = ./srcs
GNL_DIR = ./gnl
PARSING_DIR = ./parsing
INC_DIR = ./includes

OBJDIR = .build
OBJ_SRC_DIR = $(OBJDIR)/srcs
OBJ_GNL_DIR = $(OBJDIR)/gnl
OBJ_PARSING_DIR = $(OBJDIR)/parsing

MAIN_SRCS = $(SRC_DIR)/main.c \
			$(SRC_DIR)/exit_error.c \
			$(SRC_DIR)/draw.c \
			$(SRC_DIR)/init.c \
			$(SRC_DIR)/movements.c \
			$(SRC_DIR)/ray.c \
			$(SRC_DIR)/render.c \
			$(SRC_DIR)/textures.c \
			$(SRC_DIR)/pov_handler.c \
			$(SRC_DIR)/utils.c\
			$(PARSING_DIR)/get_infile/infile_to_tab.c \
			$(PARSING_DIR)/get_infile/utils_infile.c \
			$(PARSING_DIR)/map_to_rectangle.c \
			$(PARSING_DIR)/utils/free_stuff.c \
			$(PARSING_DIR)/utils/map_utils.c \
			$(PARSING_DIR)/extract_map.c \
			$(PARSING_DIR)/valid_chars.c \
			$(PARSING_DIR)/get_params/extract_params.c \
			$(PARSING_DIR)/check_params/check_colors.c \
			$(PARSING_DIR)/check_params/check_textures.c \
			$(PARSING_DIR)/get_params/params_utils.c \



GNL_SRCS = $(GNL_DIR)/get_next_line.c \
		   $(GNL_DIR)/get_next_line_utils.c

SRCS = $(MAIN_SRCS) $(GNL_SRCS) $(PARSING_SRCS)

MAIN_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_SRC_DIR)/%.o, $(MAIN_SRCS))
GNL_OBJS = $(patsubst $(GNL_DIR)/%.c, $(OBJ_GNL_DIR)/%.o, $(GNL_SRCS))
PARSING_OBJS = $(patsubst $(PARSING_DIR)/%.c, $(OBJ_PARSING_DIR)/%.o, $(PARSING_SRCS))

OBJS = $(MAIN_OBJS) $(GNL_OBJS) $(PARSING_OBJS)

LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx_Linux.a

GREEN = \033[1;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m
CYAN = \033[0;36m
RESET = \033[0m

TOTAL_FILES = $(words $(SRCS))
COMPILED_FILES = 0

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"
	@echo "$(CYAN)📁 Object files organized in $(OBJDIR)/ directory$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)📚 Compiling libft...$(RESET)"
	@make -C $(LIBFT_PATH) --no-print-directory

$(MLX):
	@echo "$(YELLOW)🖼️  Compiling minilibx...$(RESET)"
	@make -C $(MLX_PATH) --no-print-directory

$(OBJ_SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_SRC_DIR)
	@$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
	@echo "$(BLUE)[$(COMPILED_FILES)/$(TOTAL_FILES)] 🔨 Compiling $< → $@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_GNL_DIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(OBJ_GNL_DIR)
	@$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
	@echo "$(BLUE)[$(COMPILED_FILES)/$(TOTAL_FILES)] 🔨 Compiling $< → $@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PARSING_DIR)/%.o: $(PARSING_DIR)/%.c
	@mkdir -p $(OBJ_PARSING_DIR)
	@$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
	@echo "$(BLUE)[$(COMPILED_FILES)/$(TOTAL_FILES)] 🔨 Compiling $< → $@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
	@if [ -d "$(OBJDIR)" ]; then \
		echo "$(RED)  └── Removing $(OBJDIR)/ directory$(RESET)"; \
		rm -rf $(OBJDIR); \
	fi
	@make clean -C $(LIBFT_PATH) --no-print-directory
	@make clean -C $(MLX_PATH) --no-print-directory 2>/dev/null || true
	@echo "$(GREEN)✓ Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(RED)🗑️  Cleaning $(NAME)...$(RESET)"
	@if [ -f "$(NAME)" ]; then \
		echo "$(RED)  └── Removing $(NAME)$(RESET)"; \
		rm -f $(NAME); \
	fi
	@make fclean -C $(LIBFT_PATH) --no-print-directory
	@echo "$(GREEN)✓ $(NAME) cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re debug info