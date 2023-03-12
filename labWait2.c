#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>


int main(){
int status;

pid_t pid_B, pid_C, pid_D;


pid_B=fork();
	if(pid_B==0){
	sleep(3);
	return 1;
	}

pid_C=fork();
	if(pid_C==0){
	sleep(1);
	return 2;
	}
	
pid_D=fork();
	if(pid_D==0){
	return 3;
	}
	
	
waitpid(pid_B, &status, 2);
printf("El estado de B es: %d\n",WEXITSTATUS(status));

waitpid(pid_C, &status, 3);
printf("El estado de C es: %d\n",WEXITSTATUS(status));

waitpid(pid_D, &status, 1);
printf("El estado de D es: %d\n",WEXITSTATUS(status));
	
}
	
	




