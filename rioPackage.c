#include "rioPackage.h"


/*
*The rio_readn function transfers up to n bytes from the-current file position
*of descriptor fd into memory location usrbuf
*/
ssize_t rio_readn(int fd, void *usrbuf, size_t n)
{
  size_t nleft = n;
  ssize_t nread;
  char *bufp = usrbuf;

  while(nleft > 0){
	if((nread = read(fd, bufp, nleft)) < 0){
		if(errno == EINTR)   /*Interrupted by sig handler return*/
			nread = 0;  /*and call(), and read() again */
		  else
			return -1;  /* err no set by read() */
}
else if(nread == 0)
	break;   		   /* EOF */
nleft -= nread;
bufp += nread;
}
return (n - nleft); 	  	  /*Return >= 0 */
}
