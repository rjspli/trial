#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define CNT_PROC 3

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int fd[2];

int initsem(key_t semkey){
    union semun semunarg;
    int status = 0, semid;
    semid = semget(semkey, 1, IPC_CREAT | IPC_EXCL | 0600);

    if(semid == -1){
        if(errno == EEXIST)
            semid = semget(semkey, 1, 0);
    }
    else{
        semunarg.val = 1;
        status = semctl(semid, 0, SETVAL, semunarg);
    }

    if(semid == -1 || status == -1){
        perror("initsem");
        return(-1);
    }

    return semid;
}

int uninitsem(int *semid){
    semctl(*semid, 0, IPC_RMID);
}

int semlock(int semid){
    struct sembuf buf;
    buf.sem_num = 0;
    buf.sem_op = -1;
    buf.sem_flg = SEM_UNDO;
    if(semop(semid, &buf, 1) == -1){
        perror("semlock failed");
        exit(1);
    }
    return 0;
}

int semunlock(int semid){
    struct sembuf buf;
    buf.sem_num = 0;
    buf.sem_op = 1;
    buf.sem_flg = SEM_UNDO;
    if(semop(semid, &buf, 1) == -1){
        perror("semunlock failed");
        exit(1);
    }
    return 0;
}

void semhandle(int *mqid, int *semid){
    pid_t pid = getpid();
    int len;

    if((*semid = initsem(1)) < 0)
        exit(1);

    close(fd[1]);
    len = read(fd[0], mqid, 4);
    close(fd[0]);

    msgsnd(*mqid, (int*)semid, 4, 0);

    semlock(*semid);
    printf("Lock : Process %d\n",(int)pid);
    printf("!!! critical section\n");
    sleep(1);
    printf("Unlock: Process %d\n", (int)pid);
    semunlock(*semid);

    exit(0);
}

int main(void){
    int a;
    int semid = 0;
    int mqid = 0;
    pid_t pid = getpid();

    mqid = msgget(10, IPC_CREAT|0666);

    if(pipe(fd) == -1){
        perror("pipe");
        exit(1);
    }

    printf("parent pid:%d\n", (int)pid);
    for(a = 0; a < CNT_PROC; a++)
        if(fork() == 0) semhandle(&mqid, &semid);

    close(fd[0]);
    write(fd[1], (int*)&mqid, 4);
    close(fd[1]);

    msgrcv(mqid, (int*)&semid, 4, 0, 0);

    for(a = 0; a < CNT_PROC; a++){
        pid_t ch_pid = waitpid(-1, 0, 0);
    }

    uninitsem(&semid);

    msgctl(mqid, IPC_RMID, 0);

    return 0;
}
