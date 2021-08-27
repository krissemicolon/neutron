# neutron
> A 5dbfwmtt interpreter

## Abstract
Like BF, 5D BF With Multiverse Time Travel operates on an array of memory cells initialized to zero. Multiple pointers to memory, and to the program, may coexist in each timeline. The state of the tape is stored as a timeline, allowing programs to rewind time. In addition, programs may create and traverse parallel universes, which are timelines that all execute simultaneously, "below" their parent timeline. Each timeline has its own pointer.
The following graphic demonstrates the behavior of parallel timelines. Note that this does not include time travel, as that would make the graphic impossible to read.

```
main timeline    split
-------------------+---------------------------------------------->
                   |     split      2nd timeline dies
      2nd timeline +-------+-----------X /------------------------>
                           |            / 3rd timeline replaces 2nd
              3rd timeline +-----------/
```

## Syntax
| Instruction |                                        |
|-------------|----------------------------------------|
| `>`         | Move all memory pointers in this timeline 1 cell to the right. |
| `<`         | Move all memory pointers in this timeline pointer 1 cell to the left. |
| `+`         | Increment all cells pointed to in this timeline. |
| `-`         | Decrement all cells pointed to in this timeline. |
| `.`         | Output a character for all cells pointed to in this timeline. |
| `,`         | Input a character and store it in all cells pointed to in this timeline. |
| `[`         | Move this instruction pointer to the matching ] if all cells pointed to in this timeline are 0. If this timeline has no pointers, jump forward. |
| `]`         | Move this instruction pointer back to the matching [ if any cells pointed to in this timeline are nonzero. If this timeline has no pointers, do not jump backward. | 
| `~`         | Rewind the current tape back in time by 1 step. |
| `(`         | Spawn a parallel timeline below the current timeline, with a copy of the tape and all pointers in it. This instruction pointer jumps to the matching ). Spawn a new instruction pointer within the newly spawned timeline, beginning execution immediately after this instruction. |
| `)`         | If this is executed outside of the main timeline, kill this timeline and all the memory/instruction pointers currently in it. Otherwise, do nothing. |
| `v`         | Move all memory pointers in this timeline to the same location in the next ("lower") parallel universe. If a lower timeline does not exist, these pointers are discarded instead. |
| `^`         | Move all memory pointers in this timeline to the same location in the previous ("higher") parallel universe. If a higher timeline does not exist, these pointers are discarded. |
| `@`         | If the next ("lower") parallel universe contains a nonzero amount of memory pointers, freeze this instruction pointer for this turn. If the next parallel universe has no memory pointers, or if this is the "lowest" timeline, do nothing and continue.

## Notes
Notes
It is not necessary for [] and () braces to be matched with each other, as long as each opening brace matches with its own closing brace. This means that [(]) is valid syntax, and so is ([)].
Yes, the language is not strictly five-dimensional.
The ~ instruction will only rewind the tape. That is, it will only undo the effects of +, -, or , instructions. Anything that doesn't manipulate the tape is ignored by ~.

## Examples
Double the amount of pointers in this timeline
```
(^)
```

Rewind time until the current cell is 0
```
[~]
```

Cat, but faster
```
(-^.[.]),[,]
```

Undefined behavior time
```
((+++.)---.)(+-+.)-+-.
```

Two instructional pointers??
```
([)]+
```

