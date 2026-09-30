// RULE: empty-catch (MEDIUM) | lang: rust
fn might_fail() -> Result<(),String> { Err("x".into()) }
pub fn risky(){
    match might_fail() {
        Ok(_) => {}
        Err(_) => {} // empty error arm: swallowed
    }
}
