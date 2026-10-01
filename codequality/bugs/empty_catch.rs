// RULE: empty-catch | lang: rust — empty error handling (multiple idioms)
fn might_fail() -> Result<(), String> { Err("x".into()) }

pub fn risky() {
    // empty Err arm
    match might_fail() {
        Ok(_) => {}
        Err(_) => {}
    }
    // empty if-let error handler
    if let Err(_) = might_fail() {
    }
    // empty panic catch
    let _ = std::panic::catch_unwind(|| {});
}
