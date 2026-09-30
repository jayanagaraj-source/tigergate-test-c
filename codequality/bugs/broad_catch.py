# RULE: broad-catch (MEDIUM) | lang: python
import logging
def risky():
    try:
        do_thing()
    except Exception as e:      # overly broad exception handler
        logging.error(e)
