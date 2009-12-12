#ifndef __PLATFORM_H
#define __PLATFORM_H

#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <direct.h>
#include <Ws2tcpip.h>
#include <process.h>

#include "gettimeofday.h"
#include "snprintf.h"
#include "net.h"
#include "w32_errno.h"
#include "w32_stat.h"

#ifndef __cplusplus
typedef unsigned short mode_t;
#endif

#define strcasecmp lstrcmpi
#define strncasecmp strnicmp
#define mkdir(path, mode) mkdir(path)
#define sleep(sex) Sleep(sex)
#define getuid() 0
#define getgid() 0

char *strptime(const char *s, const char *format, struct tm *tm);

#define socket w32_socket
#define getsockopt w32_getsockopt
#define setsockopt w32_setsockopt
#define bind w32_bind
#define connect w32_connect
#define send w32_send
#define recv w32_recv
#define closesocket w32_closesocket
#define getservbyname w32_getservbyname
#define getaddrinfo w32_getaddrinfo
#define freeaddrinfo w32_freeaddrinfo
#define inet_ntop w32_inet_ntop
#define gethostbyname w32_gethostbyname
#define select w32_select
#define ftruncate _chsize
#define getpid GetCurrentProcessId

#define PATH_MAX 32767

#define SEARCH_LIBDIR ""

#ifndef MIN
#define MIN(a, b)	(((a) < (b)) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b)	(((a) > (b)) ? (a) : (b))
#endif

#ifndef HAVE_IN_PORT_T
typedef	unsigned	short	in_port_t;
#endif

#ifndef HAVE_IN_ADDR_T
typedef	unsigned	int	in_addr_t;
#endif

#define PATHSEP "\\"

#undef DATADIR
#undef CONFDIR
#if !defined(THIS_IS_LIBCLAMAV) && defined(_MSC_VER)
#define LIBCLAMAV_EXPORT __declspec(dllimport)
#else
#define LIBCLAMAV_EXPORT
#endif
LIBCLAMAV_EXPORT extern const char *DATADIR;
LIBCLAMAV_EXPORT extern const char *CONFDIR;
LIBCLAMAV_EXPORT extern const char *CONFDIR_CLAMD;
LIBCLAMAV_EXPORT extern const char *CONFDIR_FRESHCLAM;
LIBCLAMAV_EXPORT extern const char *CONFDIR_MILTER;
#undef HAVE_CONFIG_H

#ifdef OUT
#undef OUT
#endif

#endif /* __PLATFORM_H */

