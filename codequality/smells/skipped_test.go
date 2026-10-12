// RULE: skipped-test | lang: go
package smells
import "testing"
func TestSkipped(t *testing.T) {
	t.Skip("disabled test")
}
