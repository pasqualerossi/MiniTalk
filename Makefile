SERVER = server
CLIENT = client

FLAGS = -Wall -Wextra -Werror
CC = cc

all:
	@${CC} ${FLAGS} server.c -o ${SERVER}
	@${CC} ${FLAGS} client.c -o ${CLIENT}
	@echo "Server and Client Have Been Complied Successfully"

clean:
	@rm -f ${SERVER}
	@rm -f ${CLIENT}
	@echo "Server and Client Have Been Cleaned Successfully"

re: fclean all

.PHONY: all clean fclean re
