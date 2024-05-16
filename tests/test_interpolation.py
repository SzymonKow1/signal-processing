from __future__ import annotations

import signal_processing as m


print("Choose width, heigth & file")
m.bilinear_interpolation(int(input()), int(input()), ("../res/" + input())) 
