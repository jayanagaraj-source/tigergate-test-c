// RULE: empty-catch | lang: dart — empty catch (specific + generic)
void risky() {
  try { doThing(); } on FormatException catch (e) {}
  try { doThing(); } catch (e) {}
}
