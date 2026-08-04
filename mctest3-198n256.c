#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

/*
 * Compilación:
 * gcc -O3 -march=native -static mctest3-198n256.c -o mctest3-198n256.exe -lgmp
 * Uso:
 * ./mctest3-198n256 <n>
 * Ejemplo para n=0 (k=198):  ./mctest3-198-256n 0
 * Ejemplo para n=1 (k=454):  ./mctest3-198-256n 1
 */

// Paso estándar de Collatz: si es par x/2, si es impar 3x+1
void paso_collatz_estandar(mpz_t x) {
    if (mpz_even_p(x)) {
        mpz_tdiv_q_2exp(x, x, 1); // x = x / 2
    } else {
        mpz_mul_ui(x, x, 3);      // x = 3*x
        mpz_add_ui(x, x, 1);      // x = x + 1
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <n>\n", argv[0]);
        return 1;
    }

    long n_input = atol(argv[1]);
    unsigned long k = 198 + 256 * n_input;

    printf("=== Verificación para n = %ld (k = %lu) ===\n", n_input, k);

    mpz_t Mk, Mk1, estado_k, estado_k1;
    mpz_inits(Mk, Mk1, estado_k, estado_k1, NULL);

    // Mk = 2^k - 1
    mpz_ui_pow_ui(Mk, 2, k);
    mpz_sub_ui(Mk, Mk, 1);

    // Mk1 = 2^(k+1) - 1
    mpz_ui_pow_ui(Mk1, 2, k + 1);
    mpz_sub_ui(Mk1, Mk1, 1);

    mpz_set(estado_k, Mk);
    mpz_set(estado_k1, Mk1);

    // Pasos teóricos en el operador estándar
    unsigned long pasos_k = 2 * k + 13;
    unsigned long pasos_k1 = 2 * k + 14;

    // Iterar Mk por (2k + 13) pasos
    for (unsigned long i = 0; i < pasos_k; i++) {
        paso_collatz_estandar(estado_k);
    }

    // Iterar Mk+1 por (2k + 14) pasos
    for (unsigned long i = 0; i < pasos_k1; i++) {
        paso_collatz_estandar(estado_k1);
    }

    // Calcular el valor teórico mediante la fórmula cerrada: N(k) = (3^(k+4) + 599) / 512
    mpz_t N_teorico, num, denom;
    mpz_inits(N_teorico, num, denom, NULL);

    mpz_ui_pow_ui(num, 3, k + 4);
    mpz_add_ui(num, num, 599);
    mpz_set_ui(denom, 512);

    // Verificación de divisibilidad exactitud
    if (!mpz_divisible_p(num, denom)) {
        printf("ERROR: La fórmula teórica no dio un entero exacto.\n");
        return 1;
    }
    mpz_divexact(N_teorico, num, denom);

    // Comparación de los 3 valores
    int match_trayectorias = (mpz_cmp(estado_k, estado_k1) == 0);
    int match_formula = (mpz_cmp(estado_k, N_teorico) == 0);

    printf("Pasos iterados Mk  (%lu): ", pasos_k);
    gmp_printf("%Zd\n", estado_k);

    printf("Pasos iterados Mk+1 (%lu): ", pasos_k1);
    gmp_printf("%Zd\n", estado_k1);

    printf("Resultado por fórmula cerrada : ");
    gmp_printf("%Zd\n", N_teorico);

    printf("\n--- RESULTADO DE LA VERIFICACIÓN ---\n");
    if (match_trayectorias && match_formula) {
        printf("[OK] La confluencia y la fórmula cerrada coinciden exactamente.\n");
    } else {
        printf("[FALLO] Hay discrepancia entre la simulación y la fórmula.\n");
    }

    mpz_clears(Mk, Mk1, estado_k, estado_k1, N_teorico, num, denom, NULL);
    return 0;
}

