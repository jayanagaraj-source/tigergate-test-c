// RULE: empty-catch | lang: typescript — truly empty catch
export function risky() {
  try { doThing(); } catch (e) {}
}
