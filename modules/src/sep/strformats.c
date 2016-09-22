
#include <sitedef.h>
#include <assert.h>
#include "strformats.h"
#include "streamlist.h"
#include "sep_main_internal.h"
#include <sep_main_external.h>


#define         FMT_LENGTH      13

static char str_fmt_names[NUM_FMT][FMT_LENGTH] = {
                                        "xdr_float",
                                        "xdr_int",
                                        "xdr_byte",
                                        "native_float",
                                        "native_byte",
                                        "vplot",
                                        "tmc_float",
                                        "tmc_byte"
                                };

#if NeedFunctionPrototypes
_XFUNCPROTOBEGIN
int get_format_num( char *str)
_XFUNCPROTOEND
#else
int get_format_num( str)
char *str;
#endif
{
   int i;
   for( i=0 ; i<NUM_FMT; i++ ){
      if( !strcmp( str, str_fmt_names[i] )) return i;
   }
   return -1;
}

#if NeedFunctionPrototypes
_XFUNCPROTOBEGIN
char* get_format_name( int num)
_XFUNCPROTOEND
#else
char* get_format_name( num)
int num;
#endif
{
char *ret;

ret = alloc( (int)strlen( str_fmt_names[num] ) + 1 );
strcpy( ret, str_fmt_names[num] );
 return( ret );
}

#if NeedFunctionPrototypes
_XFUNCPROTOBEGIN
void set_format( char *tag, char *format )
_XFUNCPROTOEND
#else
void set_format( tag, format )
char* tag;
char* format;
#endif
{
  int form_num;
  streaminf* info;

  assert( tag != 0 );
  assert( format != 0 );

  if( ( form_num = get_format_num( format ) ) == -1 ) {
	seperr( "set_format( %s , %s ): unknown format ",tag,format );
  }

  info = tag_info( tag, TAG_OUT );

  assert( info != 0 );

  info->format_num = form_num ;

}

#if NeedFunctionPrototypes
_XFUNCPROTOBEGIN
void set_output_data_format(  char *format )
_XFUNCPROTOEND
#else
void set_output_data_format(  format )
char* format;
#endif
{
set_format("out",format);
}

#if NeedFunctionPrototypes
_XFUNCPROTOBEGIN
char* get_format( char *tag )
_XFUNCPROTOEND
#else
char* get_format( tag )
char* tag;
#endif
{
  streaminf* info;

  assert( tag != 0 );

  info = tag_info( tag, TAG_IN );

  assert( info != 0 );

  return (get_format_name( info->format_num ));

}
