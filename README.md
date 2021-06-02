# Before starting

* This document is a code style convention among `Autonomous Technologies Lab` engineers, developers, coders. Whoever works with source code is encouraged to reflect his or her preferences on this document.
* The purpose of this document is to increase the speed of development fo whole team by using a unified code style since it improves code quality and maintainability of code. Unified code style can help new users pick up the code quickly, effective code reviews, **`???deriving source code metrics such as SLO???`**.

# C++ code style

## 1. Case

**1.1. Variables and function names are lowercase with words separated by an underscore**

Right:

```c++
int throttle_input;
```

Wrong:

```c++
int ThrottleInput;
```

**1.2. Constant names and macros are uppercase with words separated by an underscore**

Right:

```c++
const int UPPER_UNDERLINED_CASE;
```

Wrong:

```c++
const int upper_underlined_case;
const int UPPERUNDERLINEDCASE;
```

## 2. Indentation

**2.1. Spaces**

Indent using 4 spaces everywhere. Do not use tabs.

Right:

```c++
int foo() {
    return 0;         
}
```

Wrong:

```c++
int foo() {
  return 0;         
}
```

**2.2. Case statements**

The case label indentation is acceptable either when lined up with the switch or indented once.

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

Wrong:

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

## 3. Spacing

**3.1. Unary operators**

Do not place spaces around unary operators.

Right:

```c++
i++;
```

Wrong:

```c++
i ++ ;
```

**3.2. Control statements**

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

## 4. Function calls

Do not place spaces between a function and its parentheses, or between a parenthesis and its content.

Right:

```c++
foo(a, 10);
```

Wrong:

```c++
foo (a, 10);

foo(a, 10 );
```

### 5. Trailing whitespaces

Don’t leave trailing whitespace on new code (a good editor can manage this for you). Fixing whitespace on existing code should be done as a separate commit (do not include with other changes).

## 6. Line breaks

**6.1. Single statements**

Each statement should get its own line except in method implementations in header files which may (or may not be) on a single line(line length is less than 100).

Right:

```c++
x++;
y++;
If (condition) {
    foo();
}

bool requires_GPS() const override { return false; }
```

Wrong:

```c++
x++; y++;
if (condition) foo();
```

**6.2. Else statement**

An else statement should go on the same line as a preceding close brace.

Right:

```c++
If (condition) {
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

## 7. Braces

**7.1. Function braces**

Functions definitions: place each brace on its own line. For methods inside a header file, braces can be inline(if length is less than 100).

**7.2. Control statements**

Control statements (if, while, do, else) should always use braces around the statements.
Right:

```c++
If (condition) {
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

**7.3. Other braces**

Place the open brace on the line preceding the code block; place the close brace on its own line.
Right:

```c++
class My_Class {
    ...
};

namespace AP_HAL {
    ...
}

for (int i = 0; i < 10; i++) {
    ...
}
```

Wrong:

```c++
class My_Class
{
    ...
};
```

## 8. Names

**8.1. Private members**

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

**8.2. Functions and variables**

Functions that return a single physical value or variables that represent a physical value should be suffixed by the physical unit.

Right:

```c++
uint16 get_angle_rad() { ... }; 
float distance_m;
```

Wrong:

```c++
uint16 get_angle() { ... };
float distance;
```

**8.3. Other**

Functions or variables that represent a value relative to a frame should be suffixed with the frame first, then with the physical unit (if any).

Right:

```c++
uint16 get_distance_ned_cm() { ... }; 
uint16 get_distance_enu_m() { ... }; 
float position_neu_mm;
```

Wrong:

```c++
uint16 get_distance() { ... };
float position;
```

## 9. Commenting

**9.1. Comment of a file**

Each file with public visibility should have a comment at the top describing what it does.

```c++
/**
 * @file vtol_type.h
 * @author Roman Bapst       	<bapstroman@gmail.com>
 * @author Sander Smeets     	<sander@droneslab.com>
 * @author Andreas Antener   	<andreas@uaventure.com>
 */
```

### Comment of a function

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

Example of `CPPLINT.cfg`:
 
```bash
# Stop searching for additional config files.
set noparent
 
# 1. Increase limit line length because 80 it's not enough.
#    100 should be ok since all modern supports even 2 text editors
#    with this length.
#    120 could be used if you really want it
linelength=100
 
# 2. Ignore requirement to use copyright since we don’t have it yet
filter=-legal/copyright
 
# 3. Ignore requirement to use 1 space indent inside class
#    So you can use any number of spaces that you want.
#    4 spaces is recommended
filter=-whitespace/indent
 
# 4. (optional) Ignore requirement to include "foo/bar.h" instead of
#    just "bar.h"
filter=-build/include_subdir
 
# 5. For C-projects:
#    C-style cast is the only way to perform cast.
filter=-readability/casting
```

## 3. astype

`astyle` is our tool of choice for formatting the code

astylerc: script that checks formatting without changes and print color diff

```bash
#!/bin/bash
# Check http://astyle.sourceforge.net/astyle.html
 
function show_files_diff {
   astyle  --style=linux \
           --indent=spaces=4 \
           --indent-col1-comments \
           --suffix=none \
           --lineend=linux \
           --pad-header \
           --indent-preproc-cond \
           --indent-preproc-block \
           --max-code-length=120 \
           < $filename > $filename.pretty
   git --no-pager diff --no-index --minimal --histogram --color=always $filename $filename.pretty
   rm -f $filename.pretty
}
 
for filename in Src/Common/Inc/*.h; do
   show_files_diff
done
```