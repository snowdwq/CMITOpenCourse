#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define FILEPATH "/home/alexis/CMITOpenCourse/Lecture11/testFile.bin"
#define NUMINTS  (1000)
#define FILESIZE (NUMINTS * sizeof(int))

int main(void)
{
    int fd;
    int result;

    /* Open a file for writing.
     *  - Creating the file if it doesn't exist.
     *  - Truncating it to 0 size if it already exists. (not really needed)
     *
     * Note: "O_WRONLY" mode is not sufficient when mmaping.
     */
    fd = open(FILEPATH, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
    if (fd == -1) {
	perror("Error opening file for writing");
	exit(EXIT_FAILURE);
    }

    /* Stretch the file size to the size of the (mmapped) array of ints
     */
    result = lseek(fd, FILESIZE-1, SEEK_SET);
    if (result == -1) {
	close(fd);
	perror("Error calling lseek() to 'stretch' the file");
	exit(EXIT_FAILURE);
    }

     /* Something needs to be written at the end of the file to
     * have the file actually have the new size.
     * Just writing an empty string at the current file position will do.
     *
     * Note:
     *  - The current position in the file is at the end of the stretched
     *    file due to the call to lseek().
     *  - An empty string is actually a single '\0' character, so a zero-byte
     *    will be written at the last byte of the file.
     */
    result = write(fd, "", 1);
    if (result != 1) {
	close(fd);
	perror("Error writing last byte of the file");
	exit(EXIT_FAILURE);
    }

    char* buffer = malloc(FILESIZE);
    result = read(fd, buffer, FILESIZE);
    if (result == -1) {
	close(fd);
	perror("Error reading from file");
	exit(EXIT_FAILURE);
    }

    unsigned int i;
    unsigned int countZeros = 0;

    for(i = 0; i < FILESIZE; i++)
    {
        if(buffer[i] == '\0')
        {
            countZeros++;
        }
    }

    printf("%d", countZeros);

    int l = 1 << 12;

    printf("\n%d\n%lu", l, sizeof(unsigned int));

    close(fd);
    return 0;
}
