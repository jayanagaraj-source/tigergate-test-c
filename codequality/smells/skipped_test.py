# RULE: skipped-test | lang: python
import pytest
@pytest.mark.skip(reason="disabled test")
def test_feature():
    assert True
