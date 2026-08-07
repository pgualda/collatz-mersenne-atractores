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

| Paso de Unión Acelerado | Familia Semilla Modelo ($k_n$) | Exp | n=0 |
| :---: | :---: | :---: | :---: |
| $k + 2$ | $30 + 64n$ | $\frac{3^{k+3}+125}{128}$|$43430160676216$|
| $k + 3_{1}$ | $78 + 256n$ |$\frac{3^{k+4}+439}{256}$|$519640\dots2808$|
| $k + 3_{2}$| $198 + 256n$ |$\frac{3^{k+4}+599}{512}$|$466899\dots7884$|
| $k + 3_{3}$ | $206 + 256n$ |$\frac{3^{k+4}+439}{512}$|$612665\dots8498$|
| $k + 3_{4}$ | $322 + 512n$ |$\frac{3^{k+4}+1063}{1024}$|$339804\dots2308$|
| $k + 3_{5}$ | $1288 + 4096n$ |$\frac{3^{k+4}+8207}{8192}$|$336721\dots0694$|
| $k + 4$ | $110 + 512n$ |$\frac{3^{k+5}+1445}{512}$|$144435\dots9696$|
| $k + 5$ | $302 + 512n$ |$\frac{3^{k+6}+4591}{1024}$|$877094\dots3298$|
| $k + 6$ | $...$ |$...$|$...$|

La unión en 3 o más pasos acelerados no es unica.

---
Se observo que asi como cualquier Mk (o directamente desde el R3 3^K-1) 30+64n coalesce en 10 pasos desde el R3, 34+64n coalesce en 234 pasos absolutos, verificado para R3-34 / R3-35 y R3-98 y R3-99, grandes grupos de R3 cercanos tienen cantidades de pasos similares, sin embargo el punto de coalescencia -si bien regular para los Mk/R3 de la misma forma- ocurre en una cantidad de pasos distinta.
En la forma de un R3 k (30+64n, 34+64n, 78+256n etc) esta predeterminada la cantidad de pasos de colision con el R3 k+1. 
Existe una forma 3^(k+pasos)+C/2^n para esos numeros.
---

## 🛠️ Verificación Computacional (`mctest2-30-64n.c`)

El repositorio incluye una herramienta en C con **GNU GMP** para validar la colisión y comparar el estado de la simulación con la fórmula cerrada para enteros de precisión arbitraria.

### Compilación

```bash
gcc -O3 -march=native -static mctest2-30-64n.c -o mctest2-30-64n.exe -lgmp
```
Se agrega para verificacion computacional de casos no demostrados:

mctest3-78-256n.c

mctest3-198-256n.c

mctest3-206-256n.c

mctest3-322-512n.c

mctest3-1288-4096n.c

mctest4-110-256n.c

mctest5-302-512n.c


instrucciones de compilacion en el codigo.

---
### Citation / DOI
To cite this repository or the underlying mathematical proof:
[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.21798733.svg)](https://doi.org/10.5281/zenodo.21798733)
