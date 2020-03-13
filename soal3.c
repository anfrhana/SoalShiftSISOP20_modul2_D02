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
	else

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
	else 
    {

	while ((wait(&status)) > 0);

	chdir("/home/hana/modul2/jpg/");
	DIR *d;
	d = opendir(".");
	struct dirent *dir;

	if(d){

        while((dir = readdir(d)) != NULL){

	pid4 = fork();

	struct stat st;
	stat(dir->d_name, &st);

	if(pid4 < 0){
	exit(EXIT_FAILURE);
	}

	if(pid4== 0){
	char file[500];
	sprintf(file, "/home/hana/modul2/jpg/%s", dir->d_name);

	if(S_ISDIR(st.st_mode)){
		if(strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0);
	else
      {

	pid5 = fork();

	if(pid5 < 0){
	exit(EXIT_FAILURE);
	}
	
	if(pid5 == 0){
	char* argv[] = {"mv", file, "/home/hana/modul2/indomie/", NULL};
	execv("/bin/mv", argv);
	}
///////////////////////////////////////////////////////////////////////////////////
	else{

	while((dir = readdir(d)) != NULL){

	pid6 = fork();

	if(pid6 == 0){
	chdir("/home/hana/modul2/jpg/");
	char *mk[]={"touch","/home/hana/modul2/jpg/coba1.txt",NULL};
        execv("/bin/touch",mk);
	}

	sleep(3);

	pid7 = fork();

	if(pid7 == 0){
	chdir("/home/hana/modul2/jpg/");
	char *mk[]={"touch","/home/hana/modul2/jpg/coba2.txt",NULL};
        execv("/bin/touch",mk);
	}
	}
	}
	closedir(d);
}}}

}



