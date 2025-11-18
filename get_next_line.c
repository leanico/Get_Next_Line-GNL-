#include <fcntl. h>
#include <unistd.h>

char *get_next_line(int fd)
{
	char *buffer;
	static char *stash;


	if(stash == NULL)
		stash = malloc('\0');

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);	
	
	
		SIEMPRE LIBERAR MEMORIA POR CADA MALLOC


	 ssize_t read( int fd, void *buffer, size_t BUFFER_SIZE)
	 {
✔️ A) un número > 0

Significa: leyó esa cantidad de bytes (pueden ser menos de BUFFER_SIZE).
Ejemplo: pedís 10, pero devuelve 4. Y eso está bien.

✔️ B) 0

Significa: EOF (End Of File).
No hay más datos.
Si te quedaba algo en la stash → devolvés eso.
Si no → devolvés NULL.

✔️ C) -1

Significa: error de lectura.
En GNL:
→ tenés que liberar lo necesario y devolver NULL.
	 }
	        
    ssize_t read(size_t count; int fd, void buf[count], size_t count)
	
	 stash 
	 cortar_stash(stash):
    - buscar \n
    - si no hay -> no cortar, volver a leer
    - si hay:
          * hacer "line" con todo hasta \n
          * hacer "resto" con todo después
          * stash = resto
          * return line
	 Ejemplo:

stash = "Hola\nMundo"

→ devolvés "Hola\n"
→ stash ahora es "Mundo"

stash = ft_strjoin(stash, buffer)

char *nuevo = strjoin(stash_antigua, buffer);
free(stash_antigua);
stash = nuevo;

--
resto = substr(stash, despues_del_n);
free(stash);
stash = resto;

	int close(int fd)
}
--
[buffer] → malloc → leer → concatenar → free

[stash antigua] → strjoin → free → [stash nueva]

si hay '\n':
    line = malloc
    resto = malloc
    free(stash)  
    stash = resto  
    return line

si EOF y stash != NULL:
    line = malloc(stash)
    free(stash)
    stash = NULL
    return line

si EOF y stash == NULL:
    return NULL
