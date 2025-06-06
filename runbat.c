#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ch_to_int(char ch)
{
 char buf[]={ch,0x00};
 return atoi(buf);
}

static struct
{
 int argc;
 char** argv;
} arglist;

static FILE* infile;
static FILE* outfile;

void shift_args(int arg)
{
 arglist.argc-=arg;
 arglist.argv+=arg;
}

int main(int argc,char* argv[])
{
 if(argc>2)
 {
  arglist.argc=argc-1;
  arglist.argv=argv+1;
 }
 else return 0;
 infile=fopen(arglist.argv[0],"r");
 /* If invoked as "template" instead of RUNBAT, output to output.out */
 outfile=(strcmp(argv[0],"template"))?fopen("output.out","w"):fopen("batch.out",
 /* Process batch file and write to output file */
 char ch;
 while((ch=fgetc(infile))!=EOF)
 {
  switch(ch)
  {
   case '$':
   case '%':
    fprintf(outfile,"%s",arglist.argv[ch_to_int(fgetc(infile))]);
    break;
   default:
    fputc(ch,outfile);
  }
 }
 fclose(infile);
 fclose(outfile);
 return 0;
} 
