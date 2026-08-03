#ifndef _BACKPORTS_LINUX_COMPILER_TYPES_H
#define _BACKPORTS_LINUX_COMPILER_TYPES_H 1

#if LINUX_VERSION_IS_GEQ(6,12,1)
#include_next <linux/compiler_types.h>
#endif

#ifndef __counted_by
/*
 * Optional: only supported since gcc >= 14
 * Optional: only supported since clang >= 17
 *
 *   gcc: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=108896
 * clang: https://reviews.llvm.org/D148381
 */
#if __has_attribute(__element_count__)
# define __counted_by(member)		__attribute__((__element_count__(#member)))
#else
# define __counted_by(member)
#endif
#endif

#ifndef at_least
/*
 * This designates the minimum number of elements a passed array parameter must
 * have. For example:
 *
 *     void some_function(u8 param[at_least 7]);
 *
 * If a caller passes an array with fewer than 7 elements, the compiler will
 * emit a warning.
 */
#ifndef __CHECKER__
#define at_least static
#else
#define at_least
#endif
#endif

#endif /* _BACKPORTS_LINUX_COMPILER_TYPES_H */
