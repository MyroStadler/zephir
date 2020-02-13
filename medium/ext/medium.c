
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "medium.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *medium_greeting_ce;

ZEND_DECLARE_MODULE_GLOBALS(medium)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(medium)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Medium_Greeting);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(medium)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_medium_globals *medium_globals TSRMLS_DC)
{
	medium_globals->initialized = 0;

	/* Cache Enabled */
	medium_globals->cache_enabled = 1;

	/* Recursive Lock */
	medium_globals->recursive_lock = 0;

	/* Static cache */
	memset(medium_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_medium_globals *medium_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(medium)
{
	zend_medium_globals *medium_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	medium_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(medium_globals_ptr);
	zephir_initialize_memory(medium_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(medium)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(medium)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_MEDIUM_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_MEDIUM_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_MEDIUM_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_MEDIUM_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_MEDIUM_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(medium)
{
	php_zephir_init_globals(medium_globals);
	php_zephir_init_module_globals(medium_globals);
}

static PHP_GSHUTDOWN_FUNCTION(medium)
{
	
}


zend_function_entry php_medium_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_medium_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry medium_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_medium_deps,
	PHP_MEDIUM_EXTNAME,
	php_medium_functions,
	PHP_MINIT(medium),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(medium),
#else
	NULL,
#endif
	PHP_RINIT(medium),
	PHP_RSHUTDOWN(medium),
	PHP_MINFO(medium),
	PHP_MEDIUM_VERSION,
	ZEND_MODULE_GLOBALS(medium),
	PHP_GINIT(medium),
	PHP_GSHUTDOWN(medium),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(medium),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_MEDIUM
ZEND_GET_MODULE(medium)
#endif
