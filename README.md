# myrostadler/zephir

This is a repository for developing custom PHP extensions using Zephir. 
If you want to use it for your extension development download or fork it and remove all extension folders in the project root 
(root folders that do not start with a dot) to be replaced with your own. Otherwise build your own repo around the Dockerfile here. 

For more information on Zephir please see the docs: https://docs.zephir-lang.com/

## Docker

```bash
docker-compose up -d
docker-compose exec app bash
```

The docker container serves the purpose of development server for those who do not have native Linux.
E.g. on MacOS you would work on the source in your IDE and do builds etc. in the container where the source is mounted, in `/root/src`.

If you want to create a standalone dev server instead of using a docker container, see instructions at 
https://docs.zephir-lang.com/0.12/en/installation


## Notes

1. Extension source code goes in a folder with the same name as the parent module folder, i.e. a utils module's extension source code would be in `/root/src/utils/utils`. See namespacing in `*/config.json`
1. The php.ini file [in the docker container] to modify when you want to add extensions is `/etc/php.d/custom-php.ini`

## Common operations

### Create extension skeleton

In the docker container in directory `/root/src`, to scaffold an extension named `utils`:

```bash
zephir init utils
cd utils
```

### Build extension

In the docker container in directory `/root/src`, where the extension to build is named `utils`:

```bash
cd utils
zephir clean
zephir build
```

## Tests

This project has plain-php tests, as seen in various `.test` folders; 

**TODO: add proper unit testing.**

The easiest way to test as you go is with a PHP interactive shell: in the docker container add your extension to `/etc/php.d/custom-php.ini` and open interactive shell using the command `php -a`, then run some simple PHP in the interactive shell that hits your new extension.

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
// utils/.test/test.php

echo Utils\Greeting::say(), "\n";
```

## Deploying custom PHP extensions

### Look at this delicious cake you can't have...

The most common way to install a PHP extension is to **build from source**, 
which is how the `zephir_parser.so` extension was installed using the bash lines:

```bash
git clone git://github.com/phalcon/php-zephir-parser.git
cd php-zephir-parser/
phpize
./configure
make
make install
echo "extension=zephir_parser.so" >> /etc/php.d/custom-php.ini
```

### ...now eat your kale

Since we use Zephir to build, if we wanted people to build from source they would have to install the entire Zephir build pipeline, the same as us. 
While this is not a major problem it is probably better to offer the extension for download on a CDN somewhere 
with instructions for enabling it (adding `extension=/path/to/my_extension.so` to `php.ini`).

At the time of writing (Feb. 2020) Zephir supports PHP 7.0 - 7.4.

