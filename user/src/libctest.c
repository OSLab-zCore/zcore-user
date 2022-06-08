#include <asynccall.h>
#include <barrier.h>
#include <file.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ulib.h>
#include <unistd.h>

#define INSIZE (0x1000000)

char buf[INSIZE];

int main() {
  int FD = open("riscv64_bare.txt", O_RDWR | O_CREAT);
  int len = read(FD, buf, INSIZE);
  int i = 0, begin = 0, end = 0, passed_tests = 0;
  while (i < len) {
    while (buf[i] != ' ') {
      i++;
      end++;
    }
    while (buf[i] == ' ') {
      i++;
    }
    while (buf[i] != '\n') {
      i++;
    }
    if (buf[i - 1] == 'K') {
      char name[end - begin + 1];
      memcpy(name, buf + begin, end - begin);
      name[end - begin] = '\0';
      int pid;
      if ((pid = fork()) == 0) {
        char* argv[] = {name, NULL};
        int returncode = sys_exec(name, 0, argv);
        cprintf("%s FAILED_S, returncode = %d.\n", name, returncode);
        exit(0);
      }
      int store;
      struct timespec time = {.tv_sec = 0, .tv_nsec = 1e8};
      while (waitpid(pid, &store) <= 0) {
        sleep(&time);
      }
      if (store != 0) {
        cprintf("%s FAILED_F, returncode = %d.\n", name, store);
        return 0;
      }
      passed_tests++;
    }
    i++;
    begin = i, end = i;
  }
  cprintf("passed_tests = %d.\n", passed_tests);
  return 0;
}