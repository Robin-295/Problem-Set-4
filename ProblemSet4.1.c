#include <stdio.h>
#include <stdlib.h>

char pixels[200]; // Store the pixel information from "pixels.txt"
char compressed[200]; // Store the compressed pixel information

int read(void);
int  write(void);
void encode(void);

int main(){
  if(read() == 1) return 1;
  encode();
  if(write() == 1) return 1;

  return 0;
}

int read(void){
  FILE *readFile;
  readFile = fopen("pixels.txt", "r");

  if(readFile == NULL){
    printf("File cannot be opened or does not exist.\n");
    return 1; //Return error
  }

  // Copy the content of file to array
  int count = 0;
  char c;
  while((c = fgetc(readFile)) != EOF){
    pixels[count++] = c;
  }

  pixels[count] = '\0';

  //Close opened file
  if(readFile) fclose(readFile);
  return 0;
}

int write(void){
  FILE *writeFile;
  writeFile = fopen("compressed.txt", "w");

  if(writeFile == NULL){
    printf("File cannot be opened or does not exist.\n");
    return 1; //Return error
  }

  char c;
  int i = 0;
  while((c = compressed[i++]) != '\0'){
    fputc(c, writeFile);
  }

  if(writeFile) fclose(writeFile);
  return 0;
}

void encode(void){

	int count; // used to count occurrence of a char
	int p = 0; // current position in compressed[]

	for (int i = 0; pixels[i]; i++)
	{
		// count occurrences of current character in pixels[]
		count = 1;
		while (pixels[i] == pixels[i + 1])
			count++, i++;

		// puts count and current character into compressed[]
		compressed[p] = itoa(count); p=++;
		compressed[p] = pixels[i]; p++;
	}

	compressed[p] = '\0'; // make sure compressed string ends in null
	return 0;
}


}