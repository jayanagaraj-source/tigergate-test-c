// RULE: empty-catch (MEDIUM) | lang: swift
func risky(){
    do { try doThing() }
    catch { /* empty catch: swallowed */ }
}
