# Bug-rule fixtures (TigerGate Code Quality -> Bug)

Each rule has fixtures in the languages the Rules Catalog lists for it (from the
image), plus a C fixture to test whether the rule also applies to this repo's
own language. Mark "Fired?" after your scan.

## debugger-statement (HIGH) — JS, TS, Ruby, Python, PHP
| File | Language | Fired? |
|------|----------|--------|
| debugger.js  | javascript | [ ] |
| debugger.ts  | typescript | [ ] |
| debugger.py  | python     | [ ] |
| debugger.rb  | ruby       | [ ] |
| debugger.php | php        | [ ] |
| debugger_statement.c | c (not in rule scope) | [ ] |

## empty-catch (MEDIUM) — Go, Java, C#, Kotlin, Scala, JS, TS, PHP, Swift, Rust, Dart, C++
| File | Language | Fired? |
|------|----------|--------|
| empty_catch.go    | go        | [ ] |
| EmptyCatch.java   | java      | [ ] |
| EmptyCatch.cs     | csharp    | [ ] |
| EmptyCatch.kt     | kotlin    | [ ] |
| EmptyCatch.scala  | scala     | [ ] |
| empty_catch.js    | javascript| [ ] |
| empty_catch.ts    | typescript| [ ] |
| empty_catch.php   | php       | [ ] |
| empty_catch.swift | swift     | [ ] |
| empty_catch.rs    | rust      | [ ] |
| empty_catch.dart  | dart      | [ ] |
| empty_catch.cpp   | cpp       | [ ] |
| empty_catch.c     | c (not in rule scope) | [ ] |

## swallowed-error (MEDIUM) — Go
| File | Language | Fired? |
|------|----------|--------|
| swallowed_error.go | go | [ ] |
| swallowed_error.c  | c (not in rule scope) | [ ] |

## broad-catch (MEDIUM) — Java, C#, Python
| File | Language | Fired? |
|------|----------|--------|
| BroadCatch.java | java   | [ ] |
| BroadCatch.cs   | csharp | [ ] |
| broad_catch.py  | python | [ ] |
| broad_catch.c   | c (not in rule scope) | [ ] |
