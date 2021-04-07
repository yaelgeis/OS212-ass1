#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"



struct perf {
  int ctime;        // process creation time
  int ttime;        // process termination time
  int stime;        // the total time the process spent in the SLEEPING state
  int retime;       // the total time the process spent in the RUNNABLE state
  int rutime;       // the total time the process spent in the RUNNING state
  int average_bursttime;  // approximate estimated burst time
};


/*int main(int argc, char *argv[])
{
    
    int mask = 1<<6 | 1 <<16 | 1<<1 | 1<<12; //trace kill and write
    trace(mask, getpid());
 	int pid = fork(); // trace that dad forked
    int status;
 	if (pid > 0){ //parent
        wait(&status);
        int pid2 = fork();      // trace that dad forked
 	    if (pid2 == 0){ //child2
            trace(1<<6, getpid()); //trace kill  overide mask
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
 		}
 	}
    else{ //child1
        write(1, "child1\n", 7);  //  should be traced
        int pid3 = fork(); 
        if (pid3 > 0){ //child1
            trace(mask,getpid());
            wait(&status);
            kill(pid3);  //should be traced
        }
        else{ // child of child1   
            write(1, "child of child1\n", 16);  //  just print
        }
  }
  */
  
  /*printf("started\n");

    int pid2, pid3;
    if ((pid2 = fork()) == 0)
    {                           // child1
        int c = 0;
        while (c < 80)
        {                                      // print 3 times  and 30 sec sleep
            printf("child is running\n");
            //sleep(10);
            c++;
        }
        while (c < 200)
        {
            printf("%d\n", c);
            c++;
        }
        printf("\n");
        if((pid3 = fork())== 0){
            printf("im child num 2\n");

        }
        else{
            //int stat;
           // wait(&stat);
        }
    }
    else
    {
        int status;
        struct perf p;
        
        int x = wait_stat(&status, &p);
        printf("ret val: %d\n ", x);
        printf("ctime: %d\n ", p.ctime);
        printf("ttime: %d\n ", p.ttime);
        printf("stime: %d\n ", p.stime);
        printf("retime: %d\n ", p.retime);
        printf("rutime: %d\n", p.rutime);
    }

    sleep(1);
    sbrk(4096);

    
exit(0);


return 0;
}*/


//funcs
void test_for_bursttime_when_son_just_dies();
void testing_trace();
void extra_complicated_long_test();
void test_for_bursttime_when_son_does_long_stuff();
void test_for_bursttime_when_proces_with_lots_short_running_time(int num);
void test_with_lots_of_processes_for_order_checks();
void test_for_FCFS();
void test_for_FCFS_2childs_different_creation_time();
void test_for_SRT_preemptive();


int main(int argc, char** argv){
    // fprintf(2, "Hello world!\n");
    testing_trace();//task2
    extra_complicated_long_test();//mainly for task3
    test_for_bursttime_when_son_just_dies();// tasks 3 + 4.3. expecte bursttime 500?
    test_for_bursttime_when_son_does_long_stuff();
    test_for_bursttime_when_proces_with_lots_short_running_time(5);//with num 100 expects burrst time 0.  
                                                                      //with num 2 expects burrst time ? Explenation: 
                                                                      // - born with 500
                                                                      // after firsr run in while - 250
                                                                      // after second run in whike - 125
                                                                      // afetr exit - 62
    //test_with_lots_of_processes_for_order_checks();                                                                  
    //test_for_FCFS();
    //test_for_FCFS_2childs_different_creation_time();
    //test_for_SRT_preemptive();
    exit(0);
}

