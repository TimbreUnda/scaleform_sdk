// Compatibility shim for FMOD (built with VS2010).
// Modern MSVC (VS2015+) removed __iob_func; provide it for linking.
#include <cstdio>

#if _MSC_VER >= 1900
extern "C" FILE* __cdecl __iob_func(void)
{
    // FMOD references stdin/stdout/stderr via __iob_func.
    // In modern CRT these are inline functions, not an array.
    static FILE iob[3];
    iob[0] = *stdin;
    iob[1] = *stdout;
    iob[2] = *stderr;
    return iob;
}
#endif
