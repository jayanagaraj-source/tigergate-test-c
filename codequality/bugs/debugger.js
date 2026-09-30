// RULE: debugger-statement (HIGH) | lang: javascript
function process(d){
  debugger; // debugger breakpoint left in code
  return d*2;
}
