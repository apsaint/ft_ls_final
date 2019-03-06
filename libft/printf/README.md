# FT_PRINTF
## A lightweight printf based on std printf.
FT_PRINTF is an embbeded printf using an internal fixed buffer. It conforms to libc standard requirements (undefined behaviours are handled like the glibc printf implementation). Ft_printf is one of the 42 school's projects. 

**Supported standard features**

 - specifiers -> diuoxXfs
 - modifiers -> h hh l ll L j z
 - width & precision
 - wildcards (*)

**Extra features**

 - specifier b -> The int (or appropriate variant) argument is converted
   to unsigned binary notation.

**Notes**
Internal buffer: The default size is 64 chars. To adjust the buffer, open ft_printf.h and modify the INTERNAL_BUFFER_SIZE macro.
