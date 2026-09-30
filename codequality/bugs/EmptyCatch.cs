// RULE: empty-catch (MEDIUM) | lang: csharp
using System;
class EmptyCatch{
  void Risky(){
    try{ DoThing(); }
    catch(Exception e){ /* empty catch: swallowed */ }
  }
  void DoThing(){}
}
