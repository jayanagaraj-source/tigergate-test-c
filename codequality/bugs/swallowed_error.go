// RULE: swallowed-error (MEDIUM) | lang: go
package bugs
import "errors"
func compute()(int,error){ return 0, errors.New("boom") }
func Run() int {
	result, _ := compute() // error assigned to _ and discarded
	return result
}
