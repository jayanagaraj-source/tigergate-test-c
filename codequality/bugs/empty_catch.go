// RULE: empty-catch | lang: go — truly empty error handler
package bugs
func doThingEC() error { return nil }
func RiskyEC() {
	if err := doThingEC(); err != nil {
	}
}
