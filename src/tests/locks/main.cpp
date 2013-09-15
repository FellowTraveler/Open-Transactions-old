#include <cstdlib>
#include <csignal>
#include <iostream>

/**
Test with:
g++ main.cpp  && ./a.out

and do CTRL-C and from other term kill  `pidof a.out`  or various combinations
*/

using std::cout;
using std::cin;
using std::endl;

#define DBG(X) { std::cout << __LINE__ << ": " << X << endl; }

extern int signalHandler_ctrlC_is_running_level; // 0=not 1=yes

void signalHandler_ctrlC( int signum ) {
	DBG("\nGot signal SIG" << signum );
	if (signalHandler_ctrlC_is_running_level) {
		DBG("We are already handling a shutdown and now another signal received - aborting now then.");
		abort();
	}
	signalHandler_ctrlC_is_running_level = 1;

	DBG("Will exit nicelly");
	exit(signum);
}

void cleanup_pid_files() {
	DBG("*** Cleaning up the PID locks ***");
	cout << "Simulating problem here (press ENTER to continue or CTRL-C to break a program that hanged on cleanup)... " << endl;
 	std::string s; getline(cin,s);
	DBG("PID locks are removed - bye");
}

void my_exit() {
	DBG("my_exit");		
	cleanup_pid_files();
}


int signalHandler_ctrlC_is_running_level=0;

int main() {
	DBG("started");
	signal(SIGINT, signalHandler_ctrlC);  
	signal(SIGTERM, signalHandler_ctrlC);  
	signal(SIGHUP, signalHandler_ctrlC);  
	signal(SIGSTOP, signalHandler_ctrlC);  

	atexit( my_exit );

	cout<<"Waiting (press ENTER to exit normally or CTRL-C to simulate canceling the program)... "; std::string s; getline(cin,s);

	DBG("normal end of main()");
	return 1;
}

