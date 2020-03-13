#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>


int main() {
	
	pid_t pid, pid2, pid3, pid4, pid5, pid6, pid7;
	int status;

	pid= fork();
  	
	if (pid < 0) {
	exit(EXIT_FAILURE); 
	}

	if (pid == 0) {
	char *argv[] = {"mkdir", "-p", "/home/hana/modul2/indomie", NULL};
	execv("/bin/mkdir", argv);	
	}
	
	else {
////////////////////////////////////////////////////////////////////////////////////
	while((wait(&status)) > 0);

	pid2 = fork();
  
	if (pid2 < 0) {
	exit(EXIT_FAILURE);
	}

	if (pid2 == 0) {
	char *argv[] = {"mkdir","-p", "/home/hana/modul2/sedaap", NULL};
	execv("/bin/mkdir", argv);
	}
///////////////////////////////////////////////////////////////////////////////////
	else{

	while((wait(&status)) > 0);
	
	pid3 = fork();
  
	if (pid3 < 0) {
	exit(EXIT_FAILURE); 
  	}

	if (pid3 == 0) {
	char *unzip[] = {"unzip", "/home/hana/modul2/jpg.zip", NULL};
     	execv("/usr/bin/unzip", unzip);
	}
//////////////////////////////////////////////////////////////////////////////////

	}
	}
}

