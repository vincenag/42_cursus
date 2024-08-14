# Ruta al archivo docker-compose
SRC = srcs/docker-compose.yml

# Comandos para Docker Compose
DC = docker compose -f $(SRC)
DC_UP = $(DC) up -d --build
DC_DOWN = $(DC) down
DC_STOP = $(DC) stop
DC_RM = $(DC) rm -f
DC_RESTART = $(DC) restart

all: up

# Crear directorios para volúmenes y levantar los contenedores
up: create_dirs
	$(DC_UP)
	@echo "Containers are up and running."

create_dirs:
	@mkdir -p ~/data/mariadb ~/data/wordpress
	@echo "Directories for volumes created."

# Detener y eliminar contenedores, redes, volúmenes, etc.
down:
	$(DC_DOWN)
	@echo "Containers stopped and networks removed."

# Detener contenedores sin eliminarlos
stop:
	$(DC_STOP)
	@echo "Containers stopped."

# Eliminar contenedores
rm:
	$(DC_RM)
	@echo "Containers removed."

# Reiniciar contenedores
restart:
	$(DC_RESTART)
	@echo "Containers restarted."

# Limpieza profunda: elimina todos los contenedores, imágenes, volúmenes y redes de Docker
fclean: down stop_containers remove_containers remove_images remove_volumes remove_networks clean_data prune_system
	@echo "Deep clean completed."

stop_containers:
	@echo "Stopping all running containers..."
	@docker stop $$(docker ps -qa) > /dev/null 2>&1 || true
	@echo "Containers stopped."

remove_containers:
	@echo "Removing all containers..."
	@docker rm $$(docker ps -qa) > /dev/null 2>&1 || true
	@echo "Containers removed."

remove_images:
	@echo "Removing all images..."
	@docker rmi -f $$(docker images -qa) > /dev/null 2>&1 || true
	@echo "Images removed."

remove_volumes:
	@echo "Removing all volumes..."
	@docker volume rm $$(docker volume ls -q) > /dev/null 2>&1 || true
	@echo "Volumes removed."

remove_networks:
	@echo "Removing all networks..."
	@docker network rm $$(docker network ls -q) > /dev/null 2>&1 || true
	@echo "Networks removed."

clean_data:
	@echo "Cleaning data directory..."
	@sudo rm -rf ~/data/* > /dev/null 2>&1 || true
	@echo "Data directory cleaned."

prune_system:
	@echo "Pruning Docker system..."
	@docker system prune -af > /dev/null 2>&1 || true
	@echo "System pruned."

# Reinicia el entorno completamente
re: fclean up

# Ver logs de los contenedores
logs:
	$(DC) logs -f

.PHONY: all up down stop rm restart fclean re logs