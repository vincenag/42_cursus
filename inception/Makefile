# path to docker-compose file
SRC = srcs/docker-compose.yml

# Variables
DC = docker compose -f $(SRC)
DC_UP = $(DC) up -d --build
DC_DOWN = $(DC) down
DC_STOP = $(DC) stop
DC_RM = $(DC) rm -f
DC_RESTART = $(DC) restart

#========================= COLORS =========================#

GREEN   = \033[92;5;118m
YELLOW  = \033[93m
CIAN    = \033[36m
END     = \033[0m

#========================= RULES =========================#

all: up

up: create_dirs
	$(DC_UP)
	@echo "$(GREEN)Containers are up and running.$(END)"

create_dirs:
	@mkdir -p ~/data/mariadb ~/data/wordpress
	@echo "$(GREEN)Directories for volumes created.$(END)"

down:
	$(DC_DOWN)
	@echo "$(CIAN)Containers stopped and networks removed.$(END)"

stop:
	$(DC_STOP)
	@echo "$(CIAN)Containers stopped.$(END)"

rm:
	$(DC_RM)
	@echo "$(CIAN)Containers removed.$(END)"

restart:
	$(DC_RESTART)
	@echo "$(CIAN)Containers restarted.$(END)"

fclean: down stop_containers remove_containers remove_images remove_volumes remove_networks clean_data prune_system
	@echo "$(GREEN)Deep clean completed.$(END)"

stop_containers:
	@echo "$(YELLOW)Stopping all running containers...$(END)"
	@docker stop $$(docker ps -qa) > /dev/null 2>&1 || true
	@echo "$(CIAN)Containers stopped.$(END)"

remove_containers:
	@echo "$(YELLOW)Removing all containers...$(END)"
	@docker rm $$(docker ps -qa) > /dev/null 2>&1 || true
	@echo "$(CIAN)Containers removed.$(END)"

remove_images:
	@echo "$(YELLOW)Removing all images...$(END)"
	@docker rmi -f $$(docker images -qa) > /dev/null 2>&1 || true
	@echo "$(CIAN)Images removed.$(END)"

remove_volumes:
	@echo "$(YELLOW)Removing all volumes...$(END)"
	@docker volume rm $$(docker volume ls -q) > /dev/null 2>&1 || true
	@echo "$(CIAN)Volumes removed.$(END)"

remove_networks:
	@echo "$(YELLOW)Removing all networks...$(END)"
	@docker network rm $$(docker network ls -q) > /dev/null 2>&1 || true
	@echo "$(CIAN)Networks removed.$(END)"

clean_data:
	@echo "$(YELLOW)Cleaning data directory...$(END)"
	@sudo rm -rf ~/data/* > /dev/null 2>&1 || true
	@echo "$(CIAN)Data directory cleaned.$(END)"

prune_system:
	@echo "$(YELLOW)Pruning Docker system...$(END)"
	@docker system prune -af > /dev/null 2>&1 || true
	@echo "$(CIAN)System pruned.$(END)"

re: fclean up

logs:
	$(DC) logs -f

.PHONY: all up down stop rm restart fclean re logs