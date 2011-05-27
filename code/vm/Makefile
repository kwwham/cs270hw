# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the virtual memory assignment
#    Defines set up assuming the virtual memory assignment is done before 
# 	the file system assignment. If not, use the "filesys first"  
#	defines below. 
#
# Also, if you want to simplify the translation so it assumes
# only linear page tables, don't define USE_TLB.
#
# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES = -DUSER_PROGRAM  -DFILESYS_NEEDED -DFILESYS_STUB -DVM
INCPATH = -I../filesys -I../bin -I../vm -I../userprog -I../threads -I../machine
HFILES = $(THREAD_H) $(USERPROG_H) $(VM_H)
CFILES = $(THREAD_C) $(USERPROG_C) $(VM_C)
C_OFILES = $(THREAD_O) $(USERPROG_O) $(VM_O)

# if file sys done first!
# DEFINES = -DUSER_PROGRAM -DFILESYS_NEEDED -DFILESYS -DVM -DUSE_TLB
# INCPATH = -I../vm -I../bin -I../filesys -I../userprog -I../threads -I../machine
# HFILES = $(THREAD_H) $(USERPROG_H) $(FILESYS_H) $(VM_H)
# CFILES = $(THREAD_C) $(USERPROG_C) $(FILESYS_C) $(VM_C)
# C_OFILES = $(THREAD_O) $(USERPROG_O) $(FILESYS_O) $(VM_O)

include ../Makefile.common
include ../Makefile.dep
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
main.o: ../threads/main.cc ../threads/copyright.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h ../threads/thread.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/syscall.h ../userprog/PCB.h \
 ../filesys/UserOpenFile.h ../filesys/SysOpenFile.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../userprog/syscall.h ../userprog/bitmap.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/synch.h ../userprog/MemoryManager.h ../threads/synch.h \
 ../userprog/ProcessManager.h ../vm/SwapManager.h ../machine/translate.h \
 ../vm/VMManager.h ../vm/SwapManager.h ../filesys/SysOpenFile.h
list.o: ../threads/list.cc ../threads/copyright.h ../threads/list.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h
scheduler.o: ../threads/scheduler.cc ../threads/copyright.h \
 ../threads/scheduler.h ../threads/list.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/syscall.h ../userprog/PCB.h ../filesys/UserOpenFile.h \
 ../filesys/SysOpenFile.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../userprog/syscall.h ../userprog/bitmap.h ../threads/system.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../threads/synch.h ../userprog/MemoryManager.h \
 ../threads/synch.h ../userprog/ProcessManager.h ../vm/SwapManager.h \
 ../machine/translate.h ../vm/VMManager.h ../vm/SwapManager.h \
 ../filesys/SysOpenFile.h /usr/include/time.h /usr/include/bits/time.h \
 /usr/include/sys/time.h /usr/include/sys/select.h \
 /usr/include/bits/select.h /usr/include/bits/sigset.h
synch.o: ../threads/synch.cc ../threads/copyright.h ../threads/synch.h \
 ../threads/thread.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/syscall.h \
 ../userprog/PCB.h ../filesys/UserOpenFile.h ../filesys/SysOpenFile.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../userprog/syscall.h \
 ../userprog/bitmap.h ../threads/list.h ../threads/system.h \
 ../threads/scheduler.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../userprog/MemoryManager.h \
 ../threads/synch.h ../userprog/ProcessManager.h ../vm/SwapManager.h \
 ../machine/translate.h ../vm/VMManager.h ../vm/SwapManager.h \
 ../filesys/SysOpenFile.h
synchlist.o: ../threads/synchlist.cc ../threads/copyright.h \
 ../threads/synchlist.h ../threads/list.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/synch.h ../threads/thread.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/syscall.h ../userprog/PCB.h \
 ../filesys/UserOpenFile.h ../filesys/SysOpenFile.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../userprog/syscall.h ../userprog/bitmap.h
