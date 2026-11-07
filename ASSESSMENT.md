# An honest assessment of this code

Written in November 2026 from a line-by-line review. I compiled every file with `gcc -Wall -Wextra -std=c11`, ran the ones that were safe to run, and tested the memory behavior with sanitizers. I did not change the originals.

## Bottom line

This is genuine introductory student work: small console programs, mostly Windows-only. One program is correct. One is an unfinished draft that cannot work. The best one has real memory bugs. It says nothing about professional engineering. It does show a motivated beginner who broke problems into functions and finished things.

## Build and run

| File | Builds with plain gcc on Linux | What happened |
|---|---|---|
| `roman numerals.c` | Yes | Correct for every integer from 1 to 1000 (0 errors in 1000 cases). Accepts 0 and prints an empty line. Non-numeric input loops forever |
| `structs.c` | Yes, with warnings | Normal input works. A 300-character name overflows a buffer. Two output labels are copy-pasted wrong |
| `wordSearchProjectSoFar.c` | Yes, with warnings | Hangs. `while (doesItFit = 'N')` is an assignment, so the loop never ends. Seven of the eight direction functions are empty. A 26-letter word overflows a 20-character buffer |
| `stringsAssignment.c` | No (`scanf_s` is Microsoft-only) | Works for normal strings with a shim. The triangle option reads past the end of the string |

The group files (redacted copies) also use `scanf_s`, `system("pause")` and `fflush(stdin)`. I ran them with a small shim that maps those to standard calls.

## Judged against an intro course in 2013

Solid to good, with some standouts.

- **Decomposition is the clear strength.** From the first file there is a block of prototypes and small single-purpose functions. Menus use `switch` inside a loop and pass results back through pointers.
- **Structs and pointers progress across the set.** First parallel arrays, then structs, then an array of heap pointers sorted by swapping pointers instead of copying records (the drinking game).
- **The best program is the drinking game.** It has a menu, a sort, input validation loops and a formula. It also has the most memory bugs.
- **The Roman numeral solver is the only fully verified algorithm.** It is hand-built with range and modulo checks, a little repetitive, and correct.
- **Debugging evidence is thin.** There is a `//Does this work?` comment, some commented-out test code, and two versions of the group project. There are no tests.

## Judged against a plain professional standard

It fails, as any intro code from 2013 would.

- Windows-only habits that make it non-portable.
- Unchecked `scanf` and `malloc`.
- Unbounded string reads in most files. One file uses the bounded form correctly, so the safe pattern had not yet become a habit.
- Macros that hide statements, sentinel `'Y'/'N'` flags, duplicated logic, magic numbers.
- `srand(time(NULL))` called on every pick, which repeats values within a second.
- No tests, no version history in the files, nothing at scale.

## Bugs, by file

**wordSearchProjectSoFar.c.** `=` used instead of `==` in all eight direction checks (lines 94 to 117), so every handler runs every time. Infinite retry loop (line 118). Random ranges off by one (lines 132 to 133). Words copied without a terminator (lines 78 to 85). The grid is never initialized or printed.

**stringsAssignment.c.** The triangle reads past the terminator (lines 120 to 129). `strlen(s) - 1` underflows on an empty string. Non-numeric input loops forever.

**structs.c.** Unbounded `scanf("%s")` on lines 40 and 43. Wrong labels on lines 88 and 89.

**roman numerals.c.** The check at line 111 accepts 0. A failed `scanf` loops forever.

**drinking game (group folder).** Overflows the 1000-slot pointer array at 1002 players. A 300-character name overflows a heap buffer. `free()` on an uninitialized pointer when you quit immediately. The "blood alcohol" number comes from integer division and an extra `* 10`, so it is nonsense. It is a joke program and must not be used as guidance.

## A note on authorship

The group files belong to the teams credited in their original headers: three people for the drinking game and four for the tally project. I remember doing substantial coding on some assignments, but I don't have reliable records showing each person's contribution.

Similar names, formatting and coding habits don't establish authorship. Shared instruction or a class template could explain those similarities. The observations above describe the code, not who deserves credit for particular lines. Former teammates' corrections or additional files are welcome, with their identities kept private unless they agree otherwise.

## What the code does not prove

Professional engineering ability. Testing practice. Version control habits. Scale, security awareness, design review or maintenance. Who wrote which part of a group project. That the finished word search worked.

## What it honestly shows

Curiosity and persistence across months. Comfort breaking a task into small named functions. Exploring menus, sorting and more complex data structures. Learning across the period. Finishing small programs end to end. Willingness to publish work that is rough.

## What a hiring manager should conclude

I would read this as a credential for curiosity and follow-through, not for engineering skill. A decision would rest on what I build now, not on this. I care more that I published it unflattered than about anything in it.
