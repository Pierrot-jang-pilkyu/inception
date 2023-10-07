SRCS = ./srcs
CF = $(SRCS)/docker-compose.yaml
DC = docker compose -f $(CF)

all: up

ps:
	$(DC) ps

up: 
	bash $(SRCS)/requirements/tools/mkdir.sh
	$(DC) up --build

down: 
	$(DC) down

start: 
	$(DC) start

stop: 
	$(DC) stop

clean: 
	$(MAKE) down
	bash $(SRCS)/requirements/tools/clean.sh

fclean:
	$(MAKE) clean
	docker system prune -a

re: fclean all
		
.PHONY = all up down start stop clean fclean re