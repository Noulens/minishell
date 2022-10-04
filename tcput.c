/*
 *
 *         This program places the cursor on the specified row and column.
 *         Rows and columns start at 0 from the top left hand corner.
 *         By default this program reads the TERM variable from the user's
 *         environment. If the Command line includes a terminal name, it will
 *         use argv[1] as the terminal type.  SCO suggests that you read the
 *      man page entry, line by line, and compare it to the program.
 * 
 *              cc  tcput.c  -ltermcap  -o tcput -g
 *
 *     Command Syntax  ...    progname  [ TERM_type ]  Row  Col  <Return>
 *
 *
#include<stdio.h>
#include<termio.h>  Note:  tcap.h includes stdio.h and termio.h
                              If you have SCO XENIX Development System 
                              Release 2.3, please look on page 7-6 and
                              7-7 of the C Library Guide.
*/
#include <stdio.h>
#include <termio.h>
#include <curses.h>
#include <term.h>
#include <errno.h>

#define MAXTERM 1024
#define MAXENTRY 512

extern char *BC;
extern char *UP;
extern char PC; 
extern short ospeed;

void outc(ch)
char ch;
{
         putchar(ch);
}

main(argc,argv)
int argc;
char *argv[];
{
         char *tgetstr();
         char *tgoto();
         void outc();

         char termbuffer[MAXTERM];
         char cap_buf[MAXENTRY], *table;
         char type_term[10];
         char *PCstr;
         char *CL, *CM;
         struct termio oldterm, newterm;

         ioctl( stdout, TCGETA, &oldterm);
         ospeed = oldterm.c_cflag & CBAUD;
         newterm = oldterm;
         newterm.c_oflag = newterm.c_oflag  & ~(TABDLY);
         ioctl( stdout, TCSETA, &newterm);
         if ( argc == 3 )
                  strcpy(type_term, getenv("TERM="));
         else
                  strcpy(type_term, argv[1]);
         if( tgetent(termbuffer, type_term) != 1) {
                  perror("No termcap, fail");
                  exit(1);
         }
         table = cap_buf;
         BC = tgetstr("bc",&table);
         CL = tgetstr("cl",&table);
         CM = tgetstr("cm",&table);
         UP = tgetstr("up",&table);
         PCstr = tgetstr("pc",&table);
         if ( PCstr != NULL)
                  PC = PCstr[0];
         else
                  PC = '\0';

/*         CLEAR SCREEN       */
         tputs(CL,1,outc);  
/*
 *                                      dest col      dest row
 */
         if ( argc == 3 )
                  tputs(tgoto(CM, atoi(argv[2]), atoi(argv[1])), 1, outc);
         else
                  tputs(tgoto(CM, atoi(argv[3]), atoi(argv[2])), 1, outc);
         ioctl( stdout, TCSETA, &oldterm);
         return(0);
}
