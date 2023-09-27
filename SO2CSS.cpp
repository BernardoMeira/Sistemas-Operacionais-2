#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main(){
	pid_t x,y,z;
	x = fork();
	if(x > 0){
		cout << "ID Pai: " << getpid() << endl;
	}
	if ( x == 0){
		sleep(1);
		cout << "ID Filho 1: " << getpid() << ", ID Pai: " << getppid() << endl;
	} else if (x == -1){
		cout << "Impossivel criar processo." << endl;
	} else {
		y = fork();
		if (y == 0){
			sleep(2);
			cout << "ID Filho 2: " << getpid() << ", ID Pai: " << getppid() << endl;
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