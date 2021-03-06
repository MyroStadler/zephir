
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Medium_Greeting) {

	ZEPHIR_REGISTER_CLASS(Medium, Greeting, medium, greeting, medium_greeting_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Medium_Greeting, say) {

	zval *this_ptr = getThis();


	php_printf("%s", "hello world!");

}

