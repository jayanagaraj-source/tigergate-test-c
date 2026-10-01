// RULE: swallowed-error | lang: go — error explicitly discarded
package bugs
import "errors"
func doThingSE() error { return errors.New("boom") }
func computeSE() (int, error) { return 0, errors.New("x") }
func RunSE() int {
	err := doThingSE()
	_ = err
	result, _ := computeSE()
	return result
}
