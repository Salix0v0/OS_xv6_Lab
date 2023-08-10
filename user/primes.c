#include "kernel/types.h"
<<<<<<< Updated upstream
#include "user/user.h"

void func(int *input, int num){
	if(num == 1){
		printf("prime %d\n", *input);
		return;
	}
	int p[2],i;
	int prime = *input;
	int temp;
	printf("prime %d\n", prime);
	pipe(p);
    if(fork() == 0){
        for(i = 0; i < num; i++){
            temp = *(input + i);
			write(p[1], (char *)(&temp), 4);
		}
        exit(0);
    }
	close(p[1]);
	if(fork() == 0){
		int counter = 0;
		char buffer[4];
		while(read(p[0], buffer, 4) != 0){
			temp = *((int *)buffer);
			if(temp % prime != 0){
				*input = temp;
				input += 1;
				counter++;
			}
		}
		func(input - counter, counter);
		exit(0);
    }
	wait(0);
	wait(0);
}

int main(){
    int input[34];
	int i = 0;
	for(; i < 34; i++){
		input[i] = i+2;
	}
	func(input, 34);
    exit(0);
}
=======
#include "user.h"

void process(int pd[],int num);

#define N 34
#define SIZE 8

int
main(int argc, char** argv){
    int pd[2];
	int n;  
    pipe(pd);
	
    if(fork() == 0)
	{
        process(pd,N);
    }
    else
	{
        for(int i=0;i<N;i++)
		{
			n=i+2;
        	write(pd[1], &n,SIZE);
		}
    }
    
	wait(0);
	exit(0);
}

void process(int pd_parent[],int num){
    int n_parent[N];
    int n_child[N];
    
    close(pd_parent[1]);
	for(int i=0;i<num;i++)
	{
		read(pd_parent[0],n_parent+i,SIZE);
	}
    
	printf("prime %d\n", n_parent[0]);  
	
	int top=0;

    for(int i=1;i<num;i++)
	{
		if(n_parent[i]%n_parent[0]!=0)
		{
			n_child[top]=n_parent[i];
			top++;
		}
	}

    close(pd_parent[0]);
    
    if(top == 0) {
        exit(0);
    }

    int pd_child[2];
    pipe(pd_child);

    if(fork() == 0){
        process(pd_child,top);
    }
    else{
		for(int i=0;i<top;i++)
        	write(pd_child[1],n_child+i,8);
			
	}
}



>>>>>>> Stashed changes
