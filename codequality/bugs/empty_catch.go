// RULE: empty-catch (MEDIUM) | lang: go
package bugs
func doThing() error { return nil }
func Risky(){
	if err := doThing(); err != nil {
		// empty error handler: swallowed
	}
}
