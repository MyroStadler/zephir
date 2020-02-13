
extern zend_class_entry *medium_greeting_ce;

ZEPHIR_INIT_CLASS(Medium_Greeting);

PHP_METHOD(Medium_Greeting, say);

ZEPHIR_INIT_FUNCS(medium_greeting_method_entry) {
	PHP_ME(Medium_Greeting, say, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
