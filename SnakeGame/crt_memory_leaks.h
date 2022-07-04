#ifndef CRT_MEMORY_LEAKS
#define CRT_MEMORY_LEAKS

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>


#ifdef _DEBUG

#define new( _NORMAL_BLOCK, __FILE__, __LINE__) //overriding new keyword

#else

#endif


#endif // !CRT_MEMORY_LEAKS
