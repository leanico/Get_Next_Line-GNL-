#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *stash;
    char      *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    stash = read_and_add_to_stash(stash, fd);
    if (!stash)
        return (NULL);
    line = extract_line(stash); 
    if (!line)
    {
		free (stash);
		stash = NULL;
		return (NULL);
	}    
	
    stash = update_stash(stash); 
    return(line);
}	
	


char *extract_line(char *stash) // OK
{
	char *new_line;
	size_t len;
	char *start;

	if (stash == NULL || stash[0] == '\0')
		return (NULL);
	start = ft_strchr(stash, '\n');
	if (start != NULL) // si start (el que busca \n) encuentra un salto de linea (o sea que "fallo strchr")
		len = (start - stash) + 1; // +1 para el salto de linea - stash apunta a [0] de si mismo
	else
		len = ft_strlen(stash); // si strchr no encontró salto de linea que la longitud sea el total del stash
	new_line = ft_substr(stash, 0, len); // substr ya asigna memoria y ya le agrega el caracter nulo al final
	if (new_line == NULL) 
        return (NULL);
	return (new_line);
}


char	*update_stash(char *stash) // actualiza el stash despues de extraer la linea
{
	char	*start_of_rest;
	char	*new_stash;
	size_t	start_index;
	size_t	len_of_rest;

	// 1. Encontrar el salto de línea.
	start_of_rest = ft_strchr(stash, '\n');

	// 2. Caso: No hay salto de línea (se extrajo la última línea).
	if (!start_of_rest)
	{
		free(stash); // ¡LIBERAR MEMORIA!
		return (NULL);
	}

	// 3. Calcular la posición de inicio para la nueva subcadena.
	// La nueva cadena comienza 1 byte después del '\n'.
	start_index = (start_of_rest - stash) + 1;

	// 4. Calcular la longitud restante de la cadena.
	len_of_rest = ft_strlen(stash) - start_index;

	// 5. Crear la nueva subcadena.
	new_stash = ft_substr(stash, start_index, len_of_rest);
	
	// 6. Manejar error de asignación de memoria (si falla malloc dentro de ft_substr).
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}

	// 7. Liberar el stash original y devolver el nuevo.
	free(stash); // ¡LIBERAR MEMORIA!
	return (new_stash);
}

char *read_and_add_to_stash(char *stash, int fd)
{
    ssize_t num; // cantidad de bytes leídos
    char *buffer;
    char *temp;

    // Inicializar stash si es NULL
    if (!stash)
    {
        stash = (char *)malloc(1);
        if (!stash)
            return (NULL);
        stash[0] = '\0';
    }

    buffer = (char *)malloc(BUFFER_SIZE + 1); // +1 para '\0'
    if (!buffer)
        return (NULL);

    while (!ft_strchr(stash, '\n'))
    {
        num = read(fd, buffer, BUFFER_SIZE);

        if (num < 0) // error de lectura
        {
            free(buffer);
            return (NULL); // ❌ No liberamos stash aquí
        }
        else if (num == 0) // EOF
        {
            break;
        }

        buffer[num] = '\0';
        temp = stash;
        stash = ft_strjoin(temp, buffer);
        if (!stash)
        {
            free(temp);
            free(buffer);
            return (NULL);
        }
        free(temp);
    }

    free(buffer);
    return (stash);
}


