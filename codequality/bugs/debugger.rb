# RULE: debugger-statement (HIGH) | lang: ruby
def process(d)
  binding.pry  # debugger breakpoint left in code
  byebug       # debugger breakpoint left in code
  d*2
end
