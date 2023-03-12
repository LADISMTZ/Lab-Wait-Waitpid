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

pid_t pid_L, pid_D;

pid_L=fork();




	if(pid_L==0){
	sleep(3);
	printf("Termine mi ejecucon \nMi pid es: %d\nEl pid de mi padre es:%d\n", getpid(),getppid());
	return 0;
	}

pid_D=fork();
	if(pid_D==0){
	sleep(1);
	printf("Termine mi ejecucon \nMi pid es: %d\nEl	 pid de mi padre es:%d\n", getpid(),getppid());
	return 0;
	}
	
wait(&status);
if (WEXITSTATUS(status)==0){
printf("Uno de mis hijos ha terminado la ejecucion\n");
	}
wait(&status);
	
}
	
	