system.o: ../threads/system.cc ../threads/copyright.h ../threads/system.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/syscall.h ../userprog/PCB.h ../filesys/UserOpenFile.h \
 ../filesys/SysOpenFile.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../userprog/syscall.h ../userprog/bitmap.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../threads/synch.h \
 ../userprog/MemoryManager.h ../threads/synch.h \
 ../userprog/ProcessManager.h ../vm/SwapManager.h ../machine/translate.h \
 ../vm/VMManager.h ../vm/SwapManager.h ../filesys/SysOpenFile.h
thread.o: ../threads/thread.cc ../threads/copyright.h ../threads/thread.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/syscall.h \
 ../userprog/PCB.h ../filesys/UserOpenFile.h ../filesys/SysOpenFile.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../userprog/syscall.h \
 ../userprog/bitmap.h ../threads/switch.h ../threads/synch.h \
 ../threads/list.h ../threads/system.h ../threads/scheduler.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../userprog/MemoryManager.h ../threads/synch.h \
 ../userprog/ProcessManager.h ../vm/SwapManager.h ../machine/translate.h \
 ../vm/VMManager.h ../vm/SwapManager.h ../filesys/SysOpenFile.h
utility.o: ../threads/utility.cc ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/stdarg.h
threadtest.o: ../threads/threadtest.cc ../threads/copyright.h \
 ../threads/system.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/syscall.h ../userprog/PCB.h ../filesys/UserOpenFile.h \
 ../filesys/SysOpenFile.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../userprog/syscall.h ../userprog/bitmap.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../threads/synch.h \
 ../userprog/MemoryManager.h ../threads/synch.h \
 ../userprog/ProcessManager.h ../vm/SwapManager.h ../machine/translate.h \
 ../vm/VMManager.h ../vm/SwapManager.h ../filesys/SysOpenFile.h \
 /usr/include/time.h /usr/include/bits/time.h /usr/include/sys/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h
interrupt.o: ../machine/interrupt.cc ../threads/copyright.h \
 ../machine/interrupt.h ../threads/list.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h ../threads/thread.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/syscall.h ../userprog/PCB.h \
 ../filesys/UserOpenFile.h ../filesys/SysOpenFile.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../userprog/syscall.h ../userprog/bitmap.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../machine/stats.h ../machine/timer.h ../threads/synch.h \
 ../userprog/MemoryManager.h ../threads/synch.h \
 ../userprog/ProcessManager.h ../vm/SwapManager.h ../machine/translate.h \
 ../vm/VMManager.h ../vm/SwapManager.h ../filesys/SysOpenFile.h
sysdep.o: ../machine/sysdep.cc ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h /usr/include/signal.h /usr/include/bits/sigset.h \
 /usr/include/bits/signum.h /usr/include/time.h \
 /usr/include/bits/siginfo.h /usr/include/bits/sigaction.h \
 /usr/include/bits/sigcontext.h /usr/include/asm/sigcontext.h \
 /usr/include/linux/types.h /usr/include/asm/types.h \
 /usr/include/asm-generic/types.h /usr/include/asm-generic/int-ll64.h \
 /usr/include/asm/bitsperlong.h /usr/include/asm-generic/bitsperlong.h \
 /usr/include/linux/posix_types.h /usr/include/linux/stddef.h \
 /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h \
 /usr/include/bits/sigstack.h /usr/include/sys/ucontext.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sigthread.h \
 /usr/include/sys/types.h /usr/include/endian.h \
 /usr/include/bits/endian.h /usr/include/bits/byteswap.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
 /usr/include/sys/time.h /usr/include/sys/socket.h /usr/include/sys/uio.h \
 /usr/include/bits/uio.h /usr/include/bits/socket.h \
 /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/asm/sockios.h \
 /usr/include/asm-generic/sockios.h /usr/include/sys/file.h \
 /usr/include/fcntl.h /usr/include/bits/fcntl.h /usr/include/bits/stat.h \
 /usr/include/sys/un.h /usr/include/sys/mman.h /usr/include/bits/mman.h \
 /usr/include/unistd.h /usr/include/bits/posix_opt.h \
 /usr/include/bits/environments.h /usr/include/bits/confname.h \
 /usr/include/getopt.h /usr/include/errno.h /usr/include/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../machine/interrupt.h ../threads/list.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/system.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/syscall.h ../userprog/PCB.h ../filesys/UserOpenFile.h \
 ../filesys/SysOpenFile.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../userprog/syscall.h ../userprog/bitmap.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../machine/stats.h \
 ../machine/timer.h ../threads/synch.h ../userprog/MemoryManager.h \
 ../threads/synch.h ../userprog/ProcessManager.h ../vm/SwapManager.h \
 ../machine/translate.h ../vm/VMManager.h ../vm/SwapManager.h \
 ../filesys/SysOpenFile.h
