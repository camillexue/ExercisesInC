#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/un.h>
#include <stdarg.h>
#include <syslog.h>

#define MAXLINE 4096
#define BUFSIZE 1500

typedef struct rec {                /* outgoing UDP data */
  u_short seq;          /* sequence number */
} Rec;

typedef struct timeval Timeval;
typedef struct sockaddr Sockaddr;

socklen_t salen;                    /* length of a socket address */
int datalen = sizeof (Rec);         /* length of the data in a datagram */

u_short sport;                      /* source UDP port # */
u_short dport = 32768 + 668;        /* destination port -- hopefully unused */
                                    /* 668 = the neighbor of the beast */
Timeval sendtv[1];
Timeval recvtv[1];
Timeval difftv[1];



/* variables we might want to configure */
int max_ttl = 30;
int nprobes = 2;

/* other global variables */

int seq = 0;

char recvbuf[BUFSIZE];
char sendbuf[BUFSIZE];
Rec *rec = (Rec *) sendbuf;

int sendfd, recvfd;
int pipefd[2];              /* the pipe for the alarm handler */

Sockaddr *sasend;    /* socket addresses for various purposes */
Sockaddr *sarecv;
Sockaddr *salast;
Sockaddr *sabind;
/* the following are a few definitions from Stevens' unp.h */

#define max(a,b) ((a) > (b) ? (a) : (b))

void sig_alrm(int signo);
int process_ip(struct ip *ip, int len);
int recv_dgram();
void sub_tv(Timeval *plus, Timeval *minue, Timeval *res);
double time_to_double(Timeval *time);
void print_report();
void send_dgram(int ttl);
int send_probes(int ttl);
void loop_ttl();
