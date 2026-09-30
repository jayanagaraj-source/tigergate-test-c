// RULE: empty-catch (MEDIUM) | lang: kotlin
fun risky(){
  try { doThing() }
  catch (e: Exception) { /* empty catch: swallowed */ }
}
fun doThing() {}
