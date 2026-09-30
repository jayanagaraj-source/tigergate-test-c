// RULE: empty-catch (MEDIUM) | lang: typescript
export function risky(){
  try{ doThing(); }
  catch(e){ /* empty catch: swallowed */ }
}
