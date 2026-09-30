// RULE: print-stack-trace (LOW) | lang: csharp
using System;
class PrintStackTrace{
  void Run(){
    try{ Work(); }
    catch(Exception e){ Console.WriteLine(e.StackTrace); } // printed, not logged
  }
  void Work(){}
}
