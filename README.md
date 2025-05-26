# Runbat

A utility to implement batch file arguments for PDOS.

## Compiling on PDOS

1. Create a working directory:
mkdir c:\devel\pdos\runbat

2. Copy RUNBAT.C and RUNBAT.MAK to the working directory.

3. Compile RUNBAT.EXE with PDMAKE:
pdmake -f runbat.mak

4. If compile is successful, you may copy RUNBAT.EXE to C:\DOS directory.

## Usage

Once compiled, you may use RUNBAT.EXE to simulate
argument passing to a batch file. Try running "TEST.BAT one two three" on it's own first, then do the following:
RUNBAT TEST.BAT one two three

On the first run, the arguments are not derefenced. With RUNBAT, a file called BATCH.OUT is created, with the arguments properly dereferenced. Copy the BATCH.OUT file to TEST.BAT, then run TEST.BAT again.

## Todo

* Implement environment variable expansion.