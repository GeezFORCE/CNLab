#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int csd,cport,len;
char sendmsg[20],revmsg[20];
struct sockaddr_in servaddr;
printf("Enter the port\n");
scanf("%d",&cport);
csd=socket(AF_INET,SOCK_STREAM,0);
if(csd<0)
 printf("Can't Create\n");
else
 printf("Scocket is Created\n");
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(cport);
if(connect(csd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0)
 printf("Can't Connect\n");
else
 printf("Connected\n");
do
 {
fgets(sendmsg,20,stdin);
len=strlen(sendmsg);
sendmsg[len-1]='\0';
send(csd,sendmsg,20,0);
wait(20);
recv(csd,revmsg,20,0);
printf("%s",revmsg);
}
while(strcmp(revmsg,"bye")!=0);
return(0);
}