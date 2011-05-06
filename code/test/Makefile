# use normal make for this Makefile
#
# Makefile for building user programs to run on top of Nachos
#
# Several things to be aware of:
#
#    Nachos assumes that the location of the program startup routine (the
# 	location the kernel jumps to when the program initially starts up)
#       is at location 0.  This means: start.o must be the first .o passed 
# 	to ld, in order for the routine "Start" to be loaded at location 0
#

# if you are cross-compiling, you need to point to the right executables
# and change the flags to ld and the build procedure for as

#GCCDIR = ../../../gnu-decstation-ultrix/decstation-ultrix/2.95.3/
GCCDIR = /cs/class/cs270t/gcc/2.95.3/

LDFLAGS = -T script -N
ASFLAGS = -mips2
CPPFLAGS = $(INCDIR)

# if you aren't cross-compiling:
# GCCDIR =
# LDFLAGS = -N -T 0
# ASFLAGS =
# CPPFLAGS = -P $(INCDIR)

PATH = $(GCCDIR):/lib:/usr/bin:/bin

CC = $(GCCDIR)gcc -B../../../gnu-decstation-ultrix/
AS = $(GCCDIR)as
LD = $(GCCDIR)ld

CPP = gcc -E
INCDIR =-I../userprog -I../threads
CFLAGS = -G 0 -c $(INCDIR)

all: shell matmult sort bigfile1 testmfile f1

start.o: start.s ../userprog/syscall.h
	$(CPP) $(CPPFLAGS) start.c > strt.s
	$(AS) $(ASFLAGS) -o start.o strt.s
	rm strt.s

shell.o: shell.c
	$(CC) $(CFLAGS) -c shell.c
shell: shell.o start.o
	$(LD) $(LDFLAGS) start.o shell.o -o shell.coff
	../bin/coff2noff shell.coff shell

sort.o: sort.c
	$(CC) $(CFLAGS) -c sort.c
sort: sort.o start.o
	$(LD) $(LDFLAGS) start.o sort.o -o sort.coff
	../bin/coff2noff sort.coff sort

halt.o: halt.c
	$(CC) $(CFLAGS) -c halt.c
halt: halt.o start.o
	$(LD) $(LDFLAGS) start.o halt.o -o halt.coff
	../bin/coff2noff halt.coff halt

test.o: test.c
	$(CC) $(CFLAGS) -c test.c
test: test.o start.o
	$(LD) $(LDFLAGS) start.o test.o -o test.coff
	../bin/coff2noff test.coff test

test1.o: test1.c
	$(CC) $(CFLAGS) -c test1.c
test1: test1.o start.o
	$(LD) $(LDFLAGS) start.o test1.o -o test1.coff
	../bin/coff2noff test1.coff test1

test2.o: test2.c
	$(CC) $(CFLAGS) -c test2.c
test2: test2.o start.o
	$(LD) $(LDFLAGS) start.o test2.o -o test2.coff
	../bin/coff2noff test2.coff test2

test3.o: test3.c
	$(CC) $(CFLAGS) -c test3.c
test3: test3.o start.o
	$(LD) $(LDFLAGS) start.o test3.o -o test3.coff
	../bin/coff2noff test3.coff test3

test3_1.o: test3_1.c
	$(CC) $(CFLAGS) -c test3_1.c
test3_1: test3_1.o start.o
	$(LD) $(LDFLAGS) start.o test3_1.o -o test3_1.coff
	../bin/coff2noff test3_1.coff test3_1

test3_2.o: test3_2.c
	$(CC) $(CFLAGS) -c test3_2.c
test3_2: test3_2.o start.o
	$(LD) $(LDFLAGS) start.o test3_2.o -o test3_2.coff
	../bin/coff2noff test3_2.coff test3_2

test4.o: test.c
	$(CC) $(CFLAGS) -c test4.c
test4: test4.o start.o
	$(LD) $(LDFLAGS) start.o test4.o -o test4.coff
	../bin/coff2noff test4.coff test4

test4_1.o: test.c
	$(CC) $(CFLAGS) -c test4_1.c
test4_1: test4_1.o start.o
	$(LD) $(LDFLAGS) start.o test4_1.o -o test4_1.coff
	../bin/coff2noff test4_1.coff test4_1

test4_2.o: test.c
	$(CC) $(CFLAGS) -c test4_2.c
test4_2: test4_2.o start.o
	$(LD) $(LDFLAGS) start.o test4_2.o -o test4_2.coff
	../bin/coff2noff test4_2.coff test4_2

test5.o: test5.c
	$(CC) $(CFLAGS) -c test5.c
test5: test5.o start.o
	$(LD) $(LDFLAGS) start.o test5.o -o test5.coff
	../bin/coff2noff test5.coff test5

test5_1.o: test5_1.c
	$(CC) $(CFLAGS) -c test5_1.c
test5_1: test5_1.o start.o
	$(LD) $(LDFLAGS) start.o test5_1.o -o test5_1.coff
	../bin/coff2noff test5_1.coff test5_1

test5_2.o: test5_2.c
	$(CC) $(CFLAGS) -c test5_2.c
test5_2: test5_2.o start.o
	$(LD) $(LDFLAGS) start.o test5_2.o -o test5_2.coff
	../bin/coff2noff test5_2.coff test5_2

bigfile1.o: bigfile1.c
	$(CC) $(CFLAGS) -c bigfile1.c
bigfile1: bigfile1.o start.o
	$(LD) $(LDFLAGS) start.o bigfile1.o -o bigfile1.coff
	../bin/coff2noff bigfile1.coff bigfile1

f1.o: f1.c
	$(CC) $(CFLAGS) -c f1.c
f1: f1.o start.o
	$(LD) $(LDFLAGS) start.o f1.o -o f1.coff
	../bin/coff2noff f1.coff f1

testmfile.o: testmfile.c
	$(CC) $(CFLAGS) -c testmfile.c
testmfile: testmfile.o start.o
	$(LD) $(LDFLAGS) start.o testmfile.o -o testmfile.coff
	../bin/coff2noff testmfile.coff testmfile

matmult.o: matmult.c
	$(CC) $(CFLAGS) -c matmult.c
matmult: matmult.o start.o
	$(LD) $(LDFLAGS) start.o matmult.o -o matmult.coff
	../bin/coff2noff matmult.coff matmult
