#include <fcntl. h>
#include <unistd.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
	int fd;
	char *buffer;
	static char *stash;


	if(stash == NULL)
		stash = malloc('\0');

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);	
	
	fd = size_t read(int fd, void *buffer, size_t BUFFER_SIZE)
	if (fd < 0)
	{
		free(buffer);
		return(NULL);
	}
	if (fd == 0)
	{
		
		return (stash);
	}


	int close(int fd);
	return(line);
}

	✔️ get_next_line()


concatena con stash

llama a funciones auxiliares

devuelve la línea final



size_t read(int fd, void *buffer, size_t BUFFER_SIZE)
{
		
✔️ A) un número > 0

Significa: leyó esa cantidad de bytes (pueden ser menos de BUFFER_SIZE).
Ejemplo: pedís 10, pero devuelve 4. Y eso está bien.

✔️ B) 0

Significa: EOF (End Of File).
No hay más datos.
Si te quedaba algo en la stash → devolvés eso.
Si no → devolvés NULL.


	 }
	        
	
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



✔️ read_and_append_to_stash()

Una función interna que hace:

leer del fd

llenar buffer

concatenar al stash

parar cuando encuentra un \n en stash o llega EOF

char *extract_line(char *stash)
{
	char *new_line;
	size_t len;
	unsigned int start;

	while (*stash != \0)
	{
		if (*stash != '\n')
			return (stash);
		else
		{
			len = ft_strlen(stash);
			start = ft_strchr(stash, '\n');
			new_line = ft_substr(stash, start, len);
			return (new_line);
		}
		stash++;
	}
	return(new_line)
}


✔️ update_stash_after_line()

Hace:

crear una nueva stash con lo que quedó después del \n

liberar la stash vieja

asignar la nueva

		SIEMPRE LIBERAR MEMORIA POR CADA MALLOC