#include <stdio.h>
#include <unistd.h>

int main(void) {
  char filename[] = "/home/nginx/test/mytemp.XXXXXX"; // template for our file.        
  int fd = mkstemp(filename);    // Creates and opens a new temp file r/w.
                                 // Xs are replaced with a unique number.
  if (fd == -1) {
    printf ("before return\n"); 
    return 1;        // Check we managed to open the file.
  }
  printf ("before write %d\n", fd);
  write(fd, "abc", 4);           // note 4 bytes total: abc terminating '\0'
  /* ...
     do whatever else you want.
     ... */
  close(fd);
  unlink(filename);              // Delete the temporary file.
}
