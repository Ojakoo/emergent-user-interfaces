# These values should ALWAYS match the STATE enum in Arduino/main.ino

__all__ = [
    "IDLE",
    "START",
]

IDLE = 0
START = 1

SAMPLING_RATE = 80  # samples per second
# Buffer shape:
# dstream: [data1, data2, ...], len: BUFFER_LEN
BUFFER_LEN_SEC = 2  # buffer length in seconds
BUFFER_LEN = SAMPLING_RATE * BUFFER_LEN_SEC  # buffer length in samples

FILTER_CUTOFF = 8  # low-pass cut off frequency in Hz
