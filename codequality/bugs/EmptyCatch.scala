// RULE: empty-catch (MEDIUM) | lang: scala
object EmptyCatch {
  def risky(): Unit = {
    try { doThing() }
    catch { case _: Throwable => /* empty catch: swallowed */ }
  }
  def doThing(): Unit = {}
}
