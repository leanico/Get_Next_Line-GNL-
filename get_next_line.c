#include <fcntl. h>
#include <unistd.h>

char *get_next_line(int fd)
{

	char buffer[BUFFER_SIZE + 1];

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
	
	int close(int fd)
}
