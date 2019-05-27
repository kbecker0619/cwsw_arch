/** @file
 *	@brief	stubs to allow no-dependency compilation of standalone component project.
 *
 *	Copyright (c) 2019 Kevin L. Becker. All rights reserved.
 *
 *	Created on: May 26, 2019
 *	@author KBECKE35
 */

#ifndef STUBS_CWSW_LIB_H_
#define STUBS_CWSW_LIB_H_

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------
#include <stdio.h>		/* printf() */

// ----	Project Headers -------------------------

// ----	Module Headers --------------------------


#ifdef	__cplusplus
extern "C" {
#endif


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================
#define STUBS_CWSW_LIB_H__REVSTRING "$Revision: 0.0.0 $"


// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================

/**	When built on a PC, it's likely I want to see module elements that we would
 *	otherwise want to keep secret.
 */
#define PRIVATE						/* nothing */


/**	Macro to allow (for example) the use of enumeration names in a string. */
#define TO_STRING(x)	#x

#if defined (__GNUC__)					/*{*/
/** GNU's recommended implementation of macros using _Pragma keyword */
#define DO_PRAGMA(x)					DO_PRAGMA_(x)
#define DO_PRAGMA_(x)					_Pragma(TO_STRING(x))

/** Building block for creating a macro to ignore a specific compiler warning. This is the
 *  argument to the "ignore" command used in the #DISABLE_WARNING macro.
 */
#define GCC_WARNING_STRING(warnname)	"-W" TO_STRING(warnname)
/** disable a specific warning. intended to take as a parameter, the unquoted readable name of the warning. */
#define DISABLE_WARNING(x)				DO_PRAGMA(GCC diagnostic ignored GCC_WARNING_STRING(x))

/* these are defined as parameterless-but-otherwise-FLM on purpose; right or wrong, my intention is
 * to make it clear that these are compiler directives, and do not expand to code.
 */
#define SAVE_WARNING_CONTEXT			DO_PRAGMA(GCC diagnostic push)
#define RESTORE_WARNING_CONTEXT			DO_PRAGMA(GCC diagnostic pop)

/** Suppress non-ISO but GCC-supported extensions, such as the __FUNCTION__ macro to retrieve as a
 * 	string the current function name.
 */
#define SUPPRESS_EXTRAISO_IDENT			SAVE_WARNING_CONTEXT; DISABLE_WARNING(pedantic)


#elif defined(_MSC_VER)					/*}{*/

#define DISABLE_WARNING(warn_num)		__pragma(warning(disable:warn_num))
#define SAVE_WARNING_CONTEXT			__pragma(warning(push))
#define RESTORE_WARNING_CONTEXT			__pragma(warning(pop))

/** Suppress MSVC's complaint about an if() test using a constant expession. */
#define SUPPRESS_CONST_EXPR				SAVE_WARNING_CONTEXT; DISABLE_WARNING(4127)

/** Suppress non-ISO but GCC-supported extensions, such as the __FUNCTION__ macro to retrieve as a
 * 	string the current function name.
 */
#define SUPPRESS_EXTRAISO_IDENT			SAVE_WARNING_CONTEXT; DISABLE_WARNING(4555)

#endif									/*}*/


#define dbg_printf						printf


#ifdef	__cplusplus
}
#endif

#endif /* STUBS_CWSW_LIB_H_ */
