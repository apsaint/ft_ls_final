#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int ptr = 2;
	int a, b;

	ft_printf("eiwojoeDowdkopqwkdpoqwkwopkdqpodkwqpok\n");

	ft_printf("%*.*s\n", 10, 4, "toto aime les banannes");
	printf("%*.*s\n", 10, 4, "toto aime les banannes");

	ft_printf("%.10f\n", 0.000456789);
	printf("%.10f\n", 0.000456789);

	a = ft_printf("%f\n", 12.00345);
	b = printf("%f\n", 12.00345);

	a = ft_printf("%.2f\n", 12.00345);
	b = printf("%.2f\n", 12.00345);

	a = ft_printf("%.20f\n", 12.00345);
	b = printf("%.20f\n", 12.00345);

	ft_printf("i (-347): %i\n", -347);
	printf("exp: %i\n\n", -347);

	ft_printf(".i (-347): %.i\n", -347);
	printf("exp: %.i\n\n", -347);

	ft_printf("-6i (-347): %-6iENDPADDING\n", -347);
	printf("exp: %-6iENDPADDING\n\n", -347);

	ft_printf("-06i (-347): %-06iENDPADDING\n", -347);
	printf("exp: %-06iENDPADDING\n\n", -347);

	ft_printf("6i (347): %6i\n", 347);
	printf("exp: %6i\n\n", 347);

	ft_printf("06i (347): %06i\n", 347);
	printf("exp: %06i\n\n", 347);

	ft_printf("i (320): %i\n", 320);
	printf("exp : %i\n\n", 320);

	ft_printf("hhi (120): %hhi\n", 120);
	printf("exp : 120\n\n");

	ft_printf("u (32727U): %u\n", 32727U);
	printf("exp : 32727\n\n");

	ft_printf("llu (48329439048390491ULL): %llu\n", 48329439048390491ULL);
	printf("exp : 48329439048390491\n\n");

	ft_printf("hhi (260 overflowed): %hhi\n", 260);
	printf("exp : %hhi\n\n", 260);

	ft_printf("10.5u (37U): %10.5u\n", 37U);
	printf("exp: %10.5u\n\n", 37U);

	ft_printf(".5u (37U): %.5u\n", 37U);
	printf("exp: %.5u\n\n", 37U);

	ft_printf("x (47U): %x\n", 47U);
	printf("exp: %x\n\n", 47U);

	ft_printf("x (0U): %x\n", 0U);
	printf("exp: %x\n\n", 0U);

	ft_printf("5.2x (47U): %5.2x\n", 5427U);
	printf("exp: %5.2x\n\n", 5427U);

	ft_printf("#x (47U): %#x\n", 47U);
	printf("exp: %#x\n\n", 47U);

	ft_printf("#X (47U): %#X\n", 47U);
	printf("exp: %#X\n\n", 47U);

	a = ft_printf("p (ptr): %p\n", &ptr);
	b = printf("exp: %p\n\n", &ptr);

	a = ft_printf("%p\n", 0);
	b = printf("%p\n", 0);

	a = ft_printf("%.2p %.2p\n", 0, 0);
	b = printf("%2.p %.2p\n", 0, 0);

	ft_printf("2.5u (37U): %2.5u\n", 37U);
	printf("exp: %2.5u\n\n", 37U);

	ft_printf(".1u (37U): %.1u\n", 37U);
	printf("exp: %.1u\n\n", 37U);

	ft_printf("o (37U): %o\n", 37U);
	printf("exp: %o\n\n", 37U);

	ft_printf("#o (37U): %#o\n", 37U);
	printf("exp: %#o\n\n", 37U);

	ft_printf("#o (37U): %#o\n", 37U);
	printf("exp: %#o\n\n", 37U);

	ft_printf("s: %s\n", "toto aime les grecs");
	printf("exp: %s\n\n", "toto aime les grecs");

	ft_printf(".6s: %.6s\n", "toto aime les grecs");
	printf("exp: %.6s\n\n", "toto aime les grecs");

	ft_printf(".s: %.s\n", "toto aime les grecs");
	printf("exp: %.s\n\n", "toto aime les grecs");

	ft_printf(".-6s: %.-6s\n", "toto aime les grecs");
	printf("exp: %.-6s\n\n", "toto aime les grecs");

	ft_printf("% #04i %.30s", 42, "toto\n");
	printf("%# 04i %.30s", 42, "toto\n");

	ft_printf("%+12.7f %.0s\n", 42.545543, "toto");
	printf("%+12.7f %.0s\n", 42.545543, "toto");

	ft_printf("f (33.123456789): %f\n", 33.123456789);
	printf("exp: %f\n\n", 33.123456789);

	ft_printf(".0f (33.123456789): %.0f\n", 33.123456789);
	printf("exp: %.0f\n\n", 33.123456789);

	ft_printf("#.0f (33.123456789): %#.0fE\n", 33.123456789);
	printf("exp: %#.0fE\n\n", 33.123456789);

	ft_printf("#-20fE (33.123456789): %#-20fE\n", 33.123456789);
	printf("exp: %#-20fE\n\n", 33.123456789);

	ft_printf("#-20fE (33.123456789): %#-20fE\n", -33.123456789);
	printf("exp: %#-20fE\n\n", -33.123456789);

	ft_printf("#-020f (33.123456789): %#-020fE\n", 33.123456789);
	printf("exp: %#-020fE\n\n", 33.123456789);

	ft_printf("fE (0.0): %fE\n", 0.0);
	printf("exp: %fE\n\n", 0.0);

	ft_printf("#-020fE (33.123456789): %#-020fE\n", -33.123456789);
	printf("exp: %#-020fE\n\n", -33.123456789);

	ft_printf("#-20.15fE (33.123456789): %#-20.15fE\n", -33.123456789);
	printf("exp: %#-20.15fE\n\n", -33.123456789);

	ft_printf("f (-33.123456789): %f\n", -33.123456789);
	printf("exp: %f\n\n", -33.123456789);

	ft_printf(".2f (33.255): %.2f\n", 33.255);
	printf("exp: %.2f\n\n", 33.255);

	ft_printf(" .2f (33.255): % .2f\n", 33.255);
	printf("exp: % .2f\n\n", 33.255);

	ft_printf("c (f): %c\n", 'f');
	printf("exp: %c\n\n", 'f');

	ft_printf("%% (f): %%\n");
	printf("exp: %%\n\n");

	ft_printf("pos ull: %LLu lorrem ipsum\n", 48329439048390491ULL);
	printf("no segfault\n\n");

	ft_printf("%jx\n", 4294967295);
	printf("%jx\n", 4294967295);

	ft_printf("%ji\n", 4294967295);
	printf("%ji\n", 4294967295);

	ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);

	// zeros
	ft_printf("#x (0U): %#x\n", 0U);
	printf("exp: %#x\n\n", 0U);
	ft_printf("i (0): %i\n", 0);
	printf("exp: %#i\n\n", 0);
	ft_printf("#f (0.0): %f\n", 0.0);
	printf("exp: %f\n\n", 0U);

	ft_printf("%15u\n", 4294967295);
	printf("%15u\n", 4294967295);

	ft_printf("%d\n", 2147483648);
	printf("%d\n", 2147483648);


	ft_printf("%+u\n", 4294967295);
	ft_printf("%ju\n", 4294967296);
	int toto = 1;
	ft_printf("%#p\n", &toto);
	printf("%#p\n", &toto);	

	ft_printf("%10s is a string\n", "this");
	return (0);
}