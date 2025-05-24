# Nombre del ejecutable final
NAME = pipex

# Compilador y flags de compilación
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente y sus correspondientes archivos objeto
SRCS = pipex.c pipex_utils.c main_utils.c
OBJS = $(SRCS:.c=.o)  # Sustituye .c por .o automáticamente

# Ruta y archivo de la libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Includes para encontrar los headers de pipex y de libft
INCLUDES = -I. -I$(LIBFT_DIR)

# Colores ANSI para mensajes con estilo en la terminal
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

# Mensajes personalizados con emojis y colores
MSG_OK = "$(GREEN)✅ Compilado con éxito!$(RESET)"
MSG_CLEAN = "$(YELLOW)🧹 Limpieza realizada$(RESET)"
MSG_FCLEAN = "$(RED)💥 Eliminado todo lo que no sirve$(RESET)"
MSG_RE = "$(BLUE)🔁 Recompilando desde cero...$(RESET)"

# Regla principal: compila libft y los objetos, luego crea el ejecutable
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDES) -o $(NAME)
	@echo $(MSG_OK)  # Muestra mensaje si todo va bien

# Regla para compilar libft entrando en su carpeta
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Regla "all" por defecto: llama a la regla principal
all: $(NAME)

# Borra los .o propios y los de libft
clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	@echo $(MSG_CLEAN)

# Borra todo lo que clean borra + el ejecutable y libft.a
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo $(MSG_FCLEAN)

# Limpia y recompila desde cero
re:
	@echo $(MSG_RE)
	@$(MAKE) fclean
	@$(MAKE) all

# Evita errores si existen archivos llamados igual que las reglas
.PHONY: all clean fclean re
