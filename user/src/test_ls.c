#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syscall.h>
#include <time.h>
#include <ulib.h>
#include <unistd.h>

int main(void) {
  int pid;
  if ((pid = fork()) == 0) {
    char name[] = "/libc-test/src/functional/argv-static.exe";
    char* argv[] = {name};
    int returncode = sys_exec(name, 0, argv);
    cprintf("%s FAILED1, returncode = %d.\n", name, returncode);
    exit(0);
  }
  // if(fork() == 0) {
  //     cputs("child process[1], wait for keyboard input.\n wait for next\n");
  //     for(int i = 0; i < 100; i++) {
  //         char c = getchar();
  //         cprintf("char[%d] = %c, wait for next\n", i, c);
  //     }
  //     cputs("child process[1] over");
  // }
  // sys_block_in_kernel();
  int store;
  struct timespec time = {.tv_sec = 0, .tv_nsec = 1e8};
  while (waitpid(pid, &store) <= 0) {
    sleep(&time);
  }
  cprintf("RETURN %d\n", store);
  return 0;
}