/**
 * @file example.cpp
 * @author d.ponomarev
 * @date Mar 13, 2022
 * @note code style example
 */
#include <iostream>


///< 1. Brace Style
int BraceStyleExample(bool isBar) {
    if (isBar) {
        bar();
        return 1;
    } else {
        return 0;
    }
}


///< 2. Tab
void tab_example() {
    if (isBar1
            && isBar2) {
        bar();
    }
}

///< 3. Indentation

///< 3.1. Classes

class IndentationClassExample {
  public:
    Foo();
    virtual ~Foo();
};

///< 3.2. Switches

void indentation_switch_example () {
    switch (condition) {
        case foo_cond:
            foo();
            break;
        case bar_cond:
            bar();
            break;
        default:
            assert(false);
    }
}

///< 3.3. Namespaces

namespace foospace {
class Foo {
  public:
    Foo();
    virtual ~Foo();
};
}