void test_for_SRT_preemptive(){

    int cpid=fork();
    fprintf(1, "cpid is: %d\n", cpid);
    if(cpid==0){ //son 
        fprintf(1, "child1 going to waste time...\n");
        int i= 0;
        while(i<300000000){
            i++;
        }
        fprintf(1, "child finished.\n");
        exit(0);
    }
    else{//father
        int i = 0;
        int cpid2=fork();
        fprintf(1, "cpid2 is: %d\n", cpid2);
        if(cpid2==0){//son like sunshine
            fprintf(1, "child2 start wasting time...\n");
            while(i<1000000000){
                i++;
            }
            fprintf(1, "child2finished...\n");
            exit(0);
        }
        else{
            fprintf(1, "father1 going to sleep...\n");
            sleep(2);
            fprintf(1, "father1 finished to sleep...\n");
            wait(0);
            wait(0);
        }
    }

}

void test_for_FCFS_2childs_different_creation_time(){
    int cpid=fork();
    fprintf(1, "cpid is: %d\n", cpid);
    if(cpid==0){//son like sunshine
        fprintf(1, "child1 going to sleep...\n");
        sleep(2);
        fprintf(1, "child1 going to sleep agin...\n");
        sleep(2);
        fprintf(1, "child1 exit...\n");
        exit(0);
    }
    else{//father
        int i = 0;
        fprintf(1, "father1 start wasting time...\n");
        while(i<1000000000){
            i++;
            //if(i==100000000){sleep(1);}
        }
        int cpid2=fork();
        fprintf(1, "cpid2 is: %d\n", cpid2);
        if(cpid2==0){//son like sunshine
            fprintf(1, "child2 going to sleep...\n");
            sleep(2);
            fprintf(1, "child2 waking up & exiting...\n");
            exit(0);
        }
        else{
            fprintf(1, "father1 going to sleep...\n");
            sleep(2);
            fprintf(1, "father1 waking up & waiting...\n");
            wait(0);
            wait(0);
        }
    }
}

void test_for_FCFS(){
    int cpid=fork();
    fprintf(1, "cpid is: %d\n", cpid);
    if(cpid==0){//son like sunshine
    int i = 0;
            while(i<1000000000){
            i++;
        }
        fprintf(1, "son going to sleep...\n");
        sleep(2);
        fprintf(1, "son waking up & exiting...\n");
        exit(0);
    }
    else{//father
        int i = 0;
        fprintf(1, "father start wasting time...\n");
        
        while(i<1000000000){
            i++;
            //if(i==100000000){sleep(1);}
        }
        fprintf(1, "father going to waste agin...\n");
        while(i<1000000000){
            i++;
            //if(i==100000000){sleep(1);}
        }
        fprintf(1, "father sleeping...\n");
        sleep(2);
        fprintf(1, "father waking up & waiting...\n");
        wait(0);
    }
}


void test_with_lots_of_processes_for_order_checks(){
    int i=0;
    struct perf* performance = malloc(sizeof(struct perf));
    int cpid=fork();
    if(cpid==0){//son like sunshine
        while(i<5){
            int cpid2=fork();
            if(cpid2==0){//grandchild
                if(i%2==0){
                    int k=0;
                    while(k<10000000000000){
                        k++;
                    }
                }
                else{
                    sleep(1);
                    sbrk(2);
                    int k=0;
                    while(k<10000000000000){
                        k++;
                    }
                }
                exit(0); //so grandchild won't make kids
            }
            else{//father (child1)
                wait(0);
            }
            i++;
        }
    }
    else{//father
    int t_pid = wait_stat(0, performance);
    fprintf(1, "terminated pid: %d, ctime: %d, ttime: %d, stime: %d, retime: %d, rutime: %d average_bursttime: %d \n",
                t_pid, performance->ctime, performance->ttime, performance->stime, performance->retime, performance->rutime,
                 performance->average_bursttime);
    }
}

void test_for_bursttime_when_proces_with_lots_short_running_time(int num){
    int i=0;
    struct perf* performance = malloc(sizeof(struct perf));
    int cpid=fork();
    if(cpid==0){//son like sunshine
        while(i<num){
            i++;
            sleep(1);
        }
    }
    else{//father
    int t_pid = wait_stat(0, performance);
    fprintf(1, "terminated pid: %d, ctime: %d, ttime: %d, stime: %d, retime: %d, rutime: %d average_bursttime: %d \n",
                t_pid, performance->ctime, performance->ttime, performance->stime, performance->retime, performance->rutime,
                 performance->average_bursttime);
    }
}


