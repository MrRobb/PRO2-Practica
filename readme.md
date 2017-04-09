
## Especie
- Reproducción sexual
- Genética mendeliana

## Individuo

| Variable  | Significado   |
|:---------:    |:--------------------------------------------------------: |
| `N + X + Y`     | `N` cromosomas normales + Dos cromosomas sexuales   |
| `pi`    | Par de cromosomas `i` (normales). Compuesto de `ci1` y `ci2` (ambos de longitud `li`).    |
| `XX ó XY`  | Femenino o Masculino, respectivamente.    |

## Reproducción sexual

`XY` —\> Padre
`XX` —\> Madre

- Espermatozoide y óvulo sólo tienen un cromosoma de cada par
- En la fecundación se emparejan
- **Cruzamiento:** Para `cada par` de cromosomas se selecciona un punto aleatorio de corte (entre dos genes) `k` entre 0 i `li`.
	- **Normales:** `ci1` y `ci2` —\> `ci1’` y `ci2’`
		- `ci1’` contiene los mismos alelos que `ci1` de 1 a `k` y los mismos que `ci2` de `k+1` a `li`.
		- `ci2’` contiene los mismos alelos que `ci2` de 1 a `k` y los mismos que `ci1` de `k+1` a `li`.
	- **Sexuales:** la madre transmite el `X` y el padre puede transmitir un `X` o un `Y`.
		- El cruzamiento sólo se realiza en la parte común a ambos cromosomas (entre 1 y `l0`, con el punto de corte `k` entre 0 y `l0`) mientras que el resto de genes de los cromosomas `c01` y `c02` pasan directamente a los cromosomas `c01'` y `c02'`.

## Árbol genealógico

- Árbol binario

![Binary Tree][1]

- `Ap` No vacío + Estructura de `Ap` ==  Estructura de algún subconjunto conexo de un árbol `Ag` —\> **`Ap` árbol parcial de `Ag`**
- **Completar(`Ap`)** —\> `Ac` (copia de `Ag`)
	- A los nodos de `Ac` pero no en `Ap` se les añadirá una marca especial con respecto a su valor en `Ag`.

[1]:	https://cloud.githubusercontent.com/assets/7969569/24838861/b1e92926-1d50-11e7-810e-a5e49685d771.png "Binary Tree"