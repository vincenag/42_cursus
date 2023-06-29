# Libft

Creación de una librería propia.

## Parte 1 - Funciones de libc
Rehacer ciertas funciones de libc:

• isalpha  
• isdigit  
• isalnum  
• isascii  
• isprint  
• strlen  
• memset  
• bzero  
• memcpy  
• memmove  
• strlcpy  
• strlcat  
• toupper  
• tolower  
• strchr  
• strrchr  
• strncmp  
• memchr  
• memcmp  
• strnstr  
• atoi  
• calloc  
• strdup
## Parte 2 - Funciones adicionales
• ft_substr: Reserva (con malloc(3)) y devuelve una substring de la string ’s’. La substring empieza desde el índice ’start’ y tiene una longitud máxima ’len’.  
• ft_strjoin: Reserva (con malloc(3)) y devuelve una nueva string, formada por la concatenación de ’s1’ y ’s2’.  
• ft_strtrim: Elimina todos los caracteres de la string ’set’ desde el principio y desde el final de ’s1’, hasta encontrar un caracter no perteneciente a ’set’. La string resultante se devuelve con una reserva de malloc(3).  
• ft_split: Reserva (utilizando malloc(3)) un array de strings resultante de separar la string ’s’ en substrings utilizando el caracter ’c’ como delimitador. El array debe terminar con un puntero NULL.  
• ft_itoa: Utilizando malloc(3), genera una string que represente el valor entero recibido como argumento. Los números negativos tienen que gestionarse.  
• ft_strmapi: A cada carácter de la string ’s’, aplica la función ’f’ dando como parámetros el índice de cada carácter dentro de ’s’ y el propio carácter. Genera una nueva string con el resultado del uso sucesivo de ’f’.  
• ft_striteri: A cada carácter de la string ’s’, aplica la función ’f’ dando como parámetros el índice de cada carácter dentro de ’s’ y la dirección del propio carácter, que podrá modificarse si es necesario.  
• ft_putchar_fd: Envía el carácter ’c’ al file descriptor especificado.  
• ft_putstr_fd: Envía la string ’s’ al file descriptor especificado.  
• ft_putendl_fd: Envía la string ’s’ al file descriptor dado, seguido de un salto de línea.
• ft_putnbr_fd: Envía el número ’n’ al file descriptor dado.
## Parte bonus
Utilizar la siguiente estructura para representar un nodo de tu lista. Añadir
la declaración al archivo libft.h:  
typedef struct s_list  
{  
  void           *content;  
  struct s_list *next;  
} t_list;  

Los miembros de la estructura t_list son:
* content: la información contenida por el nodo.  
* void *: permite guardar cualquier tipo de información.  
* next: la dirección del siguiente nodo, o NULL si el siguiente nodo es el último.

Funciones:  
- ft_lstnew: Crea un nuevo nodo utilizando malloc(3). La variable miembro ’content’ se inicializa con el contenido del parámetro ’content’. La variable ’next’, con NULL.
- ft_lstadd_front: Añade el nodo ’new’ al principio de la lista ’lst’.
- ft_lstsize: Cuenta el número de nodos de una lista.
- ft_lstlast: Devuelve el último nodo de la lista.
- ft_lstadd_back: Añade el nodo ’new’ al final de la lista ’lst’.
- ft_lstdelone: Toma como parámetro un nodo ’lst’ y libera la memoria del contenido utilizando la función ’del’ dada como parámetro, además de liberar el nodo. La memoria de ’next’ no debe liberarse.
- ft_lstclear: Elimina y libera el nodo ’lst’ dado y todos los consecutivos de ese nodo, utilizando la función ’del’ y free(3). Al final, el puntero a la lista debe ser NULL.
- ft_lstiter: Itera la lista ’lst’ y aplica la función ’f’ en el contenido de cada nodo.
- ft_lstmap: lst: un puntero a un nodo. f: la dirección de un puntero a una función usada en la iteración de cada elemento de la lista. del: un puntero a función utilizado para eliminar el contenido de un nodo, si es necesario.














