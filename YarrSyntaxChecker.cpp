/*
 * Copyright (C) 2011, 2016 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#include "Escargot.h"
#include "YarrSyntaxChecker.h"

#include "YarrParser.h"

namespace JSC { namespace Yarr {

class SyntaxChecker {
public:
    void assertionBOL() {}
    void assertionEOL() {}
    void assertionWordBoundary(bool) {}
    void atomPatternCharacter(UChar32) {}
    void atomBuiltInCharacterClass(BuiltInCharacterClassID, bool) {}
    void atomCharacterClassBegin(bool = false) {}
    void atomCharacterClassAtom(UChar) {}
    void atomCharacterClassRange(UChar, UChar) {}
    void atomCharacterClassBuiltIn(BuiltInCharacterClassID, bool) {}
    void atomCharacterClassEnd() {}
    void atomParenthesesSubpatternBegin(bool = true) {}
    void atomParentheticalAssertionBegin(bool = false) {}
    void atomParenthesesEnd() {}
    void atomBackReference(unsigned) {}
    void quantifyAtom(unsigned, unsigned, bool) {}
    void disjunction() {}
};

const char* checkSyntax(const String& pattern, bool hasUnicodeOption)
{
    SyntaxChecker syntaxChecker;
    return parse(syntaxChecker, pattern, hasUnicodeOption);
}

}} // JSC::Yarr
