from __future__ import annotations

import signal_processing as m

print(m.add(3, 3))
m.plot()
m.hello()


def test_version():
    assert m.__version__ == "0.0.1"


def test_add():
    assert m.add(1, 2) == 3


def test_sub():
    assert m.subtract(1, 2) == -1