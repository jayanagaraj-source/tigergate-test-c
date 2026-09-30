// RULE: broad-catch (MEDIUM) | lang: csharp
using System;
class BroadCatch{
  void Risky(){
    try{ DoThing(); }
    catch(Exception e){ Console.WriteLine(e); } // overly broad exception handler
  }
  void DoThing(){}
}
