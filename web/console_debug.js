// RULE: console-debug | lang: javascript
function handle(x) {
  console.log("debug", x);
  console.debug("trace", x);
  console.info("info", x);
  console.warn("warn", x);
  console.trace("stack");
  return x;
}
