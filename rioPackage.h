/*
* PROTOTYPES AND DEFINITIONS
*/
#ifndef RIO_PACKAGE_H
#define RIO_PACKAGE_H



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>




/* RIO Buffer size */
#define RIO_BUFSIZE 8192

/* Persistent state for the robus I/O (rio) package */
typedef struct {
	int rio_fd                 /*Descriptor for this internal buf */
	int rio_cnt                /*Unread bytes in internal buf */
	char *rio_bufptr           /*Next unread  byte in internal buf */
	char rio_buf[RIO_BUFSIZE]  /*INTERNAL BUFFER */
}rio_t;


/* Rio (Robust I/O) package */
ssize_t rio_readn(int fd, void *usrbuf, size_t n);
ssize_t rio_writen(int fd, void *usrbuf, size_t n);
void rio_readinitb(rio_t *rp, int fd); 
ssize_t	rio_readnb(rio_t *rp, void *usrbuf, size_t n);
ssize_t	rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);


/* Wrappers for Rio package */
ssize_t Rio_readn(int fd, void *usrbuf, size_t n);
void Rio_writen(int fd, void *usrbuf, size_t n);
void Rio_readinitb(rio_t *rp, int fd); 
ssize_t Rio_readnb(rio_t *rp, void *usrbuf, size_t n);
ssize_t Rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);


#endif /* RIO_PACKAGE_H */
