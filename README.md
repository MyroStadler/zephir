# myrostadler/zephir

This repository is for developing custom PHP extensions using Zephir.

## Docker

```bash
docker-compose up -d
docker-compose exec app bash
```

The docker container serves the purpose of development server.
You would work on the source in your IDE and do builds etc. in the container, where the source is mounted in `/root/src`.
If you want to create a standalone dev server instead of using a docker container, see iinstructions at 
https://docs.zephir-lang.com/0.12/en/installation


## Notes

1. Extension source code goes in a folder with the same name as the module. See namespacing in `*/config.json`
1. The php.ini file [in the docker container] to modify when you want to add extensions is `/etc/php.d/custom-php.ini`

## Common operations

### Create extension skeleton

```bash
zephir init utils
cd utils
```

### Build extension

```bash
cd utils
zephir clean
zephir build
```

## Tests

This project has plain-php tests, as seen in various "test" folders; TODO: add proper unit testing.

Easiest way to test immediately is with `php -a` in the docker container, then using some simple PHP that hits your new extension.

## Code examples

#### Example Zephir-language extension class "Utils\Greeting"

```php
// utils/utils/greeting.zep

namespace Utils;

class Greeting {

    public static function say() {
        echo "hello world!";
    }

}
```

### Example test file in plain PHP

```php
// utils/test/test.php

echo Utils\Greeting::say(), "\n";
```



