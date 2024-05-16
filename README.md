# signal-processing

[![Gitter][gitter-badge]][gitter-link]

|      CI              | status |
|----------------------|--------|
| conda.recipe         | [![Conda Actions Status][actions-conda-badge]][actions-conda-link] |
| pip builds           | [![Pip Actions Status][actions-pip-badge]][actions-pip-link] |


An example project built with [pybind11][] and [scikit-build-core][]. Python
3.7+ (see older commits for older versions of Python using [scikit-build (classic)][]).


[gitter-badge]:            https://badges.gitter.im/pybind/Lobby.svg
[gitter-link]:             https://gitter.im/pybind/Lobby
[actions-badge]:           https://github.com/pybind/scikit_build_example/workflows/Tests/badge.svg
[actions-conda-link]:      https://github.com/pybind/scikit_build_example/actions?query=workflow%3AConda
[actions-conda-badge]:     https://github.com/pybind/scikit_build_example/workflows/Conda/badge.svg
[actions-pip-link]:        https://github.com/pybind/scikit_build_example/actions?query=workflow%3APip
[actions-pip-badge]:       https://github.com/pybind/scikit_build_example/workflows/Pip/badge.svg
[actions-wheels-link]:     https://github.com/pybind/scikit_build_example/actions?query=workflow%3AWheels
[actions-wheels-badge]:    https://github.com/pybind/scikit_build_example/workflows/Wheels/badge.svg

Funkcjonalności:

Wizualizacja sygnału z wykorzystaniem biblioteki matplotplusplus
Filtracja 1D i 2D
Generowanie sygnałów o zadanej częstotliwości (sin, cos, prostokątny, piłokształtny)
Interpolacja dwuliniowa na siatce


linki:

Pliki audio
https://github.com/adamstark/AudioFile
https://github.com/adamstark/AudioFile/blob/master/examples/CMakeLists.txt

Pybind dokumentacja
https://pybind11.readthedocs.io/en/latest/index.html#

Notatki:
zeby dodac nowa funkcje do pythona nalezy napisac w binder.cpp nowy moduł i uzupełnic 
from ._core import __doc__, __version__,
__all__ = ["__doc__", "__version__", "plot"]
o nazwy dodanych funkcji 
instalacja w minicondzie: python -m pip install . -vv w terminalu w katalogu signal-processing 

