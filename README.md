## Srish

This is Srijan's Shell, `srish`. This project is to understand what shells do and how one can learn from that and try to create our own basic shell.
In the spirit of understanding shells, I will be doing this all on the terminal, using bash and vim.
Compile using `gcc -o srish srish.c -Wall -Werror`

### The shell has two modes; batch mode and interactive mode.

Batch mode is basically executing commands via the shell without jumping into shell mode. E.g. `./srish ls -al` on your favourite linux based terminal.

Interactive mode is what we are used to seeing when we start a shell. A prompt `srish> ` is shown, which handles all the binary request.

Exit using `exit`.

---

For now, the shell doesnt implement `cd`. I would advice not to add this shell to your bin since, apparently, `access()` is not really that secure.
