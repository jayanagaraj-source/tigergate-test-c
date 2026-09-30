<?php
// RULE: empty-catch (MEDIUM) | lang: php
function risky(){
    try { doThing(); }
    catch (Exception $e) { /* empty catch: swallowed */ }
}
