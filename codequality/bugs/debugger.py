# RULE: debugger-statement (HIGH) | lang: python
import pdb
def process(d):
    breakpoint()      # debugger breakpoint left in code
    pdb.set_trace()   # debugger breakpoint left in code
    return d*2
