// RULE: empty-catch (MEDIUM) | lang: dart
void risky(){
  try { doThing(); }
  catch (e) { /* empty catch: swallowed */ }
}
