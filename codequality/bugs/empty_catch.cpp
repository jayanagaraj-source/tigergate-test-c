// RULE: empty-catch | lang: cpp — empty catch (specific + generic)
#include <stdexcept>
void mightThrow();
void risky() {
  try { mightThrow(); } catch (const std::runtime_error& e) {}
  try { mightThrow(); } catch (...) {}
}
