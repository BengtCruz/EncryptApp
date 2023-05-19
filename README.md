# EncryptApp
Encryption and decryption application in C programming language.

# Makefile Info

## CFLAGS

**-g** : This flag enables debugging information to be included in the compiled executable. It allows you to use debugging tools, such as gdb, to analyze and debug your program.

**-Wall** : This flag enables a set of warning messages. It enables commonly useful warnings that help detect potential issues in your code, such as unused variables, missing function prototypes, and more. It's generally a good practice to enable this flag to catch potential problems early.

**-Wextra** : This flag enables additional warning messages beyond those enabled by -Wall. It includes more specific warnings to catch a broader range of potential issues.

**-Werror** : This flag treats all warnings as errors. If any warning is encountered during compilation, it will be treated as an error, causing the compilation to fail. This can be useful to enforce strict adherence to coding standards and prevent potential issues from being ignored.

**-pedantic** : This flag instructs the compiler to strictly adhere to the ISO C standard and provide additional diagnostics for non-standard or questionable code constructs. It helps ensure that the code follows the standard guidelines and avoids language extensions or non-portable features.

**-std=c99** : This flag specifies the C language standard to be used during compilation. In this case, it specifies the C99 standard. This enables features introduced in the C99 standard, such as variable declarations anywhere within a function and single-line comments (starting with //).

**-lm** : This flag links the math library (libm). It is required when your program uses math functions like sqrt(), sin(), cos(), etc. The -lm flag ensures that the linker includes the math library when building the executable.

# Technologies

## OpenSSL

### Set Up

* Download binaries at [SourceForge](https://sourceforge.net/projects/openssl/files/)

* Extract binaries from zip file.

* Place OpenSSL folder in root C:\OpenSSL

* Include path to bin in your system. 

* Create Environment Variables:

OPENSSL_CONF=C:\OpenSSL\bin\openssl.cnf
C_INCLUDE_PATH=C:\OpenSLL\include\openssl;%C_INCLUDE_PATH%;

Your C compiler should now also search for header files in OpenSSL include directory.

* Test by running:
``openssl version``