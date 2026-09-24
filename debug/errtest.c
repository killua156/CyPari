#include <pari/pari.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
  pari_init(8000000, 0);
  pari_CATCH(CATCH_ALL) {
    char *s = pari_err2str(pari_err_last());
    printf("err2str=[%s] strlen=%zu\n", s, strlen(s));
  } pari_TRY {
    gp_read_str("pi()");
  } pari_ENDCATCH;
  char *d = pari_strdup("not a function in function call");
  printf("strdup=[%s] strlen=%zu\n", d, strlen(d));
  pari_close();
  return 0;
}
