#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libudev.h>
#include <stdio.h>
#include <mntent.h>
#include "Monitor.h"

int main(void) {
	
	pid_t pid, sid;
  	int logsdaemon;     
          
	pid = fork();
	/* validar fork retorno */
	if (pid < 0) {
		return -1;
	}
	/* finalizar proceso padre */
	if (pid > 0) {
		return -1;
	}

	/*  mascara de ficheros cambiado: acceso de otro usuario a ficheros generados aqui*/
	umask(0);
	      
	/*ficheros de logs del demonio para poder comunicarse con el daemon */        
	logsdaemon = open ("monitorCPU", O_WRONLY | O_CREAT, 0600);
	/* validar apertura de fichero */
	if (logsdaemon == -1) {
		perror ("Error fichero log daemon");
		return -1;
	}
	/* asignar un nuevo pid evitando problemas que se genere un proceso zombie*/
	/* y validar nuevo id para procesos */
	
	sid = setsid();
	
	if (sid < 0) {
		perror("new SID failed");
		
	}

	/* descriptores standard deben ser cerrados (medida de seguridad) */

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	

	/* proceso daemon */
	/* bucle infinito del daemon */
	/* aqui debe escanear constantemente la PC para verificar si existen nuevos dispositivos USB 
	conectados y 
	 */
	void *buf=malloc(2000);
	while (1) {
		FILE *fp = popen("top -bn2 | grep '%Cpu' | tail -1", "r");
		n=fread(buf,100,1, fp);
		write (logsdaemon, buf, n);
      	sleep(1); 	
	}	
	return -1; //borrar cuando creamos daemon
}

