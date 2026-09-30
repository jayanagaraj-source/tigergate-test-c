// RULE: empty-catch (MEDIUM) | lang: javascript
function risky(){
  try{ doThing(); }
  catch(e){ /* empty catch: swallowed */ }
}
