#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	//varibles
	int c, i, j;
	int flag;
	int fread_size;
	unsigned char times_read;
	unsigned char size_read;
	unsigned char char_buf[257];
	int int_buf[256];
	double dbl_buf[256];

	//init flag
	flag = 0;

	while ((c = getchar()) != EOF) {
		switch (c) {
		case 'n':
			printf("\n");
			flag = 0;
			break;
		case 's':
			//read count
			times_read = getchar();
			//check space printing
			if (flag > 0) { printf(" "); }
			flag = 1;
			//print
			for (i = 0; i < (int)times_read + 1; i++) {
				size_read = getchar();
				fread_size = fread(char_buf, 1, (int)size_read + 1, stdin);
				//error catch
				if (fread_size != (int)size_read + 1) {
					if ((int)size_read == 255) {
						fprintf(stderr, "Input error: no string size\n");
						exit(1);
					}
					fprintf(stderr, "Input error: not enough chars\n");
					exit(1);
				}
				for (j = 0; j < (int)size_read + 1; j++) { printf("%c", char_buf[j]); }
				if (i != (int)times_read) { printf(" "); }
			}
			break;
		case 'i':
			//read count and bytes
			times_read = getchar();
			fread_size = fread(int_buf, 4, (int)times_read + 1, stdin);
			//error catch
			if (fread_size != (int)times_read + 1) {
				fprintf(stderr, "Input error: not enough ints\n");
				exit(1);
			}
			//check space printing
			if (flag > 0) { printf(" "); }
			flag = 1;
			//print
			for (i = 0; i < (int)times_read + 1; i++) {
				printf("%d", int_buf[i]);
				if (i != (int)times_read) { printf(" "); }
			}
			break;
		case 'd':
			//read count and bytes
			times_read = getchar();
			fread_size = fread(dbl_buf, 8, (int)times_read + 1, stdin);
			//error catch
			if (fread_size != (int)times_read + 1) {
				fprintf(stderr, "Input error: not enough doubles\n");
				exit(1);
			}
			//check space printing
			if (flag > 0) { printf(" "); }
			flag = 1;
			//print
			for (i = 0; i < (int)times_read + 1; i++) {
				printf("%.10lg", dbl_buf[i]);
				if (i != (int)times_read) { printf(" "); }
			}
			break;
		default:
			fprintf(stderr, "Input error: bad type\n");
			exit(1);
			break;
		}
	}
	exit(0);
}