#include "kernel/types.h"
#include "user/user.h"

<<<<<<< Updated upstream
int main(int argn, char *argv[]){
	if(argn != 2){
		fprintf(2, "must 1 argument for sleep\n");
		exit(1);
	}
	int sleepNum = atoi(argv[1]);
	printf("(nothing happens for a little while)\n");
	sleep(sleepNum);
	exit(0);
=======
int main(int argc, char *argv[]){
	if(argc<2){
		printf("please write the time of sleep\n");
		exit(1);
	}
	else{
		sleep(atoi(argv[1]));
		printf("(nothing happens for a little while)\n");
		exit(0);
	}
>>>>>>> Stashed changes
}