stats.o: ../machine/stats.cc ../threads/copyright.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/stats.h
timer.o: ../machine/timer.cc ../threads/copyright.h ../machine/timer.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/syscall.h ../userprog/PCB.h \
 ../filesys/UserOpenFile.h ../filesys/SysOpenFile.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../userprog/syscall.h ../userprog/bitmap.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/synch.h ../userprog/MemoryManager.h ../threads/synch.h \
 ../userprog/ProcessManager.h ../vm/SwapManager.h ../machine/translate.h \
 ../vm/VMManager.h ../vm/SwapManager.h ../filesys/SysOpenFile.h
addrspace.o: ../userprog/addrspace.cc ../threads/copyright.h \
 ../threads/system.h ../threads/copyright.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/syscall.h ../userprog/PCB.h ../filesys/UserOpenFile.h \
 ../filesys/SysOpenFile.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../userprog/syscall.h ../userprog/bitmap.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../threads/synch.h \
 ../userprog/MemoryManager.h ../threads/synch.h \
 ../userprog/ProcessManager.h ../vm/SwapManager.h ../machine/translate.h \
 ../vm/VMManager.h ../vm/SwapManager.h ../filesys/SysOpenFile.h \
 ../userprog/addrspace.h ../bin/noff.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/iostream \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/ostream \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/ios \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/iosfwd \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/stringfwd.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/postypes.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/cwchar \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/cstddef \
 /usr/include/bits/wchar.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/exception \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/char_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/localefwd.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/c++locale.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/clocale \
 /usr/include/locale.h /usr/include/bits/locale.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/cctype \
 /usr/include/ctype.h /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/ios_base.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/ext/atomicity.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/gthr.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/bits/sched.h /usr/include/bits/time.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/setjmp.h \
 /usr/include/unistd.h /usr/include/bits/posix_opt.h \
 /usr/include/bits/environments.h /usr/include/bits/confname.h \
 /usr/include/getopt.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/atomic_word.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/locale_classes.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/string \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/new \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/ostream_insert.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/cxxabi-forced.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/stl_function.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/backward/binders.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/basic_string.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/basic_string.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/locale_classes.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/streambuf \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/streambuf.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/basic_ios.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/locale_facets.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/cwctype \
 /usr/include/wctype.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/ctype_base.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/streambuf_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/ctype_inline.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/locale_facets.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/basic_ios.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/ostream.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/istream \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/istream.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/cmath \
 /usr/include/math.h /usr/include/bits/huge_val.h \
 /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
 /usr/include/bits/inf.h /usr/include/bits/nan.h \
 /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/cmath.tcc
bitmap.o: ../userprog/bitmap.cc ../threads/copyright.h \
 ../userprog/bitmap.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../filesys/openfile.h
