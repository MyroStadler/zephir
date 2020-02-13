
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_MEDIUM_H
#define PHP_MEDIUM_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_MEDIUM_NAME        "medium"
#define PHP_MEDIUM_VERSION     "0.0.1"
#define PHP_MEDIUM_EXTNAME     "medium"
#define PHP_MEDIUM_AUTHOR      "Phalcon Team"
#define PHP_MEDIUM_ZEPVERSION  "0.12.16-12256a1"
#define PHP_MEDIUM_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(medium)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(medium)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(medium)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(medium, v)
#else
	#define ZEPHIR_GLOBAL(v) (medium_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_medium_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(medium_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(medium_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def medium_globals
#define zend_zephir_globals_def zend_medium_globals

extern zend_module_entry medium_module_entry;
#define phpext_medium_ptr &medium_module_entry

#endif
