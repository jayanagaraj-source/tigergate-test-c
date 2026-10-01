// RULE: console-debug | lang: typescript
export function handle(x: number): number {
  console.log("debug", x);
  console.debug("trace", x);
  console.info("info", x);
  return x;
}