exception.o: ../userprog/exception.cc ../threads/copyright.h \
 ../threads/system.h ../threads/copyright.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/syscall.h ../userprog/PCB.h ../filesys/UserOpenFile.h \
 ../filesys/SysOpenFile.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../userprog/syscall.h ../userprog/bitmap.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../threads/synch.h \
 ../userprog/MemoryManager.h ../threads/synch.h \
 ../userprog/ProcessManager.h ../vm/SwapManager.h ../machine/translate.h \
 ../vm/VMManager.h ../vm/SwapManager.h ../filesys/SysOpenFile.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/exception \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/iostream \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/ostream \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/ios \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/iosfwd \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/stringfwd.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/postypes.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/cwchar \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/cstddef \
 /usr/include/bits/wchar.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/char_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/localefwd.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/c++locale.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/clocale \
 /usr/include/locale.h /usr/include/bits/locale.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/cctype \
 /usr/include/ctype.h /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/ios_base.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/ext/atomicity.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/gthr.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/bits/sched.h /usr/include/bits/time.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/setjmp.h \
 /usr/include/unistd.h /usr/include/bits/posix_opt.h \
 /usr/include/bits/environments.h /usr/include/bits/confname.h \
 /usr/include/getopt.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/atomic_word.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/locale_classes.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/string \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/new \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/ostream_insert.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/cxxabi-forced.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/stl_function.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/backward/binders.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/basic_string.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/basic_string.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/locale_classes.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/streambuf \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/streambuf.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/basic_ios.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/locale_facets.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/cwctype \
 /usr/include/wctype.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/ctype_base.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/streambuf_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/i686-redhat-linux/bits/ctype_inline.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/locale_facets.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/basic_ios.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/ostream.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/istream \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/../../../../include/c++/4.4.5/bits/istream.tcc
progtest.o: ../userprog/progtest.cc ../threads/copyright.h \
 ../threads/system.h ../threads/copyright.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/syscall.h ../userprog/PCB.h ../filesys/UserOpenFile.h \
 ../filesys/SysOpenFile.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../userprog/syscall.h ../userprog/bitmap.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../threads/synch.h \
 ../userprog/MemoryManager.h ../threads/synch.h \
 ../userprog/ProcessManager.h ../vm/SwapManager.h ../machine/translate.h \
 ../vm/VMManager.h ../vm/SwapManager.h ../filesys/SysOpenFile.h \
 ../machine/console.h ../userprog/addrspace.h
SysOpenFile.o: ../filesys/SysOpenFile.cc ../filesys/SysOpenFile.h \
 ../filesys/openfile.h ../threads/copyright.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../userprog/syscall.h ../threads/synch.h ../threads/thread.h \
 ../threads/utility.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../userprog/syscall.h ../userprog/PCB.h ../filesys/UserOpenFile.h \
 ../userprog/bitmap.h ../threads/list.h
console.o: ../machine/console.cc ../threads/copyright.h \
 ../machine/console.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/syscall.h ../userprog/PCB.h \
 ../filesys/UserOpenFile.h ../filesys/SysOpenFile.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../userprog/syscall.h ../userprog/bitmap.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/synch.h ../userprog/MemoryManager.h ../threads/synch.h \
 ../userprog/ProcessManager.h ../vm/SwapManager.h ../machine/translate.h \
 ../vm/VMManager.h ../vm/SwapManager.h ../filesys/SysOpenFile.h
machine.o: ../machine/machine.cc ../threads/copyright.h \
 ../machine/machine.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../machine/disk.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/syscall.h ../userprog/PCB.h \
 ../filesys/UserOpenFile.h ../filesys/SysOpenFile.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../userprog/syscall.h ../userprog/bitmap.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/synch.h ../userprog/MemoryManager.h ../threads/synch.h \
 ../userprog/ProcessManager.h ../vm/SwapManager.h ../machine/translate.h \
 ../vm/VMManager.h ../vm/SwapManager.h ../filesys/SysOpenFile.h
mipssim.o: ../machine/mipssim.cc ../threads/copyright.h \
 ../machine/machine.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../machine/disk.h \
 ../machine/mipssim.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/syscall.h \
 ../userprog/PCB.h ../filesys/UserOpenFile.h ../filesys/SysOpenFile.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../userprog/syscall.h \
 ../userprog/bitmap.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../threads/synch.h ../userprog/MemoryManager.h \
 ../threads/synch.h ../userprog/ProcessManager.h ../vm/SwapManager.h \
 ../machine/translate.h ../vm/VMManager.h ../vm/SwapManager.h \
 ../filesys/SysOpenFile.h
