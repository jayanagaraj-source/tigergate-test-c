// Cross-language fixture for the 5 new custom rules — JavaScript.
// The rule patterns are brace/semicolon based, so JS matches like C.
// Lets you confirm the new "All languages" rules fire beyond C.
//   custom:empty-function
//   custom:boolean-equality
//   custom:unreachable-code   (same-line form)
//   custom:commented-out-code
//   custom:duplicate-string-literal

// ---- custom:empty-function ----
function onInit() {}
function noop(a) {}

// ---- custom:boolean-equality ----
function check(ready, done, active) {
  if (ready == true) return 1;
  if (done != false) return 2;
  while (active == false) active = 1;
  return ready != true;
}

// ---- custom:unreachable-code (same-line) ----
function getValue(x) {
  return x + x; logValue(x);
}

// ---- custom:commented-out-code ----
function run(x) {
  // let old = compute(x);
  // old = old + x;
  // cacheStore(old);
  return x;
}

// ---- custom:duplicate-string-literal (distinct literal, 3x) ----
function report(msg) {}
function logEvents(code) {
  report("upload timed out");
  if (code > 0) report("upload timed out");
  report("upload timed out");
}
