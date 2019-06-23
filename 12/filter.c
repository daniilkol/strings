#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LEN 1234
int compare( const char *a, const char *b )
{
  int i;

  for (i = 0; a[i] && b[i]; i++)
    if (a[i] != b[i])
      return 0;
  if (a[i] || b[i])
    return 0;



  return 1;
}
int filter( const char *a, const char *b, const char *s, const char *t )
{
  FILE *fp1, *fp2;
  char buf[LEN], buf_orig[LEN];
  int kolichestvo = 0, pos, i, len_buf, tmp_len;

  if (!(fp1 = fopen(a, "r")))
    return -1;
  if (!(fp2 = fopen(b, "w")))
    return -1;
  while (fgets(buf, LEN, fp1))
  {
    tmp_len = len_buf = strlen(buf);
    strcpy(buf_orig, buf);
    while ((pos = strcspn(buf, t)) != len_buf && len_buf > 0)
    {
      for (i = pos; i < len_buf - 1; i++)
	buf[i] = buf[i + 1];
      tmp_len--;
    }

    buf[tmp_len - 1] = 0;
    if (!compare(buf, s))
    {
      fprintf(fp2, "%s", buf_orig);
      kolichestvo++;
    }
  }

  if (!feof(fp1))
  {
    fclose(fp1);
    fclose(fp2);
    return -2;
  }

  fclose(fp1);
  fclose(fp2);
  return kolichestvo;
}
