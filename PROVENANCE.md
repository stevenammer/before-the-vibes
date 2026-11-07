# Provenance

## Where the files came from

Each file is an attachment I emailed to myself or a teammate in 2013 and 2014 while taking two intro C courses. I recovered them from my own mailbox in November 2026. I am not publishing message links or my address.

The word-search file is a snapshot from February 6, 2014, sent with the note "This is what I got so far". The finished version was not recovered.

## What was checked

- Every file's length and SHA-256 match the manifest of the archive I was handed. That archive was compiled by an AI assistant from my mailbox. A manifest made by the same process is consistent with itself but is not an independent check against the mailbox, and I am saying so.
- The four files in `originals/` are byte for byte what came out of the archive. They use Windows line endings. A stray `5` at the very end of `roman numerals.c`, inside a comment, is original and harmless. I left it.
- The diff between the two versions of the group project reproduces the final file exactly. A diff can show what changed. It cannot show who typed it.

## What was not checked

- I did not independently re-verify the files against the original email attachments.
- The searches for the finished word search (mail, drives, old folders) came back empty. That does not prove it no longer exists.

## What was left out or changed, and why

- Other students are named in the headers of the group files. Their names, the assignment details and one profane output line are redacted in `group-work-names-redacted/`. See `REDACTIONS.md` for the exact lines and the hash of each original.
- Private records tied to my enrollment are not part of this repo.

## A rule for this repo

The originals are never edited. If I fix or rebuild something, it goes in `reconstructions-2026/` with a header saying it is new 2026 work.
