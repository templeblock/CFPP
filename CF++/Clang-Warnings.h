/*******************************************************************************
 * Copyright (c) 2015, Jean-David Gadina - www.xs-labs.com
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/*!
 * @copyright   (c) 2015 - Jean-David Gadina - www.xs-labs.com
 * @brief       Extra warning flags for Clang
 */

#ifndef CFPP_CLANG_WARNINGS_H
#define CFPP_CLANG_WARNINGS_H

#ifndef __clang__
#error "Clang is required in order to use this header file"
#elif __clang_major__ < 6
#error "Clang 6.0.0 or greater is required in order to use this header file"
#else

/* 
 * C++ - Not wanted unless using C++98 as standard
 * 
 * #pragma clang diagnostic fatal "-Wc++98-c++11-c++14-compat-pedantic"
 * #pragma clang diagnostic fatal "-Wc++98-c++11-c++14-compat"
 * #pragma clang diagnostic fatal "-Wc++98-c++11-compat-pedantic"
 * #pragma clang diagnostic fatal "-Wc++98-c++11-compat"
 * #pragma clang diagnostic fatal "-Wc++98-compat-bind-to-temporary-copy"
 * #pragma clang diagnostic fatal "-Wc++98-compat-local-type-template-args"
 * #pragma clang diagnostic fatal "-Wc++98-compat-pedantic"
 * #pragma clang diagnostic fatal "-Wc++98-compat-unnamed-type-template-args"
 * #pragma clang diagnostic fatal "-Wc++98-compat"
 */

/*
 * Objective-C - Not wanted as this may fail considering a selector
 * implemented in a category
 * 
 * #pragma clang diagnostic fatal "-Wselector"
 */

/* Recognized by Clang 6.0.0 */
#if __clang_major__ >= 6

