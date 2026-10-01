// RULE: empty-catch | lang: rust — empty error arm
fn might_fail() -> Result<(), String> { Err("x".into()) }
pub fn risky() {
    match might_fail() {
        Ok(_) => {}
        Err(_) => {}
    }
}
