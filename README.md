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
zephir clean
zephir build
```

### Docker

```bash
docker-compose up -d
docker-compose exec app bash
```

The docker container serves the purpose of development server.
You would work on the source in your IDE and do builds etc. in the container, where the source is mounted in `/root/src`.

The php.ini file to modify when you want to add extensions is `/etc/php.d/custom-php.ini`

