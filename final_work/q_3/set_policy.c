#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>
#include <errno.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/unistd.h>
#include <linux/sched.h>

/* use the proper system call */
#ifdef __x86_64__
#define __NR_sched_setattr 314
#endif
#ifdef __i386__
#define __NR_sched_setattr 351
#endif
#ifdef __arm__
#define __NR_sched_setattr 380
#endif

struct sched_attr {
  __u32 size;
  __u32 sched_policy;
  __u64 sched_flags;
  __u32 sched_priority;
  __u32 sched_nice;

  /*SCHED_DEADLINE*/
  __u64 sched_runtime;
  __u64 sched_deadline;
  __u64 sched_period;
};

/* The sched_getattr() system call fetches the scheduling policy and the
associated attributes for the thread whose ID is specified in pid.
If pid equals zero, the scheduling policy and attributes of the calling thread will be retrieved.
*/
int sched_setattr(pid_t pid, const struct sched_attr *attr, unsigned int flags){
  return syscall( __NR_sched_setattr, pid, attr, flags);
}

void main(int argc , char** argv){
  //scheduler policy
  int policy = atoi(argv[1]);
  //priority number
  int priority = atoi(argv[2]);

  struct sched_param p;
  pid_t pid  = getpid();
  printf("the pid is = %d\n", pid);
  printf("policy = %d\n", policy);
  printf("priority = %d\n",priority);

  /*change policy & priority for:
  SCHED_OTHER = 0;
  SCHED_FIFO = 1;
  SCHED_RR = 2;
  SCHED_IDLE = 5;
  */
  if(policy != 6){
    p.sched_priority = priority;
    if(sched_setscheduler(0, policy, &p) == -1){
      if(errno==ESRCH) printf("failed with ESRCH\n");
		  if(errno==EPERM) printf("failed with EPERM\n");
		  if(errno==EINVAL) printf("failed with EINVAL\n");
    }
  }
   //for SCHED_DEADLINE
  else{
    struct sched_attr attr;
    attr.size = sizeof(attr);
    attr.sched_policy = 6;
    attr.sched_flags = 0;
    attr.sched_nice = 0;
    attr.sched_priority = priority;
    /* create a 10ms/30ms reservation */
    attr.sched_runtime = 10000000;
    attr.sched_deadline = 30000000;
    attr.sched_period = 30000000;
    sched_setattr(getpid(), &attr, 0);
  }

  while(1){};
}