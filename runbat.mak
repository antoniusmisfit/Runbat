# Produce Windows executables
# links with PDPCLIB created by makefile.msv

CC=gccwin
CFLAGS=-O2
LD=ldwin
LDFLAGS=
AS=aswin
AR=arwin
COPTS=-S $(CFLAGS) -fno-common -ansi -I. -I../pdpclib -D__WIN32__

all: clean runbat.exe

runbat.exe: runbat.o
  $(LD) $(LDFLAGS) -s -o runbat.exe ../pdpclib/w32start.o runbat.o ../pdpclib/msvcrt.a

.c.o:
  $(CC) $(COPTS) -o $*.s $<
  $(AS) -o $@ $*.s
  rm -f $*.s

clean:
  rm -f *.o runbat.exe
