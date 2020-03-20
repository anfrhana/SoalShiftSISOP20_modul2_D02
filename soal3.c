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
	
	pid_t pid, pid2, pid3,pid4;
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
	else{
//////////////////////////////////////////////////////////////////////////////////
	while ((wait(&status)) > 0);

	struct dirent *direktori;
	DIR *dr = opendir("/home/hana/modul2/jpg");
	
	if (dr == NULL) {
	return 0;
	}
	
	while ((direktori = readdir(dr)) != NULL) {
		char path[100];

		struct stat filetype;
		if (strcmp(direktori->d_name, ".") == 0 || strcmp(direktori->d_name, "..") == 0)continue;	 
		else {
			strcpy(path, "/home/hana/modul2/jpg/");
			strcat(path, direktori->d_name);
	
			if (stat(path, &filetype) == 0) {
				if (filetype.st_mode & S_IFDIR) {

				if (pid4 = fork() == 0) {
				char *move1[] = {"mv", path, "/home/hana/modul2/indomie/", NULL};
				execv("/bin/mv", move1);
				}
				}

				else {
				if (pid4 = fork() == 0) {
				char *move2[] = {"mv", path, "/home/hana/modul2/sedaap/", NULL};
				execv("/bin/mv", move2);
				}
				}
			}
		}
	}
	closedir(dr);
	sleep(3);
//////////////////////////////////////////////////////////////////////////////////////////////////////////	
	struct dirent *newfile;
	DIR *f = opendir("/home/hana/modul2/indomie");
	
	while ((newfile = readdir(f)) != NULL) {
		char loc[100];
		if (strcmp(newfile->d_name, ".") == 0 || strcmp(newfile->d_name, "..") == 0) continue;
		 
		else {
			
			strcpy(loc, "/home/hana/modul2/indomie/");
			strcat(loc, newfile->d_name);
	
			if (pid4 = fork() == 0) {
			chdir(loc);
			char *cr1[] = {"touch", "coba1.txt", NULL};
			execv("/bin/touch", cr1);
			} 

			sleep(3);

			if (pid4 = fork() == 0) {
			chdir(loc);
			char *cr2[] = {"touch", "coba2.txt", NULL};
			execv("/bin/touch", cr2);
			}
		}
	}
	closedir(f);
   }
  }
 }
}

