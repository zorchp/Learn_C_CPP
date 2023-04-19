#include <stdio.h>
#include <time.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat sb;
    if (stat("data", &sb) == -1) fprintf(stderr, "stat-error");
    printf("size=%ld\n", sb.st_size);
    printf("mode=%u\n", sb.st_mode);
    printf("uid=%u\n", sb.st_uid);
    printf("gid=%u\n", sb.st_gid);
    printf("hard link number=%ld\n", sb.st_nlink);
    putchar('\n');
    printf("dev-id=%ld\n",sb.st_dev);
    printf("rdev-id=%ld\n", sb.st_rdev);
    printf("i-node=%ld\n", sb.st_ino);
    printf("block-size=%ld\n", sb.st_blksize);
    printf("blocks=%ld\n", sb.st_blocks);
    putchar('\n');
    printf("last access time=%s", ctime(&sb.st_atime));
    printf("last modify time=%s", ctime(&sb.st_mtime));
    printf("last status change time=%s\n", ctime(&sb.st_ctime));
    return 0;
}
/* size=10 */
/* mode=33152 */
/* uid=1001 */
/* gid=1001 */
/* hard link number=1 */
/*  */
/* dev-id=64513 */
/* rdev-id=0 */
/* i-node=1212099 */
/* block-size=4096 */
/* blocks=8 */
/*  */
/* last access time=Thu Feb  9 17:42:47 2023 */
/* last modify time=Sun Feb  5 01:19:56 2023 */
/* last status change time=Sun Feb  5 01:19:56 2023 */