#pragma clang diagnostic fatal "-W#pragma-messages"
#pragma clang diagnostic fatal "-W#warnings"
#pragma clang diagnostic fatal "-Wabi"
#pragma clang diagnostic fatal "-Wabstract-final-class"
#pragma clang diagnostic fatal "-Waddress-of-temporary"
#pragma clang diagnostic fatal "-Waddress"
#pragma clang diagnostic fatal "-Waggregate-return"
#pragma clang diagnostic fatal "-Wall"
#pragma clang diagnostic fatal "-Wambiguous-macro"
#pragma clang diagnostic fatal "-Wambiguous-member-template"
#pragma clang diagnostic fatal "-Warc-maybe-repeated-use-of-weak"
#pragma clang diagnostic fatal "-Warc-non-pod-memaccess"
#pragma clang diagnostic fatal "-Warc-repeated-use-of-weak"
#pragma clang diagnostic fatal "-Warc-retain-cycles"
#pragma clang diagnostic fatal "-Warc-unsafe-retained-assign"
#pragma clang diagnostic fatal "-Warc"
#pragma clang diagnostic fatal "-Warray-bounds-pointer-arithmetic"
#pragma clang diagnostic fatal "-Warray-bounds"
#pragma clang diagnostic fatal "-Wasm-operand-widths"
#pragma clang diagnostic fatal "-Wasm"
#pragma clang diagnostic fatal "-Watomic-properties"
#pragma clang diagnostic fatal "-Wattributes"
#pragma clang diagnostic fatal "-Wauto-import"
#pragma clang diagnostic fatal "-Wavailability"
#pragma clang diagnostic fatal "-Wbad-array-new-length"
#pragma clang diagnostic fatal "-Wbad-function-cast"
#pragma clang diagnostic fatal "-Wbind-to-temporary-copy"
#pragma clang diagnostic fatal "-Wbitfield-constant-conversion"
#pragma clang diagnostic fatal "-Wbitwise-op-parentheses"
#pragma clang diagnostic fatal "-Wbool-conversion"
#pragma clang diagnostic fatal "-Wbool-conversions"
#pragma clang diagnostic fatal "-Wbridge-cast"
#pragma clang diagnostic fatal "-Wbuiltin-macro-redefined"
#pragma clang diagnostic fatal "-Wbuiltin-requires-header"
#pragma clang diagnostic fatal "-Wc++-compat"
#pragma clang diagnostic fatal "-Wc++0x-compat"
#pragma clang diagnostic fatal "-Wc++0x-extensions"
#pragma clang diagnostic fatal "-Wc++0x-narrowing"
#pragma clang diagnostic fatal "-Wc++11-compat-deprecated-writable-strings"
#pragma clang diagnostic fatal "-Wc++11-compat-pedantic"
#pragma clang diagnostic fatal "-Wc++11-compat-reserved-user-defined-literal"
#pragma clang diagnostic fatal "-Wc++11-compat"
#pragma clang diagnostic fatal "-Wc++11-extensions"
#pragma clang diagnostic fatal "-Wc++11-extra-semi"
#pragma clang diagnostic fatal "-Wc++11-long-long"
#pragma clang diagnostic fatal "-Wc++11-narrowing"
#pragma clang diagnostic fatal "-Wc++1y-extensions"
#pragma clang diagnostic fatal "-Wc11-extensions"
#pragma clang diagnostic fatal "-Wc99-compat"
#pragma clang diagnostic fatal "-Wc99-extensions"
#pragma clang diagnostic fatal "-Wcast-align"
#pragma clang diagnostic fatal "-Wcast-of-sel-type"
#pragma clang diagnostic fatal "-Wcast-qual"
#pragma clang diagnostic fatal "-Wchar-align"
#pragma clang diagnostic fatal "-Wchar-subscripts"
#pragma clang diagnostic fatal "-Wcomment"
#pragma clang diagnostic fatal "-Wcomments"
#pragma clang diagnostic fatal "-Wcompare-distinct-pointer-types"
#pragma clang diagnostic fatal "-Wconditional-uninitialized"
#pragma clang diagnostic fatal "-Wconfig-macros"
#pragma clang diagnostic fatal "-Wconstant-conversion"
#pragma clang diagnostic fatal "-Wconsumed"
#pragma clang diagnostic fatal "-Wconversion-null"
#pragma clang diagnostic fatal "-Wconversion"
#pragma clang diagnostic fatal "-Wcovered-switch-default"
#pragma clang diagnostic fatal "-Wctor-dtor-privacy"
#pragma clang diagnostic fatal "-Wcustom-atomic-properties"
#pragma clang diagnostic fatal "-Wdangling-else"
#pragma clang diagnostic fatal "-Wdangling-field"
#pragma clang diagnostic fatal "-Wdealloc-in-category"
#pragma clang diagnostic fatal "-Wdelegating-ctor-cycles"
#pragma clang diagnostic fatal "-Wdelete-incomplete"
#pragma clang diagnostic fatal "-Wdelete-non-virtual-dtor"
#pragma clang diagnostic fatal "-Wdeprecated-declarations"
#pragma clang diagnostic fatal "-Wdeprecated-implementations"
#pragma clang diagnostic fatal "-Wdeprecated-increment-bool"
#pragma clang diagnostic fatal "-Wdeprecated-objc-isa-usage"
#pragma clang diagnostic fatal "-Wdeprecated-objc-pointer-introspection-performSelector"
#pragma clang diagnostic fatal "-Wdeprecated-objc-pointer-introspection"
#pragma clang diagnostic fatal "-Wdeprecated-register"
#pragma clang diagnostic fatal "-Wdeprecated-writable-strings"
#pragma clang diagnostic fatal "-Wdeprecated"
#pragma clang diagnostic fatal "-Wdisabled-optimization"
#pragma clang diagnostic fatal "-Wdiscard-qual"
#pragma clang diagnostic fatal "-Wdistributed-object-modifiers"
#pragma clang diagnostic fatal "-Wdiv-by-zero"
#pragma clang diagnostic fatal "-Wdivision-by-zero"
#pragma clang diagnostic fatal "-Wdocumentation-deprecated-sync"
#pragma clang diagnostic fatal "-Wdocumentation-html"
#pragma clang diagnostic fatal "-Wdocumentation-pedantic"
#pragma clang diagnostic fatal "-Wdocumentation-unknown-command"
#pragma clang diagnostic fatal "-Wdocumentation"
#pragma clang diagnostic fatal "-Wduplicate-decl-specifier"
#pragma clang diagnostic fatal "-Wduplicate-method-arg"
#pragma clang diagnostic fatal "-Wduplicate-method-match"
#pragma clang diagnostic fatal "-Weffc++"
#pragma clang diagnostic fatal "-Wempty-body"
#pragma clang diagnostic fatal "-Wendif-labels"
#pragma clang diagnostic fatal "-Wenum-conversion"
#pragma clang diagnostic fatal "-Wexit-time-destructors"
#pragma clang diagnostic fatal "-Wextern-c-compat"
#pragma clang diagnostic fatal "-Wextra-semi"
#pragma clang diagnostic fatal "-Wextra-tokens"
#pragma clang diagnostic fatal "-Wextra"
#pragma clang diagnostic fatal "-Wflexible-array-extensions"
#pragma clang diagnostic fatal "-Wformat-extra-args"
#pragma clang diagnostic fatal "-Wformat-invalid-specifier"
#pragma clang diagnostic fatal "-Wformat-non-iso"
#pragma clang diagnostic fatal "-Wformat-nonliteral"
#pragma clang diagnostic fatal "-Wformat-security"
#pragma clang diagnostic fatal "-Wformat-y2k"
#pragma clang diagnostic fatal "-Wformat-zero-length"
#pragma clang diagnostic fatal "-Wformat"
#pragma clang diagnostic fatal "-Wformat=2"
#pragma clang diagnostic fatal "-Wfour-char-constants"
#pragma clang diagnostic fatal "-Wgcc-compat"
#pragma clang diagnostic fatal "-Wglobal-constructors"
#pragma clang diagnostic fatal "-Wgnu-alignof-expression"
#pragma clang diagnostic fatal "-Wgnu-anonymous-struct"
#pragma clang diagnostic fatal "-Wgnu-binary-literal"
#pragma clang diagnostic fatal "-Wgnu-case-range"
#pragma clang diagnostic fatal "-Wgnu-complex-integer"
#pragma clang diagnostic fatal "-Wgnu-compound-literal-initializer"
#pragma clang diagnostic fatal "-Wgnu-conditional-omitted-operand"
#pragma clang diagnostic fatal "-Wgnu-designator"
#pragma clang diagnostic fatal "-Wgnu-empty-initializer"
#pragma clang diagnostic fatal "-Wgnu-empty-struct"
#pragma clang diagnostic fatal "-Wgnu-flexible-array-initializer"
#pragma clang diagnostic fatal "-Wgnu-flexible-array-union-member"
#pragma clang diagnostic fatal "-Wgnu-folding-constant"
#pragma clang diagnostic fatal "-Wgnu-imaginary-constant"
#pragma clang diagnostic fatal "-Wgnu-label-as-value"
#pragma clang diagnostic fatal "-Wgnu-redeclared-enum"
#pragma clang diagnostic fatal "-Wgnu-statement-expression"
#pragma clang diagnostic fatal "-Wgnu-static-float-init"
#pragma clang diagnostic fatal "-Wgnu-string-literal-operator-template"
#pragma clang diagnostic fatal "-Wgnu-union-cast"
#pragma clang diagnostic fatal "-Wgnu-variable-sized-type-not-at-end"
#pragma clang diagnostic fatal "-Wgnu-zero-line-directive"
#pragma clang diagnostic fatal "-Wgnu-zero-variadic-macro-arguments"
#pragma clang diagnostic fatal "-Wgnu"
#pragma clang diagnostic fatal "-Wheader-hygiene"
#pragma clang diagnostic fatal "-Wignored-attributes"
#pragma clang diagnostic fatal "-Wignored-qualifiers"
#pragma clang diagnostic fatal "-Wimplicit-atomic-properties"
#pragma clang diagnostic fatal "-Wimplicit-conversion-floating-point-to-bool"
#pragma clang diagnostic fatal "-Wimplicit-fallthrough-per-function"
#pragma clang diagnostic fatal "-Wimplicit-fallthrough"
#pragma clang diagnostic fatal "-Wimplicit-function-declaration"
#pragma clang diagnostic fatal "-Wimplicit-int"
#pragma clang diagnostic fatal "-Wimport"
#pragma clang diagnostic fatal "-Wincompatible-ms-struct"
#pragma clang diagnostic fatal "-Wincompatible-pointer-types-discards-qualifiers"
#pragma clang diagnostic fatal "-Wincompatible-pointer-types"
#pragma clang diagnostic fatal "-Wincomplete-module"
#pragma clang diagnostic fatal "-Wincomplete-umbrella"
#pragma clang diagnostic fatal "-Winfinite-recursion"
#pragma clang diagnostic fatal "-Winit-self"
#pragma clang diagnostic fatal "-Winitializer-overrides"
#pragma clang diagnostic fatal "-Winline"
#pragma clang diagnostic fatal "-Wint-conversion"
#pragma clang diagnostic fatal "-Wint-conversions"
#pragma clang diagnostic fatal "-Wint-to-pointer-cast"
#pragma clang diagnostic fatal "-Wint-to-void-pointer-cast"
#pragma clang diagnostic fatal "-Winvalid-command-line-argument"
#pragma clang diagnostic fatal "-Winvalid-iboutlet"
#pragma clang diagnostic fatal "-Winvalid-noreturn"
#pragma clang diagnostic fatal "-Winvalid-offsetof"
#pragma clang diagnostic fatal "-Winvalid-pch"
#pragma clang diagnostic fatal "-Winvalid-pp-token"
#pragma clang diagnostic fatal "-Winvalid-source-encoding"
#pragma clang diagnostic fatal "-Wkeyword-compat"
#pragma clang diagnostic fatal "-Wknr-promoted-parameter"
#pragma clang diagnostic fatal "-Wlarge-by-value-copy"
#pragma clang diagnostic fatal "-Wliteral-conversion"
#pragma clang diagnostic fatal "-Wliteral-range"
#pragma clang diagnostic fatal "-Wlocal-type-template-args"
#pragma clang diagnostic fatal "-Wlogical-not-parentheses"
#pragma clang diagnostic fatal "-Wlogical-op-parentheses"
#pragma clang diagnostic fatal "-Wlong-long"
#pragma clang diagnostic fatal "-Wloop-analysis"
#pragma clang diagnostic fatal "-Wmain-return-type"
#pragma clang diagnostic fatal "-Wmain"
#pragma clang diagnostic fatal "-Wmalformed-warning-check"
#pragma clang diagnostic fatal "-Wmethod-signatures"
#pragma clang diagnostic fatal "-Wmicrosoft"
#pragma clang diagnostic fatal "-Wmismatched-parameter-types"
#pragma clang diagnostic fatal "-Wmismatched-return-types"
#pragma clang diagnostic fatal "-Wmismatched-tags"
#pragma clang diagnostic fatal "-Wmissing-braces"
#pragma clang diagnostic fatal "-Wmissing-declarations"
#pragma clang diagnostic fatal "-Wmissing-field-initializers"
#pragma clang diagnostic fatal "-Wmissing-format-attribute"
#pragma clang diagnostic fatal "-Wmissing-include-dirs"
#pragma clang diagnostic fatal "-Wmissing-method-return-type"
#pragma clang diagnostic fatal "-Wmissing-noreturn"
#pragma clang diagnostic fatal "-Wmodule-conflict"
#pragma clang diagnostic fatal "-Wmost"
#pragma clang diagnostic fatal "-Wmultichar"
#pragma clang diagnostic fatal "-Wnarrowing"
#pragma clang diagnostic fatal "-Wnested-externs"
#pragma clang diagnostic fatal "-Wnew-returns-null"
#pragma clang diagnostic fatal "-Wnewline-eof"
#pragma clang diagnostic fatal "-Wnon-gcc"
#pragma clang diagnostic fatal "-Wnon-literal-null-conversion"
#pragma clang diagnostic fatal "-Wnon-modular-include-in-framework-module"
#pragma clang diagnostic fatal "-Wnon-modular-include-in-module"
#pragma clang diagnostic fatal "-Wnon-pod-varargs"
#pragma clang diagnostic fatal "-Wnon-virtual-dtor"
#pragma clang diagnostic fatal "-Wnonnull"
#pragma clang diagnostic fatal "-Wnonportable-cfstrings"
#pragma clang diagnostic fatal "-WNSObject-attribute"
#pragma clang diagnostic fatal "-Wnull-arithmetic"
#pragma clang diagnostic fatal "-Wnull-character"
#pragma clang diagnostic fatal "-Wnull-conversion"
#pragma clang diagnostic fatal "-Wnull-dereference"
#pragma clang diagnostic fatal "-Wobjc-cocoa-api"
#pragma clang diagnostic fatal "-Wobjc-designated-initializers"
#pragma clang diagnostic fatal "-Wobjc-literal-compare"
#pragma clang diagnostic fatal "-Wobjc-method-access"
#pragma clang diagnostic fatal "-Wobjc-missing-super-calls"
#pragma clang diagnostic fatal "-Wobjc-noncopy-retain-block-property"
#pragma clang diagnostic fatal "-Wobjc-nonunified-exceptions"
#pragma clang diagnostic fatal "-Wobjc-property-implementation"
#pragma clang diagnostic fatal "-Wobjc-property-no-attribute"
#pragma clang diagnostic fatal "-Wobjc-property-synthesis"
#pragma clang diagnostic fatal "-Wobjc-protocol-method-implementation"
#pragma clang diagnostic fatal "-Wobjc-readonly-with-setter-property"
#pragma clang diagnostic fatal "-Wobjc-redundant-api-use"
#pragma clang diagnostic fatal "-Wobjc-redundant-literal-use"
#pragma clang diagnostic fatal "-Wobjc-root-class"
#pragma clang diagnostic fatal "-Wobjc-string-compare"
#pragma clang diagnostic fatal "-Wobjc-string-concatenation"
#pragma clang diagnostic fatal "-Wold-style-cast"
#pragma clang diagnostic fatal "-Wold-style-definition"
#pragma clang diagnostic fatal "-Wout-of-line-declaration"
#pragma clang diagnostic fatal "-Wover-aligned"
#pragma clang diagnostic fatal "-Woverflow"
#pragma clang diagnostic fatal "-Woverlength-strings"
#pragma clang diagnostic fatal "-Woverloaded-shift-op-parentheses"
#pragma clang diagnostic fatal "-Woverloaded-virtual"
#pragma clang diagnostic fatal "-Woverriding-method-mismatch"
#pragma clang diagnostic fatal "-Wpacked"
#pragma clang diagnostic fatal "-Wpadded"
#pragma clang diagnostic fatal "-Wparentheses-equality"
#pragma clang diagnostic fatal "-Wparentheses"
#pragma clang diagnostic fatal "-Wpedantic"
#pragma clang diagnostic fatal "-Wpointer-arith"
#pragma clang diagnostic fatal "-Wpointer-to-int-cast"
#pragma clang diagnostic fatal "-Wprivate-extern"
#pragma clang diagnostic fatal "-Wprofile-instr-out-of-date"
#pragma clang diagnostic fatal "-Wproperty-attribute-mismatch"
#pragma clang diagnostic fatal "-Wprotocol"
#pragma clang diagnostic fatal "-Wreceiver-expr"
#pragma clang diagnostic fatal "-Wreceiver-forward-class"
#pragma clang diagnostic fatal "-Wredeclared-class-member"
#pragma clang diagnostic fatal "-Wredundant-decls"
#pragma clang diagnostic fatal "-Wreinterpret-base-class"
#pragma clang diagnostic fatal "-Wreorder"
#pragma clang diagnostic fatal "-Wreserved-user-defined-literal"
#pragma clang diagnostic fatal "-Wreturn-stack-address"
#pragma clang diagnostic fatal "-Wreturn-type-c-linkage"
#pragma clang diagnostic fatal "-Wreturn-type"
#pragma clang diagnostic fatal "-Wsection"
#pragma clang diagnostic fatal "-Wselector-type-mismatch"
#pragma clang diagnostic fatal "-Wself-assign-field"
#pragma clang diagnostic fatal "-Wself-assign"
#pragma clang diagnostic fatal "-Wsemicolon-before-method-body"
#pragma clang diagnostic fatal "-Wsentinel"
#pragma clang diagnostic fatal "-Wsequence-point"
#pragma clang diagnostic fatal "-Wserialized-diagnostics"
#pragma clang diagnostic fatal "-Wshadow"
#pragma clang diagnostic fatal "-Wshift-op-parentheses"
#pragma clang diagnostic fatal "-Wshorten-64-to-32"
#pragma clang diagnostic fatal "-Wsign-compare"
#pragma clang diagnostic fatal "-Wsign-conversion"
#pragma clang diagnostic fatal "-Wsign-promo"
#pragma clang diagnostic fatal "-Wsizeof-array-argument"
#pragma clang diagnostic fatal "-Wsizeof-array-decay"
#pragma clang diagnostic fatal "-Wsizeof-pointer-memaccess"
#pragma clang diagnostic fatal "-Wsometimes-uninitialized"
#pragma clang diagnostic fatal "-Wsource-uses-openmp"
#pragma clang diagnostic fatal "-Wstack-protector"
#pragma clang diagnostic fatal "-Wstatic-float-init"
#pragma clang diagnostic fatal "-Wstatic-in-inline"
#pragma clang diagnostic fatal "-Wstatic-local-in-inline"
#pragma clang diagnostic fatal "-Wstatic-self-init"
#pragma clang diagnostic fatal "-Wstrict-aliasing"
#pragma clang diagnostic fatal "-Wstrict-aliasing=0"
#pragma clang diagnostic fatal "-Wstrict-aliasing=1"
#pragma clang diagnostic fatal "-Wstrict-aliasing=2"
#pragma clang diagnostic fatal "-Wstrict-overflow"
#pragma clang diagnostic fatal "-Wstrict-overflow=0"
#pragma clang diagnostic fatal "-Wstrict-overflow=1"
#pragma clang diagnostic fatal "-Wstrict-overflow=2"
#pragma clang diagnostic fatal "-Wstrict-overflow=3"
#pragma clang diagnostic fatal "-Wstrict-overflow=4"
#pragma clang diagnostic fatal "-Wstrict-overflow=5"
#pragma clang diagnostic fatal "-Wstrict-prototypes"
#pragma clang diagnostic fatal "-Wstrict-selector-match"
#pragma clang diagnostic fatal "-Wstring-compare"
#pragma clang diagnostic fatal "-Wstring-conversion"
#pragma clang diagnostic fatal "-Wstring-plus-char"
#pragma clang diagnostic fatal "-Wstring-plus-int"
#pragma clang diagnostic fatal "-Wstrncat-size"
#pragma clang diagnostic fatal "-Wsuper-class-method-mismatch"
#pragma clang diagnostic fatal "-Wswitch-default"
#pragma clang diagnostic fatal "-Wswitch-enum"
#pragma clang diagnostic fatal "-Wswitch"
#pragma clang diagnostic fatal "-Wsynth"
#pragma clang diagnostic fatal "-Wtautological-constant-out-of-range-compare"
#pragma clang diagnostic fatal "-Wthread-safety-analysis"
#pragma clang diagnostic fatal "-Wthread-safety-attributes"
#pragma clang diagnostic fatal "-Wthread-safety-beta"
#pragma clang diagnostic fatal "-Wthread-safety-precise"
#pragma clang diagnostic fatal "-Wthread-safety"
#pragma clang diagnostic fatal "-Wtrigraphs"
#pragma clang diagnostic fatal "-Wtype-limits"
#pragma clang diagnostic fatal "-Wtype-safety"
#pragma clang diagnostic fatal "-Wunavailable-declarations"
#pragma clang diagnostic fatal "-Wundeclared-selector"
#pragma clang diagnostic fatal "-Wundefined-reinterpret-cast"
#pragma clang diagnostic fatal "-Wunicode"
#pragma clang diagnostic fatal "-Wuninitialized"
#pragma clang diagnostic fatal "-Wunknown-pragmas"
#pragma clang diagnostic fatal "-Wunknown-warning-option"
#pragma clang diagnostic fatal "-Wunnamed-type-template-args"
#pragma clang diagnostic fatal "-Wunneeded-internal-declaration"
#pragma clang diagnostic fatal "-Wunneeded-member-function"
#pragma clang diagnostic fatal "-Wunreachable-code-aggressive"
#pragma clang diagnostic fatal "-Wunreachable-code-break"
#pragma clang diagnostic fatal "-Wunreachable-code-loop-increment"
#pragma clang diagnostic fatal "-Wunreachable-code-return"
#pragma clang diagnostic fatal "-Wunreachable-code"
#pragma clang diagnostic fatal "-Wunsequenced"
#pragma clang diagnostic fatal "-Wunsupported-friend"
#pragma clang diagnostic fatal "-Wunused-argument"
#pragma clang diagnostic fatal "-Wunused-command-line-argument"
#pragma clang diagnostic fatal "-Wunused-comparison"
#pragma clang diagnostic fatal "-Wunused-const-variable"
#pragma clang diagnostic fatal "-Wunused-exception-parameter"
#pragma clang diagnostic fatal "-Wunused-function"
#pragma clang diagnostic fatal "-Wunused-label"
#pragma clang diagnostic fatal "-Wunused-member-function"
#pragma clang diagnostic fatal "-Wunused-parameter"
#pragma clang diagnostic fatal "-Wunused-private-field"
#pragma clang diagnostic fatal "-Wunused-property-ivar"
#pragma clang diagnostic fatal "-Wunused-result"
#pragma clang diagnostic fatal "-Wunused-value"
#pragma clang diagnostic fatal "-Wunused-variable"
#pragma clang diagnostic fatal "-Wunused"
#pragma clang diagnostic fatal "-Wused-but-marked-unused"
#pragma clang diagnostic fatal "-Wuser-defined-literals"
#pragma clang diagnostic fatal "-Wvarargs"
#pragma clang diagnostic fatal "-Wvariadic-macros"
#pragma clang diagnostic fatal "-Wvector-conversion"
#pragma clang diagnostic fatal "-Wvector-conversions"
#pragma clang diagnostic fatal "-Wvexing-parse"
#pragma clang diagnostic fatal "-Wvisibility"
#pragma clang diagnostic fatal "-Wvla-extension"
#pragma clang diagnostic fatal "-Wvla"
#pragma clang diagnostic fatal "-Wvolatile-register-var"
#pragma clang diagnostic fatal "-Wwrite-strings"
#pragma clang diagnostic fatal "-Wzero-length-array"

