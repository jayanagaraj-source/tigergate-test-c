// RULE: empty-catch | lang: csharp — empty catch (specific + generic)
using System;
using System.IO;
class EmptyCatch {
  void Risky() {
    try { DoThing(); } catch (IOException e) {}
    try { DoThing(); } catch (Exception e) {}
  }
  void DoThing() {}
}
