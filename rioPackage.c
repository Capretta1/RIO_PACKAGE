#include "rioPackage.h"


/*
*This function transfers up to n bytes from the-current file position
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
			nread = 0;  /*and call read() again */
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



/*
*This function transfers n bytes from location ursbuf to descriptor fd
*/
ssize_t rio_writen(int fd, void *ursbuf, size_t n)
{
 size_t nleft = n;
 ssize_t nwritten;
 char *bufp = ursbuf;

 while (nleft > 0){
	if((nwritten = write(fd, bufp, nleft) <= 0){
		if (errno = ENTR)        /*Interruptes by sig handler return*/
			nwritten = 0;   /* and call write() again*/
		else
			return -1;     /* err no set by write() */
}
nleft -= nwritten;
bufp += nwritten;
}
return n;
}


/*
*This function is called once per open descriptor. It associates the descriptor fd with a read buffer of type rio_t at address rp.
*/
void rio_readinitb(rio_t *rp, int fd)
{
	rp->rio_fd = fd;
	rp->rio_cnt = 0;
	rp->rio_bufptr = rp->rio_buf;
}
