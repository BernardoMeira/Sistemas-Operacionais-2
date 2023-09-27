#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

using namespace std;

void* create_shared_memory(size_t size) {
  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_SHARED | MAP_ANONYMOUS;
  return mmap(NULL, size, protection, visibility, -1, 0);
}

int main(){
	pid_t x,y,z,n;
	char P1_F2[] = {"Olá F2"};
	char* shmem = (char*)create_shared_memory(128);
	memcpy(shmem, P1_F2, sizeof(P1_F2));
	x = fork();
	if(x > 0){
		cout << "ID Pai: " << getpid() << endl;
	}
	if (x == 0){
		sleep(1);
		cout << "ID Filho 1: " << getpid() << ", ID Pai: " << getppid() << endl;
		n = fork();
	    if (n == 0){
	        cout << "   ID N1: " << getpid() << ", ID Pai: " << getppid() << endl;
	    }
	} else if (x == -1){
		cout << "Impossivel criar processo." << endl;
	} else {
		y = fork();
		if (y == 0){
			sleep(2);
			cout << "ID Filho 2: " << getpid() << ", ID Pai: " << getppid() << endl;
			memcpy(shmem, P1_F2, sizeof(P1_F2));
	        cout << "   " << shmem << endl;
		} else {
			z = fork();
			if (z == 0){
				sleep(3);
				cout << "ID Filho 3: " << getpid() << ", ID Pai: " << getppid() << endl;
			}
		}
	}
	sleep(4);
	return 0;
}