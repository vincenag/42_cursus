# PIPEX:
Tu programa deberá ejecutarse de la siguiente forma:
./pipex archivo1 comando1 comando2 archivo2

Deberá utilizar 4 argumentos:
- archivo1 y archivo2 son nombres de arhivos.
- comando1 y comando2 son comandos de shell con sus respectivos parámetros.
- 
La ejecución del programa pipex deberá hacer lo mismo que el siguiente comando:
$> < archivo1 comando1 | comando2 > archivo2

## Parte Bonus:
- Gestionar múltiples pipes.
$> ./pipex archivo1 comando1 comando2 comando3 ... comandon archivo2

Deberá comportarse así:
$> < archivo1 comando1 | comando2 | comando3 ... | comandon > archivo2

- Aceptar << y >> cuando el primer parámetro es “here_doc”:
$> ./pipex here_doc LIMITADOR comando comando1 archivo

Deberá comportarse así:
comando << LIMITADOR | comando1 >> archivo
