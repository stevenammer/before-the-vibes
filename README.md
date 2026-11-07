# Before the vibes

> **Still missing: the finished word search.** I finished it in 2014, writing much of it in a text editor at work and debugging it at home. I searched my mailbox and my computers in November 2026. The only copy I can find is the unfinished snapshot from February 6, 2014, which is in this repo and does not work. The ending of that project is missing. If it turns up, it will be added with its source and date.

Student C programs I wrote in 2013 and 2014 in two intro courses. Published as they were, bugs included.

I use AI to build software now. This repo exists so you can see what I could do before that, and how rough it was. It is not a portfolio of engineering work.

## The files

| File | What it does | Status today | Known problems |
|---|---|---|---|
| `originals/roman numerals.c` | Converts a number to a Roman numeral | Correct. I tested every number from 1 to 1000 against a reference and found no errors | Accepts 0 and prints nothing. Loops forever on non-numeric input |
| `originals/stringsAssignment.c` | Reverses, measures and prints a string vertically and as a triangle | Works for normal strings. Windows-only (`scanf_s`) | The triangle reads past the end of the string. Overflows on a very long string |
| `originals/structs.c` | Reads and prints a person record using structs | Works on normal input | Unbounded `scanf("%s")`. Two output labels are wrong |
| `originals/wordSearchProjectSoFar.c` | An unfinished draft of a word-search generator, "what I got so far" from February 2014 | **Does not work.** It hangs | A `=` where a `==` belongs puts it in an infinite loop. Seven of eight direction functions are empty |
| `group-work-names-redacted/*` | Group assignments and a small game, with other people's names removed | Run on Windows with a shim | See `ASSESSMENT.md` |

## What this is not

- Not evidence of professional engineering. There are no tests, no version control, and no sign of working at scale.
- Not portable. Most of it uses Windows habits like `system("pause")`, `fflush(stdin)` and `scanf_s`.
- Not the finished word search. I finished it independently in 2014, writing much of it in a text editor at work and debugging it at home. **That finished version has not been found.** The draft in this repo is a snapshot from partway through. Everything about the finished version is my own account and nothing here documents it.

## What it does show

Honest answer, from a line-by-line review: someone who splits a problem into small named functions from the first file, keeps building past the assignment (the drinking game has a menu, a sort and a formula nobody asked for), and gets better between 2013 and 2014. That is curiosity and follow-through. Read `ASSESSMENT.md` for the bugs and the limits.

## Files you should know about

- `PROVENANCE.md` where the files came from and what was and wasn't checked.
- `ASSESSMENT.md` an unflattered review, written in November 2026.
- `group-work-names-redacted/REDACTIONS.md` exactly what I redacted and why.
- `reconstructions-2026/` empty. Any future fix goes there, labeled as new work.

## About the group files

`group-work-names-redacted/drinkingGame.c` had a three-person team in its header. My recollection is that I wrote nearly all of it, and I don't remember working closely with others. The code can't settle that. What it does show is one consistent coding style from top to bottom, with the same habits as my solo files, including the same function names (`getChoice`, `displayMenu`). Style is evidence, not proof, and a shared class template could explain some of it, so take my account as my account.

The group tally project (`GroupProjectComplete.c` and its earlier draft) was credited to a group of four. A diff of the two versions shows what changed between them, not who typed it.

Names and assignment details are removed from those files. `group-work-names-redacted/REDACTIONS.md` lists exactly which lines changed.

## Content note

`group-work-names-redacted/drinkingGame.c` is a student-era drinking game. One profane output line is redacted in this public copy; the change is recorded in `group-work-names-redacted/REDACTIONS.md`. Its alcohol calculation is wrong and mustn't be used as guidance.

## License

The four files in `originals/` are MIT licensed. The group files are shown for reference and carry no license.
