#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

struct perf {
  int ctime;        // process creation time
  int ttime;        // process termination time
  int stime;        // the total time the process spent in the SLEEPING state
  int retime;       // the total time the process spent in the RUNNABLE state
  int rutime;       // the total time the process spent in the RUNNING state
  float bursttime;  // approximate estimated burst time
};

void print_perf(struct perf *performance) {
    fprintf(1, "perf:\n");
    fprintf(1, "\tctime: %d\n", performance->ctime);
    fprintf(1, "\tttime: %d\n", performance->ttime);
    fprintf(1, "\tstime: %d\n", performance->stime);
    fprintf(1, "\tretime: %d\n", performance->retime);
    fprintf(1, "\trutime: %d\n", performance->rutime);
    fprintf(1, "\n\tTurnaround time: %d\n", (performance->ttime - performance->ctime));
}


int main(int argc, char** argv){
  	int pid1, status1;
	struct perf perf2;
	pid1 = fork();
	if (pid1 > 0) { //parent
		int s = wait_stat(&status1, &perf2);
		printf("pid is: %d\n", s);
		print_perf(&perf2);
	}
	 else { //child
	 	sleep(10);
	 	write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		 write(1, "hello i'm a child\n", 18);
		
    }
	exit(0);
}
