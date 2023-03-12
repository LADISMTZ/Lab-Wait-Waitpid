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

pid_t pid_A, pid_C, pid_B, pid_D;

pid_A=fork();
	
	if(pid_A==0){
	
	pid_D=fork();
		if(pid_D==0){
		printf("Mi nombre es Pid D, mi id es %d, y el de mi padre es %d\n",getpid(), getppid());
		execl("/bin/ls","ls",NULL);
		return 0;
		}
	waitpid(pid_D, &status, 0);
	printf("Mi nombre es Pid A, mi id es %d, y el de mi padre es %d\n",getpid(), getppid());
	execl("/bin/rm","rm","newFolder", NULL);
	return 0;
	}



pid_B=fork();
	if(pid_B==0){
	printf("Mi nombre es Pid B, mi id es %d, y el de mi padre es %d\n",getpid(), getppid());
	execl("/bin/mkdir", "mkdir","newFolder", NULL);
	return 0;
	}


pid_C=fork();
	if(pid_C==0){
	printf("Mi nombre es Pid C, mi id es %d, y el de mi padre es %d\n",getpid(), getppid());
	execl("/bin/ls","ls",NULL);
	return 0;
	}
	
	
waitpid(pid_A, &status, 0);
waitpid(pid_C, &status, 0);
waitpid(pid_B, &status, 0);
printf("Soy M y mi pid es: %d", getpid());
execl("/bin/ls","ls",NULL);
}
	
	




