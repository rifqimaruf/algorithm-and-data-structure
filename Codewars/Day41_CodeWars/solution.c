#include <stdio.h>
#include <stdlib.h>

char *repeat_str(size_t count, const char *src) {
  if (src == NULL) return NULL; // Handle kasus input NULL
  size_t src_len = strlen(src);
  size_t total_len = src_len * count + 1;

  char *result = (char *)malloc(total_len);
  if (result == NULL) return NULL; // Handle kegagalan alokasi memori

  for (size_t i = 0; i < count; i++) {
    strcpy(result + i * src_len, src);
  }

  result[total_len - 1] = '\0';
  return result;
}

int main()
{
    char str[100];
    size_t count;

    printf("Enter a string to repeat: ");
    scanf("%s", str);

    printf("Enter number of repeatation: ");
    scanf("%zu", &count);

    char *result = repeat_str(count, str);
    printf("Result: %s\n", result);
    free(result);

    return 0;

}