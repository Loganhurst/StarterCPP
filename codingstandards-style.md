# C++ Coding Standards for CST136

Version:  1.0 - Check back for new versions before you start each lab.

These standards started life here:  https://gist.github.com/lefticus/10191322#file-codingstandards-1-style-md

## Descriptive and Consistent Naming

C++ allows for arbitrary length identifier names, so there's no reason to be terse when naming variables. Use descriptive names, and be consistent in the style

 * `CamelCase`
 * `snake_case`
 
are common examples. snake_case has the advantage that it can also work with spell checkers, if desired.

Chose either 'CamelCase' or snake_case and stick to it within your program.  

### Common C++ Naming Conventions

These naming conventions are prefered and you'll only use points if your code is totally awkward.

 * Types start with capitals: `MyClass`
 * functions and variables start with lower case: `myMethod`
 * constants are all capital: `const int PI=3.14159265358979323;`

*Note that the C++ standard does not follow any of these guidelines. Everything in the standard is lowercase only.*

Prefer a verb_noun or VerbNoun name for functions.  For class methods the noun can be implied.

The reader should understand what the variable / method / constant does using the name only.


### Distinguish Private Object Data

Name private data with a `m_` prefix to distinguish it from public data.

Please do this.  It will drive you and your instructor nuts otherwise.


### Well formed example

```cpp
class MyClass
{
public:
  MyClass(int t_data)
    : m_data(t_data)
  {
  }
  
  int getData() const
  {
    return m_data;
  }
  
private:
  int m_data;
};
```

## Use `nullptr`

C++11 introduces `nullptr` which is a special type denoting a null pointer value. This should be used instead of 0 or NULL to indicate a null pointer.

## Comments

Comment blocks should use `//`, not `/* */`. Using `//` makes it much easier to comment out a block of code while debugging.

Use #ifdef TODO to block out code you aren't finished with yet.  


## Never Use `using` In a Header File

This causes the name space you are `using` to be pulled into the namespace of the header file.


## Include Guards

Header files must contain an distinctly named include guard to avoid problems with including the same header multiple times or conflicting with other headers from other projects

```cpp
#ifndef MYPROJECT_MYCLASS_H
#define MYPROEJCT_MYCLASS_H

namespace MyProject {
class MyClass {
};
}

#endif
```

## Use consistent indenting. 

Tabs are not allowed, and a mixture of tabs and spaces is strictly forbidden. Modern autoindenting IDEs and editors require a consistent standard to be set.

```cpp
// Good Idea
int myFunction(bool t_b)
{
  if (t_b)
  {
    // do something
  }
}
```

## {} are required for blocks. 
Leaving them off can lead to semantic errors in the code.

```cpp
// Bad Idea
// this compiles and does what you want, but can lead to confusing
// errors if close attention is not paid.
for (int i = 0; i < 15; ++i)
  std::cout << i << std::endl;

// Bad Idea
// the cout is not part of the loop in this case even though it appears to be
int sum = 0;
for (int i = 0; i < 15; ++i)
  ++sum;
  std::cout << i << std::endl;
  
  
// Good Idea
// It's clear which statements are part of the loop (or if block, or whatever)
int sum = 0;
for (int i = 0; i < 15; ++i) {
  ++sum;
  std::cout << i << std::endl;
}
```

## Keep lines a reasonable length

```cpp
// Bad Idea
// hard to follow
if (x && y && myFunctionThatReturnsBool() && caseNumber3 && (15 > 12 || 2 < 3)) { 
}

// Good Idea
// Logical grouping, easier to read
if (x && y && myFunctionThatReturnsBool() 
    && caseNumber3 
    && (15 > 12 || 2 < 3)) { 
}
```


## Use "" For Including Local Files
... `<>` is [reserved for system includes](http://blog2.emptycrate.com/content/when-use-include-verses-include).

```cpp
// Bad Idea. Requires extra -I directives to the compiler
// and goes against standards
#include <string>
#include <includes/MyHeader.h>

// Worse Idea
// requires potentially even more specific -I directives and 
// makes code more difficult to package and distribute
#include <string>
#include <MyHeader.h>


// Good Idea
// requires no extra params and notifies the user that the file
// is a local file
#include <string>
#include "MyHeader.h"
```

## Initialize Member Variables
...with the member initializer list

```cpp
// Bad Idea
class MyClass
{
public:
  MyClass(int t_value)
  {
    m_value = t_value;
  }

private:
  int m_value;
};


// Good Idea
// C++'s memeber initializer list is unique to the language and leads to
// cleaner code and potential performance gains that other languages cannot 
// match
class MyClass
{
public:
  MyClass(int t_value)
    : m_value(t_value)
  {
  }

private:
  int m_value;
};
```

## Forward Declare when Possible

This:
```cpp
// some header file
class MyClass;

void doSomething(const MyClass &);
```

instead of:

```cpp
// some header file
#include "MyClass.h"

void doSomething(const MyClass &);
```

This is a proactive approach to simplify compilation time and rebuilding dependencies.

## Use Object Based .h and .cpp

If you have more then 150 lines in your program then separate out any classes / structs into their own .h and .cpp.  Note that .h files should only have inline methods.

## Always Use Namespaces

There is almost never a reason to declare an identifier in the global namespaces. Instead, functions and classes should exist in an appropriately named namespaces or in a class inside of a namespace. Identifiers which are placed in the global namespace risk conflicting with identifiers from other (mostly C, which doesn't have namespaces) libraries.
Do not bring in the whole std namespace in labs,  Instead site each individual element.  ie std::cout or std::endl 

## Avoid Compiler Macros

Compiler definitions and macros are replaced by the pre-processor before the compiler is ever run. This can make debugging very difficult because the debugger doesn't know where the source came from.

```cpp
// Good Idea
namespace my_project {
  class Constants {
  public:
    static const double PI = 3.14159;
  }
}

// Bad Idea
#define PI 3.14159;
```

## Site your source
When you didn't originate the code, site your source.  For example see the top of this style guide.
