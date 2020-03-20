//Producer Process
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/shm.h> 
#include <sys/stat.h>
#include <sys/mman.h>

int main() 
{ 
    const int SIZE = 4096; 
  
    const char* name = "OS"; 
  
    int common_var = 1;  

    int shm_fd; 

    const char* msg ="a";
  
    void* ptr; 
  
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666); 

    ftruncate(shm_fd, SIZE); 

    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0); 
  
    sprintf(ptr, "%d", common_var++ ); 
  
    ptr += strlen(msg); 

    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    printf("%ls", (int*)ptr);

  //  sprintf(ptr, "%s", message_1); 
  //  ptr += strlen(message_1); 
    return 0; 
} 