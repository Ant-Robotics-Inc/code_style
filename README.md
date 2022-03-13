# Before starting

This document is a code style convention among `Raccoonlab` engineers, developers, coders.

At that moment this document covers 2 programming languages: C++ and Python:
- C++ code style is mainly based on Google code style with few differences. It is recommended to use such tools as `astyle` and `cpplint` to automatically verify the style of source code.
- Python code style is base on PEP8.

Whoever works with source code is encouraged to reflect his or her preferences on this document.

# Content
- [C++ code style](#c-code-style)
    - [1. Brace Style](#1-brace-style)
    - [2. Tab](#1-tab)
    - [3. Indentation](#3-indentation)
    - [4. Case style](#4-case-style)
        - [4.1. Type Names](#41-type-names)
        - [4.2. Variables](#42-variables)
        - [4.3. Functions](#43-functions)
        - [4.4. Constants](#44-constants)
    - [3. Spacing](#3-spacing)
    - [4. Function calls](#4-function-calls)
    - [5. Trailing whitespaces](#5-trailing-whitespaces)
    - [6. Line breaks](#6-line-breaks)
        - [6.1. Single statements](#61-single-statements)
        - [6.2. Else statement](#62-else-statement)
    - [7. Names](#7-names)
        - [7.1. Private members](#71-private-members)
    - [8. Commenting](#8-commenting)
        - [8.1. Comment of a file](#81-comment-of-a-file)
        - [8.2. Comment of a function](#82-comment-of-a-function)
- [Automation tools](#automation-tools)
    - [1. Doxygen](#1-doxygen)
    - [2. cpplint](#2-cpplint)
    - [3. astype](#3-astype)
    - [4. github actions](#4-github-actions)


# C++ code style

## 1. Brace Style

Typically there are three basic brace styles.
1. Attached – the braces are attached to the end of the last line of the previous block (Java, Google).
2. Broken – the braces are broken from the previous block (Allman).
3. Linux – The braces are attached except for the opening brace of a function, class, or namespace (K&R, Linux).

Here, let's use `attached` style. Below you can see few examples.

Right:

```c++
int BraceStyleExample(bool isBar) {
    if (isBar) {
        bar();
        return 1;
    } else {
        return 0;
    }
}
```

**Control statements**

Control statements (if, while, do, else) should always use braces around the statements.

```c++
if (condition) {
    foo();
} else {
    bar();
}
```

Wrong:

```c++
if (condition)
    foo();
else
    bar();
```

## 2. Tab

Indent using 4 spaces everywhere. Do not use tabs.

Right:

```c++
void Foo() {
....if (isBar1
............&& isBar2) {
........bar();
....}
}
```

## 3. Indentation

### 3.1. Classes

Public, protected and private keywords require 2 spaces.

Right:

```c++
class Foo {
  public:
    Foo();
    virtual ~Foo();
};
```

### 3.2. Switches

The case label requires 4 spaces indentation.

Right:

```c++
switch (condition) {
    case foo_cond:
        foo();
        break;
    case bar_cond:
        bar();
        break;
}
```

### 3.3. Namespaces

Namespaces do not add an extra level of indentation

```c++
namespace foospace {
class Foo {
  public:
    Foo();
    virtual ~Foo();
};
}
```

## 4. Case style

Here we use mixed case style. It is preaty similar to the Google case style.

### 4.1. Type Names

Types are PascalCase.

### 4.2. Variables

Variables are `snake_case`. Example:

```c++
int throttle_input;
```

### 4.3. Functions

Functions are `camelCase`. Example:

```c++
void setValue();
```

### 4.4. Constants

Constant names and macros are uppercase with words separated by an underscore. Example:

```c++
const int UPPER_UNDERLINED_CASE;
```


## 5. Spacing

### 5.1. Unary operators

Do not place spaces around unary operators.

Right:

```c++
i++;
```

Wrong:

```c++
i ++ ;
```

### 5.2. Control statements

Single space between control statements and their parentheses.

Right:

```c++
if (condition) {
    foo();
}
```

Wrong:

```c++
if(condition){
    foo();
}

if(condition) {
    foo();
}
```

### 5.3. Trailing whitespaces

Don’t leave trailing whitespace on new code (a good editor can manage this for you). Fixing whitespace on existing code should be done as a separate commit (do not include with other changes).

## 6. Line breaks

### 6.1. Single statements

Each statement should get its own line except in method implementations in header files which may (or may not be) on a single line(line length is less than 100).

Right:

```c++
x++;
y++;
if (condition) {
    foo();
}

bool requires_GPS() const override { return false; }
```

Wrong:

```c++
x++; y++;
if (condition) foo();
```

### 6.2. Else statement

An else statement should go on the same line as a preceding close brace.

Right:

```c++
if (condition) {
    foo();
} else {
    bar();
}
```

Wrong:

```c++
if(condition){
    foo();
}
else{
    bar();
}
```

## 7. Names

### 7.1. Private members

Private members in classes should be prefixed with an underscore:

Right:

```c++
class My_Class {
  private:
    int _field;
};
```

Wrong:

```c++
class My_Class {
  private:
    int field;
};
```


## 8. Commenting

### 8.1. Comment of a file

Each file with public visibility should have a comment at the top describing what it does.

```c++
/**
 * @file vtol_type.h
 * @author Roman Bapst       	<bapstroman@gmail.com>
 * @author Sander Smeets     	<sander@droneslab.com>
 * @author Andreas Antener   	<andreas@uaventure.com>
 */
```

### 8.2. Comment of a function

Other things such as method and field descriptions are optional and depend on the value of them for readers and they should not be too explicit.

```c++
/**
 * @brief  	Sets state of a selection of motors, see struct motor_state
 * @return 	next_state if successful, otherwise current_state
 */
motor_state set_motor_state(const motor_state current_state, const motor_state next_state, const int value = 0);
```

# Automation tools

## 1. Doxygen

[Doxygen](https://www.doxygen.nl/manual/docblocks.html)  is the common practice for most of C/C++ projects. Doxygen suggests to use several rules of code commenting which allows in further to generate documentation from the code. Javadoc is our Doxygen tool of choice generating documentation. 

There are different levels of details: in addition to commenting out non-obvious code fragments, somebody comment only the filename and authors, others additionally add file or classes description, there are those who comment on every method and every field.

## 2. cpplint

[cpplint](https://github.com/cpplint/cpplint) is the utility for formatting checks and static code analysis. It is based on Google C++ code style, but some things such as line length, braces and number of spaces can be filtered.

It is expected to use [CPPLINT.cfg](CPPLINT.cfg) file with configuration.

## 3. astype

`astyle` is our tool of choice for formatting the code.

Typicaly you may deal with following scripts:

1. [astylerc](astylerc) is the file that has rules for astyle
2. [astyle_check_single_file.sh](astyle_check_single_file.sh) script that show code style mistakes
3. [astyle_fix_single_file.sh](astyle_fix_single_file.sh) script that automatically fix style mistakes

## 4. github actions

[.github/workflows/code_style.yml](.github/workflows/code_style.yml) is an example of how can you automatically run cpplint and astyle together with your code on github.
