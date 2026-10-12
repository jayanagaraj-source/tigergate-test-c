// RULE: empty-catch | lang: go — empty error / recover handlers (multiple idioms)
package bugs

func doThingEC() error { return nil }

func RiskyEC() {
	// empty error-handling block
	if err := doThingEC(); err != nil {
	}
	// empty recover (Go's panic "catch")
	defer func() {
		recover()
	}()
	// empty recover, blank-assigned
	defer func() {
		_ = recover()
	}()
}
