# Before the vibes

> **Still missing: the finished word search.** It was our group's final project, and I built the finished version on my own in 2014, writing much of it in a text editor at work and debugging it at home. I searched my mailbox and my computers in November 2026. The only copy I can find is the unfinished snapshot from February 6, 2014, which is in this repo and does not work. The ending of that project is missing. If it turns up, it will be added with its source and date.

C coursework from two intro courses I took in 2013 and 2014. This archive includes my individual assignments and shared group projects, bugs included.

I use AI to build software now. This repo exists so you can see what I could do before that, and how rough it was. It is not a portfolio of engineering work.

## The files

| File | What it does | Status today | Known problems |
|---|---|---|---|
| `originals/roman numerals.c` | Converts a number to a Roman numeral | Correct. I tested every number from 1 to 1000 against a reference and found no errors | Accepts 0 and prints nothing. Loops forever on non-numeric input |
| `originals/stringsAssignment.c` | Reverses, measures and prints a string vertically and as a triangle | Works for normal strings. Windows-only (`scanf_s`) | The triangle reads past the end of the string. Overflows on a very long string |
| `originals/structs.c` | Reads and prints a person record using structs | Works on normal input | Unbounded `scanf("%s")`. Two output labels are wrong |
| `originals/wordSearchProjectSoFar.c` | An unfinished draft of a word-search generator, "what I got so far" from February 2014. The word search was our group's final project; this is the part I built on my own | **Does not work.** It hangs | A `=` where a `==` belongs puts it in an infinite loop. Seven of eight direction functions are empty |
| `group-work-names-redacted/*` | Group assignments and a small game, with other people's names removed | Run on Windows with a shim | See `ASSESSMENT.md` |

## What this is not

- Not evidence of professional engineering. There are no tests, no version control, and no sign of working at scale.
- Not portable. Most of it uses Windows habits like `system("pause")`, `fflush(stdin)` and `scanf_s`.
- Not the finished word search. It was a group project, and I built the finished version on my own in 2014, before my groupmates and I could really collaborate. I wrote much of it in a text editor at work and debugged it at home. **That finished version has not been found.** The draft in this repo is a snapshot from partway through. Everything about the finished version is my own account and nothing here documents it.

## What it does show

Honest answer, from a line-by-line review: small named functions from the first file and increasing use of structs and pointers across the assignments. The shared drinking game includes a menu, a sort and a formula. That is curiosity and follow-through. Read `ASSESSMENT.md` for the bugs and the limits.

## Files you should know about

- `PROVENANCE.md` where the files came from and what was and wasn't checked.
- `ASSESSMENT.md` an unflattered review, written in November 2026.
- `group-work-names-redacted/REDACTIONS.md` exactly what I redacted and why.
- `reconstructions-2026/` empty. Any future fix goes there, labeled as new work.

## About the group files

These files were submitted by groups of three and four classmates. They're shared work. I don't have reliable records showing who contributed which lines.

I remember doing substantial coding on some assignments, but that's my recollection. The files don't independently establish each person's contribution, and similar coding habits can't settle that.

The drinking game had a three-person team in its header. The tally project (`GroupProjectComplete.c` and its earlier draft) was credited to four people. A diff shows what changed between the tally versions, not who typed it.

The word search is the exception to read carefully. It was a group assignment, but I built it on my own, impulsively, before collaboration was really possible for the team. That is my account, and the draft in `originals/` is the only part that survives.

If any former teammates remember things differently or have files to add, I'd welcome their perspective. Names stay private unless the people involved agree to be identified.

Names and assignment details are removed from those files. `group-work-names-redacted/REDACTIONS.md` lists exactly which lines changed.

## Content note

`group-work-names-redacted/drinkingGame.c` is a student-era drinking game. One profane output line is redacted in this public copy; the change is recorded in `group-work-names-redacted/REDACTIONS.md`. Its alcohol calculation is wrong and mustn't be used as guidance.

## License

The four files in `originals/` are MIT licensed. The group files are shown for reference and carry no license.