#endif

/* Recognized by Clang 6.1.0 */
#if __clang_major__ > 6 || __clang_minor__ >= 1

#pragma clang diagnostic fatal "-Wabsolute-value"
#pragma clang diagnostic fatal "-Wat-protocol"
#pragma clang diagnostic fatal "-Wbackend-plugin"
#pragma clang diagnostic fatal "-Wc++14-compat-pedantic"
#pragma clang diagnostic fatal "-Wc++14-compat"
#pragma clang diagnostic fatal "-Wc++14-extensions"
#pragma clang diagnostic fatal "-Wc++1z-extensions"
#pragma clang diagnostic fatal "-Wclass-varargs"
#pragma clang diagnostic fatal "-Wcstring-format-directive"
#pragma clang diagnostic fatal "-Wcuda-compat"
#pragma clang diagnostic fatal "-Wenum-too-large"
#pragma clang diagnostic fatal "-Wexplicit-initialize-call"
#pragma clang diagnostic fatal "-Wfallback"
#pragma clang diagnostic fatal "-Wfloat-conversion"
#pragma clang diagnostic fatal "-Wframe-larger-than="
#pragma clang diagnostic fatal "-Wfunction-def-in-objc-container"
#pragma clang diagnostic fatal "-Wignored-optimization-argument"
#pragma clang diagnostic fatal "-Wignored-pragmas"
#pragma clang diagnostic fatal "-Wimplicitly-unsigned-literal"
#pragma clang diagnostic fatal "-Winline-asm"
#pragma clang diagnostic fatal "-Wmacro-redefined"
#pragma clang diagnostic fatal "-Wobjc-literal-conversion"
#pragma clang diagnostic fatal "-Wobjc-multiple-method-names"
#pragma clang diagnostic fatal "-Wopenmp-clauses"
#pragma clang diagnostic fatal "-Wopenmp-loop-form"
#pragma clang diagnostic fatal "-Wpass-failed"
#pragma clang diagnostic fatal "-Wpointer-bool-conversion"
#pragma clang diagnostic fatal "-Wpragmas"
#pragma clang diagnostic fatal "-Wprofile-instr-unprofiled"
#pragma clang diagnostic fatal "-Wproperty-access-dot-syntax"
#pragma clang diagnostic fatal "-Wswitch-bool"
#pragma clang diagnostic fatal "-Wtautological-compare"
#pragma clang diagnostic fatal "-Wtautological-overlap-compare"
#pragma clang diagnostic fatal "-Wtautological-pointer-compare"
#pragma clang diagnostic fatal "-Wtautological-undefined-compare"
#pragma clang diagnostic fatal "-Wthread-safety-negative"
#pragma clang diagnostic fatal "-Wthread-safety-verbose"
#pragma clang diagnostic fatal "-Wundefined-bool-conversion"
#pragma clang diagnostic fatal "-Wunknown-attributes"
#pragma clang diagnostic fatal "-Wunused-getter-return-value"
#pragma clang diagnostic fatal "-Wwritable-strings"

#endif

/* Recognized by Clang 7.0.0 */
#if __clang_major__ >= 7

#pragma clang diagnostic fatal "-Wflag-enum"
#pragma clang diagnostic fatal "-Wfuture-compat"
#pragma clang diagnostic fatal "-Winconsistent-missing-override"
#pragma clang diagnostic fatal "-WIndependentClass-attribute"
#pragma clang diagnostic fatal "-Wkeyword-macro"
#pragma clang diagnostic fatal "-Wpotentially-evaluated-expression"
#pragma clang diagnostic fatal "-Wreserved-id-macro"
#pragma clang diagnostic fatal "-Wself-move"
#pragma clang diagnostic fatal "-Wthread-safety-reference"
#pragma clang diagnostic fatal "-Wunevaluated-expression"
#pragma clang diagnostic fatal "-Wunused-local-typedef"
#pragma clang diagnostic fatal "-Wunused-local-typedefs"

#endif

#endif

#endif /* CFPP_CLANG_WARNINGS_H */
