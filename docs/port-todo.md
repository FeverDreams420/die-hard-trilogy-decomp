# Port to-do

Places where the matching C uses a fake (inline asm, register pin or barrier)
that a native port has to rewrite. Each one carries a `// FAKE:` comment in
the source.

| Fake | Where | What the port does |
| --- | --- | --- |
| `GET_RA(var)` (`include/common.h`): `sw $31` into a global | DH3 `func_80072A40`, `func_800724C4`; DH2 `func_800735F8`, `func_8007307C` | Remove the line. It records the caller's return address, probably for debugging; nothing reads it for game logic as far as known. |
| `TRAP()` (`include/common.h`): bare `break 7` debug trap | DH2 `func_80034154` | Replace with `abort()` (or a logged assertion). It fires when a task's next-step pointer is already the value in `D_800B7350`, which looks like a sanity check that never triggers in normal play. |
