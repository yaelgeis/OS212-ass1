#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char **argv)
{

  // if(argc < 3){
  //   fprintf(2, "usage: trace..\n");
  //   exit(1);
  // }
  // int mask = atoi(argv[1]);
  // int pid = atoi(argv[2]);
  // trace(mask,pid);


 	int mask = 1<<6 | 1 <<16; //trace kill and write
  trace(mask, getpid());
 	int pid = fork();
  int status;
 	if (pid > 0){ //parent
    wait(&status);
 		int pid2 = fork();
 		if (pid2 == 0){ //child2
      trace(1<<6, getpid()); //trace kill
      int pid4 = fork();
      wait(&status);
      if (pid4 >0){ //child 2
        kill(pid4); //should be traced
   			write(1, "child2\n", 7);  //shouldnt be traced
      }
 		}
 		else{ //parent
      wait(&status);
 			write(1, "parent\n", 7); //should be traced
      open("/path", 0); //shouldn't be traced
 		}
 	}
  else{ //child1
    write(1, "child1\n", 7);  //should be traced
    int pid3 = fork(); //shouldnt be traced
    if (pid3 >0){ //child1
      wait(&status);
      kill(pid3);  //should be traced
    }
  }
  

  exit(0);

}
