# Code-Smell fixtures (TigerGate Code Quality -> Code Smell)

Language-scoped rules have fixtures in their listed languages; All-languages
rules use a C fixture (this repo's language). Mark "Fired?" after your scan.

| Rule ID | Lang scope | File | Language | Fired? |
|---------|-----------|------|----------|--------|
| console-debug     | JS, TS      | console_debug.js    | javascript | [ ] |
| console-debug     | JS, TS      | console_debug.ts    | typescript | [ ] |
| console-debug     | JS, TS      | console_debug.c     | c (not in scope) | [ ] |
| deep-nesting      | All         | deep_nesting.c      | c | [ ] |
| skipped-test      | All         | skipped_test.c      | c | [ ] |
| file-too-long     | All         | file_too_long.c     | c (806 lines) | [ ] |
| long-function     | All         | long_function.c     | c (~120-line fn) | [ ] |
| print-stack-trace | Java, C#    | PrintStackTrace.java| java   | [ ] |
| print-stack-trace | Java, C#    | PrintStackTrace.cs  | csharp | [ ] |
| print-stack-trace | Java, C#    | print_stack_trace.c | c (not in scope) | [ ] |
| too-many-params   | All         | too_many_params.c   | c (10 params) | [ ] |
| todo-fixme        | All         | todo_fixme.c        | c | [ ] |