void test_for_bursttime_when_son_does_long_stuff(){
    int i=0;
    struct perf* performance = malloc(sizeof(struct perf));
    int cpid=fork();
    if(cpid==0){//son like sunshine
        while(i<1000000000){
            i++;
        }
    }
    else{//father
    int t_pid = wait_stat(0, performance);
    fprintf(1, "terminated pid: %d, ctime: %d, ttime: %d, stime: %d, retime: %d, rutime: %d average_bursttime: %d \n",
                t_pid, performance->ctime, performance->ttime, performance->stime, performance->retime, performance->rutime,
                 performance->average_bursttime);
    }
}


void test_for_bursttime_when_son_just_dies(){
    struct perf* performance = malloc(sizeof(struct perf));
    int cpid=fork();
    if(cpid==0){//son like sunshine
        exit(0);
    }
    else{//father
    int t_pid = wait_stat(0, performance);
    fprintf(1, "terminated pid: %d, ctime: %d, ttime: %d, stime: %d, retime: %d, rutime: %d average_bursttime: %d \n",
                t_pid, performance->ctime, performance->ttime, performance->stime, performance->retime, performance->rutime,
                 performance->average_bursttime);
    }
}

void testing_trace(){
    //mask=(1<< SYS_fork)|( 1<< SYS_kill)| ( 1<< SYS_sbrk) | ( 1<< SYS_write);
    int mask=(1<< 1);
    sleep(1); //doesn't print this sleep
    trace(mask, getpid());
    int cpid=fork();//prints fork once
    if (cpid==0){
        fork();// prints fork for the second time - the first son forks
        //mask= (1<< 13); //to turn on only the sleep bit
        mask= (1<< 1)|(1<< 13); //you can uncomment this inorder to check you print for both fork and sleep syscalls
        trace(mask, getpid()); //the first son and the grandchilde changes mask to print sleep
        sleep(1);
        fork();//should print nothing
        exit(0);//shold print nothing
    }
    else {
        sleep(10);// the father doesnt pring it - has original mask
    }
    mask= (1<< 12)|( 1<< 2) | (1<<6); //sbrk & exit & kill
    trace(mask, getpid());
    cpid= fork();
    kill(cpid);
    sbrk(4096);
}

void extra_complicated_long_test(){

    struct perf* performance = malloc(sizeof(struct perf));
    int mask=(1<< 1) | (1<< 23) | (1<< 3);
    trace(mask, getpid());
    int cpid = fork();
    if (cpid != 0){
        int t_pid = wait_stat(0, performance);
        fprintf(1, "terminated pid: %d, ctime: %d, ttime: %d, stime: %d, retime: %d, rutime: %d average_bursttime: %d \n", t_pid, performance->ctime, performance->ttime, performance->stime, performance->retime, performance->rutime, performance->average_bursttime);
    }
    else{
        sleep(10);
        for(int i=1; i < 15; i++){
            int c_pid = fork();
            if(c_pid == 0){
                sleep(i);
                exit(0);
            }
            else{
                int i = 0;
                while(i<100000000){
                    i++;
                }
            }
        }
        sleep(10);
        for(int i=1; i < 15; i++){
            int c_pid = fork();
            if(c_pid == 0){
                int i = 0;
                while(i<100000000){
                    i++;
                }
                exit(0);
            }
            else{
                int t_pid = wait_stat(0, performance);
                fprintf(1, "terminated pid: %d, ctime: %d, ttime: %d, stime: %d, retime: %d, rutime: %d average_bursttime: %d \n", t_pid, performance->ctime, performance->ttime, performance->stime, performance->retime, performance->rutime, performance->average_bursttime);
                int i = 0;
                while(i<10000){
                    i++;
                }
            }
        }
    }
}






