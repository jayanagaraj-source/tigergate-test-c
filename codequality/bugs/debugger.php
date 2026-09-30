<?php
// RULE: debugger-statement (HIGH) | lang: php
function process($d){
    xdebug_break(); // debugger breakpoint left in code
    return $d*2;
}
