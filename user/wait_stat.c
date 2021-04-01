#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"



// /******* New struct ********/  
// struct perf {
//   int ctime;        // process creation time
//   int ttime;        // process termination time
//   int stime;        // the total time the process spent in the SLEEPING state
//   int retime;       // the total time the process spent in the RUNNABLE state
//   int rutime;       // the total time the process spent in the RUNNING state
//   float bursttime;  // approximate estimated burst time
// };

int main(int argc, char **argv)
{

 	// int status, pid;
	// struct perf* p = malloc(sizeof(struct perf));
	// pid = fork();
	// if (pid == 0){
	// 	write(1, "hello, i'm a child\n", 19);
	// }
	// else{
	// 	wait_stat(&status, p);
	// 	printf("parent printing\n");
	// 	printf("status: %d\n", status);
	// 	printf("ctime: %d\n", p->ctime);
	// 	printf("ctime: %d\n", p->ttime);
	// 	printf("ctime: %d\n", p->stime);
	// 	printf("ctime: %d\n", p->retime);
	// 	printf("ctime: %d\n", p->rutime);
	// }

  	exit(0);

}
