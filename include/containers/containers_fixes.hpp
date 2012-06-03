#ifndef STLPLUS_CONTAINERS_FIXES
#define STLPLUS_CONTAINERS_FIXES
////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

//   Contains work arounds for OS or Compiler specific problems with container
//   templates

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Unnecessary compiler warnings
////////////////////////////////////////////////////////////////////////////////

#ifdef _MSC_VER
// Microsoft Visual Studio
// shut up the following irritating warnings
//   4786 - VC6, identifier string exceeded maximum allowable length and was truncated (only affects debugger)
//   4305 - VC6, identifier type was converted to a smaller type
//   4503 - VC6, decorated name was longer than the maximum the compiler allows (only affects debugger)
//   4309 - VC6, type conversion operation caused a constant to exceeded the space allocated for it
//   4290 - VC6, C++ exception specification ignored
//   4800 - VC6, forcing value to bool 'true' or 'false' (performance warning)
//   4355 - VC6, 'this' : used in base member initializer list
//   4675 - VC7.1, "change" in function overload resolution _might_ have altered program
//   4996 - VC8, 'xxxx' was declared deprecated
#pragma warning(disable: 4786 4305 4503 4309 4290 4800 4355 4675 4996)
#endif

#ifdef __BORLANDC__
// Borland
// Shut up the following irritating warnings
//   8026 - Functions with exception specifications are not expanded inline
//   8027 - Functions with xxx are not expanded inline
#pragma warn -8026
#pragma warn -8027
#endif

////////////////////////////////////////////////////////////////////////////////
// Problems with the typename keyword
////////////////////////////////////////////////////////////////////////////////

// There are problems with using the 'typename' keyword. Technically, if you
// use a type member of a template class (i.e. a type declared within the
// template class by a local typedef), you need to tell the compiler that it
// is a type name. This is because the compiler cannot work out whether a
// member is a type, a method or a data field at compile time. However,
// support for the typename keyword has traditionally been incomplete in both
// gcc and Visual Studio. I have used macros to try to resolve this issue. The
// macros add the keyword for compiler versions that require it and omit it
// for compiler versions that do not support it

// There are five places where typename keywords cause problems:
//
//   1) in a typedef where a template class's member type is being mapped onto
//      a type definition within another template class or function 
//      e.g. template<typename T> fn () {
//             typedef typename someclass<T>::member_type local_type;
//                     ^^^^^^^^
//   2) in a function parameter declaration, with similar rules to the above
//      e.g. template<typename T> fn (typename someclass<T>::member_type)
//                                    ^^^^^^^^
//   3) in instantiating a template, the parameter to the template, with similar rules to the above
//      e.g. template_class<typename someclass<T>::member_type>
//                          ^^^^^^^^
//   4) Return expressions
//      e.g. return typename ntree<T>::const_iterator(this,m_root);
//                  ^^^^^^^^
//   5) Creating temporary objects when passing arguments to a function or constructor
//      e.g. return typename ntree<T>::const_prefix_iterator(typename ntree<T>::const_iterator(this,m_root));
//                                                           ^^^^^^^^
// Note that the typename keyword is only required when the type being referred to is a member of a template class
//
// So far it *seems* as if all compilers either require all of them or none of
// them, so this set of situations can be handled by a single macro

// default values, overridden for individual problem cases below
#define TYPENAME typename

// GCC 
//   - pre-version 3 didn't handle typename in any of these cases
//   - version 3 onwards, typename is required for all three cases as per default
#ifdef __GNUC__
#if __GNUC__ < 3
#undef TYPENAME
#define TYPENAME
#endif
#endif

// Visual Studio
//   - version 6 (compiler v.12) cannot handle typename in any of these cases
//   - version 7 (.NET) (compiler v.13) requires a typename in a parameter specification but supports all
//   - version 8 (2005) (compiler v.14) requires parameters and templates, supports all
#ifdef _MSC_VER
#if _MSC_VER <= 1200
#undef TYPENAME
#define TYPENAME
#endif
#endif

// Borland 
//   - doesn't handle typename in 5.5, does in 5.82, not sure about other cases
#ifdef __BORLANDC__
#if __BORLANDC__ <= 0x550
#undef TYPENAME
#define TYPENAME
#endif
#endif

////////////////////////////////////////////////////////////////////////////////
// Member templates
// e.g. a template function in a template class

// Not all compilers support them - this fix can be used to disable member
// templates for compilers that don't. Unfortunately that means that some
// functionality will be missing for those compilers.

#define STLPLUS_MEMBER_TEMPLATES

// Visual Studio v6 (compiler version 12) does not support them
#ifdef _MSC_VER
#if _MSC_VER <= 1200
#undef STLPLUS_MEMBER_TEMPLATES
#endif
#endif

////////////////////////////////////////////////////////////////////////////////
#endif
