https://doi.org/10.5281/zenodo.21780683
# Deterministic Collatz Confluence for Mersenne Numbers ($k \equiv 30 \pmod{64}$)

Este repositorio contiene la demostración formal y el script de verificación computacional para la colisión determinista en trayectorias de Collatz entre números de Mersenne adyacentes $M_k = 2^k - 1$ y $M_{k+1} = 2^{k+1} - 1$ para $k \equiv 30 \pmod{64}$.

---

## 📌 Teorema Principal

Para todo $k \equiv 30 \pmod{64}$, las secuencias de Collatz de $M_k$ y $M_{k+1}$ confluyen exactamente en un nodo común expresado en forma cerrada por:

$$N(k) = \frac{3^{k+3} + 125}{128}$$

* **Pasos en operador estándar:**
  * $M_k$ alcanza el nodo en $2k + 10$ pasos.
  * $M_{k+1}$ alcanza el nodo en $2k + 11$ pasos.

---

## 📊 Patrones Observados (Familias de Semillas)

Análisis computacional de otros puntos de confluencia y sus familias asociadas ($k_n$)[cite: 2]:

| Paso de Unión Acelerado | Familia Semilla Modelo ($k_n$) |
| :---: | :---: |
| $k + 2$ | $30 + 64n$ |
| $k + 3$ | $198 + 256n$ |
| $k + 4$ | $110 + 512n$ |
| $k + 5$ | $302 + 512n$ |
| $k + 6$ | $258 + 1024n$ |

---

## 🛠️ Verificación Computacional (`mctest.c`)

El repositorio incluye una herramienta en C con **GNU GMP** para validar la colisión y comparar el estado de la simulación con la fórmula cerrada para enteros de precisión arbitraria[cite: 2].

### Compilación

```bash
gcc -O3 -march=native -static mctest.c -o mctest.exe -lgmp
