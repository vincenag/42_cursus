# Nombre del proyecto
PROJECT_NAME = Inception

# Comandos para Docker Compose
DC = docker-compose -f srcs/docker-compose.yml
DC_UP = $(DC) up --build
DC_DOWN = $(DC) down
DC_STOP = $(DC) stop
DC_RM = $(DC) rm -f
DC_RESTART = $(DC) restart

all: up

# Ejecutar Docker Compose y construir servicios
up:
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

# Ver logs de los contenedores
logs:
	$(DC) logs -f

# Tareas de Makefile
.PHONY: up down stop rm restart logs