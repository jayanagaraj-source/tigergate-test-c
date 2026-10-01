// RULE: empty-catch | lang: swift — empty catch
func risky() {
    do { try doThing() } catch {}
}
