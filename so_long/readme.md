# So long

<img width="1440" alt="So_long" src="https://github.com/vincenag/42_cursus/assets/133342460/1e57e247-f626-466f-8854-30a92420b6ed"><br>
Disclaimer: Textures used in this game have been created by Pixel-Boy and AAA (downloaded from itch.io -> ninja-adventure-asset-pack) <br><br>
* El objetivo del jugador es recolectar todos los objetos presentes en el mapa y salir eligiendo la ruta más corta posible.
* Las teclas W, A, S y D se utilizarán para mover al personaje principal.
* El jugador debe poder moverse en 4 direcciones: subir, bajar, ir a la izquierda o ir a la derecha.
* El jugador no puede entrar dentro de las paredes.
* Tras cada movimiento, el número real de movimientosdebe mostrarse en un terminal.
* Utilizarás una perspectiva 2D (vista de pájaro o lateral).
* El juego no necesita ser en tiempo real.

## Gestión de gráficos
* El programa mostrará la imagen en una ventana.
* La gestión de tu ventana debe ser limpia (cambiar de ventana, minimizar, etc)
* Pulsar la tecla ESC debe cerrar la ventana y cerrar el programa limpiamente.
* Hacer clic en la cruz roja de la ventana debe cerrar la ventana y terminar el programa limpiamente.
* El uso de images de la miniLibX es obligatorio

## Mapa
* El mapa estará construido de 3 componentes: paredes, objetos y espacio abierto.
* El mapa estará compuesto de solo 5 caracteres: 0 para un espacio vacío, 1 para un muro, C para un coleccionable, E para salir del mapa y P para la posición inicial del jugador.
* El mapa debe tener una salida, al menos un objeto y una posición inicial.
* El mapa debe ser rectangular.
* El mapa deberá estar cerrado/rodeado de muros, en caso contrario el programa deberá devolver un error.
* Tienes que comprobar si hay un camino válido en el mapa.
* Debes poder procesar cualquier tipo de mapa, siempre y cuando respete las anteriores normas.
* En caso de fallos de configuración de cualquier tipo encontrados en el archivo, el programa debe terminar correctamente y devolver “Error\n” seguido de un mensaje explícito de tu elección.

# Parte bonus
* Haces que el jugador pierda cuando toque una patrulla de enemigos.
* Añades algunas animaciones de sprites.
* Muestras el contador de movimiento directamente en la pantalla en lugar de en el terminal.

