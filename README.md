# Runbat

A utility to implement batch file arguments for [PDOS](https://www.pdos.org/).

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

## Tips and Tricks

RUNBAT isn't limited to being used on batch files. You can create a file as a "template file":

SAVE template.txt
Dear $1,

My name is $2 and this is to acknowledge that you are awesome.
.

Then invoke RUNBAT as such:

RUNBAT template.txt Paul Tony

The resulting BATCH.OUT output file can then be renamed as letter.txt, suitable for whatever use you need.
Or you can copy RUNBAT.EXE to TEMPLATE.EXE, and follow the above instructions, replacing RUNBAT and BATCH.OUT with TEMPLATE and OUTPUT.OUT respectively.

## Todo

* Implement environment variable expansion.
* Implement support for "response files".
