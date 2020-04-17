#include "stdio.h"
#include "md5.h"

int main(int argc, char* argv[])
{
	if (argc <= 1) return 0;

	const char* data = argv[1];
	size_t len = strlen(data);

	MD5_CTX ctx;
	MD5Init(&ctx);
	MD5Update(&ctx, data, len);
	MD5Final(&ctx);

	for (size_t i = 0; i < 16; i++)
		printf("%02x", ctx.digest[i]);
	printf("\n");

	return 0;
}
