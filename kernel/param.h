#define NPROC        64  // maximum number of processes
#define NCPU          8  // maximum number of CPUs
#define NOFILE       16  // open files per process
#define NFILE       100  // open files per system
#define NINODE       50  // maximum number of active i-nodes
#define NDEV         10  // maximum major device number
#define ROOTDEV       1  // device number of file system root disk
#define MAXARG       32  // max exec arguments
#define MAXOPBLOCKS  10  // max # of blocks any FS op writes
#define LOGSIZE      (MAXOPBLOCKS*3)  // max data blocks in on-disk log
#define NBUF         (MAXOPBLOCKS*3)  // size of disk block cache
#define FSSIZE       1000  // size of file system in blocks
#define MAXPATH      128   // maximum file path name
#define QUANTUM 	 5	   // Added for A1T4


//A1T4 - scheduler types
#define DEFAULT 	 0	   
#define FCFS    	 1	   
#define SRT 	     2
#define CFSD    	 3	  

//A1T4 - decay factors
#define THP 	 1  // Test High Priority	   
#define HP 	     3  // High Priority	   
#define NP 	     5  // Normal Priority
#define LP 	     7  // Low Priority
#define TLP 	 25 // Test Low Priority
