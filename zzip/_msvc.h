#ifndef _ZZIP__MSVC_H
#define _ZZIP__MSVC_H 1
 
/* zzip/_msvc.h. Generated automatically at end of configure. */
/* config.h.in.  Generated automatically from configure.ac by autoheader.  */
/* config values have been automatically set by zzip/_msvc.sed */

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef _zzip_const */

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef ZZIP__FILE_OFFSET_BITS */

/* Define if you have the <direct.h> header file. */
#ifndef ZZIP_HAVE_DIRECT_H 
#define ZZIP_HAVE_DIRECT_H  1 
#endif

/* Define if you have the <dirent.h> header file, and it defines `DIR'. */
/* #undef ZZIP_HAVE_DIRENT_H */

/* Define if you have the <dlfcn.h> header file. */
/* #undef ZZIP_HAVE_DLFCN_H */

/* Define if you have the <inttypes.h> header file. */
/* #undef ZZIP_HAVE_INTTYPES_H */

/* Define if you have the <io.h> header file. */
#ifndef ZZIP_HAVE_IO_H 
#define ZZIP_HAVE_IO_H  1 
#endif

/* Define if you have the <memory.h> header file. */
#ifndef ZZIP_HAVE_MEMORY_H 
#define ZZIP_HAVE_MEMORY_H  1 
#endif

/* Define if you have the <ndir.h> header file, and it defines `DIR'. */
/* #undef ZZIP_HAVE_NDIR_H */

/* Define if you have the <stdint.h> header file. */
/* #undef ZZIP_HAVE_STDINT_H */

/* Define if you have the <stdlib.h> header file. */
#ifndef ZZIP_HAVE_STDLIB_H 
#define ZZIP_HAVE_STDLIB_H  1 
#endif

/* Define if you have the `strcasecmp' function. */
/* #undef ZZIP_HAVE_STRCASECMP */

/* Define if you have the <string.h> header file. */
#ifndef ZZIP_HAVE_STRING_H 
#define ZZIP_HAVE_STRING_H  1 
#endif

/* Define if you have the <strings.h> header file. */
/* #undef ZZIP_HAVE_STRINGS_H */

/* Define if you have the <sys/dir.h> header file, and it defines `DIR'. */
/* #undef ZZIP_HAVE_SYS_DIR_H */

/* Define if you have the <sys/int_types.h> header file. */
/* #undef ZZIP_HAVE_SYS_INT_TYPES_H */

/* Define if you have the <sys/mman.h> header file. */
/* #undef ZZIP_HAVE_SYS_MMAN_H */

/* Define if you have the <sys/ndir.h> header file, and it defines `DIR'. */
/* #undef ZZIP_HAVE_SYS_NDIR_H */

/* Define if you have the <sys/param.h> header file. */
/* #undef ZZIP_HAVE_SYS_PARAM_H */

/* Define if you have the <sys/stat.h> header file. */
#ifndef ZZIP_HAVE_SYS_STAT_H 
#define ZZIP_HAVE_SYS_STAT_H  1 
#endif

/* Define if you have the <sys/types.h> header file. */
#ifndef ZZIP_HAVE_SYS_TYPES_H 
#define ZZIP_HAVE_SYS_TYPES_H  1 
#endif

/* Define if you have the <unistd.h> header file. */
/* #undef ZZIP_HAVE_UNISTD_H */

/* Define if you have the <winbase.h> header file. */
#ifndef ZZIP_HAVE_WINBASE_H 
#define ZZIP_HAVE_WINBASE_H  1  /* hmm, is that win32 ? */ 
#endif

/* Define if you have the <windows.h> header file. */
#ifndef ZZIP_HAVE_WINDOWS_H 
#define ZZIP_HAVE_WINDOWS_H  1  /* yes, this is windows */ 
#endif

/* Define if you have the <winnt.h> header file. */
#ifndef ZZIP_HAVE_WINNT_H 
#define ZZIP_HAVE_WINNT_H  1      /* is that always true? */ 
#endif

/* Define if you have the <zlib.h> header file. */
#ifndef ZZIP_HAVE_ZLIB_H 
#define ZZIP_HAVE_ZLIB_H  1      /* you do have it, right? */ 
#endif

/* Define as `__inline' if that's what the C compiler calls it, or to nothing
   if it is not supported. */
#ifndef _zzip_inline 
#define _zzip_inline  __inline 
#endif

/* Define for large files, on AIX-style hosts. */
/* #undef ZZIP__LARGE_FILES */

/* whether the system defaults to 32bit off_t but can do 64bit when requested
   */
/* #undef ZZIP_LARGEFILE_SENSITIVE */

/* Define to `long' if <sys/types.h> does not define. */
#ifndef _zzip_off_t 
#define _zzip_off_t  long 
#endif

/* Name of package */
#ifndef ZZIP_PACKAGE 
#define ZZIP_PACKAGE  "zziplib-msvc"     /* yes, make it known */ 
#endif

/* The number of bytes in type int */
#ifndef ZZIP_SIZEOF_INT 
#define ZZIP_SIZEOF_INT  4 
#endif

/* The number of bytes in type long */
#ifndef ZZIP_SIZEOF_LONG 
#define ZZIP_SIZEOF_LONG  4 
#endif

/* The number of bytes in type short */
#ifndef ZZIP_SIZEOF_SHORT 
#define ZZIP_SIZEOF_SHORT  2 
#endif

/* Define to `unsigned' if <sys/types.h> does not define. */
/* #undef _zzip_size_t */

/* Define to `int' if <sys/types.h> does not define. */
#ifndef _zzip_ssize_t 
#define _zzip_ssize_t  int 
#endif

/* Define if you have the ANSI C header files. */
#ifndef ZZIP_STDC_HEADERS 
#define ZZIP_STDC_HEADERS  1 
#endif

/* Version number of package */
/* #undef ZZIP_VERSION */
 
/* once: _ZZIP__MSVC_H */
#endif
