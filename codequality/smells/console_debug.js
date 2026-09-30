// RULE: console-debug (INFO) | lang: javascript
function handle(x){
  console.log("debug", x);   // debug console statement
  console.debug("trace", x); // debug console statement
  return x;
}
