## myrostadler/zephir

This is a hard hat area.

### Prerequisites

- php with modules: mbstring, xml, dom
- zephir parser
- zephir

See https://docs.zephir-lang.com/0.12/en/installation

### Create extension skeleton

```bash
zephir init utils
cd utils
```

### Example class

- Source code goes in a folder with the same name as the module. 
See namespacing in `*/config.json`

```php
// utils/utils/greeting.zep

namespace Utils;

class Greeting {

    public static function say() {
        echo "hello world!";
    }

}
```

### Example test

```php
// utils/test/test.php

echo Utils\Greeting::say(), "\n";
```

### Build extension

```bash
cd utils
zephir build
```