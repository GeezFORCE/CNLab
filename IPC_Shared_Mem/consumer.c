#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <sys/shm.h> 
#include <sys/stat.h> 
#include <sys/mman.h>
#include<string.h>
  
int main() 
{ 
    const int SIZE = 4096; 

    const char* name = "OS"; 
  
    const char* msg = "a";
    
    int shm_fd; 
  
    void* ptr; 
  
    shm_fd = shm_open(name, O_RDWR, 0666); 

    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0); 
    
    printf("%ls", (int*)ptr);

    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    int common_var = (int*)ptr;
    printf("%ls",&common_var);
    sprintf(ptr, "%d", common_var++ );

    
    ptr += strlen(msg); 
   shm_unlink(name); 
    return 0; 
}