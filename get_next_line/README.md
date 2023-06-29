# get_next_line

**Obejtivo:** Escribir una función que devuelva la línea leída de un file descriptor.  

- Llamar a tu función get_next_line de manera repetida (por ejemplo, usando un bucle) te permitirá leer el contenido del archivo hacia el que apunta el file descriptor, línea a línea, hasta el final.
- Tu función deberá devolver la línea que se acaba de leer. Si no hay nada más que leer o si ha ocurrido un error, deberá devolver NULL.
- Asegúrate de que tu función se comporta adecuadamente cuando lea de un archivo y cuando lea de stdin.
- Ten en cuenta que la línea devuelta debe terminar con el caracter n, excepto si se ha llegado al final del archivo y esté no termina con un caracter n.
- En el header get_next_line.h deberás tener como mínimo el prototipo de la función get_next_line.
- Añade todas las funciones de ayuda que necesites en el archivo get_next_line_utils.c
- Tu programa debe compilar con el flag -D BUFFER_SIZE=xx. Este flag se utilizará para determinar el tamaño del buffer de las lecturas de tu get_next_line(). Este parámetro será modificado por tus evaluadores y por Moulinette para probar tu
programa.

## Parte bonus

Tu get_next_line tiene que ser capaz de gestionar múltiples fd a la vez. Es decir, si tienes tres fd disponibles para lectura (por ejemplo: 3, 4 y 5), debes poder utilizar get_next_line una vez sobre el fd 3, otra vez sobre el fd 4, y otra vez sobre el fd
5 de forma alterna. Y sí, no debe perder el hilo de lectura de cada uno de los fd. Añade el sufijo _bonus.[c\h] a los archivos de esta parte bonus.
