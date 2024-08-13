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
up:
	mkdir -p ~/data/mariadb
	mkdir -p ~/data/wordpress
	$(DC_UP)

# Detener y eliminar contenedores, redes, volúmenes, etc.
down:
	$(DC_DOWN)

# Detener contenedores sin eliminarlos
stop:
	$(DC_STOP)

# Eliminar contenedores
rm:
	$(DC_RM)

# Reiniciar contenedores
restart:
	$(DC_RESTART)

# Limpieza profunda: elimina todos los contenedores, imágenes, volúmenes y redes de Docker
fclean: down
	@docker system prune -af
	@sudo rm -rf ~/data/*
	@docker stop $(docker ps -qa) 2>/dev/null || true; \
	docker rm $(docker ps -qa) 2>/dev/null || true; \
	docker rmi -f $(docker images -qa) 2>/dev/null || true; \
	docker volume rm $$(docker volume ls -q) 2>/dev/null || true; \
	docker network rm $(docker network ls -q) 2>/dev/null || true

# Reinicia el entorno completamente
re: fclean up

# Ver logs de los contenedores
logs:
	$(DC) logs -f

.PHONY: all up down stop rm restart fclean re logs