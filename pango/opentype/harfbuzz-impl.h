/*******************************************************************
 *
 *  Copyright 1996-2000 by
 *  David Turner, Robert Wilhelm, and Werner Lemberg.
 *
 *  Copyright 2006  Behdad Esfahbod
 *
 *  This is part of HarfBuzz, an OpenType Layout engine library.
 *
 *  See the file name COPYING for licensing information.
 *
 ******************************************************************/
#ifndef HARFBUZZ_IMPL_H
#define HARFBUZZ_IMPL_H

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_TRUETYPE_TAGS_H

#include "harfbuzz-global.h"

HB_BEGIN_HEADER

#ifndef HB_INTERNAL
# define HB_INTERNAL
#endif

#ifndef NULL
# define NULL ((void *)0)
#endif

#ifndef FALSE
# define FALSE 0
#endif

#ifndef TRUE
# define TRUE 1
#endif

#ifndef TTAG_GDEF
# define TTAG_GDEF  HB_MAKE_TAG( 'G', 'D', 'E', 'F' )
#endif
#ifndef TTAG_GPOS
# define TTAG_GPOS  HB_MAKE_TAG( 'G', 'P', 'O', 'S' )
#endif
#ifndef TTAG_GSUB
# define TTAG_GSUB  HB_MAKE_TAG( 'G', 'S', 'U', 'B' )
#endif

#ifndef HB_UNUSED
# define HB_UNUSED(arg) ((arg) = (arg))
#endif

#define HB_LIKELY(cond) (cond)
#define HB_UNLIKELY(cond) (cond)

#define ARRAY_LEN(Array) ((int)(sizeof (Array) / sizeof (Array)[0]))


#define  ALLOC(_ptr,_size)   \
           ( (_ptr) = _hb_alloc( _size, &error ), error != 0 )

#define  REALLOC(_ptr,_newsz)  \
           ( (_ptr) = _hb_realloc( (_ptr), (_newsz), &error ), error != 0 )

#define  FREE(_ptr)                    \
  do {                                 \
    if ( (_ptr) )                      \
    {                                  \
      _hb_free( _ptr );                \
      _ptr = NULL;                     \
    }                                  \
  } while (0)

#define  ALLOC_ARRAY(_ptr,_count,_type)   \
           ALLOC(_ptr,(_count)*sizeof(_type))

#define  REALLOC_ARRAY(_ptr,_newcnt,_type) \
           REALLOC(_ptr,(_newcnt)*sizeof(_type))

#define  MEM_Copy(dest,source,count)   memcpy( (char*)(dest), (const char*)(source), (size_t)(count) )

#define ERR(err)   _hb_err (err)


HB_INTERNAL HB_Pointer
_hb_alloc( HB_UInt   size,
	   HB_Error *perror_ );

HB_INTERNAL HB_Pointer
_hb_realloc( HB_Pointer block,
	     HB_UInt    new_size,
	     HB_Error  *perror_ );

HB_INTERNAL void
_hb_free( HB_Pointer block );


/* helper func to set a breakpoint on */
HB_INTERNAL HB_Error
_hb_err (HB_Error code);


HB_END_HEADER

#endif /* HARFBUZZ_IMPL_H */
