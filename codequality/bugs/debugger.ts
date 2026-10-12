// RULE: debugger-statement (HIGH) | lang: typescript
export function process(d:number):number{
  debugger; // debugger breakpoint left in code
  return d*2;
}
