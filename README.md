# RIO Package

RIO (Robust I/O) is a custom I/O package that automatically handles **short counts** for you when performing Unix read and write operations.

## What Is a Short Count?

A **short count** occurs when a system call like `read()` or `write()` processes **fewer bytes than requested**, *without* it being an error.

Short counts exist because Unix I/O is designed around **streams**, not fixed-size file reads or writes.

When you call:

```c
read(fd, buf, 1024);
the kernel effectively asks:

“How many bytes are available right now?”

It then returns whatever amount is currently available, which could be:

1024 bytes

200 bytes

1 byte

As long as at least 1 byte is returned, the call is considered successful.

Important Notes

👉 A short count is NOT:

End-of-file (EOF)

An error

Your program must be prepared to handle short counts correctly, which is exactly what the RIO package does for you.

