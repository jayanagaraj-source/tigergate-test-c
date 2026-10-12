<?php
// RULE: empty-catch | lang: php — empty catch (specific + generic)
function risky() {
    try { doThing(); } catch (RuntimeException $e) {}
    try { doThing(); } catch (Exception $e) {}
}
