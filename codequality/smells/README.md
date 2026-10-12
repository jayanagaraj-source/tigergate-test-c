# Code-Smell fixtures — C only (TigerGate Code Quality -> Code Smell)

| Rule ID | Severity | File | C construct used | Fired? |
|---------|----------|------|------------------|--------|
| console-debug     | INFO   | console_debug.c    | printf/fprintf/puts debug prints | [ ] |
| deep-nesting      | LOW    | deep_nesting.c     | 7 nested control structures | [ ] |
| skipped-test      | LOW    | skipped_test.c     | `#if 0` disabled + no-op test | [ ] |
| file-too-long     | LOW    | file_too_long.c    | 806-line file | [ ] |
| long-function     | MEDIUM | long_function.c    | ~120-line function body | [ ] |
| print-stack-trace | LOW    | print_stack_trace.c| backtrace_symbols_fd to stderr | [ ] |
| too-many-params   | LOW    | too_many_params.c  | 10-parameter function | [ ] |
| todo-fixme        | INFO   | todo_fixme.c       | TODO + FIXME comments | [ ] |

deep-nesting, file-too-long, long-function, too-many-params, todo-fixme are
All-languages rules -> the C fixtures test C coverage directly. console-debug
(JS/TS) and print-stack-trace (Java/C#) do NOT list C -> expected to not fire.
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
