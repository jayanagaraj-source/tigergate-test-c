// RULE: empty-catch (MEDIUM) | lang: cpp
#include <stdexcept>
void mightThrow();
void risky(){
  try { mightThrow(); }
  catch (const std::runtime_error& e) { /* empty catch: swallowed */ }
}
