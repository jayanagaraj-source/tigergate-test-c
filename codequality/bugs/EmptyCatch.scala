// RULE: empty-catch | lang: scala — empty catch (multiple idioms)
object EmptyCatch {
  def risky(): Unit = {
    try { doThing() } catch { case _: java.io.IOException => }
    try { doThing() } catch { case _: Throwable => {} }
    try { doThing() } catch { case e: Exception => () }
  }
  def doThing(): Unit = {}
}
