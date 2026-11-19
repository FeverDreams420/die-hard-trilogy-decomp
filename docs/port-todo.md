# Port to-do

Places where the matching C uses a fake (inline asm, register pin or barrier)
that a native port has to rewrite. Each one carries a `// FAKE:` comment in
the source.

| Fake | Where | What the port does |
| --- | --- | --- |
| `GET_RA(var)` (`include/common.h`): `sw $31` into a global | DH3 `func_80072A40`, `func_800724C4`; DH2 `func_800735F8`, `func_8007307C` | Remove the line. It records the caller's return address, probably for debugging; nothing reads it for game logic as far as known. |
| `TRAP()` (`include/common.h`): bare `break 7` debug trap | DH2 (44): `func_8001E6EC`, `func_8001E890`, `func_80020444`, `func_80020560`, `func_8002087C`, `func_8002318C`, `func_8002359C`, `func_8002378C`, `func_80023858`, `func_80023A68`, `func_80023AC0`, `func_80023DA0`, `func_80024124`, `func_80033F74`, `func_80034154`, `func_80034A18`, `func_80034BA0`, `func_8003CCC0`, `func_8003CD9C`, `func_8003CE70`, `func_8003D10C`, `func_8003D8D4`, `func_8003DAC4`, `func_8004265C`, `func_80046224`, `func_80046498`, `func_8004F9B4`, `func_80051820`, `func_80051B9C`, `func_8005472C`, `func_80056DD4`, `func_80057220`, `func_80057660`, `func_80059440`, `func_8005A9B0`, `func_8005D474`, `func_80062BD0`, `func_800643F0`, `func_800645A8`, `func_80069474`, `func_8006A474`, `func_8006DD40`, `func_8006E740`, `func_80070C08` | Replace with `abort()` (or a logged assertion). It fires when a task's next-step pointer is already the value in `D_800B7350`, which looks like a sanity check that never triggers in normal play. |
