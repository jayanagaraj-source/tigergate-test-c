# Bug-rule fixtures — C only (TigerGate Code Quality -> Bug)

Every fixture is C, since this repo is scanned as C. Rules that have no native
C construct use the closest C equivalent, so you can check whether TigerGate
detects them in C. Mark "Fired?" after the scan.

| Rule ID | Severity | File | C construct used | Fired? |
|---------|----------|------|------------------|--------|
| debugger-statement | HIGH   | debugger_statement.c | __builtin_trap / raise(SIGTRAP) / int3 / assert(0) | [ ] |
| empty-catch        | MEDIUM | empty_catch.c        | empty error branch `if (rc) { }` | [ ] |
| swallowed-error    | MEDIUM | swallowed_error.c    | return value assigned then discarded | [ ] |
| broad-catch        | MEDIUM | broad_catch.c        | one catch-all signal/setjmp handler | [ ] |

Note: per TigerGate's Rules Catalog none of these four list C (empty-catch
lists C++). If a fixture here is NOT flagged, that is the expected
language-scope behavior; if it IS flagged, TigerGate applies the rule to C.
