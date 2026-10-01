// RULE: empty-catch | lang: scala — empty catch
object EmptyCatch {
  def risky(): Unit = {
    try { doThing() } catch { case _: java.io.IOException => }
    try { doThing() } catch { case _: Throwable => }
  }
  def doThing(): Unit = {}
}
