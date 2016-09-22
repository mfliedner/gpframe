/*$
=head1 NAME

initpar - initiate seplib I/O parameter handling

=head1 SYNOPSIS

C<initpar(argc,argv)> in  C,  C<call initpar()> in Fortran

=head1 INPUT PARAMETERS

=over 4

=item argc - int 

      standard C number of arguments

=item argv - char** 

      standard C argument List

=back

=head1 DESCRIPTION

Initialize getpar global information from argc and argv.
used in C programs. This must be called as the first thing in your
main routine.

=head1 SEE ALSO

L<getch>, L<hetch>, L<fetch>

=head1 KEYWORDS 

initalize seplib getpar init

=head1 LIBRARY

B<sep>

=cut
*/
/*
 * Author: Stewart A. Levin   MRDC  4/14/89   
 */
#include <sitedef.h>

#include <sep_pars_external.h>
int sepxargc;
char **sepxargv;
#
#if NeedFunctionPrototypes
_XFUNCPROTOBEGIN
void initpar(int argc, char** argv)
_XFUNCPROTOEND
#else
void initpar(argc,argv)
int argc;
char **argv;
#endif
{
	int i;
 sepxargc=argc;
 sepxargv=argv;
 

}
