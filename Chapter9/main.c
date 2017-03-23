/*
 * to flush the buffer, write writes it to stdout, or whatever file descriptor it receives
 * read accepts a file descriptor and fills a buffer with n bytes from the file.
 * write accepts a file descriptor and takes n bytes from the buffer and writes them to a file
 * read fills a buffer from a file, write flushes a buffer to a file
 * *fp->ptr++ gets ptr, dereferences it, then increments it
 * to flush a buffer you write the bytes from the location of the pointer to the base, then
 * set the pointer to the base.
 * fillbuf and flushbuf both increment the pointer and decrement the count associated with
 * the buffer, fillbuf increments the pointer to signal the next character to get, flushbuf
 * increments the pointer to signal the next address to place a character.
 */

/*
 * the Dirent in DIR is the directory entry for itself.  the file descriptor will indicate a
 * location where all of the contents of the file can be found.
 */
