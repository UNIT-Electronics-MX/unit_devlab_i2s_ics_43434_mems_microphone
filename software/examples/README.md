# Software Examples — UE0149 I²S ICS-43434

The Arduino sketches follow one layout:

```text
i2s/
├── README.md
└── cpp_examples/
    ├── AudioInputBasicRead/
    │   ├── AudioInputBasicRead.ino
    │   └── README.md
    └── LegacySerialPlotter/
        ├── LegacySerialPlotter.ino
        └── README.md
```

Each sketch is in its own directory, and its `.ino` filename matches
the directory name so Arduino IDE can open it directly.

| Example | Purpose | Output |
|---|---|---|
| [AudioInputBasicRead](i2s/cpp_examples/AudioInputBasicRead/README.md) | Capture I²S through DevLab_AudioInput | PCM16 peak as text, 115200 baud |
| [LegacySerialPlotter](i2s/cpp_examples/LegacySerialPlotter/README.md) | Capture through the older ESP32 driver | Shifted sample average as text, 115200 baud |

Start with [I²S wiring and setup](i2s/README.md). The complete
procedure and library example are also in
[Board Operation](../../tools/product-reference/chapters/05-board-operation.md).
