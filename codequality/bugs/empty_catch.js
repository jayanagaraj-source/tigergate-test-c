// RULE: empty-catch | lang: javascript — truly empty catch
function risky() {
  try { doThing(); } catch (e) {}
}
