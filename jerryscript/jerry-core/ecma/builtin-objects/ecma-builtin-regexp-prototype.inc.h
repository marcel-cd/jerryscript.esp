/* Copyright JS Foundation and other contributors, http://js.foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * RegExp.prototype built-in description
 */

#include "ecma-builtin-helpers-macro-defines.inc.h"

#if JERRY_BUILTIN_REGEXP

/* ECMA-262 v5, 15.10.6.1 */
OBJECT_VALUE (LIT_MAGIC_STRING_CONSTRUCTOR, ECMA_BUILTIN_ID_REGEXP, ECMA_PROPERTY_CONFIGURABLE_WRITABLE)

ACCESSOR_READ_ONLY (LIT_MAGIC_STRING_FLAGS, ECMA_REGEXP_PROTOTYPE_ROUTINE_GET_FLAGS, ECMA_PROPERTY_FLAG_CONFIGURABLE)

ACCESSOR_READ_ONLY (LIT_MAGIC_STRING_SOURCE, ECMA_REGEXP_PROTOTYPE_ROUTINE_GET_SOURCE, ECMA_PROPERTY_FLAG_CONFIGURABLE)

ACCESSOR_READ_ONLY (LIT_MAGIC_STRING_GLOBAL, ECMA_REGEXP_PROTOTYPE_ROUTINE_GET_GLOBAL, ECMA_PROPERTY_FLAG_CONFIGURABLE)

ACCESSOR_READ_ONLY (LIT_MAGIC_STRING_IGNORECASE_UL,
                    ECMA_REGEXP_PROTOTYPE_ROUTINE_GET_IGNORE_CASE,
                    ECMA_PROPERTY_FLAG_CONFIGURABLE)

ACCESSOR_READ_ONLY (LIT_MAGIC_STRING_DOTALL, ECMA_REGEXP_PROTOTYPE_ROUTINE_GET_DOT_ALL, ECMA_PROPERTY_FLAG_CONFIGURABLE)

ACCESSOR_READ_ONLY (LIT_MAGIC_STRING_MULTILINE,
                    ECMA_REGEXP_PROTOTYPE_ROUTINE_GET_MULTILINE,
                    ECMA_PROPERTY_FLAG_CONFIGURABLE)

ACCESSOR_READ_ONLY (LIT_MAGIC_STRING_UNICODE,
                    ECMA_REGEXP_PROTOTYPE_ROUTINE_GET_UNICODE,
                    ECMA_PROPERTY_FLAG_CONFIGURABLE)

ACCESSOR_READ_ONLY (LIT_MAGIC_STRING_STICKY, ECMA_REGEXP_PROTOTYPE_ROUTINE_GET_STICKY, ECMA_PROPERTY_FLAG_CONFIGURABLE)

ROUTINE (LIT_GLOBAL_SYMBOL_REPLACE, ECMA_REGEXP_PROTOTYPE_ROUTINE_SYMBOL_REPLACE, 2, 2)
ROUTINE (LIT_GLOBAL_SYMBOL_SEARCH, ECMA_REGEXP_PROTOTYPE_ROUTINE_SYMBOL_SEARCH, 1, 1)
ROUTINE (LIT_GLOBAL_SYMBOL_SPLIT, ECMA_REGEXP_PROTOTYPE_ROUTINE_SYMBOL_SPLIT, 2, 2)
ROUTINE (LIT_GLOBAL_SYMBOL_MATCH, ECMA_REGEXP_PROTOTYPE_ROUTINE_SYMBOL_MATCH, 1, 1)
ROUTINE (LIT_GLOBAL_SYMBOL_MATCH_ALL, ECMA_REGEXP_PROTOTYPE_ROUTINE_SYMBOL_MATCH_ALL, 1, 1)

#if JERRY_BUILTIN_ANNEXB
ROUTINE (LIT_MAGIC_STRING_COMPILE, ECMA_REGEXP_PROTOTYPE_ROUTINE_COMPILE, 2, 2)
#endif /* JERRY_BUILTIN_ANNEXB */
ROUTINE (LIT_MAGIC_STRING_EXEC, ECMA_REGEXP_PROTOTYPE_ROUTINE_EXEC, 1, 1)
ROUTINE (LIT_MAGIC_STRING_TEST, ECMA_REGEXP_PROTOTYPE_ROUTINE_TEST, 1, 1)
ROUTINE (LIT_MAGIC_STRING_TO_STRING_UL, ECMA_REGEXP_PROTOTYPE_ROUTINE_TO_STRING, 0, 0)

#endif /* JERRY_BUILTIN_REGEXP */

#include "ecma-builtin-helpers-macro-undefs.inc.h"