translate.o: ../machine/translate.cc ../threads/copyright.h \
 ../machine/machine.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/syscall.h ../userprog/PCB.h ../filesys/UserOpenFile.h \
 ../filesys/SysOpenFile.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../userprog/syscall.h ../userprog/bitmap.h ../threads/system.h \
 ../threads/utility.h ../threads/thread.h ../machine/machine.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/synch.h ../userprog/MemoryManager.h ../threads/synch.h \
 ../userprog/ProcessManager.h ../vm/SwapManager.h ../machine/translate.h \
 ../vm/VMManager.h ../vm/SwapManager.h ../filesys/SysOpenFile.h
MemoryManager.o: ../userprog/MemoryManager.cc ../threads/copyright.h \
 ../userprog/MemoryManager.h ../userprog/bitmap.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../filesys/openfile.h ../threads/synch.h \
 ../threads/thread.h ../threads/utility.h ../machine/machine.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/syscall.h \
 ../userprog/PCB.h ../filesys/UserOpenFile.h ../filesys/SysOpenFile.h \
 ../userprog/bitmap.h ../userprog/syscall.h ../threads/list.h \
 ../threads/system.h ../threads/scheduler.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/synch.h ../userprog/MemoryManager.h \
 ../userprog/ProcessManager.h ../vm/SwapManager.h ../machine/translate.h \
 ../vm/VMManager.h ../vm/SwapManager.h ../filesys/SysOpenFile.h
ProcessManager.o: ../userprog/ProcessManager.cc ../threads/copyright.h \
 ../userprog/ProcessManager.h ../threads/synch.h ../threads/copyright.h \
 ../threads/thread.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/syscall.h \
 ../userprog/PCB.h ../filesys/UserOpenFile.h ../filesys/SysOpenFile.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../userprog/syscall.h \
 ../userprog/bitmap.h ../threads/list.h ../vm/SwapManager.h \
 ../machine/translate.h
PCB.o: ../userprog/PCB.cc ../userprog/PCB.h ../userprog/syscall.h \
 ../threads/copyright.h ../filesys/UserOpenFile.h \
 ../filesys/SysOpenFile.h ../filesys/openfile.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../userprog/syscall.h ../userprog/bitmap.h ../threads/system.h \
 ../threads/utility.h ../threads/thread.h ../machine/machine.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../threads/synch.h ../userprog/MemoryManager.h \
 ../threads/synch.h ../userprog/ProcessManager.h ../vm/SwapManager.h \
 ../machine/translate.h ../vm/VMManager.h ../vm/SwapManager.h \
 ../filesys/SysOpenFile.h
SwapManager.o: ../vm/SwapManager.cc ../vm/SwapManager.h \
 ../threads/copyright.h ../filesys/openfile.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../userprog/bitmap.h ../machine/translate.h \
 ../userprog/syscall.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/syscall.h ../userprog/PCB.h \
 ../filesys/UserOpenFile.h ../filesys/SysOpenFile.h ../userprog/bitmap.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/synch.h ../userprog/MemoryManager.h ../threads/synch.h \
 ../userprog/ProcessManager.h ../vm/SwapManager.h ../vm/VMManager.h \
 ../filesys/SysOpenFile.h
VMManager.o: ../vm/VMManager.cc ../vm/VMManager.h ../threads/copyright.h \
 ../machine/translate.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.4.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../vm/SwapManager.h ../filesys/openfile.h \
 ../userprog/bitmap.h ../userprog/syscall.h ../threads/synch.h \
 ../threads/thread.h ../threads/utility.h ../machine/machine.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/syscall.h \
 ../userprog/PCB.h ../filesys/UserOpenFile.h ../filesys/SysOpenFile.h \
 ../userprog/bitmap.h ../threads/list.h ../threads/system.h \
 ../threads/scheduler.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../threads/synch.h \
 ../userprog/MemoryManager.h ../userprog/ProcessManager.h \
 ../vm/SwapManager.h ../vm/VMManager.h ../filesys/SysOpenFile.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
