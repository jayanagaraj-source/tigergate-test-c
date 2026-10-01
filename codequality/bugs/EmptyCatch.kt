// RULE: empty-catch | lang: kotlin — empty catch (specific + generic)
fun risky() {
  try { doThing() } catch (e: java.io.IOException) {}
  try { doThing() } catch (e: Exception) {}
}
fun doThing() {}
