*Este proyecto ha sido creado como parte del currículo de 42 por leaherre*

# Proyecto: Get Next Line (GNL)

## Descripción

El objetivo de este proyecto es implementar una función llamada get_next_line que lee una línea de un archivo de forma eficiente y devuelve cada línea en un buffer. Este proyecto pone énfasis en el manejo de archivos, cadenas de texto y memoria dinámica.

El proyecto consta de varias funciones que ayudan a leer y gestionar los datos del archivo, incluyendo la lectura, la extracción de líneas y la actualización del "stash" (un buffer que almacena los datos leídos).

### Funciones principales:
- `get_next_line`: Lee y devuelve la siguiente línea del archivo.
- `read_and_add_to_stash`: Lee datos del archivo y los añade al "stash".
- `extract_line`: Extrae una línea completa desde el "stash".
- `update_stash`: Actualiza el "stash" eliminando la parte de la línea que ya fue leída.

## Instrucciones

### Requisitos

- El archivo `get_next_line.c` debe ser compilado junto con el utils.c 
- Un main.c
gcc -Wall -Wextra -Werror get_next_line.c utils.c main.c -o get_next_line

### Funciones Implementadas

# `ft_strlen`

Calcula la longitud de una cadena de caracteres.

**Parámetros:**
- `str`: La cadena de la que se quiere obtener la longitud.

**Devuelve:**
- El tamaño de la cadena `str` (sin contar el carácter nulo).

---

# `ft_strchr`

Busca la primera aparición de un carácter en una cadena.

**Parámetros:**
- `s`: La cadena en la que buscar el carácter.
- `c`: El carácter que se busca.

**Devuelve:**
- Un puntero al primer carácter encontrado o `NULL` si no se encuentra.

---

# `ft_strjoin`

Concatena dos cadenas de caracteres.

**Parámetros:**
- `s1`: La primera cadena.
- `s2`: La segunda cadena.

**Devuelve:**
- Una nueva cadena que es la concatenación de `s1` y `s2`, o `NULL` si ocurre un error.

---

# `ft_substr`

Crea una nueva cadena a partir de una subcadena de la original.

**Parámetros:**
- `s`: La cadena original.
- `start`: El índice de inicio.
- `len`: La longitud de la subcadena.

**Devuelve:**
- La subcadena correspondiente a la parte de `s` indicada por `start` y `len`.

---

# `ft_memcpy`

Copia un bloque de memoria desde una fuente a un destino.

**Parámetros:**
- `dst`: El destino de la copia.
- `src`: El origen de los datos.
- `n`: El número de bytes a copiar.

**Devuelve:**
- El puntero `dst` con los datos copiados.

---

# `get_next_line`

Lee la siguiente línea de un archivo, devolviéndola como una cadena.

**Parámetros:**
- `fd`: El descriptor de archivo desde donde se lee.

**Devuelve:**
- La siguiente línea del archivo o `NULL` en caso de error.

---

# `read_and_add_to_stash`

Lee datos del archivo y los agrega al "stash".

**Parámetros:**
- `stash`: El buffer donde se almacenan los datos leídos.
- `fd`: El descriptor de archivo desde donde se lee.

**Devuelve:**
- El nuevo "stash" con los datos leídos.

---

# `check_error`

Verifica y maneja posibles errores en el manejo de la memoria.

**Parámetros:**
- `stash`: El puntero al buffer donde se almacenan los datos.

**Devuelve:**
- Un puntero al buffer de lectura o `NULL` en caso de error.

---

# `extract_line`

Extrae la siguiente línea del "stash".

**Parámetros:**
- `stash`: El buffer donde se encuentran los datos.

**Devuelve:**
- La siguiente línea leída desde el "stash".

---

# `update_stash`

Actualiza el "stash" eliminando la parte que ya ha sido leída.

**Parámetros:**
- `stash`: El buffer donde se almacenan los datos.

**Devuelve:**
- El nuevo "stash" con los datos restantes.

---

# `main`

- en la misma carpeta donde esté el main tiene que haber un .txt, desde ahí se va a extraer la info para GNL
- lo de O_RDONLY es para que abra el archivo solo en modo lectura
- Mientras haya una 'line' el while se va a ejecutar
- Al final de cada vuelta el while va a liberar la memoria de 'line'
- se cierra el fd que habia sido abierto por open

int main(void)
{
    int fd;
    char *line;

    fd = open("test1.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE: %s", line);
        free(line);
    }
    close(fd);
}

--

# compilación

- cc -Wall -Wextra -Werror -D BUFFER_SIZE=xxx get_next_line.c get_next_line_utils.c main.c