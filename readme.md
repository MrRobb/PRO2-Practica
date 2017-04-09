
## Especie
- Reproducción sexual
- Genética mendeliana

## Individuo

| Variable  | Meaning   |
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

			 
