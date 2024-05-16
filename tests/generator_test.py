from __future__ import annotations

import signal_processing as m

print("Choose a function (sin, cos, square, sawtooth): ")
function_choice = input()

if function_choice == "sin":
    print("Duration of signal (s) and frequency(Hz):")
    m.sinusoidalSignal(float(input()), float(input())) 

elif function_choice == "cos":
    print("Duration of signal (s) and frequency(Hz):")
    m.cosinusoidalSignal(float(input()), float(input())) 

elif function_choice == "square":
    print("Duration of signal (s) and frequency(Hz):")
    m.squareWaveSignal(float(input()), float(input())) 

elif function_choice == "sawtooth":
    print("Duration of signal (s) and frequency(Hz):")
    m.sawtoothWaveSignal(float(input()), float(input()))